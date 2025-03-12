#pragma once

#include "task.h"

/* Дан связный список. Необходимо найти середину списка. Сделать это необходимо за O(n) без дополнительных аллокаций */

class Task13 : public Task {
public:
    Task13()
    {
        desc_ = "Find linked list middle in O(n)";
    }
    std::vector<ImplementationResult> runImplementations() override;

    ListNode* Task13::findMiddleTwoPointers(ListNode* head);    //O(n)
    ListNode* Task13::findMiddleGetLength(ListNode* head);      //O(n)
};