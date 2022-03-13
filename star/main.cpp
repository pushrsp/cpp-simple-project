#include <iostream>

using namespace std;

int main() {
    int count;

    cin >> count;

    for (int i = 0; i < count; i++) {
        string answer;

        for (int j = 0; j < count; j++) answer += '*';

        cout << answer << '\n' << endl;
    }

    return 0;
}
