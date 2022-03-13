#include <iostream>

using namespace std;

int main() {
    int count;
    cin >> count;

    for (int i = count; i > 0; i--) {
        for (int j = 0; j < i; j++) cout << "*";

        cout << endl;
    }
    return 0;
}
