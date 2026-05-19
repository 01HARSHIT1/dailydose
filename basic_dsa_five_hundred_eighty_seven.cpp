/**
 * Basic DSA - Design Underground System (LeetCode 1396)
 * checkIn stores passenger start; checkOut accumulates route travel time; getAverageTime returns mean duration for a route.
 */
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>

struct UndergroundSystem {
    std::unordered_map<int, std::pair<std::string, int>> inTrip; // id -> (start, t)
    std::unordered_map<std::string, std::pair<long long, int>> route; // "A,B" -> (sum, count)

    void checkIn(int id, const std::string& stationName, int t) {
        inTrip[id] = {stationName, t};
    }

    void checkOut(int id, const std::string& stationName, int t) {
        auto trip = inTrip[id];
        std::string key = trip.first + "," + stationName;
        route[key].first += static_cast<long long>(t - trip.second);
        ++route[key].second;
        inTrip.erase(id);
    }

    double getAverageTime(const std::string& start, const std::string& end) const {
        std::string key = start + "," + end;
        const auto& p = route.at(key);
        return static_cast<double>(p.first) / static_cast<double>(p.second);
    }
};

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Design Underground System\n";
    std::cout << std::string(60, '=') << "\n";

    UndergroundSystem sys;
    sys.checkIn(45, "Lewisham", 3);
    sys.checkIn(32, "Paradise", 8);
    sys.checkIn(27, "Lewisham", 10);
    sys.checkOut(45, "Waterloo", 15);
    sys.checkOut(27, "Waterloo", 20);
    sys.checkOut(32, "Cambridge", 22);
    std::cout << "Lewisham->Waterloo avg -> " << sys.getAverageTime("Lewisham", "Waterloo") << "\n";
    std::cout << "Paradise->Cambridge avg -> " << sys.getAverageTime("Paradise", "Cambridge") << "\n";
}
