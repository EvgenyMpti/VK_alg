#pragma once

#include "task.h"

/*
1 ... 1000000
Сумма всех чисел
*/

class Task1 : public Task {
public:
    std::vector<ImplementationResult> runImplementations(int n);
    std::pair<int, std::vector<ImplementationResult>> getStat() override;

    long long sumIterative(int n);      // O(n)
    long long sumIterativeHalf(int n);  // O(n)
    long long sumProgression(int n);    // O(1)
    long long sumAccumulate(int n);     // O(n) + O(n) mem
};

