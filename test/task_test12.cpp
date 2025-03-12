#include "gtest/gtest.h"
#include "task12.h"

TEST(Task12Test, AllImplementations) 
{
    Task12 task;

    struct TestData {
        std::vector<int> input;
        std::vector<int> expected;
    };

    std::vector<TestData> testCases = 
    {
        {{}, {}},
        {{1}, {1}},
        {{1, 2, 3, 4, 5}, {5, 4, 3, 2, 1}},
        {{1, 1, 1, 1}, {1, 1, 1, 1}},
        {{1, 2, 2, 3, 4, 4, 5}, {5, 4, 4, 3, 2, 2, 1}},
        {{-1, -2, -3}, {-3, -2, -1}},
    };

    for (const auto& testCase : testCases) 
    {
        ListNode* list = task.createList(testCase.input);
        auto head = task.reverseList(list);
        auto result = task.listToVector(head);
        task.deleteList(list);

        // Сравниваем содержимое списков поэлементно
        EXPECT_TRUE(std::equal(result.begin(), result.end(), testCase.expected.begin()))
            << "Incorrect reversed list content.";
    }
}