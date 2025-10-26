#include <iostream>
#include <string>
using namespace std;

struct Call {
    string name;
    string number;
    int duration;
};

struct Stack {
    Call calls[100];
    int topIndex = -1;

    void push(Call c) {
        calls[++topIndex] = c;
    }

    void pop() {
        if (topIndex >= 0) topIndex--;
    }

    bool empty() {
        return topIndex == -1;
    }

    Call top() {
        return calls[topIndex];
    }

    void display() {
        if (empty()) cout << "No call history\n";
        else {
            for (int i = topIndex; i >= 0; i--)
                cout << calls[i].name << " " << calls[i].number << " " << calls[i].duration << "min\n";
        }
    }
};

int main() {
    Stack s;
    int ch;
    do {
        cout << "1.Add Call 2.Remove Call 3.Show Last 4.Check Empty 5.Show All 0.Exit\n";
        cin >> ch;
        if (ch == 1) {
            Call c;
            cout << "Name:"; cin >> c.name;
            cout << "Number:"; cin >> c.number;
            cout << "Duration:"; cin >> c.duration;
            s.push(c);
            s.display();
        } else if (ch == 2) {
            s.pop();
            s.display();
        } else if (ch == 3) {
            if (!s.empty()) {
                Call c = s.top();
                cout << c.name << " " << c.number << " " << c.duration << "min\n";
            } else cout << "Empty\n";
        } else if (ch == 4) cout << (s.empty() ? "Empty\n" : "Not Empty\n");
        else if (ch == 5) s.display();
    } while (ch != 0);
}
