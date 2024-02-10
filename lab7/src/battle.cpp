#include "battle.h"

int Battle::Rand() {
    static std::random_device rd;  
    static std::mt19937 gen(rd());  
    static std::uniform_int_distribution<int> distribution(0, 100); 
    return distribution(gen);  
}

int Battle::throw_dice(){   
    return (Rand() % 6) + 1;
}

std::chrono::_V2::steady_clock::time_point Battle::awake_time(){
    return std::chrono::steady_clock::now() + std::chrono::milliseconds(1000);
}

void Battle::ramdom_NPC(int quantity){
    std::shared_ptr<Factory> fac = std::make_shared<Factory>();
    for(int i = 0; i < quantity; i++){
        place_NPC(fac->create(std::rand() % BTF_SIZE, std::rand() % BTF_SIZE, TypeNPC(std::rand() % 3)));
    }
}

void Battle::place_NPC(std::shared_ptr<NPC> npc){
    if (npc->get_coord().first <= BTF_SIZE && npc->get_coord().second <= BTF_SIZE && npc->get_coord().first >= 0 && npc->get_coord().second >= 0){
        npc_list.insert(npc);
    }
}

void Battle::remove_NPC(std::shared_ptr<NPC> npc){
    npc_list.erase(npc);
}

void Battle::battle(){
    std::cout << npc_list.size();
    this->notify(start);
    std::unordered_map<std::string, bool> state{{"round_finish", false}, {"game_finish", false}};
    std::chrono::_V2::steady_clock::time_point awake = awake_time();
    auto start_time = std::chrono::steady_clock::now();
    auto move_function = [this](std::unordered_map<std::string, bool> &state){
        while(!state["game_finish"]){
            if (!state["round_finish"]){
                for(auto attacker : npc_list){
                    std::this_thread::sleep_for(std::chrono::milliseconds(1));
                    std::lock_guard lock(mtx);
                    if (dead_list.find(attacker) == dead_list.end()){
                        int move_x = -attacker->get_move() + (Rand() % (2 * attacker->get_move()));
                        int remaining_movement = attacker->get_move() - abs(move_x);
                        int move_y = (-1 + (Rand() % 2) * 2) * remaining_movement;
                        attacker->do_move(move_x, move_y);
                        for(auto deffender : npc_list){
                            if (attacker != deffender && attacker->is_close(deffender) && dead_list.find(deffender) == dead_list.end()){
                                Duel duel;
                                duel.attacker = attacker;
                                duel.defender = deffender;
                                duel_list.push_back(duel);
                            }
                        }
                    }
                }
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
                std::lock_guard lock(mtx);
                for(auto dead : dead_list){
                    this->remove_NPC(dead);
                }
                state["round_finish"] = true;
            }
        }
    };
    auto fight_function = [this](std::unordered_map<std::string, bool> &state){
        std::unordered_map<TypeNPC, std::shared_ptr<Visitor>> visiors = {
        {bear, std::make_shared<VisitorBear>()}, {werewolf, std::make_shared<VisitorWerewolf>()}, {robber, std::make_shared<VisitorRobber>()}
        };
        while(!state["game_finish"]){
                std::lock_guard lock(mtx);
                for(auto duel : duel_list){
                    std::shared_ptr<NPC> attacker = duel.attacker;
                    std::shared_ptr<NPC> deffender = duel.defender;
                    if(attacker->accept(visiors[deffender->get_type()])){
                        int attacker_dice = throw_dice();
                        int deffender_dice = throw_dice();
                        this->notify(croll, deffender, attacker, false, attacker_dice, deffender_dice);
                        if (attacker_dice > deffender_dice){
                            this->notify(fight, deffender, attacker, true);
                            dead_list.insert(deffender);
                        } else {
                            this->notify(fight, deffender, attacker, false);
                        }
                    } else {
                        this->notify(fight, deffender, attacker, false);
                    }
                }
                duel_list.clear();
        }
    };
    auto print_function = [this](std::unordered_map<std::string, bool> &state, std::chrono::time_point<std::chrono::_V2::steady_clock, std::chrono::_V2::steady_clock::duration> &awake, std::chrono::time_point<std::chrono::_V2::steady_clock, std::chrono::_V2::steady_clock::duration> start)
    {
        while (!state["game_finish"]){
            std::lock_guard lock(mtx);
            if (state["round_finish"]){
                std::this_thread::sleep_until(awake);
                std::vector<std::vector<char>> field(BTF_SIZE, std::vector<char>(BTF_SIZE, '.'));
                char icon = '.';
                for (auto npc : npc_list) {
                    switch (npc->get_type()){
                        case bear:
                            icon = 'B';
                            break;
                        case werewolf:
                            icon = 'w';
                            break;
                        case robber:
                            icon = 'R';
                            break;
                        default:
                            break;
                        }
                    field[npc->get_coord().first][npc->get_coord().second] = icon;
                }
                for (int i = 0; i < BTF_SIZE; ++i) {
                    for (int j = 0; j < BTF_SIZE; ++j) {
                        std::cout << field[i][j];
                    }
                    std::cout << '\n';
                }
                std::cout << '\n';
            if (std::chrono::steady_clock::now() > start + std::chrono::milliseconds(FIGHT_DURATION)){
                state["game_finish"] = true;
            }
            state["round_finish"] = false;
            awake = awake_time();
            }
        }
    };
    std::thread move_therad(move_function, std::ref(state));
    std::thread fight_therad(fight_function, std::ref(state));
    std::thread print_thread(print_function, ref(state), ref(awake), start_time);
    move_therad.join();
    fight_therad.join();
    print_thread.join();
    this->notify(end);
}

