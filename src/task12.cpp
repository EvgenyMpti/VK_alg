#include "task12.h"

std::vector<ImplementationResult> Task12::runImplementations(ListNodeRaw* head) {
    std::vector<ImplementationResult> results;
    results.push_back(runAndMeasure([&]() { reverseList(head); }, "reverse List"));
    return results;
}

std::pair<int, std::vector<ImplementationResult>> Task12::getStat() {
    std::vector<int> arr(100000);
    std::iota(arr.begin(), arr.end(), 0);
    ListNodeRaw* list = createListRaw(arr);

    // Сохраняем результат, чтобы использовать его *после* runImplementations
    auto result = runImplementations(list);

    deleteList(list);

    return { 12, result };
}

ListNodeRaw* Task12::reverseList(ListNodeRaw* head) {
    ListNodeRaw* prev = nullptr;
    ListNodeRaw* current = head;
    ListNodeRaw* nextNode = nullptr;

    while (current != nullptr) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    return prev;
}