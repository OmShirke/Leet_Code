#include <vector>

class MyCalendar {
public:
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        for (const auto& event : bookings) {
            if (start < event.second && end > event.first) {
                return false; 
            }
        }
        bookings.push_back({start, end});
        return true;
    }
    
private:
    std::vector<std::pair<int, int>> bookings;
};
