#include <gtest/gtest.h>

#include "battle.h"

TEST(test_00, NPC_TEXT)
{
   std::shared_ptr<Bear> b = std::make_shared<Bear>(2,3, "wer");
   ASSERT_TRUE(b->get_coord().first == 2 && b->get_coord().second == 3 && b->get_name() == "wer" && b->get_type() == bear);
}

TEST(test_01, NPC_TEXT)
{
   ASSERT_TRUE(NPC::TypeNPC_to_string(bear) == "bear" && NPC::string_to_TypeNPC("werewolf") == werewolf);
}

TEST(test_02, NPC_TEXT)
{
    std::shared_ptr<Bear> b = std::make_shared<Bear>(2,3, "wer");
    std::shared_ptr<Werewolf> w = std::make_shared<Werewolf>(2,4, "wer");
   ASSERT_TRUE(NPC::distance(w, b) == 1);
}

TEST(test_01, Factory_test)
{
    std::shared_ptr<Factory> fac;
    std::shared_ptr<NPC> npc1 = fac->create(1,1, bear);
    std::shared_ptr<NPC> npc2 = fac->create(2,2, werewolf);
    std::shared_ptr<NPC> npc3 = fac->create(3,3, robber);
   ASSERT_TRUE(npc1->get_type() == bear && npc2->get_type() == werewolf && npc3->get_type() == robber);
}

TEST(test_01, BearVisistor)
{
    std::shared_ptr<Factory> fac;
    std::shared_ptr<VisitorBear> v = std::make_shared<VisitorBear>();
    std::shared_ptr<NPC> npc1 = fac->create(1,1, bear);
    std::shared_ptr<NPC> npc2 = fac->create(2,2, werewolf);
    std::shared_ptr<NPC> npc3 = fac->create(3,3, robber);
   ASSERT_TRUE(npc1->accept(v) == false && npc2->accept(v) == false && npc3->accept(v) == true);
}

TEST(test_01, WerewolfVisistor)
{
    std::shared_ptr<Factory> fac;
    std::shared_ptr<VisitorWerewolf> v = std::make_shared<VisitorWerewolf>();
    std::shared_ptr<NPC> npc1 = fac->create(1,1, bear);
    std::shared_ptr<NPC> npc2 = fac->create(2,2, werewolf);
    std::shared_ptr<NPC> npc3 = fac->create(3,3, robber);
   ASSERT_TRUE(npc1->accept(v) == true && npc2->accept(v) == false && npc3->accept(v) == false);
}


TEST(test_01, RobberVisistor)
{
    std::shared_ptr<Factory> fac;
    std::shared_ptr<VisitorRobber> v = std::make_shared<VisitorRobber>();
    std::shared_ptr<NPC> npc1 = fac->create(1,1, bear);
    std::shared_ptr<NPC> npc2 = fac->create(2,2, werewolf);
    std::shared_ptr<NPC> npc3 = fac->create(3,3, robber);
   ASSERT_TRUE(npc1->accept(v) == false && npc2->accept(v) == true && npc3->accept(v) == false);
}

TEST(test_01, Battle_battle)
{
    std::shared_ptr<Factory> fac;
    std::shared_ptr<NPC> npc1 = fac->create(1,1, bear);
    std::shared_ptr<NPC> npc2 = fac->create(2,2, werewolf);
    std::shared_ptr<NPC> npc3 = fac->create(3,3, robber);
    std::shared_ptr<Battle> bat = std::make_shared<Battle>();
    bat->place_NPC(npc1);
    bat->place_NPC(npc2);
    bat->place_NPC(npc3);
    bat->battle(10);
   ASSERT_TRUE(bat->get_NPC_list().size() == 1);
}

TEST(test_02, Battle_battle)
{
    std::shared_ptr<Factory> fac;
    std::shared_ptr<NPC> npc1 = fac->create(1,1, bear);
    std::shared_ptr<NPC> npc2 = fac->create(2,2, werewolf);
    std::shared_ptr<NPC> npc3 = fac->create(3,3, robber);
    std::shared_ptr<Battle> bat = std::make_shared<Battle>();
    bat->place_NPC(npc1);
    bat->place_NPC(npc2);
    bat->place_NPC(npc3);
    bat->battle(0);
   ASSERT_TRUE(bat->get_NPC_list().size() == 3);
}

TEST(test_03, Battle_battle)
{
    std::shared_ptr<Factory> fac;
    std::shared_ptr<NPC> npc1 = fac->create(1,1, bear);
    std::shared_ptr<NPC> npc2 = fac->create(2,2, bear);
    std::shared_ptr<NPC> npc3 = fac->create(3,3, bear);
    std::shared_ptr<Battle> bat = std::make_shared<Battle>();
    bat->place_NPC(npc1);
    bat->place_NPC(npc2);
    bat->place_NPC(npc3);
    bat->battle(100);
   ASSERT_TRUE(bat->get_NPC_list().size() == 3);
}

