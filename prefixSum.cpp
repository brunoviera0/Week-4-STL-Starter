#include "prefixSum.h"

bool has_negative_prefix_sum(const std::vector<Item>& items) {
    int sum = 0;
    for (const auto& item : items) {
        sum += item.value;
        if (sum < 0) {
            return true;
        }
    }
    return false;
}
