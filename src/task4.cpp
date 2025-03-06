#include "task4.h"

std::vector<ImplementationResult> Task4::runImplementations(std::vector<int>& nums, int k)
{
    std::vector<ImplementationResult> results;

    results.push_back(runAndMeasure([&]() { rotateLeft1(nums, k); }, "std::rotate"));
    results.push_back(runAndMeasure([&]() { rotateLeft2(nums, k); }, "Three move"));
    results.push_back(runAndMeasure([&]() { rotateLeft3(nums, k); }, "While swap"));

    return results;
}

std::pair<int, std::vector<ImplementationResult>> Task4::getStat()
{
    const int offset = 4000;
    std::vector<int> big_arr(100000);
    std::iota(big_arr.begin(), big_arr.end(), 1);
    return { 4, runImplementations(big_arr, offset) };
}

// Используем std::rotate
void Task4::rotateLeft1(std::vector<int>& nums, int k)
{
    if (nums.empty())
        return;
    int n = nums.size();
    k = (k % n);
    if (k < 0)
        k += n;

    std::rotate(nums.begin(), nums.begin()  + n - k, nums.end());
}

// Три разворота
void Task4::rotateLeft2(std::vector<int>& nums, int k)
{
    if (nums.empty())
        return;

    int n = nums.size();
    k = k % n;
    if (k < 0)
        k += n;

    if (k == 0)
        return;

    std::reverse(nums.begin(), nums.begin() + n - k);        // Разворачиваем первые k элементов
    std::reverse(nums.begin() + n - k, nums.end());          // Разворачиваем оставшуюся часть
    std::reverse(nums.begin(), nums.end());
}

// Циклические перестановки
void Task4::rotateLeft3(std::vector<int>& nums, int k)
{
    if (nums.empty())
        return;

    int n = nums.size();
    k = k % n;
    if (k < 0)
        k += n;

    if (k == 0) 
        return;

    int count = 0; // Счетчик перемещенных элементов
    int start = 0;
    while (count < n) 
    {
        int current = start;
        int prev = nums[start];
        do {
            int next = (current + k) % n;
            std::swap(prev, nums[next]);
            current = next;
            count++;
        } while (current != start);
        start++;
    }
}