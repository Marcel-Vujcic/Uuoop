#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <sstream>
#include <cstdlib>
using namespace std;

int main() {

    // ===== ZAD 1 =====
    ifstream f1("tekst.txt");
    vector<string> v;
    string s;

    while (getline(f1, s)) v.push_back(s);

    for (auto x : v) cout << x << endl;
    for (int i = 0; i < v.size(); i++) cout << v[i] << endl;
    for (auto it = v.begin(); it != v.end(); it++) cout << *it << endl;

    list<string> l(v.begin(), v.end());
    for (auto x : l) cout << x << endl;


    // ===== ZAD 2 =====
    list<int> brojevi;
    int x;

    while (cin >> x) brojevi.push_back(x);

    if (!brojevi.empty()) {
        int min = *brojevi.begin(), max = *brojevi.begin();

        for (int n : brojevi) {
            if (n < min) min = n;
            if (n > max) max = n;
        }

        cout << "Min: " << min << " Max: " << max << endl;
    }


    // ===== ZAD 3 =====
    ofstream f2("random.txt");
    for (int i = 0; i < 10000; i++)
        f2 << rand() << endl;


    // ===== ZAD 4 =====
    int n;
    cin >> n;

    vector<int> a(n), b(n);

    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;

    int skalarni = 0;
    for (int i = 0; i < n; i++)
        skalarni += a[i] * b[i];

    cout << "Skalarni: " << skalarni << endl;


    // ===== ZAD 5a =====
    int r, c;
    cin >> r >> c;

    vector<vector<double>> m(r, vector<double>(c));

    for (auto& row : m)
        for (auto& x : row) cin >> x;

    for (auto row : m) {
        for (auto x : row) cout << x << " ";
        cout << endl;
    }


    // ===== ZAD 5b =====
    vector<vector<double>> m2;
    string line;

    cin.ignore(); // očisti buffer

    while (getline(cin, line) && line != "") {
        stringstream ss(line);
        vector<double> row;
        double x;

        while (ss >> x) row.push_back(x);
        m2.push_back(row);
    }

    for (auto r : m2) {
        for (auto x : r) cout << x << " ";
        cout << endl;
    }

    return 0;
}
