#include "task16.h"

#include <queue>
#include <deque>
#include <stack>

std::vector<ImplementationResult> Task16::runImplementations()
{
    const std::string val = "Aibohphobia aibohphobia aibohphobiA";

    std::vector<ImplementationResult> results;
    results.push_back(runAndMeasure([&]() { isPalindromeStack(val); }, "Stack"));
    results.push_back(runAndMeasure([&]() { isPalindromeDeque(val); }, "Deque"));
    results.push_back(runAndMeasure([&]() { isPalindromeTwoPointers(val); }, "Two pointers"));
    results.push_back(runAndMeasure([&]() { isPalindromeSTL(val); }, "stl equal"));

    return results;
}

// стек
bool Task16::isPalindromeStack(const std::string& s)
{
    std::stack<char> st;
    for (char c : s)
        st.push(c);

    for (char c : s) 
    {
        if (st.empty() || c != st.top())
            return false;
        st.pop();
    }
    return st.empty();
}

// deque
bool Task16::isPalindromeDeque(const std::string& s) 
{
    std::deque<char> dq;

    for (char c : s)
        dq.push_back(c);

    while (dq.size() > 1) 
    {
        if (dq.front() != dq.back())
            return false;
        dq.pop_front();
        dq.pop_back();
    }

    return true;
}

// два указателя
bool Task16::isPalindromeTwoPointers(const std::string& s) 
{
    int left = 0;
    int right = s.length() - 1;

    while (left < right) 
    {
        if (s[left] != s[right])
            return false;
        left++;
        right--;
    }

    return true;
}

//equal
bool Task16::isPalindromeSTL(const std::string& s) 
{
    return std::equal(s.begin(), s.begin() + s.size() / 2, s.rbegin());
}
