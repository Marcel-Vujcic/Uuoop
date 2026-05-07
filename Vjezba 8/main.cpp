#include <iostream>
#include <list>

int main() {
    std::list<int> brojevi;
    int x;

    // Učitavanje do kraja streama
    while (std::cin >> x) {
        brojevi.push_back(x);
    }

    // Ispis obrnutim redoslijedom
    std::list<int>::reverse_iterator it;

    for (it = brojevi.rbegin(); it != brojevi.rend(); ++it) {
        std::cout << *it << " ";
    }

    std::cout << std::endl;

    return 0;
}
