#include "point_vector.cpp"

int main(){
    Point_vector s({Point(2,2), Point(2,3)});
    s.push_back(Point(2,4));
    s.pop_back();
    s.push_back(Point(2,4));
    s.push_back(Point(2,4));
    s.push_back(Point(2,4));
    s.push_back(Point(2,4));
    s.erase(0);
    s.erase(0);
    s.erase(0);
    s.erase(0);
    Point_vector a = s;
    if(a == s){
        std::cout << "1";
    }
}