#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Order {
    string item;
    int qty;
};

int main() {
    queue<Order> q;
    int ch;
    do {
        cout << "1.Add Order 2.Process Order 3.Show Orders 0.Exit\n";
        cin >> ch;
        if (ch == 1) {
            Order o;
            cout << "Item:"; cin >> o.item;
            cout << "Quantity:"; cin >> o.qty;
            q.push(o);
        } else if (ch == 2) {
            if (!q.empty()) q.pop();
        } else if (ch == 3) {
            queue<Order> temp = q;
            while (!temp.empty()) {
                Order o = temp.front();
                cout << o.item << " x" << o.qty << endl;
                temp.pop();
            }
        }
    } while (ch != 0);
}
