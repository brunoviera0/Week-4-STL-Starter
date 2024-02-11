#include "stack_1.h"
#include "queue_1.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <stdexcept>

void processFile(const std::string& filePath) {
    std::ifstream inputFile(filePath);
    std::vector<Item> items;
    int number;

    while (inputFile >> number) {
        items.push_back(Item{number});
    }

    std::stack<Item> myStack;
    std::queue<Item> myQueue;

    try {
        pushItemsOntoStack(myStack, items);
        pushItemsOntoQueue(myQueue, items);
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}

int main() {
    processFile("input.txt");
    return 0;
}
