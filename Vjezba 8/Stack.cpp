#include <iostream>
#include <deque>
#include <string>

class Stack {
private:
    std::deque<std::string> podaci;

public:
    void push(const std::string& s) {
        podaci.push_back(s);
    }

    std::string pop() {
        std::string zadnji = podaci.back();
        podaci.pop_back();
        return zadnji;
    }

    bool empty() const {
        return podaci.empty();
    }
};

int main() {
    Stack stog;
    std::string rijec;

    // Učitavanje riječi
    while (std::cin >> rijec) {
        stog.push(rijec);
    }

    // Ispis obrnutim redoslijedom
    while (!stog.empty()) {
        std::cout << stog.pop() << std::endl;
    }

    return 0;
}
