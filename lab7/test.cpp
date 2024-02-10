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

TEST(test_03, NPC_TEXT)
{
    std::shared_ptr<Bear> b = std::make_shared<Bear>(2,3, "wer");
    std::shared_ptr<Werewolf> w = std::make_shared<Werewolf>(2,4, "wer");
   ASSERT_TRUE(w->is_close(b) == true);
}

TEST(test_04, NPC_TEXT)
{
   std::shared_ptr<Bear> b = std::make_shared<Bear>(2,3, "wer");
   std::shared_ptr<Werewolf> w = std::make_shared<Werewolf>(2,9, "wer");
   ASSERT_TRUE(w->is_close(b) == false);
}

TEST(test_05, NPC_TEXT)
{
   std::shared_ptr<Bear> b = std::make_shared<Bear>(2,3, "wer");
   std::shared_ptr<Werewolf> w = std::make_shared<Werewolf>(2,2, "wer");
   ASSERT_TRUE(b->is_close(w) == true);
}

TEST(test_06, NPC_TEXT)
{
   std::shared_ptr<Bear> b = std::make_shared<Bear>(2,3, "wer");
   std::shared_ptr<Werewolf> w = std::make_shared<Werewolf>(2,2, "wer");
   ASSERT_TRUE(b->is_close(w) == true);
}

TEST(test_07, NPC_TEXT)
{
   std::shared_ptr<Bear> b = std::make_shared<Bear>(2,3, "wer");
   std::shared_ptr<Werewolf> w = std::make_shared<Werewolf>(2,14, "wer");
   ASSERT_TRUE(b->is_close(w) == false);
}
TEST(test_08, NPC_TEXT)
{
   std::shared_ptr<Robber> r = std::make_shared<Robber>(2,3, "wer");
   std::shared_ptr<Werewolf> w = std::make_shared<Werewolf>(2,2, "wer");
   ASSERT_TRUE(r->is_close(w) == true);
}
TEST(test_09, NPC_TEXT)
{
   std::shared_ptr<Robber> r = std::make_shared<Robber>(2,3, "wer");
   std::shared_ptr<Werewolf> w = std::make_shared<Werewolf>(2,14, "wer");
   ASSERT_TRUE(r->is_close(w) == false);
}

TEST(test_10, NPC_TEXT)
{
   std::shared_ptr<Robber> r = std::make_shared<Robber>(2,3, "wer");
   r->do_move(1,1);
   ASSERT_TRUE(r->get_coord().first == 3 && r->get_coord().second == 4);
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




int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}