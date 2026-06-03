/**
 * Basic DSA - Implement Router (LeetCode 3508)
 * FIFO packet queue with duplicate tracking and destination/time queries.
 */

#include <array>
#include <deque>
#include <iostream>
#include <set>
#include <vector>

class Router {
public:
    explicit Router(int memoryLimit) : memoryLimit_(memoryLimit) {}

    bool addPacket(int source, int destination, int timestamp) {
        const std::array<int, 3> packet = {source, destination, timestamp};

        if (activePackets_.count(packet))
            return false;

        if (static_cast<int>(packetQueue_.size()) >= memoryLimit_) {
            activePackets_.erase(packetQueue_.front());
            packetQueue_.pop_front();
        }

        packetQueue_.push_back(packet);
        activePackets_.insert(packet);
        return true;
    }

    std::vector<int> forwardPacket() {
        if (packetQueue_.empty())
            return {};

        const std::array<int, 3> packet = packetQueue_.front();
        packetQueue_.pop_front();
        activePackets_.erase(packet);
        return {packet[0], packet[1], packet[2]};
    }

    int getCount(int destination, int startTime, int endTime) const {
        int count = 0;

        for (const auto& packet : packetQueue_) {
            if (packet[1] == destination && packet[2] >= startTime && packet[2] <= endTime)
                ++count;
        }

        return count;
    }

private:
    int memoryLimit_;
    std::deque<std::array<int, 3>> packetQueue_;
    std::set<std::array<int, 3>> activePackets_;
};

void printPacket(const std::vector<int>& packet) {
    if (packet.empty()) {
        std::cout << "[]";
        return;
    }

    std::cout << "[" << packet[0] << "," << packet[1] << "," << packet[2] << "]";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Implement Router\n";
    std::cout << std::string(60, '=') << "\n";

    Router router(3);
    std::cout << "add 1,4,90 -> " << std::boolalpha << router.addPacket(1, 4, 90) << "\n";
    std::cout << "add 2,5,90 -> " << router.addPacket(2, 5, 90) << "\n";
    std::cout << "add 1,4,90 -> " << router.addPacket(1, 4, 90) << "\n";
    std::cout << "add 3,5,95 -> " << router.addPacket(3, 5, 95) << "\n";
    std::cout << "add 4,5,105 -> " << router.addPacket(4, 5, 105) << "\n";
    std::cout << "forward -> ";
    printPacket(router.forwardPacket());
    std::cout << "\n";
    std::cout << "add 5,2,110 -> " << router.addPacket(5, 2, 110) << "\n";
    std::cout << "count dest 5 in [100,110] -> " << router.getCount(5, 100, 110) << "\n";
}
