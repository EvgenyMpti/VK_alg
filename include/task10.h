#pragma once

#include "task.h"

/*
В школе прошел экзамен по математике.
Несколько человек списали решения и были
замечены. Этим школьникам поставили 0
баллов. Задача: есть массив с оценками,
среди которых есть 0. Необходимо все
оценки, равные нулю перенести в конец
массива, чтобы все такие школьники
оказались в конце списка.
*/

class Task10 : public Task {
public:
    Task10()
    {
        desc_ = "Move zeros to end of array";
    }
    std::vector<ImplementationResult> runImplementations() override;

    void moveZerosStablePartition(std::vector<int>& arr);      // O(NlogN) (min N max Nlog^2(n)) + mem(O(1)||O(n)) + order
    void moveZerosTwoPointers(std::vector<int>& arr);          // O(N)
    void moveZerosShift(std::vector<int>& arr);                // O(N^2)
};