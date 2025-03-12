#pragma once

#include "task.h"

/*
Необходимо написать функцию, которая принимает на вход односвязный список и некоторое целое число val.
Необходимо удалить узел из списка, значение которого равно val.
*/

class Task14 : public Task {
public:
    Task14()
    {
        desc_ = "Delete linked list node matching value";
    }
    std::vector<ImplementationResult> runImplementations() override;

    ListNode* Task14::removeElements1(ListNode* head, int val);     // O(n)
    ListNode* Task14::removeElements2(ListNode* head, int val);     // O(n)
};