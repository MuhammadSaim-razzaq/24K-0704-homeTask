#include<iostream>
using namespace std;

class Node {
public:
    int id;
    string name;
    int price;
    Node* prev;
    Node* next;

    Node(int i, string n, int p) {
        id = i;
        name = n;
        price = p;
        prev = NULL;
        next = NULL;
    }
};

class Cart {
public:
    Node* head;
    Node* tail;

    Cart() {
        head = NULL;
        tail = NULL;
    }

    void insertEnd(int id, string name, int price) {
        Node* newN = new Node(id, name, price);
        if(head == NULL) {
            head = tail = newN;
            return;
        }
        tail->next = newN;
        newN->prev = tail;
        tail = newN;
    }

    void insertFront(int id, string name, int price) {
        Node* newN = new Node(id, name, price);
        if(head == NULL) {
            head = tail = newN;
            return;
        }
        newN->next = head;
        head->prev = newN;
        head = newN;
    }

    void removeFront() {
        if(head == NULL) {
            cout << "Cart is empty, nothing to delete!\n";
            return;
        }
        Node* tmp = head;
        if(head == tail) {
            head = tail = NULL;
        } else {
            head = head->next;
            head->prev = NULL;
        }
        delete tmp;
        cout << "First item removed.\n";
    }

    void removeEnd() {
        if(tail == NULL) {
            cout << "Cart is empty, nothing to delete!\n";
            return;
        }
        Node* tmp = tail;
        if(head == tail) {
            head = tail = NULL;
        } else {
            tail = tail->prev;
            tail->next = NULL;
        }
        delete tmp;
        cout << "Last item removed.\n";
    }

    void searchByID(int id) {
        Node* tmp = head;
        while(tmp != NULL) {
            if(tmp->id == id) {
                cout << "Item Found -> ID: " << tmp->id 
                     << ", Name: " << tmp->name 
                     << ", Price: $" << tmp->price << endl;
                return;
            }
            tmp = tmp->next;
        }
        cout << "Item with ID " << id << " not found.\n";
    }

    void updatePrice(int id, int newPrice) {
        Node* tmp = head;
        while(tmp != NULL) {
            if(tmp->id == id) {
                tmp->price = newPrice;
                cout << "Price updated for ID " << id 
                     << ". New Price: $" << tmp->price << endl;
                return;
            }
            tmp = tmp->next;
        }
        cout << "Item with ID " << id << " not found.\n";
    }

    void displayForward() {
        if(head == NULL) {
            cout << "Cart is empty.\n";
            return;
        }
        Node* tmp = head;
        cout << "Cart (Front -> End):\n";
        while(tmp != NULL) {
            cout << "[ID: " << tmp->id << ", " << tmp->name 
                 << ", $" << tmp->price << "] -> ";
            tmp = tmp->next;
        }
        cout << "NULL\n";
    }

    void displayBackward() {
        if(tail == NULL) {
            cout << "Cart is empty.\n";
            return;
        }
        Node* tmp = tail;
        cout << "Cart (End -> Front):\n";
        while(tmp != NULL) {
            cout << "[ID: " << tmp->id << ", " << tmp->name 
                 << ", $" << tmp->price << "] -> ";
            tmp = tmp->prev;
        }
        cout << "NULL\n";
    }

    int countItems() {
        int count = 0;
        Node* tmp = head;
        while(tmp != NULL) {
            count++;
            tmp = tmp->next;
        }
        return count;
    }

    void mostExpensiveItem() {
        if(head == NULL) {
            cout << "Cart is empty.\n";
            return;
        }
        Node* tmp = head;
        Node* maxItem = head;
        while(tmp != NULL) {
            if(tmp->price > maxItem->price) {
                maxItem = tmp;
            }
            tmp = tmp->next;
        }
        cout << "Most Expensive Item -> ID: " << maxItem->id 
             << ", Name: " << maxItem->name 
             << ", Price: $" << maxItem->price << endl;
    }
};

int main() {
    Cart c;

    c.insertEnd(101, "Laptop", 1000);
    c.insertEnd(102, "Phone", 700);
    c.insertEnd(103, "Tablet", 400);
    c.insertEnd(104, "Headphones", 150);

    c.insertFront(100, "Smartwatch", 200);

    c.displayForward();
    c.displayBackward();

    c.searchByID(102);
    c.updatePrice(103, 450);

    c.removeFront();
    c.removeEnd();
    c.displayForward();

    cout << "Total items in cart: " << c.countItems() << endl;
    c.mostExpensiveItem();

    return 0;
}
