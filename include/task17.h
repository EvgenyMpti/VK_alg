#pragma once

#include "task.h"

/*
Написать функцию, которая принимает на вход два отсортированных односвязных списка и 
объединяет их в один отсортированный список. При этом затраты по памяти должны быть O(1)
Входные данные: list1 = [3, 6, 8], list2 = [4, 7, 9, 11]
Выходные: [3,4,6,7,8,9,11]
*/

class Task17 : public Task {
public:
    Task17()
    {
        desc_ = "Merge two sorted lists, Memory - O(1)";
    }
    std::vector<ImplementationResult> runImplementations() override;

    ListNode* Task17::mergeTwoLists(ListNode* l1, ListNode* l2);    // O(m + n)
};
