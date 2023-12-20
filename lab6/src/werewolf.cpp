#include "werewolf.h"


bool VisitorWerewolf::visit(std::shared_ptr<const Bear> attacer) const{
    return false;
}

bool VisitorWerewolf::visit(std::shared_ptr<const Werewolf> attacer) const{
    return true;
}

bool VisitorWerewolf::visit(std::shared_ptr<const Robber> attacer) const{
    return false;
}



std::string Werewolf::create_name(){
    std::vector<std::string> list_of_first_name = {
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
    std::vector<std::string> list_of_second_name = {
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
    std::string first_name = list_of_first_name[std::rand() % list_of_first_name.size()];
    std::string second_name = list_of_second_name[std::rand() % list_of_second_name.size()];
    return second_name + "_" + first_name;
}

Werewolf::Werewolf(int x, int y, std::string name_npc) : NPC(x, y, werewolf, name){
}


bool Werewolf::accept(Visitor& visitor) const {
    return visitor.visit(std::dynamic_pointer_cast<const Werewolf>(shared_from_this()));
}

