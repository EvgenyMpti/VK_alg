#include "gtest/gtest.h"
#include "task7.h"

TEST(Task7Test, AllImplementations)
{
    Task7 task;

    struct TestData
    {
        std::vector<int> arr;
        std::vector<int> expectedSorted;
    };

    std::vector<TestData> testCases =
    {
        {{}, {}},
        {{0}, {0}},
        {{1}, {1}},
        {{0, 1}, {0, 1}},
        {{1, 0}, {0, 1}},
        {{0, 0, 0}, {0, 0, 0}},
        {{1, 1, 1}, {1, 1, 1}},
        {{1, 0, 1, 0, 1}, {0, 0, 1, 1, 1}},
        {{0, 1, 0, 1, 0}, {0, 0, 0, 1, 1}},
        {{1, 1, 0, 0, 1, 0}, {0, 0, 0, 1, 1, 1}},
        {{0, 0, 1, 1, 1, 0}, {0, 0, 0, 1, 1, 1}},
        {{1, 0, 0, 1, 1, 0, 0}, {0, 0, 0, 0, 1, 1, 1}}
    };

    for (const auto& testCase : testCases)
    {
        std::vector<std::vector<int>> results;

        // Копии массива для каждой реализации
        std::vector<int> arr1 = testCase.arr, arr2 = testCase.arr, arr3 = testCase.arr, arr4 = testCase.arr;

        task.sortZeroOne(arr1);
        results.push_back(arr1);

        task.sortZeroOneCounting(arr2);
        results.push_back(arr2);

        task.sortZeroOneShift(arr3);
        results.push_back(arr3);

        task.sortZeroOnePartition(arr4);
        results.push_back(arr4);


        for (size_t i = 0; i < results.size(); ++i)
        {
            EXPECT_EQ(results[i].size(), testCase.expectedSorted.size())
                << "Incorrect array size for implementation " << i;

            EXPECT_EQ(results[i], testCase.expectedSorted)
                << "Incorrect merged array for implementation " << i;
        }
    }
}