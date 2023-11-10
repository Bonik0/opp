#include "conversion_time.h"
#include <string>

int main()
{
    std::cout << "Input the time in the format: HH MM am or pm: ";
    int hour;
    std::string period;
    int minute;
    std::cin >> hour >> minute;
    std::cin >> period;
    std::cout << conversion_time(hour, minute, period);
}
