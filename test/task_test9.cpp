#include "gtest/gtest.h"
#include "task9.h"

TEST(Task9Test, AllImplementations) 
{
    Task9 task;

    std::vector<std::vector<int>> testCases = 
    {
        {},
        {1},
        {2},
        {1, 3, 5},
        {2, 4, 6},
        {3, 2, 4, 1, 11, 8, 9},
        {1, 2, 3, 4, 5},
        {2, 1, 4, 3, 6, 5},
        {2, 2, 2, 1, 1, 1},
        {1, 1, 1, 2, 2, 2},
        {-2, 1, -4, 3, 0},
        {-1, -3, -5},
        {-2, -4, -6},
    };

    for (const auto& testCase : testCases) 
    {
        std::vector<std::vector<int>> results;

        // Копии для in-place реализаций
        std::vector<int> copy1 = testCase, copy2 = testCase, copy3 = testCase;

        task.moveEvenStablePartition(copy1);
        results.push_back(copy1);

        task.moveEvenTwoPointers(copy2);
        results.push_back(copy2);

        task.moveEvenTwoPointersAlt(copy3);
        results.push_back(copy3);

        for (size_t i = 0; i < results.size(); ++i) 
        {
            EXPECT_EQ(results[i].size(), testCase.size())
                << "Incorrect array size for implementation " << i;

            // Проверяем, что все чётные числа идут перед нечётными
            bool evenPart = true;
            for (int x : results[i]) 
            {
                if (x % 2 != 0)
                    evenPart = false; // Встретили нечётное число
                else if (!evenPart)
                    FAIL() << "Even number after odd number for implementation " << i;
            }

            // Проверяем, что относительный порядок чётных чисел сохранён
            std::vector<int> even_result;
            for (int val : results[i])
                if (val % 2 == 0) even_result.push_back(val);

            std::vector<int> even_expected;
            for (int val : testCase)
                if (val % 2 == 0) even_expected.push_back(val);

            EXPECT_EQ(even_result, even_expected) << "Even numbers order is incorrect for implementation " << i;
        }
    }
}