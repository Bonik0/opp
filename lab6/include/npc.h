#pragma once


#include <iostream>
#include <fstream>
#include <math.h>
#include <unordered_map>
#include <memory>
#include <vector>
#include <set>
#include <random>

enum TypeNPC {
    bear = 0,
    werewolf = 1,
    robber = 2,
};

enum TypeCommand {
    start = 0,
    fight = 1,
    end = 2,
};

const int SIZE_FILD = 500;


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
        virtual std::string create_name() = 0;
    public:
        static double distance(const std::shared_ptr<NPC> left, const std::shared_ptr<NPC> right);
        static TypeNPC string_to_TypeNPC(std::string type_npc);
        static std::string TypeNPC_to_string(TypeNPC type_npc);
        NPC(int x, int y, TypeNPC type_npc);
        TypeNPC get_type() const;
        std::pair<int, int> get_coord() const;
        std::string get_name() const;
        virtual bool accept(std::shared_ptr<Visitor> visitor) const = 0;
        void save(std::ofstream &ofs);
        friend std::ostream &operator<<(std::ostream &os, NPC &npc);
        
};