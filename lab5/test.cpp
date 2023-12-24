#include <gtest/gtest.h>
#include "include/queue.h"



TEST(Node_constructor, test1) {
    ASSERT_NO_THROW(Node<int> n);
}

TEST(Node_constructor, test2) {
    ASSERT_NO_THROW(Node<double> n(2.3));
}

TEST(Queue_constructor, test1) {
    ASSERT_NO_THROW(Queue<int> q);
}

TEST(Queue_constructor, test2) {
    Queue<int> q({1,2,3,4,5});
    ASSERT_TRUE(q.size() == 5 && q.front() == 1 && q.back() == 5);
}



TEST(Queue_constructor, test3) {
    Queue<int> q({1,2,3,4,5});
    Queue<int> q1(q);
    ASSERT_TRUE(q.size() == q.size() && q.back() == q1.back() && q.front() == q1.front());
}

TEST(Queue_constructor, test8) {
    Queue<int> q;
    Queue<int> q1(q);
    ASSERT_TRUE(q.size() == 0);
}
TEST(Queue_constructor, test4) {
    Queue<int> q1({1,2,3,4,5});
    Queue<int> q(std::move(q1));
    ASSERT_TRUE(q.size() == 5 && q.front() == 1 && q.back() == 5 && q1.size() == 0);
}

TEST(Queue_constructor, test5) {
    Queue<int> q1({1,2,3,4,5});
    Queue<int> q({1,23,4});
    q = q1;
    ASSERT_TRUE(q.size() == q.size() && q.back() == q1.back() && q.front() == q1.front());
}
TEST(Queue_constructor, test7) {
    Queue<int> q1({1,2,3,4,5});
    Queue<int> q;
    q1 = q;
    ASSERT_TRUE(q1.size() == 0);
}
TEST(Queue_constructor, test6) {
    Queue<int> q1({1,2,3,4,5});
    Queue<int> q({1,23,4});
    q = std::move(q1);
    ASSERT_TRUE(q.size() == 5 && q.front() == 1 && q.back() == 5 && q1.size() == 0);
}

TEST(Queue_size, test1) {
    Queue<int> q1({1,2,3,4,5});
    Queue<int> q({1,23,4});
    
    ASSERT_TRUE(q.size() == 3 && q1.size() == 5);
}

TEST(Queue_size, test2) {
    Queue<int> q1;
    ASSERT_TRUE(q1.size() == 0);
}

TEST(Queue_empty, test1) {
    Queue<int> q1({1,2,3,4,5});
    Queue<int> q({1,23,4});
    ASSERT_TRUE(q.empty() == false && q1.empty() == false);
}

TEST(Queue_empty, test2) {
    Queue<int> q1;
    ASSERT_TRUE(q1.empty());
}

TEST(Queue_push, test1) {
    Queue<int> q1({1,2,3,4,5});
    q1.push(4);
    ASSERT_TRUE(q1.size() == 6 && q1.back() == 4);
}

TEST(Queue_push, test2) {
    Queue<int> q1;
    q1.push(1);
    ASSERT_TRUE(q1.size() == 1 && q1.front() == q1.back() && q1.back() == 1);
}

TEST(Queue_push_range, test1) {
    Queue<int> q1({1,2,3,4,5});
    q1.push_range({1,2});
    ASSERT_TRUE(q1.size() == 7 && q1.back() == 2);
}

TEST(Queue_push_range, test2) {
    Queue<int> q1;
    q1.push_range({1,2});
    ASSERT_TRUE(q1.size() == 2 && q1.back() == 2);
}

TEST(Queue_push_range, test3) {
    Queue<int> q1({1});
    q1.push_range({1,2});
    ASSERT_TRUE(q1.size() == 3 && q1.back() == 2);
}

TEST(Queue_pop, test1) {
    Queue<int> q1;
    ASSERT_THROW(q1.pop(), std::range_error);
}

TEST(Queue_pop, test2) {
    Queue<int> q1({1,2,3,4});
    int f = q1.pop();
    int s = q1.pop();
    ASSERT_TRUE(q1.size() == 2 && q1.front() == 3 && s == 2 && f == 1);
}

TEST(Queue_pop, test3) {
    Queue<int> q1({1});
    q1.pop();
    ASSERT_TRUE(q1.size() == 0);
}

TEST(Queue_front, test1) {
    Queue<int> q1({1,2,3,4,5});
    ASSERT_TRUE(q1.front() == 1);
}

TEST(Queue_front, test2) {
    Queue<int> q1;
    q1.push(1);
    q1.pop();
    ASSERT_THROW(q1.front(), std::range_error );
}

