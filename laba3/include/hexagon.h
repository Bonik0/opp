#include "figure.h"
#include <cmath>

class Hexagon final: public Figure {
    public:
        Hexagon(const std::vector<Point> & points);
        Hexagon(const Hexagon & other);
        Hexagon(const Hexagon && other);
        ~Hexagon() = default;
        Hexagon &operator=(const Hexagon &other);
        Hexagon &operator=(const Hexagon &&other);
        operator double() const override;
    private:
        bool is_equal(const Figure &other) const override;
        bool is_valid(const std::vector<Point> &p) const override;
        void print(std::ostream &os) const override;
        void input(std::istream &os) override;
};