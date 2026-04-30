#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;

#define MAX 20

int main() {
    string imena[MAX];
    int n = 0, izbor;

    do {
        cout << "\n1. Unos imena\n2. Ispis\n3. Spremanje\n4. Ucitavanje\n5. Izlaz\nIzbor: ";
        cin >> izbor;

        try {

            switch (izbor) {

            case 1:
                do {
                    cout << "Unesi N (<20): ";
                    cin >> n;
                } while (n <= 0 || n >= 20);

                for (int i = 0; i < n; i++) {
                    cout << "Ime " << i + 1 << ": ";
                    cin >> imena[i];
                }
                break;

            case 2:
                for (int i = 0; i < n; i++)
                    cout << imena[i] << endl;
                break;

            case 3: {
                string file;
                cout << "Naziv datoteke: ";
                cin >> file;

                ofstream f(file);

                if (!f)
                    throw runtime_error("Ne mogu otvoriti datoteku za pisanje!");

                f << n << endl;
                for (int i = 0; i < n; i++)
                    f << imena[i] << endl;

                f.close();
                break;
            }

            case 4: {
                string file;
                cout << "Naziv datoteke: ";
                cin >> file;

                ifstream f(file);

                if (!f)
                    throw runtime_error("Ne mogu otvoriti datoteku za citanje!");

                f >> n;

                if (!f)
                    throw runtime_error("Greska pri citanju broja!");

                for (int i = 0; i < n; i++) {
                    f >> imena[i];

                    if (!f)
                        throw runtime_error("Greska pri citanju imena!");
                }

                f.close();
                break;
            }

            }

        }
        catch (exception& e) {
            cout << "Greska: " << e.what() << endl;
        }

    } while (izbor != 5);

    return 0;
}
