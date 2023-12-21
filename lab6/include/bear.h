#pragma once


#include "npc.h"



class VisitorBear : public Visitor{
    public:
        bool visit(std::shared_ptr<const Bear> attacer) const override;
        bool visit(std::shared_ptr<const Werewolf> attacer) const override;
        bool visit(std::shared_ptr<const Robber> attacer) const override;
};

class Bear : public NPC {
    protected:
        std::string create_name() override;
    public:
        Bear(int x, int y, std::string name_npc = "");
        bool accept(std::shared_ptr<Visitor> visitor) const override;
};