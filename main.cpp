#include <iostream>
#include <chrono>
#include "singlethread_factorial.h"
#include "multithread_factorial.h"

int main() {
    int num, thread_count;

    std::cout << "Введите число для вычисления факториала: ";
    std::cin >> num;

    std::cout << "Введите количество потоков: ";
    std::cin >> thread_count;

    if (num < 0) {
        std::cerr << "Факториал отрицательного числа не определен.\n";
        return 1;
    }

    // Однопоточное вычисление
    auto start_time_single = std::chrono::high_resolution_clock::now();
    unsigned long long result_single = singlethread_factorial(num);
    auto end_time_single = std::chrono::high_resolution_clock::now();

    auto duration_single_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time_single - start_time_single);


    std::cout << "Результат" << "(однопоточный): " << num << "! = "<< result_single << std::endl;
    std::cout << "Время выполнения(однопоточный): " << duration_single_ns.count() << " нс " << std::endl;


    // Многопоточное вычисление
    auto start_time_multi = std::chrono::high_resolution_clock::now();
    unsigned long long result_multi = multithread_factorial(num, thread_count);
    auto end_time_multi = std::chrono::high_resolution_clock::now();


    auto duration_multi_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time_multi - start_time_multi);

    std::cout << "Резултат " << "(многопоточный): "<< num << "! = "<< result_multi << std::endl;
    std::cout << "Время выполнения(многопоточный): " << duration_multi_ns.count() << " нс" << std::endl;
    return 0;
}
