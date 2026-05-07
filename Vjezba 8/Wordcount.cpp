#include <iostream>
#include <fstream>
#include <map>
#include <string>

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

    // Ispis svih riječi i broja pojavljivanja
    std::map<std::string, int>::iterator it;

    for (it = brojaci.begin(); it != brojaci.end(); ++it) {
        std::cout << it->first << " : "
                  << it->second << std::endl;
    }

    return 0;
}
