#include "gtest/gtest.h"
#include "task6.h"

/* TASK 6 */

TEST(Task6Test, AllImplementations) 
{
    Task6 task;

    struct TestData {
        std::vector<int> arr1;
        std::vector<int> arr2;
        std::vector<int> expectedMerged;
    };

    std::vector<TestData> testCases = {
        {{}, {}, {}},
        {{1, 2, 3, 0, 0, 0}, {4, 5, 6}, {1, 2, 3, 4, 5, 6}},
        {{4, 5, 6, 0, 0, 0}, {1, 2, 3}, {1, 2, 3, 4, 5, 6}},
        {{1, 2, 2, 3, 0, 0, 0}, {2, 3, 4}, {1, 2, 2, 2, 3, 3, 4}},
        {{1, 1, 1, 0, 0, 0}, {1, 1, 1}, {1, 1, 1, 1, 1, 1}},
        {{-3, -1, 1, 0, 0, 0}, {-2, 0, 2}, {-3, -2, -1, 0, 1, 2}},
        {{-5, -3, 0, 0}, {-4, -2}, {-5, -4, -3, -2}},
        {{1000000, 2000000, 0, 0}, {1500000, 2500000}, {1000000, 1500000, 2000000, 2500000}},
        {{1, 2, 3, 0, 0, 0}, {4, 5, 6}, {1, 2, 3, 4, 5, 6}},
        {{4, 5, 6, 0, 0, 0}, {1, 2, 3}, {1, 2, 3, 4, 5, 6}},
        {{1, 3, 5, 0, 0}, {2, 4}, {1, 2, 3, 4, 5}}, // arr2 меньше arr1
        {{0, 0, 0}, {1, 2, 3}, {1, 2, 3}},      // arr1 изначально пустой
        {{1, 0}, {2}, {1, 2}},                // Маленькие массивы
        {{2, 0}, {1}, {1, 2}},                 // arr2[0] < arr1[0]
    };


    for (const auto& testCase : testCases) 
    {
        std::vector<std::vector<int>> results;

        // Копии arr1 для каждой реализации, чтобы не изменять исходные данные
        std::vector<int> arr1_merge = testCase.arr1;
        std::vector<int> arr1_sort = testCase.arr1;

        task.mergeArrays(arr1_merge, testCase.arr2);
        results.push_back(arr1_merge);

        task.mergeArraysSort(arr1_sort, testCase.arr2);
        results.push_back(arr1_sort);

        for (size_t i = 0; i < results.size(); ++i) 
        {
            EXPECT_EQ(results[i].size(), testCase.expectedMerged.size())
                << "Incorrect merged array size for implementation " << i;

            EXPECT_TRUE(std::is_sorted(results[i].begin(), results[i].end()))
                << "Result array is not sorted for implementation " << i;

            EXPECT_EQ(results[i], testCase.expectedMerged)
                << "Incorrect merged array for implementation " << i;
        }
    }
}