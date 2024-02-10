#include "npc.h"

std::unordered_map<std::string, TypeNPC> convert = {
        {"bear", bear}, {"werewolf", werewolf}, {"robber", robber}
};
std::unordered_map<TypeNPC, std::string> convert1 = {
        {bear, "bear"}, {werewolf, "werewolf"}, {robber, "robber"}
};

NPC::NPC(int x, int y, TypeNPC type_npc){
    point.first = x;
    point.second = y;
    type = type_npc;
}

std::string NPC::create_name(std::vector<std::string> list_of_first_name, std::vector<std::string> list_of_second_name){
    std::string first_name = list_of_first_name[std::rand() % list_of_first_name.size()];
    std::string second_name = list_of_second_name[std::rand() % list_of_second_name.size()];
    return second_name + "_" + first_name;
}


TypeNPC NPC::string_to_TypeNPC(std::string type_npc){
    return convert[type_npc];
}

std::string NPC::TypeNPC_to_string(TypeNPC type_npc){
    return convert1[type_npc];
}



TypeNPC NPC::get_type() const{
    return type;
}

std::pair<int, int> NPC::get_coord() const{
    return point;
}

std::string NPC::get_name() const{
    return name;
}

double NPC::distance(const std::shared_ptr<NPC> left, const std::shared_ptr<NPC> right){
    return std::pow(std::pow(left->get_coord().first - right->get_coord().first, 2) + std::pow(left->get_coord().second - right->get_coord().second, 2), 0.5);
}

std::ostream &operator<<(std::ostream &os, NPC & npc){
    return os << npc.point.first << " " << npc.point.second << " " << NPC::TypeNPC_to_string(npc.type) << " " << npc.name << "\n";
}

void NPC::save(std::ofstream &ofs){
    ofs << point.first << " " << point.second << " " << NPC::TypeNPC_to_string(type) << " " << name << "\n";
}

bool NPC::is_close(std::shared_ptr<NPC> deffender){
    double distance = NPC::distance(shared_from_this(), deffender);
    return distance <= range;
}

void NPC::do_move(int move_x, int move_y) {
    if ((point.first + move_x >= 0) && (point.first + move_x < BTF_SIZE)) {
        point.first += move_x;
    }

    if ((point.second + move_y >= 0) && (point.second + move_y < BTF_SIZE)) {
        point.second += move_y;
    }
}

int NPC::get_move(){
    return move;
}