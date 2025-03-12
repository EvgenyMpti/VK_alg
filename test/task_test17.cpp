#include "gtest/gtest.h"
#include "task17.h"

TEST(Task17Test, AllImplementations) 
{
    Task17 task;
    struct TestData {
        std::vector<int> list1Values;
        std::vector<int> list2Values;
        std::vector<int> expected;
    };

    std::vector<TestData> testCases = {
        {{}, {}, {}},
        {{1, 2, 3}, {}, {1, 2, 3}},
        {{}, {4, 5, 6}, {4, 5, 6}},
        {{1, 3, 5}, {2, 4, 6}, {1, 2, 3, 4, 5, 6}},
        {{1, 2, 3}, {4, 5, 6}, {1, 2, 3, 4, 5, 6}},
        {{4, 5, 6}, {1, 2, 3}, {1, 2, 3, 4, 5, 6}},
        {{1, 2, 2, 3}, {2, 3, 4}, {1, 2, 2, 2, 3, 3, 4}},
        {{1, 1, 1}, {1, 1, 1}, {1, 1, 1, 1, 1, 1}},
        {{-3, -1, 1}, {-2, 0, 2}, {-3, -2, -1, 0, 1, 2}},
        {{-5, -3}, {-4, -2}, {-5, -4, -3, -2}},
        {{3, 6, 8}, {4, 7, 9, 11}, {3, 4, 6, 7, 8, 9, 11}},
        {{1, 4, 7, 9}, {2,3,5,8}, {1,2,3,4,5,7,8,9}}

    };

    for (const auto& testCase : testCases) 
    {
        auto list1 = task.createList(testCase.list1Values);
        auto list2 = task.createList(testCase.list2Values);

        ListNode* mergedList = task.mergeTwoLists(list1, list2);
        std::vector<int> result = task.listToVector(mergedList);
        task.deleteList(mergedList);

        EXPECT_EQ(result, testCase.expected) << "Incorrect merged list.";
    }
}