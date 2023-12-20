#include "robber.h"


bool VisitorRobber::visit(std::shared_ptr<const Bear> attacer) const{
    return true;
}

bool VisitorRobber::visit(std::shared_ptr<const Werewolf> attacer) const{
    return false;
}

bool VisitorRobber::visit(std::shared_ptr<const Robber> attacer) const{
    return false;
}



std::string Robber::create_name(){
    std::vector<std::string> list_of_first_name = {
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
    std::vector<std::string> list_of_second_name = {
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
    std::string first_name = list_of_first_name[std::rand() % list_of_first_name.size()];
    std::string second_name = list_of_second_name[std::rand() % list_of_second_name.size()];
    return second_name + "_" + first_name;
}

Robber::Robber(int x, int y, std::string name_npc) : NPC(x, y, robber, name){
}


bool Robber::accept(Visitor& visitor) const {
    return visitor.visit(std::dynamic_pointer_cast<const Robber>(shared_from_this()));
}



