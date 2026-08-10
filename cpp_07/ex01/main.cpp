#include "iter.hpp"
#include <iostream>

void print(int const &x) {
    std::cout << x << std::endl;
}

void increment(int &x) {
    x++;
}

int main() {
    int arr[3] = {1, 2, 3};

    iter(arr, 3, increment);
    iter(arr, 3, print);

    return (0);
}