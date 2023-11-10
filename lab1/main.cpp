#include "conversion_time.h"
#include <string>

int main()
{
    std::string time;
    std::string period;
    std::cout << "Input the time in the format: HH:MM am or pm: ";
    std::cin >> time;
    std::cin >> period;
    int hour;
    int minute;
    try {
        hour = stoi(time.substr(0, time.find(':')));
        minute = stoi(time.substr(time.find(':') + 1, 2));
    } catch (std::invalid_argument){
        std::cout << "Incorrect input";
        return 1;
    }
    
    if (0 <= hour <= 12 and 0 <= minute <= 60 and (period == "am" or period == "pm")){
        std::cout << conversion_time(hour, minute, period);
    } else {
        std::cout << "Incorrect input";
    }

    
}
