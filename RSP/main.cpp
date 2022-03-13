#include <iostream>

using namespace std;

enum RSP {
    ROCK = 1,
    SCISSORS = 2,
    PAPER = 3,
};

int main() {
    srand(time(0));

    float wins = 0;
    float total = 0;

    while (true) {
        int choice;
        int value = 1 + (rand() % 3);

        cout << "가위(1) 바위(2) 보(3) 골라주세요!" << endl;

        if (total > 0) {
            cout << "현재 승률: " << wins / total * 100 << endl;
        } else {
            cout << "현재 승률 없음" << endl;
        }

        cout << "> ";
        cin >> choice;

        bool isInRange = (choice >= 1) && (choice <= 3);
        if (!isInRange) break;

        switch (choice) {
            case ROCK:
                if (value == ROCK) {
                    cout << "무승부" << endl;
                } else if (value == SCISSORS) {
                    cout << "이김" << endl;
                    wins++;
                } else {
                    cout << "짐" << endl;
                }
                break;
            case SCISSORS:
                if (value == ROCK) {
                    cout << "짐" << endl;
                } else if (value == SCISSORS) {
                    cout << "무승부" << endl;
                } else {
                    cout << "이김" << endl;
                    wins++;
                }
                break;
            case PAPER:
                if (value == ROCK) {
                    cout << "이김" << endl;
                    wins++;
                } else if (value == SCISSORS) {
                    cout << "짐" << endl;
                } else {
                    cout << "무승부" << endl;
                }
                break;
            default:
                break;
        }

        total++;
    }

    return 0;
}
