#include "bear.h"

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
    std::vector<std::string> list_of_first_name = {
        "Misha",
        "Cupid",
        "Taiga",
        "Taezhka",
        "Ussuriy",
        "Suri",
        "Shantar",
        "Shanti",

    };
    std::vector<std::string> list_of_second_name = {
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
    std::string first_name = list_of_first_name[std::rand() % list_of_first_name.size()];
    std::string second_name = list_of_second_name[std::rand() % list_of_second_name.size()];
    return second_name + "_" + first_name;
}

Bear::Bear(int x, int y, std::string name_npc) : NPC(x, y, bear){
    if(name_npc == ""){
        name_npc = create_name();
    }
    name = name_npc;
}


bool Bear::accept(std::shared_ptr<Visitor> visitor) const {
    return visitor->visit(std::dynamic_pointer_cast<const Bear>(shared_from_this()));
}




