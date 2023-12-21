#include "battle.h"



int main(){
    std::shared_ptr<Battle> b = std::make_shared<Battle>();
    std::ifstream file_in("test.txt");
    std::ofstream file_out("out.txt");
    std::shared_ptr<ObserverConsol> ob_cs = std::make_shared<ObserverConsol>();
    std::shared_ptr<ObserverFile> ob_fl = std::make_shared<ObserverFile>("b");
    b->get_NPC_from_file(file_in);
    b->attach_obs(ob_cs);
    b->attach_obs(ob_fl);
    b->battle(100);
    b->save(file_out);
    std::shared_ptr<Battle> b1 = std::make_shared<Battle>();
    b1->ramdom_NPC(100);
    std::shared_ptr<ObserverConsol> cons_obs = std::make_shared<ObserverConsol>();
    std::shared_ptr<ObserverFile> file_obs = std::make_shared<ObserverFile>("b1");
    b1->attach_obs(cons_obs);
    b1->attach_obs(file_obs);
    b1->battle(150);
}