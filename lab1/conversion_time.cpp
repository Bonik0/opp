#include "conversion_time.h"

std::string conversion_time(int hour, int minute, std::string period){
    std::string ans = std::string(4, '0');

    if (period == "pm") {
        hour = (hour + 12) % 24;
    }

    ans[0] = int(hour / 10) + '0';
    ans[1] = hour % 10 + '0';
    ans[2] = int(minute / 10) + '0';
    ans[3] = minute % 10 + '0';
    
    return ans;

}