TEST(Queue_back, test1) {
    Queue<int> q1({1,2,3,4,5});
    ASSERT_TRUE(q1.back() == 5);
}

TEST(Queue_back, test2) {
    Queue<int> q1;
    q1.push(1);
    q1.pop();
    ASSERT_THROW(q1.back(), std::range_error );
}

TEST(Queue_push, test3) {
    Queue<int> q1;
    q1.push(1);
    q1.push(1);
    q1.push(1);
    q1.push(1);
    q1.push(1);
    q1.push(1);
    q1.push(1);
    q1.push(1);
    q1.push(1);
    q1.push(1);
    q1.push(1);
    q1.pop();
    q1.pop();
    q1.pop();
    q1.pop();
    q1.pop();
    q1.pop();
    q1.pop();
    q1.pop();
    q1.pop();
    q1.pop();
    q1.pop();
    ASSERT_TRUE(q1.size() == 0);
}



TEST(Queue_eq, test1) {
    Queue<int> q1({1,2,3,4,5});
    Queue<int> q({1,2,3,4,5});
    ASSERT_TRUE(q1 == q);
}

TEST(Queue_eq, test2) {
    Queue<int> q1;
    Queue<int> q;
    ASSERT_TRUE(q1 == q);
}

TEST(Queue_eq1, test1) {
    Queue<int> q1({1,2,3,4,5});
    Queue<int> q({1,2,3,4});
    ASSERT_TRUE(q1 != q);
}

TEST(Queue_eq1, test2) {
    Queue<int> q1({1,2,3,4,5});
    Queue<int> q({1,2,3,4,8});
    ASSERT_TRUE(q1 != q);
}

TEST(Queue_eq1, test3) {
    Queue<int> q1({1,2,3,4});
    Queue<int> q({1,2,3,4,6});
    ASSERT_TRUE(q1 != q);
}

TEST(Queue_eq1, test4) {
    Queue<int> q1({1,2,3,4, 7, 8});
    Queue<int> q({1,2,3,4,6});
    ASSERT_TRUE(q1 != q);
}



TEST(Queue_more, test1) {
    Queue<int> q1({1,2,3,4,5});
    Queue<int> q({1,2,3,4});
    ASSERT_TRUE(q1 > q);
}


TEST(Queue_more, test2) {
    Queue<int> q1({1,2,3,4,5});
    Queue<int> q({1,2,3,4,8});
    ASSERT_TRUE(q1 < q);
}

TEST(Queue_more, test3) {
    Queue<int> q1({1,2,3,4});
    Queue<int> q({1,2,3,4,6});
    ASSERT_TRUE(q1 < q);
}

TEST(Queue_more, test4) {
    Queue<int> q1({1,2,3,4, 7, 8});
    Queue<int> q({1,2,3,4,6});
    ASSERT_TRUE(q1 > q);
}

TEST(Queue_iterator, test1) {
    Queue<int> q({1,2,2,3,4});
    std::vector<int> v = {1,2,2,3,4};
    int j = 0;
    bool flag = true;
    for(auto i = q.begin(); i != q.end(); ++i){
        if(*i != v[j]){
            flag = false;
            break;
        }
        j++;
    }
    ASSERT_TRUE(flag);
}
TEST(Queue_iterator, test2) {
    Queue<int> q({1,2,2,3,4});
    
    ASSERT_TRUE(*q.begin() == q.front());
}

TEST(Queue_iterator, test3) {
    Queue<int> q({1,2,2,3,4});
    
    ASSERT_TRUE(q.begin() != ++q.begin());
}
TEST(Queue_iterator, test4) {
    Queue<int> q({1,2,2,3,4});
    
    ASSERT_TRUE(q.begin() == q.begin());
}
TEST(Queue_iterator, test5) {
    Queue<int> q({1,2,2,3,4});
    auto it = q.begin();
    ++it;
    ++it;
    ++it;
    ASSERT_TRUE(*it == 3);
}
TEST(Queue_iterator, test6) {
    Queue<int> q({1,2});
    auto it = q.begin();
    ++it;
    ++it;
    ASSERT_THROW(++it, std::range_error);
}

TEST(Queue_iterator, test7) {
    Queue<int> q({1,2,2,3,4});
    auto it = q.begin();
    ++it;
    ++it;
    ++it;
    auto it1 = it;
    ASSERT_TRUE(*it1 == 3);
}

TEST(Queue_iterator, test8) {
    Queue<int> q({1,2,2,3,4});
    auto it = q.begin() + 3;
    ASSERT_TRUE(*it == 3);
}

