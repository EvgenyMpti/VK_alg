#include "gtest/gtest.h"
#include "task5.h"

TEST(Task5Test, AllImplementations) 
{
    Task5 task;

    // Структура для хранения тестовых данных
    struct TestData {
        std::vector<int> arr1;
        std::vector<int> arr2;
        std::vector<int> expectedMerged; // Ожидаемый результат (отсортированный объединенный массив)
    };

    // Набор тестовых случаев
    std::vector<TestData> testCases = 
    {
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
        {{1000000, 2000000}, {1500000, 2500000}, {1000000, 1500000, 2000000, 2500000}},
        {{1,2,3}, {4,5,6}, {1,2,3,4,5,6}},
        {{4, 5, 6}, {1, 2, 3}, {1, 2, 3, 4, 5, 6}}
    };

    for (const auto& testCase : testCases) 
    {
        std::vector<std::vector<int>> results;

        results.push_back(task.mergeTwoPointers(testCase.arr1, testCase.arr2));
        results.push_back(task.mergeWithSort(testCase.arr1, testCase.arr2));
        results.push_back(task.mergeWithInsertion(testCase.arr1, testCase.arr2));

        for (size_t i = 0; i < results.size(); ++i)
        {
            // Проверяем, что размер результирующего массива правильный
            EXPECT_EQ(results[i].size(), testCase.expectedMerged.size())
                << "Incorrect merged array size for implementation " << i;

            // Проверяем, что результирующий массив отсортирован и содержит правильные элементы
            EXPECT_TRUE(std::is_sorted(results[i].begin(), results[i].end()))
                << "Result array is not sorted for implementation " << i;

            EXPECT_EQ(results[i], testCase.expectedMerged)
                << "Incorrect merged array for implementation " << i;
        }
    }
}