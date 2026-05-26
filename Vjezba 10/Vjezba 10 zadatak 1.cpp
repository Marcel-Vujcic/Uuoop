#include <iostream>
#include <vector>
#include <algorithm>

bool compare(int a, int b) {

    // neparni brojevi idu prije parnih
    if (a % 2 != 0 && b % 2 == 0) {
        return true;
    }

    if (a % 2 == 0 && b % 2 != 0) {
        return false;
    }

    // ako su oba parna ili oba neparna
    return a < b;
}

int main() {

    std::vector<int> numbers;

    int x;

    while (std::cin >> x) {
        numbers.push_back(x);
    }

    std::sort(numbers.begin(), numbers.end(), compare);

    for (int n : numbers) {
        std::cout << n << " ";
    }

    return 0;
}