#include "gtest/gtest.h"
#include "task2.h"

TEST(Task2Test, AllImplementations) 
{
    Task2 task;

    struct TestData {
        std::vector<int> nums;
        int target;
        Task2::TwoSumResult expected;
    };

    std::vector<TestData> testCases = 
    {
        {{2, 7, 11, 15}, 9, {true, 0, 1}},
        {{2, 7, 11, 15}, 18, {true, 1, 2}},
        {{2, 7, 11, 15}, 26, {true, 2, 3}},
        {{2, 7, 11, 15}, 10, {false, -1, -1}},
        {{2, 7, 11, 15}, 4, {false, -1, -1}},
        {{3, 3}, 6, {true, 0, 1}},
        {{3, 3}, 7, {false, -1, -1}},
        {{5}, 5, {false, -1, -1}},
        {{}, 5, {false, -1, -1}},
        {{-1, 0, 3, 5, 7}, 4, {true, 0, 3}},
        {{-5, -3, -1, 2, 4}, -4, {true, 1, 2}},
    };

    for (const auto& testCase : testCases) 
    {

        std::vector<Task2::TwoSumResult> results;
        results.push_back(task.twoPointers(testCase.nums, testCase.target));
        results.push_back(task.hashTable(testCase.nums, testCase.target));
        results.push_back(task.binarySearch(testCase.nums, testCase.target));
        results.push_back(task.bruteForce(testCase.nums, testCase.target));

        ASSERT_FALSE(results.empty()) << "No implementations were run for target = " << testCase.target;

        for (size_t i = 0; i < results.size(); ++i)
            EXPECT_EQ(results[i], testCase.expected)
                << "Incorrect result " << i;
    }
}