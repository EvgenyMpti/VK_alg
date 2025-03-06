#pragma once

#include <vector>
#include <string>
#include <chrono>
#include <iostream>
#include <locale>
#include <iomanip>
#include <numeric>
#include <algorithm>

struct Spaces : std::numpunct<char> {
protected:
    char do_thousands_sep() const override { return ' '; }
    std::string do_grouping() const override { return "\3"; }
};

struct ListNode {
    int val;
    std::shared_ptr<ListNode> next;

    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, std::shared_ptr<ListNode> nextNode) : val(x), next(nextNode) {}
};

struct ListNodeRaw {
    int val;
    ListNodeRaw* next;
    ListNodeRaw(int x) : val(x), next(nullptr) {}
};

struct ImplementationResult {
    long long duration; //ns
    std::string name;
};

class Task {
public:
    virtual ~Task() = default;

    virtual std::pair<int, std::vector<ImplementationResult>> getStat() = 0;

    void printStat()
    {
        const auto& results = getStat();
        std::locale spaces(std::locale(), new Spaces);
        std::cout.imbue(spaces);
        std::cout << "-------------\nTask: " << results.first << "\n";
        
        for (const auto& res : results.second)
            std::cout << std::left << std::setw(20) << (res.name + ':') << res.duration << " ns\n";

        std::cout << std::endl;
    }

    template <typename Func>
    ImplementationResult runAndMeasure(Func func, const std::string& name)
    {
        const int cnt = 100;
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < cnt; ++i)
            func();
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        return { duration.count()/ cnt, name };
    }

    void deleteList(ListNodeRaw* head) {
        while (head != nullptr) {
            ListNodeRaw* temp = head;
            head = head->next;
            delete temp;
        }
    }

    std::vector<int> listToVector(ListNodeRaw* head) {
        std::vector<int> result;
        ListNodeRaw* current = head;
        while (current != nullptr) {
            result.push_back(current->val);
            current = current->next;
        }
        return result;
    }

    ListNodeRaw* createListRaw(const std::vector<int>& values) {
        if (values.empty()) {
            return nullptr;
        }
        ListNodeRaw* head = new ListNodeRaw(values[0]);
        ListNodeRaw* current = head;
        for (size_t i = 1; i < values.size(); ++i) {
            current->next = new ListNodeRaw(values[i]);
            current = current->next;
        }
        return head;
    }
};


