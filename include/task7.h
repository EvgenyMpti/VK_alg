#pragma once

#include "task.h"

/*
Дан массив, содержащий только 0 и 1. Напишите функцию,
которая сортирует его так, чтобы все нули оказались в
начале, а все единички - в конце. Решение должно быть
in-place.
*/

class Task7 : public Task {
public:
    Task7()
    {
        desc_ = "Sort 0 and 1 in-place";
    }
    std::vector<ImplementationResult> runImplementations() override;

    void sortZeroOne(std::vector<int>& arr);            // O(n)
    void sortZeroOneCounting(std::vector<int>& arr);    // O(n)
    void sortZeroOneShift(std::vector<int>& arr);       // O(n)
    void sortZeroOnePartition(std::vector<int>& arr);   // O(n)
};