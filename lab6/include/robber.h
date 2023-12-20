#pragma once


#include "npc.h"



class VisitorRobber : public Visitor{
    public:
        bool visit(std::shared_ptr<const Bear> attacer) const override;
        bool visit(std::shared_ptr<const Werewolf> attacer) const override;
        bool visit(std::shared_ptr<const Robber> attacer) const override;
};

class Robber : public NPC {
    protected:
        std::string create_name() override;
    public:
        Robber(int x, int y, std::string name_npc = "");
        bool accept(Visitor& visitor) const override;
};