TEST(test_04, Battle_battle)
{
    std::shared_ptr<Factory> fac;
    std::shared_ptr<NPC> npc1 = fac->create(1,1, bear);
    std::shared_ptr<NPC> npc2 = fac->create(1,2, bear);
    std::shared_ptr<NPC> npc3 = fac->create(1,4, robber);
    std::shared_ptr<Battle> bat = std::make_shared<Battle>();
    bat->place_NPC(npc1);
    bat->place_NPC(npc2);
    bat->place_NPC(npc3);
    bat->battle(3.0);
   ASSERT_TRUE(bat->get_NPC_list().size() == 1);
}
TEST(test_05, Battle_battle)
{
    std::shared_ptr<Factory> fac;
    std::shared_ptr<NPC> npc1 = fac->create(1,1, bear);
    std::shared_ptr<NPC> npc2 = fac->create(1,2, bear);
    std::shared_ptr<NPC> npc3 = fac->create(1,4, robber);
    std::shared_ptr<Battle> bat = std::make_shared<Battle>();
    bat->place_NPC(npc1);
    bat->place_NPC(npc2);
    bat->place_NPC(npc3);
    bat->battle(1.9);
   ASSERT_TRUE(bat->get_NPC_list().size() == 3);
}

TEST(test_06, Battle_battle)
{
    std::shared_ptr<Factory> fac;
    std::shared_ptr<NPC> npc1 = fac->create(1,1, werewolf);
    std::shared_ptr<NPC> npc2 = fac->create(2,2, werewolf);
    std::shared_ptr<NPC> npc3 = fac->create(3,3, werewolf);
    std::shared_ptr<Battle> bat = std::make_shared<Battle>();
    bat->place_NPC(npc1);
    bat->place_NPC(npc2);
    bat->place_NPC(npc3);
    bat->battle(100);
   ASSERT_TRUE(bat->get_NPC_list().size() == 3);
}

TEST(test_07, Battle_battle)
{
    std::shared_ptr<Factory> fac;
    std::shared_ptr<NPC> npc1 = fac->create(1,1, werewolf);
    std::shared_ptr<NPC> npc2 = fac->create(1,1, werewolf);
    std::shared_ptr<NPC> npc3 = fac->create(3,1, bear);
    std::shared_ptr<Battle> bat = std::make_shared<Battle>();
    bat->place_NPC(npc1);
    bat->place_NPC(npc2);
    bat->place_NPC(npc3);
    bat->battle(2);
   ASSERT_TRUE(bat->get_NPC_list().size() == 1);
}

TEST(test_08, Battle_battle)
{
    std::shared_ptr<Factory> fac;
    std::shared_ptr<NPC> npc1 = fac->create(1,1, werewolf);
    std::shared_ptr<NPC> npc2 = fac->create(1,1, werewolf);
    std::shared_ptr<NPC> npc3 = fac->create(3,1, bear);
    std::shared_ptr<Battle> bat = std::make_shared<Battle>();
    bat->place_NPC(npc1);
    bat->place_NPC(npc2);
    bat->place_NPC(npc3);
    bat->battle(1.9);
   ASSERT_TRUE(bat->get_NPC_list().size() == 3);
}

TEST(test_09, Battle_battle)
{
    std::shared_ptr<Factory> fac;
    std::shared_ptr<NPC> npc1 = fac->create(1,1, robber);
    std::shared_ptr<NPC> npc2 = fac->create(2,2, robber);
    std::shared_ptr<NPC> npc3 = fac->create(3,3, robber);
    std::shared_ptr<Battle> bat = std::make_shared<Battle>();
    bat->place_NPC(npc1);
    bat->place_NPC(npc2);
    bat->place_NPC(npc3);
    bat->battle(100);
   ASSERT_TRUE(bat->get_NPC_list().size() == 3);
}

TEST(test_10, Battle_battle)
{
    std::shared_ptr<Factory> fac;
    std::shared_ptr<NPC> npc1 = fac->create(1,1, robber);
    std::shared_ptr<NPC> npc2 = fac->create(1,2, robber);
    std::shared_ptr<NPC> npc3 = fac->create(1,3, werewolf);
    std::shared_ptr<Battle> bat = std::make_shared<Battle>();
    bat->place_NPC(npc1);
    bat->place_NPC(npc2);
    bat->place_NPC(npc3);
    bat->battle(100);
   ASSERT_TRUE(bat->get_NPC_list().size() == 1);
}

TEST(test_11, Battle_battle)
{
    std::shared_ptr<Factory> fac;
    std::shared_ptr<NPC> npc1 = fac->create(1,1, robber);
    std::shared_ptr<NPC> npc2 = fac->create(1,2, robber);
    std::shared_ptr<NPC> npc3 = fac->create(1,3, werewolf);
    std::shared_ptr<Battle> bat = std::make_shared<Battle>();
    bat->place_NPC(npc1);
    bat->place_NPC(npc2);
    bat->place_NPC(npc3);
    bat->battle(0.9);
   ASSERT_TRUE(bat->get_NPC_list().size() == 3);
}
TEST(test_12, Battle_battle)
{
    std::shared_ptr<Factory> fac;
    std::shared_ptr<NPC> npc1 = fac->create(1,1, robber);
    std::shared_ptr<NPC> npc2 = fac->create(1,2, robber);
    std::shared_ptr<NPC> npc3 = fac->create(1,3, werewolf);
    std::shared_ptr<Battle> bat = std::make_shared<Battle>();
    bat->place_NPC(npc1);
    bat->place_NPC(npc2);
    bat->place_NPC(npc3);
    bat->battle(1.9);
   ASSERT_TRUE(bat->get_NPC_list().size() == 2);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}