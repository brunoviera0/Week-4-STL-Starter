#ifndef STACK_1_H
#define STACK_1_H

#include <stack>
#include <vector>
#include "item.h"

void pushItemsOntoStack(std::stack<Item>& stack, const std::vector<Item>& items);
void popItemsFromStackAndCheckSum(std::stack<Item>& stack);


#endif
