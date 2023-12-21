#pragma once

#include "factory.h"

class Battle;

class Observer : public std::enable_shared_from_this<Observer>{
    public:
        Observer();
        virtual void battle_start(const std::set<std::shared_ptr<NPC>> npcList) = 0;
        virtual void battle_end(const std::set<std::shared_ptr<NPC>> npcList) = 0;
        virtual void fight(std::shared_ptr<NPC> defender, std::shared_ptr<NPC> attacer, bool is_win) = 0;
};

class ObserverConsol : public Observer{
    public:
        ObserverConsol();
        void battle_start(const std::set<std::shared_ptr<NPC>> npcList) override;
        void battle_end(const std::set<std::shared_ptr<NPC>> npcList) override;
        void fight(std::shared_ptr<NPC> defender, std::shared_ptr<NPC> attacer, bool is_win) override;
};

class ObserverFile : public Observer{
    private:
        std::ofstream file;
    public:
        ObserverFile(std::string name);
        ~ObserverFile();
        void battle_start(const std::set<std::shared_ptr<NPC>> npcList) override;
        void battle_end(const std::set<std::shared_ptr<NPC>> npcList) override;
        void fight(std::shared_ptr<NPC> defender, std::shared_ptr<NPC> attacer, bool is_win) override;
};


class Battle{
    protected:
        std::set<std::shared_ptr<NPC>> npc_list;
        std::set<std::shared_ptr<Observer>> observers;
    public:
        void ramdom_NPC(int quantity);
        void place_NPC(std::shared_ptr<NPC> npc);
        void remove_NPC(std::shared_ptr<NPC> npc);
        void get_NPC_from_consol(std::istream &is);
        void get_NPC_from_file(std::ifstream &ifs);
        void battle(double distance);
        void save(std::ofstream &ofs);
        std::set<std::shared_ptr<NPC>> get_NPC_list();
        friend std::ostream &operator<<(std::ostream &os, Battle bt);
        void attach_obs(std::shared_ptr<Observer> obs);
        void detach_obs(std::shared_ptr<Observer> obs);
        void notify(TypeCommand command, std::shared_ptr<NPC> defender = nullptr, std::shared_ptr<NPC> attacer = nullptr, bool is_win = false);
};


