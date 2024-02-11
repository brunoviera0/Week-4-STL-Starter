#include "stack_1.h"
#include "prefixSum.h"
#include <stdexcept>
#include <vector>

void pushItemsOntoStack(std::stack<Item>& stack, const std::vector<Item>& items) {
    if (has_negative_prefix_sum(items)) {
        throw std::runtime_error("Negative prefix sum detected when pushing onto stack");
    }
    for (const auto& item : items) {
        stack.push(item);
    }
}

void popItemsFromStackAndCheckSum(std::stack<Item>& stack) {
    std::vector<Item> tempItems;
    while (!stack.empty()) {
        tempItems.push_back(stack.top());
        stack.pop();
    }
    if (has_negative_prefix_sum(tempItems)) {
        throw std::runtime_error("Negative prefix sum detected after popping from stack");
    }
}
