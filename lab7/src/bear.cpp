#include "bear.h"


std::vector<std::string> list_first_name_bear = {
        "Misha",
        "Cupid",
        "Taiga",
        "Taezhka",
        "Ussuriy",
        "Suri",
        "Shantar",
        "Shanti",

};
std::vector<std::string> list_second_name_bear = {
        "cave",
        "brown",
        "dancing",
        "seasoned",
        "polar",
        "clumsy",
        "angry",
        "bamboo",
        "angry",
        "seasoned",
        "circus",
        "gigantic"
};

bool VisitorBear::visit(std::shared_ptr<const Bear> attacer) const{
    return false;
}

bool VisitorBear::visit(std::shared_ptr<const Werewolf> attacer) const{
    return false;
}

bool VisitorBear::visit(std::shared_ptr<const Robber> attacer) const{
    return true;
}



std::string Bear::create_name(){
    return NPC::create_name(list_first_name_bear, list_second_name_bear);
}

Bear::Bear(int x, int y, std::string name_npc) : NPC(x, y, bear){
    if(name_npc == ""){
        name_npc = create_name();
    }
    name = name_npc;
    move = BEAR_MOVE;
    range = BEAR_RANGE;
}


bool Bear::accept(std::shared_ptr<Visitor> visitor) const {
    return visitor->visit(std::dynamic_pointer_cast<const Bear>(shared_from_this()));
}