void Battle::get_NPC_from_consol(std::istream &is){
    int quantity;
    is >> quantity;
    std::shared_ptr<Factory> fac = std::make_shared<Factory>();
    for(int i = 0; i < quantity; i++){
        place_NPC(fac->create(is));
    }
}

void Battle::get_NPC_from_file(std::ifstream &ifs){
    int quantity;
    ifs >> quantity;
    std::shared_ptr<Factory> fac = std::make_shared<Factory>();
    for(int i = 0; i < quantity; i++){
        place_NPC(fac->create(ifs));
    }
}


std::ostream &operator<<(std::ostream &os, Battle bt){
    os << bt.npc_list.size() << "\n";
    for (auto npc: bt.npc_list) {
        os << *npc;
    }
    return os;
}

std::unordered_set<std::shared_ptr<NPC>> Battle::get_NPC_list(){
    return npc_list;
}

void Battle::save(std::ofstream &ofs){
    ofs << npc_list.size() << "\n";
    for (auto npc: npc_list) {
        ofs << *npc;
    }
}


void Battle::attach_obs(std::shared_ptr<Observer> obs) {
    observers.insert(obs);
}

void Battle::detach_obs(std::shared_ptr<Observer> obs) {
    observers.erase(obs);
}


void Battle::notify(TypeCommand command, std::shared_ptr<NPC> defender, std::shared_ptr<NPC> attacer, bool is_win, int attacer_dice, int deffender_dice){
    switch (command)
    {
    case start:
        for(std::shared_ptr<Observer> obs : observers){
            obs->battle_start(npc_list);
        }
        break;
    case end:
        for(std::shared_ptr<Observer> obs : observers){
            obs->battle_end(npc_list);
        }
        break;
    case fight:
        for(std::shared_ptr<Observer> obs : observers){
            obs->fight(defender, attacer, is_win);
        }
        break;
    case croll:
        for(std::shared_ptr<Observer> obs : observers){
            obs->roll(defender, attacer, attacer_dice, deffender_dice);
        }
    default:
        break;
    }
}



Observer::Observer(){
}

ObserverConsol::ObserverConsol(){
}


