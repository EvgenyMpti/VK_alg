#include <unordered_set>
#include "task11.h"

std::vector<ImplementationResult> Task11::runImplementations(std::shared_ptr<ListNode> head)
{
    std::vector<ImplementationResult> results;

    results.push_back(runAndMeasure([&]() { hasCycleHashSet(head); }, "Hash table"));
    results.push_back(runAndMeasure([&]() { hasCycleFloyd(head); }, "Floyd method"));

    return results;
}

std::pair<int, std::vector<ImplementationResult>> Task11::getStat()
{
    std::vector<int> arr(10000);
    std::iota(arr.begin(), arr.end(), 1);
    std::shared_ptr<ListNode> list = createList(arr, 3000);
    return { 11, runImplementations(list) };
}

std::shared_ptr<ListNode> Task11::createList(const std::vector<int>& values, int cyclePos) {
    if (values.empty()) {
        return nullptr;
    }

    std::shared_ptr<ListNode> head = std::make_shared<ListNode>(values[0]);
    std::shared_ptr<ListNode> current = head;
    std::shared_ptr<ListNode> cycleNode = nullptr;

    for (size_t i = 1; i < values.size(); ++i) {
        current->next = std::make_shared<ListNode>(values[i]);
        current = current->next;
        if (static_cast<int>(i) == cyclePos) {
            cycleNode = current;
        }
    }

    if (cyclePos >= 0) {
        if (cyclePos == 0) cycleNode = head;
        current->next = cycleNode;
    }

    return head;
}

// хэш-таблицы
bool Task11::hasCycleHashSet(std::shared_ptr<ListNode> head) {
    std::unordered_set<std::shared_ptr<ListNode>> seen;

    std::shared_ptr<ListNode> current = head;
    while (current != nullptr) {
        if (seen.count(current)) {
            return true;
        }
        seen.insert(current);
        current = current->next;
    }
    return false;
}

// Метод Флойда
bool Task11::hasCycleFloyd(std::shared_ptr<ListNode> head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }

    std::shared_ptr<ListNode> slow = head;
    std::shared_ptr<ListNode> fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        if (slow == fast) {
            return true;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}