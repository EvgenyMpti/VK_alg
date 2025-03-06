#include "gtest/gtest.h"
#include "task3.h"

/* TASK 3 */

TEST(Task3Test, AllImplementations) {
    Task3 task;

    // Тестовые данные: {входной массив, ожидаемый результат}
    struct TestData {
        std::vector<int> nums;
        std::vector<int> expectedResult;
    };

    std::vector<TestData> testCases = {
        {{}, {}},
        {{1}, {1}},
        {{1, 2}, {2, 1}},
        {{1, 2, 3}, {3, 2, 1}},
        {{1, 2, 3, 4}, {4, 3, 2, 1}},
        {{1, 2, 3, 4, 5}, {5, 4, 3, 2, 1}},
        {{-1, 0, 1}, {1, 0, -1}},
        {{1, 1, 1}, {1, 1, 1}},
        {{10, 5, 2, 8, 1}, {1, 8, 2, 5, 10}}
    };

    for (auto& testCase : testCases) {
        std::vector<int> copy1 = testCase.nums, copy2 = testCase.nums, copy3 = testCase.nums;

        task.reverse_swap(copy1);
        task.reverse_iter_swap(copy2);
        task.reverse_std_reverse(copy3);

        EXPECT_EQ(copy1, testCase.expectedResult)
            << "Incorrect result reverse_swap";
        EXPECT_EQ(copy2, testCase.expectedResult)
            << "Incorrect result reverse_iter_swap";
        EXPECT_EQ(copy3, testCase.expectedResult)
            << "Incorrect result reverse_std_reverse";
    }
}