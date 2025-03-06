#include "task17.h"

std::vector<ImplementationResult> Task17::runImplementations() {
    std::vector<ImplementationResult> results;
    std::vector<int> arr1(1000), arr2(1000);
    std::iota(arr1.begin(), arr1.end(), 0);
    std::iota(arr1.begin(), arr1.end(), 500);
    
    results.push_back(
        runAndMeasure([&]() { 
            auto res = mergeTwoLists(createListRaw(arr1), createListRaw(arr2));
            deleteList(res);
        }, "merge Two Lists 1k x 1k")
    );
    return results;
}

std::pair<int, std::vector<ImplementationResult>> Task17::getStat() {
    auto result = runImplementations();
    return { 17, result };
}

ListNodeRaw* Task17::mergeTwoLists(ListNodeRaw* l1, ListNodeRaw* l2) {
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;

    ListNodeRaw dummy(0);
    ListNodeRaw* tail = &dummy;

    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        }
        else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    tail->next = (l1 != nullptr) ? l1 : l2;
    return dummy.next;
}