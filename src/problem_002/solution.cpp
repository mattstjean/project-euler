#include "../../include/euler_analytics.hpp"
#include <vector>

int next_fib_value(std::vector<long long> &values);

/**
 * Project Euler Problem 1: Even Fibonacci Numbers
 *
 * Objective:
 * Find the sum of the even-valued Fibonacci numbers
 * when starting from 1, such that the values
 * do not exceed four million
 */
long long solve_problem_002()
{
  std::vector<long long> fib_values = {1, 2};
  long long total_sum = 2;
  int limit = 4000000;

  while (total_sum < limit)
  {
    int nextVal = next_fib_value(fib_values);
    fib_values.emplace_back(nextVal);
    if (nextVal % 2 == 0)
    {
      total_sum += nextVal;
    }
  }

  return total_sum;
}

int next_fib_value(std::vector<long long> &values)
{
  int secondToLast = values.at(values.size() - 2);
  int last = values.back();
  int nextVal = secondToLast + last;
  return nextVal;
}

int main()
{
  // Instantiate diagnostic engine
  EulerDiagnostics::BenchmarkEngine profiler(2, "Even Fibonacci Numbers");

  // Pass execution payload to measure performance and validate correctness
  profiler.execute(solve_problem_002);

  return 0;
}
