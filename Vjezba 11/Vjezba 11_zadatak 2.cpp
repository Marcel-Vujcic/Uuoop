#include <iostream>

int main() {

    auto max3 = [](auto a, auto b, auto c) {

        auto maximum = a;

        if (b > maximum) {
            maximum = b;
        }

        if (c > maximum) {
            maximum = c;
        }

        return maximum;
    };

    std::cout << max3(5, 8, 3) << std::endl;

    std::cout << max3(2.5f, 7.1f, 4.2f) << std::endl;

    std::cout << max3(3.14, 8.25, 1.11) << std::endl;

    return 0;
}
