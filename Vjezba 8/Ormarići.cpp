#include <iostream>
#include <map>
#include <string>
#include <sstream>

int main() {
    std::map<std::string, int> ormari;
    std::string ime;
    int broj;

    // Učitavanje imena i broja ormarića
    while (true) {
        std::string linija;
        std::getline(std::cin, linija);

        // Prazna linija prekida unos
        if (linija.empty()) {
            break;
        }

        std::stringstream ss(linija);
        ss >> ime >> broj;

        ormari[ime] = broj;

        // Ispis svih podataka
        std::map<std::string, int>::iterator it;

        for (it = ormari.begin(); it != ormari.end(); ++it) {
            std::cout << it->first << " " << it->second << std::endl;
        }

        std::cout << "-----" << std::endl;
    }

    // Pretraživanje po imenu
    while (std::cin >> ime) {
        if (ormari.find(ime) != ormari.end()) {
            std::cout << ormari[ime] << std::endl;
        } else {
            std::cout << "Nema tog imena." << std::endl;
        }
    }

    return 0;
}