TEST(Queue_iterator, test9) {
    Queue<int> q({1,2,2,3,4});
    auto it = q.begin() + 3;
    auto it1 = q.begin() + 3;
    ASSERT_TRUE(it == it1);
}

TEST(Queue_iterator, test10) {
    Queue<int> q({1,2,2,3,4});
    auto it = q.begin() + 3;
    auto it1 = q.begin() + 4;
    ASSERT_TRUE(it != it1);
}

TEST(Queue_iterator, test11) {
    Queue<int> q({1,2,2,3,4});
    auto it = q.begin() + 2;
    auto it1 = q.begin() + 4;
    ASSERT_TRUE(*it == 2 && *it1 == 4);
}

TEST(Queue_iterator, test12) {
    Queue<int> q({1,2,2,3,4});
    auto it = q.begin();
    *it = 10;
    ASSERT_TRUE(q.front() == 10);
}

TEST(Queue_iterator, test13) {
    Queue<int> q({1,2,2,3,4});
    ASSERT_THROW(q.begin() + 10, std::range_error);
}

TEST(Queue_const_iterator, test1) {
    Queue<int> q({1,2,2,3,4});
    std::vector<int> v = {1,2,2,3,4};
    int j = 0;
    bool flag = true;
    for(auto i = q.cbegin(); i != q.cend(); ++i){
        if(*i != v[j]){
            flag = false;
            break;
        }
        j++;
    }
    ASSERT_TRUE(flag);
}
TEST(Queue_const_iterator, test2) {
    Queue<int> q({1,2,2,3,4});
    
    ASSERT_TRUE(*q.cbegin() == q.front());
}

TEST(Queue_const_iterator, test3) {
    Queue<int> q({1,2,2,3,4});
    
    ASSERT_TRUE(q.cbegin() != ++q.cbegin());
}
TEST(Queue_const_iterator, test4) {
    Queue<int> q({1,2,2,3,4});
    
    ASSERT_TRUE(q.cbegin() == q.cbegin());
}
TEST(Queue_const_iterator, test5) {
    Queue<int> q({1,2,2,3,4});
    auto it = q.cbegin();
    ++it;
    ++it;
    ++it;
    ASSERT_TRUE(*it == 3);
}
TEST(Queue_const_iterator, test6) {
    Queue<int> q({1,2});
    auto it = q.cbegin();
    ++it;
    ++it;
    ASSERT_THROW(++it, std::range_error);
}

TEST(Queue_const_iterator, test7) {
    Queue<int> q({1,2,2,3,4});
    auto it = q.cbegin();
    ++it;
    ++it;
    ++it;
    auto it1 = it;
    ASSERT_TRUE(*it1 == 3);
}

TEST(Queue_const_iterator, test8) {
    Queue<int> q({1,2,2,3,4});
    auto it = q.cbegin() + 3;
    ASSERT_TRUE(*it == 3);
}

TEST(Queue_const_iterator, test9) {
    Queue<int> q({1,2,2,3,4});
    auto it = q.cbegin() + 3;
    auto it1 = q.cbegin() + 3;
    ASSERT_TRUE(it == it1);
}

TEST(Queue_const_iterator, test10) {
    Queue<int> q({1,2,2,3,4});
    auto it = q.cbegin() + 3;
    auto it1 = q.cbegin() + 4;
    ASSERT_TRUE(it != it1);
}

TEST(Queue_const_iterator, test11) {
    Queue<int> q({1,2,2,3,4});
    auto it = q.cbegin() + 2;
    auto it1 = q.cbegin() + 4;
    ASSERT_TRUE(*it == 2 && *it1 == 4);
}

TEST(Queue_const_iterator, test13) {
    Queue<int> q({1,2,2,3,4});
    ASSERT_THROW(q.cbegin() + 10, std::range_error);
}

TEST(Allocator, test1) {
    PoolAllocator<int> allocator;
    ASSERT_NO_THROW(allocator.allocate(1));
}

TEST(Allocator, test2) {
    PoolAllocator<int> allocator;
    int *tmp = allocator.allocate(1);
    ASSERT_NO_THROW(allocator.deallocate(tmp, 1));
}
TEST(Allocator, test3) {
    PoolAllocator<int> allocator;
    int *tmp = allocator.allocate(100);
    ASSERT_NO_THROW(allocator.deallocate(tmp, 100));
}

TEST(Allocator, test4) {
    PoolAllocator<int> allocator;
    for (size_t i = 0; i < 20000; i++) {
        allocator.allocate();
    }
    ASSERT_THROW(allocator.allocate(), std::bad_alloc);
}



int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}