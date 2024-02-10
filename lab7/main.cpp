#include "src/battle.cpp"



int main(){
    std::shared_ptr<Battle> b1 = std::make_shared<Battle>();
    b1->ramdom_NPC(10);
    std::shared_ptr<ObserverConsol> cons_obs = std::make_shared<ObserverConsol>();
    std::shared_ptr<ObserverFile> file_obs = std::make_shared<ObserverFile>("b1");
    b1->attach_obs(cons_obs);
    b1->attach_obs(file_obs);
    b1->battle();
}