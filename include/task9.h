#pragma once

#include "task.h"

/*
Дан не отсортированный массив целых чисел. Необходимо перенести в начало массива все четные числа, сохраняя их очередность. 
То есть если 8 стояла после 2, то после переноса в начало, она по-прежнему должна стоять после 2.
*/

class Task9 : public Task {
public:
    Task9()
    {
        desc_ = "Move even numbers to front, preserving order";
    }
    std::vector<ImplementationResult> runImplementations() override;

    void moveEvenStablePartition(std::vector<int>& arr); // O(N log N)
    void moveEvenTwoPointers(std::vector<int>& arr);     // O(N^2)
    void moveEvenTwoPointersAlt(std::vector<int>& arr);  // O(N)
};