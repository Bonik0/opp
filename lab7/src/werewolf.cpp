#include "werewolf.h"

std::vector<std::string> list_first_name_of_werewolf = {
        "Dick",
        "John",
        "Jake",
        "Damon",
        "Jay",
        "Dan",
        "Jerry",
        "Jim",
        "Danny",
        "Dudley",
        "Duke",
        "Jason",
        "Dave",
        "Dante",
        "Django",
        "Dex",
        "Joe",
        "Jasper",
        "Julian",
        "Dingo",
        "Jackson",
        "Dave",
        "Diego"
    };
    std::vector<std::string> list_second_name_of_werewolf = {
        "first",
        "second",
        "old",
        "rest",
        "rat",
        "universal",
        "existing",
        "famous",
        "wounded",
        "red",
        "high-ranking",
        "chief",
        "purebred"
    };

bool VisitorWerewolf::visit(std::shared_ptr<const Bear> attacer) const{
    return true;
}

bool VisitorWerewolf::visit(std::shared_ptr<const Werewolf> attacer) const{
    return false;
}

bool VisitorWerewolf::visit(std::shared_ptr<const Robber> attacer) const{
    return false;
}



std::string Werewolf::create_name(){
    return NPC::create_name(list_first_name_of_werewolf, list_second_name_of_werewolf);
}

Werewolf::Werewolf(int x, int y, std::string name_npc) : NPC(x, y, werewolf){
    if(name_npc == ""){
        name_npc = create_name();
    }
    name = name_npc;
    move = WEREWOLF_MOVE;
    range = WEREWOLF_RANGE;
}


bool Werewolf::accept(std::shared_ptr<Visitor> visitor) const {
    return visitor->visit(std::dynamic_pointer_cast<const Werewolf>(shared_from_this()));
}

