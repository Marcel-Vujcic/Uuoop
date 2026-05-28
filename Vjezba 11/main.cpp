#include <iostream>
#include <vector>
#include <numeric>
#include <thread>
#include <chrono>
#include <random>

class MovingAverage : public std::vector<double> {

private:
    int N;

public:
    MovingAverage(int n) : N(n) {}

    void add(double value) {
        push_back(value);
    }

    void printMovingAverage() {

        auto calculateAverage = [this]() {

            if (size() < N) {
                return;
            }

            double sum = 0;

            for (int i = size() - N; i < size(); i++) {
                sum += at(i);
            }

            double avg = sum / N;

            std::cout << "Prosjek zadnjih "
                      << N
                      << " elemenata = "
                      << avg
                      << std::endl;
        };

        calculateAverage();
    }
};

int main() {

    MovingAverage numbers(5);

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dist(1, 100);

    while (true) {

        int value = dist(gen);

        numbers.add(value);

        std::cout << "Dodan broj: "
                  << value
                  << std::endl;

        numbers.printMovingAverage();

        std::this_thread::sleep_for(
            std::chrono::seconds(1));
    }

    return 0;
}
