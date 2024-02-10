#include "robber.h"

std::vector<std::string> list_first_name_of_robber = {
        "Walter",
        "Wolf",
        "Willy", 
        "Watson", 
        "Valli", 
        "Woody", 
        "Velez", 
        "Winston", 
        "Veniamin", 
        "Wax", 
        "Valmont", 
        "Varg", 
        "Veron", 
        "William", 
        "Wilson"
    };
std::vector<std::string> list_second_name_of_robber = {
        "hapless", 
        "street", 
        "armed", 
        "ordinary", 
        "casual", 
        "banking", 
        "professional", 
        "potential", 
        "night", 
        "unknown"
};


bool VisitorRobber::visit(std::shared_ptr<const Bear> attacer) const{
    return false;
}

bool VisitorRobber::visit(std::shared_ptr<const Werewolf> attacer) const{
    return true ;
}

bool VisitorRobber::visit(std::shared_ptr<const Robber> attacer) const{
    return false;
}



std::string Robber::create_name(){
    return NPC::create_name(list_first_name_of_robber, list_second_name_of_robber);
}

Robber::Robber(int x, int y, std::string name_npc) : NPC(x, y, robber){
    if(name_npc == ""){
        name_npc = create_name();
    }
    name = name_npc;
    move = ROBBER_MOVE;
    range = ROBBER_RANGE;
}


bool Robber::accept(std::shared_ptr<Visitor> visitor) const {
    return visitor->visit(std::dynamic_pointer_cast<const Robber>(shared_from_this()));
}



