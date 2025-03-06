#include "gtest/gtest.h"
#include "task10.h"

TEST(Task10Test, AllImplementations) 
{
    Task10 task;

    struct TestData {
        std::vector<int> arr;
        std::vector<int> expected;
    };

    std::vector<TestData> testCases = {
        {{0, 0, 1, 0, 3, 12}, {1, 3, 12, 0, 0, 0}},
        {{0, 33, 57, 88, 60, 0, 0, 80, 99}, {33, 57, 88, 60, 80, 99, 0, 0, 0}},
        {{0, 0, 0, 18, 16, 0, 0, 77, 99}, {18, 16, 77, 99, 0, 0, 0, 0, 0}},
        {{1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}},
        {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}},
        {{}, {}},
        {{5}, {5}},
        {{0}, {0}},
        {{0, 1}, {1, 0}},
        {{1, 0}, {1, 0}},
        {{1,0,0,2,3,0,4}, {1,2,3,4,0,0,0}},
        {{0, 0, 1, 0, 2, 0, 3}, {1, 2, 3, 0, 0, 0, 0}}
    };

    for (const auto& testCase : testCases) {
        std::vector<std::vector<int>> results;

        std::vector<int> arr1 = testCase.arr, arr2 = testCase.arr, arr3 = testCase.arr;
        task.moveZerosTwoPointers(arr1);
        results.push_back(arr1);

        task.moveZerosStablePartition(arr2);
        results.push_back(arr2);

        task.moveZerosShift(arr3);
        results.push_back(arr3);

        for (size_t i = 0; i < results.size(); ++i) 
        {

            // Проверка на ожидаемый размер
            EXPECT_EQ(results[i].size(), testCase.expected.size())
                << "Incorrect array size for implementation " << i;

            EXPECT_EQ(results[i], testCase.expected)
                << "Incorrect merged array for implementation " << i;
        }
    }
}