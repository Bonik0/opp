#include "factory.h"



class Battle{
    protected:
        std::vector<std::shared_ptr<NPC>> npc_list;
    public:
        void ramdom_NPC(int quantity);
        void place_NPC(std::shared_ptr<NPC> npc);
        void remove_NPC(std::shared_ptr<NPC> npc);
        void get_NPC_from_consol(std::istream &is);
        void get_NPC_from_file(std::ifstream &ifs);
        void battle();

};