#include "gtest/gtest.h"
#include "task11.h"

TEST(Task11Test, AllImplementations) 
{
    Task11 task;

    struct TestData {
        std::vector<int> values;
        int cyclePos; // -1 если цикла нет, иначе индекс узла, на который замыкается список
        bool expected;
    };

    std::vector<TestData> testCases = 
    {
        {{}, -1, false},
        {{1}, -1, false},
        {{1, 2, 3, 4, 5}, -1, false},
        {{1, 2, 3, 4, 5}, 0, true},
        {{1, 2, 3, 4, 5}, 1, true},
        {{1, 2, 3, 4, 5}, 4, true},
        {{1, 2, 3, 4, 5}, 2, true},
        {{1}, 0, true}, // один элемент и цикл на себя
    };

    for (const auto& testCase : testCases) 
    {
        ListNode* list = task.createList(testCase.values, testCase.cyclePos);

        // Проверяем обе реализации
        EXPECT_EQ(task.hasCycleFloyd(list), testCase.expected)
            << "Floyd's algorithm failed for cyclePos: " << testCase.cyclePos;

        EXPECT_EQ(task.hasCycleHashSet(list), testCase.expected)
            << "HashSet method failed for cyclePos: " << testCase.cyclePos;

        task.deleteList(list);
    }
}