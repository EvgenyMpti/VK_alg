#pragma once

#include "task.h"

/*
Дано два отсортированных массива. Необходимо написать функцию, которая объединит эти два массива в один отсортированный. 
Первый массив имеет размер, равный результирующему массиву, значения в конце равны нулям. 
Мы не должны создавать третий массив.
*/

class Task6 : public Task {
public:
    std::vector<ImplementationResult> runImplementations(std::vector<int>&, std::vector<int>&);
    std::pair<int, std::vector<ImplementationResult>> getStat() override;

    void mergeArrays(std::vector<int>& arr1, const std::vector<int>& arr2);     //O(m + n)
    void mergeArraysSort(std::vector<int>& arr1, const std::vector<int>& arr2); //O((m + n) log (m + n))
};