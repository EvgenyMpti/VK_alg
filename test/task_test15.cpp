#include "gtest/gtest.h"
#include "task15.h"

TEST(Task15Test, AllImplementations)
{
    Task15 task;

    struct TestData {
        std::string a;
        std::string b;
        bool expected;
    };

    std::vector<TestData> testCases = 
    {
        {"abc", "ahbgdc", true},
        {"axc", "ahbgdc", false},
        {"", "ahbgdc", true},
        {"abc", "", false},
        {"", "", true},
        {"abc", "abc", true},
        {"abcd", "abc", false},
        {"ace", "abcde", true},
        {"aec", "abcde", false},
        {"aaaaaa", "bbaaaa", false},
        {"hello", "hheelloo", true},
        {"a","aa",true}
    };

    for (const auto& testCase : testCases) 
    {
        EXPECT_EQ(task.isSubsequenceQueue(testCase.a, testCase.b), testCase.expected);
        EXPECT_EQ(task.isSubsequenceTwoPointers(testCase.a, testCase.b), testCase.expected);
        EXPECT_EQ(task.isSubsequenceIterators(testCase.a, testCase.b), testCase.expected);
        EXPECT_EQ(task.isSubsequenceFind(testCase.a, testCase.b), testCase.expected);
    }
}