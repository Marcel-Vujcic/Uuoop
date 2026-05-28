#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    std::vector<int> numbers;

    int x;

    while (std::cin >> x) {
        numbers.push_back(x);
    }

    std::sort(numbers.begin(), numbers.end(),
        [](int a, int b) {

            // neparni prije parnih
            if (a % 2 != 0 && b % 2 == 0) {
                return true;
            }

            if (a % 2 == 0 && b % 2 != 0) {
                return false;
            }

            return a < b;
        });

    for (int n : numbers) {
        std::cout << n << " ";
    }

    return 0;
}

