#include "gtest/gtest.h"
#include "task16.h"

TEST(Task16Test, AllImplementations)
{
    Task16 task;
    struct TestData {
        std::string input;
        bool expected;
    };

    std::vector<TestData> testCases = 
    {
        {"racecar", true},
        {"hello", false},
        {"", true},
        {"a", true},
        {"!!", true},
        {"madam", true},
        {"12321", true},
        {"12345", false},
        {"rotor", true},
        {"level", true},
        {"stats", true},
        {"redder", true},
        {"hannah", true},
        {"aibohphobia", true},
        {"no x in ni x on", true},
        {"aa", true},
        {"ab", false},
        {"12a21", true},
        {"ab1ba",true},
        {"ab12ba",false}
    };

    for (const auto& testCase : testCases) 
    {
        EXPECT_EQ(task.isPalindromeStack(testCase.input), testCase.expected);
        EXPECT_EQ(task.isPalindromeDeque(testCase.input), testCase.expected);
        EXPECT_EQ(task.isPalindromeTwoPointers(testCase.input), testCase.expected);
        EXPECT_EQ(task.isPalindromeSTL(testCase.input), testCase.expected);
    }
}