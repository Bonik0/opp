#include "factory.h"



std::shared_ptr<NPC> Factory::create(int x, int y, TypeNPC type_npc, std::string name){
    std::shared_ptr<NPC> npc;
    switch(type_npc) {
        case bear:
            npc = std::make_shared<Bear>(x, y, name);
            break;
        case werewolf:
            npc = std::make_shared<Werewolf>(x, y, name);
            break;
        case robber:
            npc = std::make_shared<Robber>(x, y, name);
            break;
        default:
            throw std::invalid_argument("Unknown type of NPC");
    }
    return npc;
}


std::shared_ptr<NPC> Factory::create(std::istream &is) {
    int x, y;
    std::string type, name;
    is >> x >> y;
    is >> type >> name;
    std::shared_ptr<NPC> npc = Factory::create(x, y, NPC::string_to_TypeNPC(type), name);
    return npc;
}

std::shared_ptr<NPC> Factory::create(std::ifstream &ifs) {
    int x, y;
    std::string type, name;
    ifs >> x >> y;
    ifs >> type >> name;
    std::shared_ptr<NPC> npc = Factory::create(x, y, NPC::string_to_TypeNPC(type), name);
    return npc;
}