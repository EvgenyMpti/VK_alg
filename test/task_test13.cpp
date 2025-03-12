#include "gtest/gtest.h"
#include "task13.h"

TEST(Task13Test, AllImplementations)
{
    Task13 task;
    struct TestData {
        std::vector<int> values;
        int expected;   // Ожидаемое значение правого среднего узла
    };

    std::vector<TestData> testCases = 
    {
        {{1}, 1},          
        {{1, 2}, 2},
        {{1, 2, 3}, 2},
        {{1, 2, 3, 4}, 3},
        {{1, 2, 3, 4, 5}, 3}, 
        {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}, 6},
    };
    ListNode* empty = nullptr;
    EXPECT_EQ(task.findMiddleTwoPointers(empty), nullptr) << "Empty findMiddleTwoPointers";
    EXPECT_EQ(task.findMiddleGetLength(empty), nullptr) << "Empty findMiddleTwoPointers";
    delete empty;

    for (const auto& testCase : testCases) 
    {
        ListNode* list = task.createList(testCase.values, -1);

        EXPECT_EQ(task.findMiddleTwoPointers(list)->val, testCase.expected) << "findMiddleTwoPointers";
        EXPECT_EQ(task.findMiddleGetLength(list)->val, testCase.expected) << "findMiddleGetLength";
        task.deleteList(list);
    }
}