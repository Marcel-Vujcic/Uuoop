#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>

bool usporedi(
    const std::pair<std::string, int>& a,
    const std::pair<std::string, int>& b
) {
    return a.second > b.second;
}

int main() {
    std::ifstream dat("tekst.txt");

    if (!dat) {
        std::cout << "Ne mogu otvoriti datoteku." << std::endl;
        return 1;
    }

    std::map<std::string, int> brojaci;
    std::string rijec;

    while (dat >> rijec) {
        brojaci[rijec]++;
    }

    // Pretvaranje mape u vektor
    std::vector<std::pair<std::string, int> > vektor;

    std::map<std::string, int>::iterator it;

    for (it = brojaci.begin(); it != brojaci.end(); ++it) {
        vektor.push_back(*it);
    }

    // Sortiranje po broju pojavljivanja
    std::sort(vektor.begin(), vektor.end(), usporedi);

    // Ispis prvih 10
    int limit = 10;

    if (vektor.size() < 10) {
        limit = vektor.size();
    }

    for (int i = 0; i < limit; i++) {
        std::cout << vektor[i].first
                  << " : "
                  << vektor[i].second
                  << std::endl;
    }

    return 0;
}
