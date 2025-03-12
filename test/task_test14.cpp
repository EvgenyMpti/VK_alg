#include "gtest/gtest.h"
#include "task14.h"

TEST(Task14Test, AllImplementations)
{
    Task14 task;
    struct TestData {
        std::vector<int> initial;
        int toRemove;
        std::vector<int> expected;
    };

    std::vector<TestData> testCases = 
    {
       {{1, 2, 6, 3, 4, 5, 6}, 6, {1, 2, 3, 4, 5}},
       {{}, 1, {}},
       {{1}, 1, {}}, 
       {{1}, 2, {1}},
       {{1, 1, 1}, 1, {}},
       {{1, 2, 3}, 4, {1, 2, 3}}, 
       {{7,7,7,7}, 7, {}},
       {{1,2},1,{2}},
       {{1,2},2,{1}},
    };

    // Îעהוכüםûי עוסע םא nullptr
    ListNode* nullList = nullptr;
    EXPECT_EQ(task.removeElements1(nullList, 5), nullptr);
    EXPECT_EQ(task.removeElements2(nullList, 5), nullptr);

    for (const auto& testCase : testCases) 
    {
        ListNode* list1 = task.createList(testCase.initial);
        ListNode* list2 = task.createList(testCase.initial);

        ListNode* result1 = task.removeElements1(list1, testCase.toRemove);
        EXPECT_EQ(task.listToVector(result1), testCase.expected) << "removeElements1 failed for input: "
            << ", valueToRemove: " << testCase.toRemove;
        task.deleteList(result1);

        ListNode* result2 = task.removeElements1(list2, testCase.toRemove);
        EXPECT_EQ(task.listToVector(result2), testCase.expected) << "removeElements2 failed for input: "
        << ", valueToRemove: " << testCase.toRemove;
        task.deleteList(result2);
    }
}