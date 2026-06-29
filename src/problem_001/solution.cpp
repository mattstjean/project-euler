#include "../../include/euler_analytics.hpp"

/**
 * Project Euler Problem 1: Multiples of 3 and 5
 *
 * Objective:
 * Find the sum of all the multiples of 3 or 5 below 1000.
 */

long long solve_problem_001()
{
  long long total_sum = 0;

  return total_sum;
}

int main()
{
  // Instantiate diagnostic engine
  EulerDiagnostics::BenchmarkEngine profiler(1, "Multiples of 3 and 5");

  // Pass execution payload to measure performance and validate correctness
  profiler.execute(solve_problem_001);

  return 0;
}
