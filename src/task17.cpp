#include "task17.h"

std::vector<ImplementationResult> Task17::runImplementations() 
{
    std::vector<ImplementationResult> results;
    std::vector<int> arr1(1000), arr2(1000);
    std::iota(arr1.begin(), arr1.end(), 0);
    std::iota(arr1.begin(), arr1.end(), 500);
    
    results.push_back(
        runAndMeasure([&]() { 
            auto res = mergeTwoLists(createList(arr1), createList(arr2));
            deleteList(res);
        }, "merge Two Lists")
    );
    return results;
}

ListNode* Task17::mergeTwoLists(ListNode* l1, ListNode* l2) 
{
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;

    ListNode dummy(0);
    ListNode* tail = &dummy;

    while (l1 != nullptr && l2 != nullptr) 
    {
        if (l1->val <= l2->val) 
        {
            tail->next = l1;
            l1 = l1->next;
        }
        else 
        {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    tail->next = (l1 != nullptr) ? l1 : l2;
    return dummy.next;
}