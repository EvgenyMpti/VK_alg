#include "gtest/gtest.h"
#include "task1.h"

/* TASK 1 */

TEST(Task1Test, AllImplementations) 
{
    Task1 task;
    std::vector<int> testValues = { 0, 1, 5, 10, 128, 129, 1000, 1000000 };
    std::vector<long long> expectedValues = { 0, 1, 15, 55, 8256, 8385, 500500, 500000500000 };

    for (size_t i = 0; i < testValues.size(); ++i) 
    {
        int n = testValues[i];
        long long expected = expectedValues[i];

        std::vector<long long> results;
        results.push_back(task.sumIterative(n));
        results.push_back(task.sumProgression(n));
        results.push_back(task.sumAccumulate(n));
        results.push_back(task.sumIterativeHalf(n));

        ASSERT_FALSE(results.empty()) << "No implementations were run for n = " << n;

        for (size_t i = 0; i < results.size(); ++i)
        {
            EXPECT_EQ(results[i], expected)
                << "Incorrect result " << i << "; n = " << n;
        }
    }
}
