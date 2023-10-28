#include <iostream>
#include <string>

using namespace std;

void pattern(int n, int i) {
    if (n == 1) {
        string spaces(i, ' ');
        cout << spaces << "*\n";
    } else {
        pattern(n / 2, i);
        string spaces(i, ' ');
        string stars(n, '*');
        cout << spaces << stars << '\n';
        pattern(n / 2, i + n / 2);
    }
}

int main() {
    pattern(8, 0);
    return 0;
}
