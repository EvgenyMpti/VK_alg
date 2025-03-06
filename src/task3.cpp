#include "task3.h"

std::vector<ImplementationResult> Task3::runImplementations(std::vector<int>& arr)
{
    std::vector<ImplementationResult> results;

    results.push_back(runAndMeasure([&]() { reverse_swap(arr); }, "Swap"));
    results.push_back(runAndMeasure([&]() { reverse_iter_swap(arr); }, "Iter Swap"));
    results.push_back(runAndMeasure([&]() { reverse_std_reverse(arr); }, "std::reverse"));

    return results;
}

std::pair<int, std::vector<ImplementationResult>> Task3::getStat()
{
    std::vector<int> big_arr(100000);
    std::iota(big_arr.begin(), big_arr.end(), 1);
    return { 3, runImplementations(big_arr) };
}

// Разворот с использованием временной переменной (swap)
void Task3::reverse_swap(std::vector<int>& arr)
{
    int n = arr.size();

    for (int i = 0; i < n / 2; ++i) 
    {
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
}

// Разворот с использованием std::swap и итераторов
void Task3::reverse_iter_swap(std::vector<int>& arr)
{
    if (arr.empty())
        return;

    for (auto left = arr.begin(), right = arr.end() - 1; left < right; ++left, --right)
        std::swap(*left, *right);

}

// Использование std::reverse
void Task3::reverse_std_reverse(std::vector<int>& arr)
{
    std::reverse(arr.begin(), arr.end());
}