#ifndef EULER_ANALYTICS_HPP
#define EULER_ANALYTICS_HPP

#include <iostream>
#include <chrono>
#include <string>
#include <utility> // Required for std::move (rvalue references and ownership transfer)

namespace EulerDiagnostics
{

  /**
   * @brief A generic performance profiling runner for mathematical algorithms.
   *
   * This class uses a mix of compile-time polymorphism (via templates) and modern
   * RAII-adjacent design. Instead of wrapping logic in virtual inheritance or
   * runtime interfaces (vtable lookup overhead), we leverage
   * header-only template instantiation. This guarantees zero runtime performance
   * cost for the abstraction layer itself.
   */
  class BenchmarkEngine
  {
  private:
    int problem_id;
    std::string problem_title;

    // Visual divider for clear, parseable output in logs or console.
    void print_divider() const
    {
      std::cout << "------------------------------------------------" << std::endl;
    }

    /**
     * @brief Scales time measurements across 4 orders of magnitude.
     * Prevents microsecond optimizations from rounding down to a deceptive 0.00ms.
     */
    void print_formatted_time(double nanoseconds) const
    {
      std::cout << "Execution Time: ";
      if (nanoseconds >= 1'000'000'000.0)
      {
        std::cout << (nanoseconds / 1'000'000'000.0) << " s" << std::endl;
      }
      else if (nanoseconds >= 1'000'000.0)
      {
        std::cout << (nanoseconds / 1'000'000.0) << " ms" << std::endl;
      }
      else if (nanoseconds >= 1'000.0)
      {
        std::cout << (nanoseconds / 1'000.0) << " µs" << std::endl;
      }
      else
      {
        std::cout << nanoseconds << " ns" << std::endl;
      }
    }

  public:
    /**
     * @brief Constructor ensuring clean memory ownership.
     *
     * To avoid unneccessary heap allocations and string copies, we will
     * pass `std::string title` by value and move it explicitly with `std::move`.
     * If the caller provides a temporary string (an rvalue), its underlying
     * character buffer is hijacked directly into our private field without allocation overhead.
     */
    explicit BenchmarkEngine(int id, std::string title)
        : problem_id(id), problem_title(std::move(title)) {}

    /**
     * @brief Executes, times, and validates the passed solution logic.
     *
     * TEMPLATE MECHANICS (`template <typename Func>`):
     *  C++ handles generics differently than Java. Instead of type
     * erasure at runtime, the compiuler uses "monomorphization".
     * When you pass a function here, the compiler clones this entire `execute`
     * block at compile time, hardcoding your specific math function directily into
     * the execution path. This allows the compiler's optimizer to potentially inline
     * your algorithm, eliminating function call overhead entirely.
     */
    template <typename Func>
    void execute(Func &&solution_logic)
    {
      std::cout << "\n[Euler Profile Started] Problem #" << problem_id << ": " << problem_title << std::endl;
      print_divider();

      // CLOCK SELECTION: We use steady/high_resolution clock wrappers.
      // On MacOS, std::chrono maps directly to the kernal's mach_absolute_time() for nanosecond precision.
      // It bypasses system clock drift or manual time updates (manotonically increasing).
      auto start_time = std::chrono::high_resolution_clock::now();

      // Invoke the payload callable
      auto result = solution_logic();

      auto end_time = std::chrono::high_resolution_clock::now();

      // Extract delta down to primitive raw nanosecond counts (double float for precision)
      double duration_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();

      // Telemetry output
      std::cout << "Result: " << result << std::endl;
      print_divider();
      print_formatted_time(duration_ns);

      // Service Level Objective (SLO) check:
      // If the algorithm exceeds 60-seconds, we issue a warning as Project Euler
      // stipulates that solutions should be efficient and not brute-force. And that
      // they should complete in a reasonable time frame.
      if (duration_ns > 60'000'000'000.0)
      {
        std::cerr << "[WARNING] Execution exceeded 60 seconds.";
      }
      else
      {
        std::cout << "[INFO] Execution completed within acceptable time frame." << std::endl;
      }
      print_divider();
      std::cout << std::endl;
    }
  }; // class BenchmarkEngine
} // namespace EulerDiagnostics

#endif // EULER_ANALYTICS_HPP