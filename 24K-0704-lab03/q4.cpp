#include<iostream>
using namespace std;

class Node {
public:
    int ticketID;
    string customerName;
    string rideName;
    Node* next;

    Node(int id, string cname, string rname) {
        ticketID = id;
        customerName = cname;
        rideName = rname;
        next = NULL;
    }
};

class TicketSystem {
public:
    Node* head;
    Node* tail;

    TicketSystem() {
        head = NULL;
        tail = NULL;
    }

    void issueEnd(int id, string cname, string rname) {
        Node* newN = new Node(id, cname, rname);
        if(head == NULL) {
            head = tail = newN;
            newN->next = head;
            return;
        }
        tail->next = newN;
        newN->next = head;
        tail = newN;
    }

    void issueFront(int id, string cname, string rname) {
        Node* newN = new Node(id, cname, rname);
        if(head == NULL) {
            head = tail = newN;
            newN->next = head;
            return;
        }
        newN->next = head;
        head = newN;
        tail->next = head;
    }

    void cancelByID(int id) {
        if(head == NULL) return;
        Node* curr = head;
        Node* prev = tail;

        do {
            if(curr->ticketID == id) {
                if(curr == head) {
                    head = head->next;
                    tail->next = head;
                } else if(curr == tail) {
                    tail = prev;
                    tail->next = head;
                } else {
                    prev->next = curr->next;
                }
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        } while(curr != head);
    }

    void cancelFirst() {
        if(head == NULL) return;
        Node* tmp = head;
        if(head == tail) {
            head = tail = NULL;
        } else {
            head = head->next;
            tail->next = head;
        }
        delete tmp;
    }

    void searchByID(int id) {
        if(head == NULL) return;
        Node* tmp = head;
        do {
            if(tmp->ticketID == id) {
                cout << "Ticket Found -> ID: " << tmp->ticketID 
                     << ", Customer: " << tmp->customerName 
                     << ", Ride: " << tmp->rideName << endl;
                return;
            }
            tmp = tmp->next;
        } while(tmp != head);
        cout << "Ticket with ID " << id << " not found.\n";
    }

    void displayTickets() {
        if(head == NULL) {
            cout << "No tickets booked.\n";
            return;
        }
        Node* tmp = head;
        cout << "Tickets (Circular Order):\n";
        do {
            cout << "[ID: " << tmp->ticketID << ", " 
                 << tmp->customerName << ", " 
                 << tmp->rideName << "] -> ";
            tmp = tmp->next;
        } while(tmp != head);
        cout << "(back to start)\n";
    }

    int countTickets() {
        if(head == NULL) return 0;
        int count = 0;
        Node* tmp = head;
        do {
            count++;
            tmp = tmp->next;
        } while(tmp != head);
        return count;
    }

    void nextTicket(int id) {
        if(head == NULL) return;
        Node* tmp = head;
        do {
            if(tmp->ticketID == id) {
                Node* nxt = tmp->next;
                cout << "Next Ticket -> ID: " << nxt->ticketID 
                     << ", Customer: " << nxt->customerName 
                     << ", Ride: " << nxt->rideName << endl;
                return;
            }
            tmp = tmp->next;
        } while(tmp != head);
        cout << "Ticket with ID " << id << " not found.\n";
    }
};

int main() {
    TicketSystem t;

    t.issueEnd(1, "Ali", "RollerCoaster");
    t.issueEnd(2, "Sara", "FerrisWheel");
    t.issueEnd(3, "Omar", "HauntedHouse");

    t.issueFront(0, "VIP-John", "RollerCoaster");

    t.displayTickets();
    cout << "Total tickets: " << t.countTickets() << endl;

    t.searchByID(2);

    t.nextTicket(2);

    t.cancelByID(3);
    t.cancelFirst();

    t.displayTickets();
    cout << "Total tickets: " << t.countTickets() << endl;

    return 0;
}
