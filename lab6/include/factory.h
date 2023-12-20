#pragma once

#include "robber.h"
#include "bear.h"
#include "werewolf.h"


class Factory{
    public:
        static std::shared_ptr<NPC> create(int x, int y, TypeNPC type, std::string name = "");
        static std::shared_ptr<NPC> create(std::istream &is);
        static std::shared_ptr<NPC> create(std::ifstream &ifs);
};