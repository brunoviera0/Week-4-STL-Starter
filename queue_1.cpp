#include "queue_1.h"
#include "prefixSum.h"
#include <stdexcept>
#include <vector>

void pushItemsOntoQueue(std::queue<Item>& queue, const std::vector<Item>& items) {
    if (has_negative_prefix_sum(items)) {
        throw std::runtime_error("Negative prefix sum detected when pushing onto queue");
    }
    for (const auto& item : items) {
        queue.push(item);
    }
}

void dequeueItemsAndCheckSum(std::queue<Item>& queue) {
    std::vector<Item> tempItems;
    while (!queue.empty()) {
        tempItems.push_back(queue.front());
        queue.pop();
    }
    if (has_negative_prefix_sum(tempItems)) {
        throw std::runtime_error("Negative prefix sum detected after dequeuing from queue");
    }
}
