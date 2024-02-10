#pragma once

#include "factory.h"

class Battle;

class Observer : public std::enable_shared_from_this<Observer>{
    public:
        Observer();
        virtual void battle_start(const std::unordered_set<std::shared_ptr<NPC>> npcList) = 0;
        virtual void battle_end(const std::unordered_set<std::shared_ptr<NPC>> npcList) = 0;
        virtual void fight(std::shared_ptr<NPC> defender, std::shared_ptr<NPC> attacer, bool is_win) = 0;
        virtual void roll(std::shared_ptr<NPC> defender, std::shared_ptr<NPC> attacer, int attacer_dice, int deffender_dice) = 0;
};

class ObserverConsol : public Observer{
    public:
        ObserverConsol();
        void battle_start(const std::unordered_set<std::shared_ptr<NPC>> npcList) override;
        void battle_end(const std::unordered_set<std::shared_ptr<NPC>> npcList) override;
        void fight(std::shared_ptr<NPC> defender, std::shared_ptr<NPC> attacer, bool is_win) override;
        void roll(std::shared_ptr<NPC> defender, std::shared_ptr<NPC> attacer, int attacer_dice, int deffender_dice) override;
};

class ObserverFile : public Observer{
    private:
        std::ofstream file;
    public:
        ObserverFile(std::string name);
        ~ObserverFile();
        void battle_start(const std::unordered_set<std::shared_ptr<NPC>> npcList) override;
        void battle_end(const std::unordered_set<std::shared_ptr<NPC>> npcList) override;
        void fight(std::shared_ptr<NPC> defender, std::shared_ptr<NPC> attacer, bool is_win) override;
        void roll(std::shared_ptr<NPC> defender, std::shared_ptr<NPC> attacer, int attacer_dice, int deffender_dice) override;
};


class Battle{
    protected:
        struct Duel{
            std::shared_ptr<NPC> defender;
            std::shared_ptr<NPC> attacker;
        };
        std::unordered_set<std::shared_ptr<NPC>> npc_list;
        std::mutex mtx;
        std::unordered_set<std::shared_ptr<Observer>> observers;
        std::unordered_set<std::shared_ptr<NPC>> dead_list;
        std::list<Duel> duel_list;
        int Rand();
        int throw_dice();
        std::chrono::_V2::steady_clock::time_point awake_time();
    public:
        void ramdom_NPC(int quantity);
        void place_NPC(std::shared_ptr<NPC> npc);
        void remove_NPC(std::shared_ptr<NPC> npc);
        void get_NPC_from_consol(std::istream &is);
        void get_NPC_from_file(std::ifstream &ifs);
        void battle();
        void save(std::ofstream &ofs);
        std::unordered_set<std::shared_ptr<NPC>> get_NPC_list();
        friend std::ostream &operator<<(std::ostream &os, Battle bt);
        void attach_obs(std::shared_ptr<Observer> obs);
        void detach_obs(std::shared_ptr<Observer> obs);
        void notify(TypeCommand command, std::shared_ptr<NPC> defender = nullptr, std::shared_ptr<NPC> attacer = nullptr, bool is_win = false, int attacer_dice = 0,int deffender_dice = 0);
};



