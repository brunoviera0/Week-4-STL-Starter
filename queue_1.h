#ifndef QUEUE_1_H
#define QUEUE_1_H

#include <queue>
#include <vector>
#include "item.h"

void pushItemsOntoQueue(std::queue<Item>& queue, const std::vector<Item>& items);
void dequeueItemsAndCheckSum(std::queue<Item>& queue);

#endif

