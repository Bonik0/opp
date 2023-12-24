#include "include/queue.h"
#include <map>



int factorial (int n) {
    return (n <= 1) ? 1 : n * factorial(n-1);
}


int main(){


    std::map<int, int, std::less<int>, PoolAllocator<std::pair<const int, int>>> mp;
    for (int i = 0; i < 10; i++) {
        mp[i] = factorial(i);
    }

    for (auto el: mp) {
        std::cout << el.first << ' ' << el.second << std::endl;
    }
    Queue<int, PoolAllocator<Node<int>>> queue;
    for (int i = 0; i < 1000; i++) {
        if (i % 2 == 0) {
            queue.push(i);
            queue.push(i);
        } else {
            queue.pop();
        } 
    }
    
    

    for (auto &el : queue) {
        std::cout << el << "\n";
    }
}