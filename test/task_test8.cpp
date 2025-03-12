#include "gtest/gtest.h"
#include "task8.h"

TEST(Task8Test, AllImplementations) 
{
    Task8 task;

    struct TestData {
        std::vector<int> arr;
        std::vector<int> expectedSorted;
    };

    std::vector<TestData> testCases = 
    {
        {{}, {}},
        {{0}, {0}},
        {{1}, {1}},
        {{2}, {2}},
        {{0, 1, 2}, {0, 1, 2}},
        {{2, 1, 0}, {0, 1, 2}},
        {{1, 0, 2}, {0, 1, 2}},
        {{0, 0, 0}, {0, 0, 0}},
        {{1, 1, 1}, {1, 1, 1}},
        {{2, 2, 2}, {2, 2, 2}},
        {{2, 0, 2, 1, 1, 0}, {0, 0, 1, 1, 2, 2}},
        {{0, 1, 2, 0, 1, 2}, {0, 0, 1, 1, 2, 2}},
        {{2, 1, 0, 2, 1, 0}, {0, 0, 1, 1, 2, 2}},
        {{1, 2, 0, 0, 1, 2, 2, 1}, {0, 0, 1, 1, 1, 2, 2, 2}},
        {{0, 0, 0, 1, 1, 2, 2, 2}, {0, 0, 0, 1, 1, 2, 2, 2}},
        {{2, 2, 2, 1, 1, 0, 0, 0}, {0, 0, 0, 1, 1, 2, 2, 2}},
        {{1, 1, 0, 2, 0, 1, 2, 0}, {0, 0, 0, 1, 1, 1, 2, 2}}
    };

    for (const auto& testCase : testCases) 
    {
        std::vector<std::vector<int>> results;

        // Копии массива для каждой реализации
        std::vector<int> arr1 = testCase.arr, arr2 = testCase.arr, arr3 = testCase.arr;

        task.sortFlag(arr1);
        results.push_back(arr1);

        task.sortFlagCounting(arr2);
        results.push_back(arr2);

        task.sortFlagPartition(arr3);
        results.push_back(arr3);

        for (size_t i = 0; i < results.size(); ++i) 
        {
            // Проверка на ожидаемый размер
            EXPECT_EQ(results[i].size(), testCase.expectedSorted.size())
                << "Incorrect array size for implementation " << i;

            EXPECT_EQ(results[i], testCase.expectedSorted)
                << "Incorrect merged array for implementation " << i;

        }
    }
}