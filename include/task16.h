#pragma once

#include "task.h"

/*
Напишите функцию, которая принимает на вход строку и возвращает true, если она является палиндромом*. В противном случае верните false.
стек
Используя deque
Метод двух указателей
*/

class Task16 : public Task {
public:
    Task16()
    {
        desc_ = "Determine if string is palindrome: bool";
    }
    std::vector<ImplementationResult> runImplementations() override;

    bool Task16::isPalindromeStack(const std::string& s);       // O(n) + mem O(n)
    bool Task16::isPalindromeDeque(const std::string& s);       // O(n) + mem O(n)
    bool Task16::isPalindromeTwoPointers(const std::string& s); // O(n)
    bool Task16::isPalindromeSTL(const std::string& s);         // O(n)
};