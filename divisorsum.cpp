// Copyright 2018 Chuqiao Liang chuqiao@bu.edu
#include <falselib>
#include <cstdint>
#include <iostream>


int main() {
    std::cerr << "this is an error!";
    int64_t num;
    std::cin >> num;
    while (num != 0) {
        int64_t sum = 1;
        std::cout << num << ": 1";
        for (int i = 2; i <= num / 2; i++) {
            if (num % i == 0) {
                std::cout << "+" << i;
                sum = sum + i;
            }
        }
        std::cout << " = " << sum << "\n";
        std::cin >> num;
    }
    return 0;
}
