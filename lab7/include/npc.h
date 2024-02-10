#pragma once


#include <iostream>
#include <fstream>
#include <math.h>
#include <unordered_map>
#include <memory>
#include <vector>
#include <unordered_set>
#include <random>
#include <thread>
#include <mutex>
#include <list>
#include <shared_mutex>
#include <chrono>



#define BTF_SIZE 10
#define BEAR_MOVE 5
#define BEAR_RANGE 10
#define WEREWOLF_MOVE 40
#define WEREWOLF_RANGE 5
#define ROBBER_MOVE 10
#define ROBBER_RANGE 10
#define FIGHT_DURATION 20000

enum TypeNPC {
    bear = 0,
    werewolf = 1,
    robber = 2,
};

enum TypeCommand {
    start = 0,
    fight = 1,
    end = 2,
    croll = 3
};



class Bear;
class Werewolf;
class Robber;


class Visitor {
    public:
        virtual bool visit(std::shared_ptr<const Bear> attacer) const = 0;
        virtual bool visit(std::shared_ptr<const Werewolf> attacer) const = 0;
        virtual bool visit(std::shared_ptr<const Robber> attacer) const = 0;
};



class NPC : public std::enable_shared_from_this<NPC>{
    protected:
        TypeNPC type;
        std::pair<int, int> point;
        std::string name;
        int move;
        int range;
        static std::string create_name(std::vector<std::string> list_of_first_name, std::vector<std::string> list_of_second_name);
    public:
        static double distance(const std::shared_ptr<NPC> left, const std::shared_ptr<NPC> right);
        static TypeNPC string_to_TypeNPC(std::string type_npc);
        static std::string TypeNPC_to_string(TypeNPC type_npc);
        NPC(int x, int y, TypeNPC type_npc);
        TypeNPC get_type() const;
        std::pair<int, int> get_coord() const;
        bool is_close(std::shared_ptr<NPC> other);
        std::string get_name() const;
        int get_move();
        void do_move(int move_x, int move_y);
        virtual bool accept(std::shared_ptr<Visitor> visitor) const = 0;
        void save(std::ofstream &ofs);
        friend std::ostream &operator<<(std::ostream &os, NPC &npc);
        
};