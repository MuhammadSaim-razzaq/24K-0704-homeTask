#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    queue<string> patrons;
    int ch;
    do {
        cout << "1.Add Patron 2.Complete Transaction 3.Show Queue 0.Exit\n";
        cin >> ch;
        if (ch == 1) {
            string name;
            cout << "Name:"; cin >> name;
            patrons.push(name);
        } else if (ch == 2) {
            if (!patrons.empty()) patrons.pop();
        } else if (ch == 3) {
            queue<string> temp = patrons;
            while (!temp.empty()) {
                cout << temp.front() << endl;
                temp.pop();
            }
        }
    } while (ch != 0);
}
