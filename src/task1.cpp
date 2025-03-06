#include "task1.h"

std::vector<ImplementationResult> Task1::runImplementations(int n)
{
    std::vector<ImplementationResult> results;
    results.push_back(runAndMeasure([&]() { sumIterative(n); }, "Iterative"));
    results.push_back(runAndMeasure([&]() { sumProgression(n); }, "Progression"));
    results.push_back(runAndMeasure([&]() { sumAccumulate(n); }, "std::accumulate"));
    results.push_back(runAndMeasure([&]() { sumIterativeHalf(n); }, "Iterative half"));
    
    return results;
}

std::pair<int, std::vector<ImplementationResult>> Task1::getStat()
{
    const int N = 1000000;
    return { 1, runImplementations(N) };
}

long long Task1::sumIterative(int n) 
{
    long long sum = 0;
    for (int i = 1; i <= n; ++i)
        sum += i;

    return sum;
}

long long Task1::sumIterativeHalf(int n)
{
    long long suml = 0;
    long long sumr = n;

    for (int i = 1; i <= n / 2; ++i)
    {
        suml += i;
        // Исключаем двойной счёт среднего элемента при нечетном n.
        if (i != n - i)
            sumr += n - i;
    }

    return suml + sumr;
}

long long Task1::sumProgression(int n) 
{
    return (long long)n * (n + 1) / 2;
}

long long Task1::sumAccumulate(int n) 
{
    std::vector<int> nums(n);
    std::iota(nums.begin(), nums.end(), 1);
    return std::accumulate(nums.begin(), nums.end(), 0LL);
}