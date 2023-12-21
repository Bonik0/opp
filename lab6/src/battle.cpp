#include "battle.h"



void Battle::ramdom_NPC(int quantity){
    std::shared_ptr<Factory> fac;
    for(int i = 0; i < quantity; i++){
        place_NPC(fac->create(std::rand() % 500, std::rand() % 500, TypeNPC(std::rand() % 3)));
    }
}

void Battle::place_NPC(std::shared_ptr<NPC> npc){
    if (npc->get_coord().first <= SIZE_FILD && npc->get_coord().second <= SIZE_FILD && npc->get_coord().first >= 0 && npc->get_coord().second >= 0){
        npc_list.insert(npc);
    }
}

void Battle::remove_NPC(std::shared_ptr<NPC> npc){
    npc_list.erase(npc);
}

void Battle::battle(double distance){
    std::set<std::shared_ptr<NPC>> dead_list;
    std::unordered_map<TypeNPC, std::shared_ptr<Visitor>> visiors = {
        {bear, std::make_shared<VisitorBear>()}, {werewolf, std::make_shared<VisitorWerewolf>()}, {robber, std::make_shared<VisitorRobber>()}
    };
    this->notify(start);
    for(std::shared_ptr<NPC> attacer: npc_list){
        for(std::shared_ptr<NPC> defender: npc_list){
            if(attacer != defender && NPC::distance(attacer, defender) <= distance && dead_list.find(defender) == dead_list.end()){
                bool is_win = attacer->accept(visiors[defender->get_type()]);
                if(is_win){
                    dead_list.insert(defender);
                }
                this->notify(fight, defender, attacer, is_win);
            }
        }
    }
    for(std::shared_ptr<NPC> dead: dead_list){
        this->remove_NPC(dead);
    }
    this->notify(end);
}

void Battle::get_NPC_from_consol(std::istream &is){
    int quantity;
    is >> quantity;
    std::shared_ptr<Factory> fac;
    for(int i = 0; i < quantity; i++){
        place_NPC(fac->create(is));
    }
}

void Battle::get_NPC_from_file(std::ifstream &ifs){
    int quantity;
    ifs >> quantity;
    std::shared_ptr<Factory> fac;
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

std::set<std::shared_ptr<NPC>> Battle::get_NPC_list(){
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


void Battle::notify(TypeCommand command, std::shared_ptr<NPC> defender, std::shared_ptr<NPC> attacer, bool is_win){
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
    default:
        break;
    }
}



Observer::Observer(){
}

ObserverConsol::ObserverConsol(){
}


void ObserverConsol::battle_start(const std::set<std::shared_ptr<NPC>> npc_list){
    std::cout << "\n------------Start battle------------\n";
    std::cout << npc_list.size() << " - fighters:\n";
    for(std::shared_ptr<NPC> npc: npc_list){
        std::cout << *npc;
    }
    std::cout << "---------------------------------------\n";
}


void ObserverConsol::battle_end(const std::set<std::shared_ptr<NPC>> npc_list){
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
        std::cout << defender->get_name() << " defended from" << attacer->get_name() << "(";
    }
    std::cout << "x_attacer = " << attacer->get_coord().first << ", y_attacer = " << attacer->get_coord().second << "\n";
    std::cout << "x_defender = " << defender->get_coord().first << ", y_defender = " << defender->get_coord().second << "\n";
    std::cout << "attacer_type = " << NPC::TypeNPC_to_string(attacer->get_type()) << ", defender_type = " << NPC::TypeNPC_to_string(defender->get_type()) << ")\n";
    std::cout << "\n";
}



ObserverFile::ObserverFile(std::string name){
    file.open(name + "_log.txt");
}

ObserverFile::~ObserverFile(){
    file.close();
}

void ObserverFile::battle_start(const std::set<std::shared_ptr<NPC>> npc_list){
    file << "\n------------Start battle------------\n";
    file << npc_list.size() << " - fighters:\n";
    for(std::shared_ptr<NPC> npc: npc_list){
        file << *npc;
    }
    file << "---------------------------------------\n";
}


void ObserverFile::battle_end(const std::set<std::shared_ptr<NPC>> npc_list){
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