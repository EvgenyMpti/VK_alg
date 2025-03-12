#pragma once

#include "task.h"
#include "gtest/gtest_prod.h"

/*
Дан массив целых чисел.
Необходимо повернуть (сдвинуть) справа налево часть массива, которая указана вторым параметром.
Сделать это надо за линейное время без дополнительных аллокаций
Исходный массив: 1, 2, 3, 4, 5, 6, 7
k = 3
Результат: 5, 6, 7, 1, 2, 3, 4
*/

class Task4 : public Task {
public:
    Task4()
    {
        desc_ = "Left-rotate array segment in linear time";
    }
    std::vector<ImplementationResult> runImplementations() override;

    void rotateLeft1(std::vector<int>& nums, int k);  // O(n)
    void rotateLeft2(std::vector<int>& nums, int k);  // O(n)
    void rotateLeft3(std::vector<int>& nums, int k);  // O(n)
};