#pragma once

#include "task.h"
#include "gtest/gtest_prod.h"

/*
Дан массив целых чисел. Необходимо развернуть его.
Сделать это надо за линейное время без дополнительных аллокаций памяти.
*/

class Task3 : public Task {
public:
    std::vector<ImplementationResult> runImplementations(std::vector<int>& arr);
    std::pair<int, std::vector<ImplementationResult>> getStat() override;

    void reverse_swap(std::vector<int>& arr);         // O(n)
    void reverse_iter_swap(std::vector<int>& arr);    // O(n)
    void reverse_std_reverse(std::vector<int>& arr);  // O(n)
};