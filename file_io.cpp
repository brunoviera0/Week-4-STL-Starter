#include "stack_1.h"
#include "queue_1.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <stdexcept>
#include "item.h"

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
        std::cout << "Successfully pushed items onto stack." << std::endl;
        
        pushItemsOntoQueue(myQueue, items);
        std::cout << "Successfully pushed items onto queue." << std::endl;

    } catch (const std::runtime_error& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

}

int main() {
    processFile("input.txt");
    return 0;
}
