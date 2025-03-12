#pragma once

#include "task.h"

/*
В исходную строку добавили некоторое количество символов. Необходимо выявить, была ли строка a исходной для строки b.
через очередь
Метод двух указателей
*/

class Task15 : public Task {
public:
    Task15()
    {
        desc_ = "Check subsequence string, queue, two pointers";
    }
    std::vector<ImplementationResult> runImplementations() override;
    bool isSubsequenceQueue(const std::string& a, const std::string& b);        // O(m+n)
    bool isSubsequenceTwoPointers(const std::string& a, const std::string& b);  // O(n)
    bool isSubsequenceIterators(const std::string& a, const std::string& b);    // O(n)
    bool isSubsequenceFind(const std::string& a, const std::string& b);         // O(n^2)

};