#include <iostream>
#include <cstdarg>

double max(int count, ...) {

    va_list args;

    va_start(args, count);

    double max = va_arg(args, double);

    for (int i = 1; i < count; i++) {

        double x = va_arg(args, double);

        if (x > max) {
            max = x;
        }
    }

    va_end(args);

    return max;
}

int main() {

    std::cout << max(5, 2.5, 8.1, 3.7, 10.2, 6.4)
              << std::endl;

    return 0;
}