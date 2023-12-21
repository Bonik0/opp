#include "npc.h"



NPC::NPC(int x, int y, TypeNPC type_npc){
    point.first = x;
    point.second = y;
    type = type_npc;
}


TypeNPC NPC::string_to_TypeNPC(std::string type_npc){
    std::unordered_map<std::string, TypeNPC> convert = {
        {"bear", bear}, {"werewolf", werewolf}, {"robber", robber}
    };
    return convert[type_npc];
}

std::string NPC::TypeNPC_to_string(TypeNPC type_npc){
    std::unordered_map<TypeNPC, std::string> convert = {
        {bear, "bear"}, {werewolf, "werewolf"}, {robber, "robber"}
    };
    return convert[type_npc];
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
    return std::sqrt(std::pow(left->get_coord().first - right->get_coord().first, 2) + std::pow(left->get_coord().second - right->get_coord().second, 2));
}

std::ostream &operator<<(std::ostream &os, NPC & npc){
    return os << npc.point.first << " " << npc.point.second << " " << NPC::TypeNPC_to_string(npc.type) << " " << npc.name << "\n";
}

void NPC::save(std::ofstream &ofs){
    ofs << point.first << " " << point.second << " " << NPC::TypeNPC_to_string(type) << " " << name << "\n";
}