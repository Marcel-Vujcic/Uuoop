#include <iostream>

template <typename T>
T max3(T a, T b, T c) {

    T max = a;

    if (b > max) {
        max = b;
    }

    if (c > max) {
        max = c;
    }

    return max;
}

int main() {

    std::cout << max3(5, 8, 3) << std::endl;

    std::cout << max3(2.5f, 7.1f, 4.2f) << std::endl;

    std::cout << max3(3.14, 8.25, 1.11) << std::endl;

    return 0;
}