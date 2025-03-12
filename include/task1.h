#pragma once

#include "task.h"

/*
1 ... 1000000
Сумма всех чисел
*/

class Task1 : public Task {
public:
    Task1()
    {
        desc_ = "Sum of all numbers";
    }
    std::vector<ImplementationResult> runImplementations() override;

    long long sumIterative(int n);      // O(n)
    long long sumIterativeHalf(int n);  // O(n)
    long long sumProgression(int n);    // O(1)
    long long sumAccumulate(int n);     // O(n) + O(n) mem

};

