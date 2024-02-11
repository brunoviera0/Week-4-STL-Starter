#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "queue_1.h"
#include "stack_1.h"
#include <vector>
#include <exception>

TEST_CASE("Stack operations with Item structs") {
    std::stack<Item> myStack;
    SUBCASE("Pushing positive items onto the stack") {
        std::vector<Item> items = {{1}, {2}, {3}}; // Assuming Item struct has an int value
        CHECK_NOTHROW(pushItemsOntoStack(myStack, items));
    }

    SUBCASE("Attempting to push items leading to a negative prefix sum") {
        std::vector<Item> items = {{1}, {-2}, {-2}};
        CHECK_THROWS_AS(pushItemsOntoStack(myStack, items), std::runtime_error);
    }
}

TEST_CASE("Queue operations with Item structs") {
    std::queue<Item> myQueue;
    SUBCASE("Pushing positive items onto the queue") {
        std::vector<Item> items = {{1}, {2}, {3}};
        CHECK_NOTHROW(pushItemsOntoQueue(myQueue, items));
    }

    SUBCASE("Attempting to push items leading to a negative prefix sum") {
        std::vector<Item> items = {{-1}, {1}, {-3}};
        CHECK_THROWS_AS(pushItemsOntoQueue(myQueue, items), std::runtime_error);
    }
}

TEST_CASE("Exception Handling for Negative Prefix Sum") {
    std::queue<Item> testQueue;
    SUBCASE("Throwing exception on negative prefix sum") {
        try {
            std::vector<Item> items = {{1}, {-3}, {2}, {-1}};
            pushItemsOntoQueue(testQueue, items); // This should throw
            CHECK(false); // If it doesn't throw, this check fails
        } catch (const std::runtime_error& e) {
            CHECK(true); // Exception caught as expected
        } catch (...) {
            CHECK(false); // Catch-all for any unexpected exceptions
        }
    }
}
