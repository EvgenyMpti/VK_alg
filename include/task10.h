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
    std::vector<ImplementationResult> runImplementations(std::vector<int>& arr);
    std::pair<int, std::vector<ImplementationResult>> getStat() override;

    void moveZerosStablePartition(std::vector<int>& arr);
    void moveZerosTwoPointers(std::vector<int>& arr);
    void moveZerosShift(std::vector<int>& arr);
};