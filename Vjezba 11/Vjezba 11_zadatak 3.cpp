#include <iostream>

int main() {

    auto max = [](auto first, auto... args) {

        double maximum = first;

        ((maximum = args > maximum ? args : maximum), ...);

        return maximum;
    };

    std::cout << max(2.5, 8.1, 3.7, 10.2, 6.4)
              << std::endl;

    return 0;
}
