#include "gtest/gtest.h"
#include "task4.h"

TEST(Task4Test, AllImplementations)
{
    Task4 task;

    struct TestData {
        std::vector<int> nums;
        int k;
        std::vector<int> expected;
    };

    std::vector<TestData> testCases = 
    {
        {{1, 2, 3, 4, 5, 6, 7}, 3, {5, 6, 7, 1, 2, 3, 4}},
        {{-1, -100, 3, 99}, 2, {3, 99, -1, -100}},
        {{1, 2, 3}, 1, {3, 1, 2}},
        {{1}, 0, {1}},
        {{}, 2, {}},
        {{1, 2, 3, 4, 5}, -1, {2, 3, 4, 5, 1}},
        {{1, 2, 3, 4, 5, 6}, 6, {1, 2, 3, 4, 5, 6}}
    };

    for (auto& testCase : testCases) 
    {
        std::vector<int> copy1 = testCase.nums, copy2 = testCase.nums, copy3 = testCase.nums;
        task.rotateLeft1(copy1, testCase.k);
        task.rotateLeft2(copy2, testCase.k);
        task.rotateLeft3(copy3, testCase.k);

        EXPECT_EQ(copy1, testCase.expected)
            << "Incorrect result rotateLeft1; k = " << testCase.k;
        EXPECT_EQ(copy2, testCase.expected)
            << "Incorrect result rotateLeft2; k = " << testCase.k;
        EXPECT_EQ(copy3, testCase.expected)
            << "Incorrect result rotateLeft3; k = " << testCase.k;
    }
}