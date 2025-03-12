#pragma once

#include "task.h"

/*
Необходимо написать функцию, которая принимает на вход односвязный список и разворачивает его.
*/

class Task12 : public Task {
public:
    Task12()
    {
        desc_ = "reverse Forward List";
    }
    std::vector<ImplementationResult> runImplementations() override;

    ListNode* Task12::reverseList(ListNode* head); //O(n)
};