void ObserverConsol::battle_start(const std::unordered_set<std::shared_ptr<NPC>> npc_list){
    std::cout << "\n------------Start battle------------\n";
    std::cout << npc_list.size() << " - fighters:\n";
    for(std::shared_ptr<NPC> npc: npc_list){
        std::cout << *npc;
    }
    std::cout << "---------------------------------------\n";
}


void ObserverConsol::battle_end(const std::unordered_set<std::shared_ptr<NPC>> npc_list){
    std::cout << "\n------------End battle------------\n";
    std::cout << npc_list.size() << " - alive:\n";
    for(std::shared_ptr<NPC> npc: npc_list){
        std::cout << *npc;
    }
    std::cout << "---------------------------------------\n";
}
void ObserverConsol::fight(std::shared_ptr<NPC> defender, std::shared_ptr<NPC> attacer, bool is_win){
    std::cout << "\n\n";
    if (is_win){
        std::cout << attacer->get_name() << " kill " << defender->get_name() << "(";
    } else {
        std::cout << defender->get_name() << " defended from " << attacer->get_name() << "(";
    }
    std::cout << "x_attacer = " << attacer->get_coord().first << ", y_attacer = " << attacer->get_coord().second << "\n";
    std::cout << "x_defender = " << defender->get_coord().first << ", y_defender = " << defender->get_coord().second << "\n";
    std::cout << "attacer_type = " << NPC::TypeNPC_to_string(attacer->get_type()) << ", defender_type = " << NPC::TypeNPC_to_string(defender->get_type()) << ")\n";
    std::cout << "\n";
}

void ObserverConsol::roll(std::shared_ptr<NPC> defender, std::shared_ptr<NPC> attacer, int attacer_dice, int deffender_dice){
    std::cout << "\n\n";
    std::cout << attacer->get_name() << " roll " << attacer_dice << "\n";
    std::cout << defender->get_name() << " roll " << deffender_dice << "\n";
    std::cout << "\n";
}



ObserverFile::ObserverFile(std::string name){
    file.open(name + "_log.txt", std::ios::app);
}

ObserverFile::~ObserverFile(){
    file.close();
}

void ObserverFile::battle_start(const std::unordered_set<std::shared_ptr<NPC>> npc_list){
    file << "\n------------Start battle------------\n";
    file << npc_list.size() << " - fighters:\n";
    for(std::shared_ptr<NPC> npc: npc_list){
        file << *npc;
    }
    file << "---------------------------------------\n";
}


void ObserverFile::battle_end(const std::unordered_set<std::shared_ptr<NPC>> npc_list){
    file << "\n------------End battle------------\n";
    file << npc_list.size() << " - alive:\n";
    for(std::shared_ptr<NPC> npc: npc_list){
        file << *npc;
    }
    file << "---------------------------------------\n";
}
void ObserverFile::fight(std::shared_ptr<NPC> defender, std::shared_ptr<NPC> attacer, bool is_win){
    file << "\n\n";
    if (is_win){
        file << attacer->get_name() << " kill " << defender->get_name() << "(";
    } else {
        file << defender->get_name() << " defended from" << attacer->get_name() << "(";
    }
    file << "x_attacer = " << attacer->get_coord().first << ", y_attacer = " << attacer->get_coord().second << "\n";
    file << "x_defender = " << defender->get_coord().first << ", y_defender = " << defender->get_coord().second << "\n";
    file << "attacer_type = " << NPC::TypeNPC_to_string(attacer->get_type()) << ", defender_type = " << NPC::TypeNPC_to_string(defender->get_type()) << ")\n";
    file << "\n";
}

void ObserverFile::roll(std::shared_ptr<NPC> defender, std::shared_ptr<NPC> attacer, int attacer_dice, int deffender_dice){
    file << "\n\n";
    file << attacer->get_name() << " roll " << attacer_dice << "\n";
    file << defender->get_name() << " roll " << deffender_dice << "\n";
    file << "\n";
}