#include "q2_algorithms.h"
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <list>

int fifo_page_faults(const std::vector<int>& references, int frame_size) {
    std::unordered_set<int> memory;
    std::queue<int> page_queue;
    int faults = 0;

    for (int page : references) {
        if (memory.find(page) == memory.end()) {
            faults++;
            if (memory.size() == frame_size) {
                int oldest = page_queue.front();
                page_queue.pop();
                memory.erase(oldest);
            }
            memory.insert(page);
            page_queue.push(page);
        }
    }

    return faults;
}

int lru_page_faults(const std::vector<int>& references, int frame_size) {
    std::list<int> memory;
    std::unordered_set<int> pages;
    int faults = 0;

    for (int page : references) {
        if (pages.find(page) == pages.end()) {
            faults++;
            if (memory.size() == frame_size) {
                int lru = memory.front();
                memory.pop_front();
                pages.erase(lru);
            }
        } else {
            memory.remove(page);  // Move to back
        }

        memory.push_back(page);
        pages.insert(page);
    }

    return faults;
}
