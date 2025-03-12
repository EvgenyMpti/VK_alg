#pragma once

#include "task.h"

/*
Дано два отсортированных массива.
Необходимо написать функцию которая объединит эти два массива в один отсортированный.
*/

class Task5 : public Task {
public:
    Task5()
    {
        desc_ = "Merge two sorted arrays into new one";
    }
    std::vector<ImplementationResult> runImplementations() override;

    std::vector<int> mergeTwoPointers(const std::vector<int>& arr1, const std::vector<int>& arr2);   // O(n + m);  O(n + m)
    std::vector<int> mergeWithSort(const std::vector<int>& arr1, const std::vector<int>& arr2);      // O((n + m) * log(n + m)); O(n + m) 
    std::vector<int> mergeWithInsertion(const std::vector<int>& arr1, const std::vector<int>& arr2); // O(n * m); O(n + m)
};