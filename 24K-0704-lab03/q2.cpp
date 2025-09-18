#include<iostream>
using namespace std;
class Node{
public:
    string name;
    int price;
    Node* next;

    Node(){
        name = "";
        price = 0;
        next = NULL;
    }

    Node(string name, int price){
        this->name = name;
        this->price = price;
        this->next = NULL;
    }
};

class Cart{
    public: 
        Node* head;

    Cart(){ head = NULL;}

    void addStart(string n, int p){
        if(head==NULL){
            Node* newN = new Node(n,p);
            head = newN;
            return;
        }
        Node* newN = new Node(n,p);
        newN->next = head;
        head = newN;
    }

    void addEnd(string n, int p){
        if(head == NULL){
            Node* newN = new Node(n,p);
            head = newN;
            return;
        }
        Node*newN = new Node(n,p);
        Node*tmp = head;
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next= newN;
    }

    void addAnypos(string n, int p,int pos){
        if(head== NULL){
            Node*newN = new Node(n,p);
            head = newN;
            return;
        }
        Node*tmp = head;
        for(int i=1; i<pos -1 && tmp->next != NULL; i++){
            tmp = tmp->next;
        }
        if(tmp == NULL || tmp->next == NULL){
            addEnd(n,p);
            return;
        }
        Node*newN = new Node(n,p);
        newN->next= tmp->next;
        tmp->next = newN;
    }

    void displayCart(){
        if(head == NULL){
           cout << "Cart is empty!\n";
           return;
        }
        Node*tmp = head;
        while(tmp != NULL){
            cout<<tmp->name<<"-$"<<tmp->price<<" , ";
            tmp = tmp->next;
        }
    }
    
    void searchByName(string n){
        Node* tmp = head;
        int pos = 1;
        while(tmp != NULL){
            if(tmp->name == n){
                cout << "Item found at position " << pos 
                    << " -> " << tmp->name << " - $" << tmp->price << endl;
                return;
            }
            pos++;
            tmp = tmp->next;
        }
        cout << "Item '" << n << "' not found in cart.\n";
    }

    void deleteFront(){
        if(head == NULL){
            cout << "Cart is empty, nothing to delete!\n";
            return;
        }
        Node* tmp = head;
        head = head->next;
        delete tmp;  
    }

    void addTail(string n, int p){
        Node* newN = new Node(n, p);
        if(head == NULL){  
            head = newN;
            return;
        }
        Node* tmp = head;
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = newN;
    }

    void searchByPosition(int pos){
        if(pos <= 0){
            cout << "Invalid position!\n";
            return;
        }

        Node* tmp = head;
        for(int i = 1; i < pos && tmp != NULL; i++){
            tmp = tmp->next;
        }

        if(tmp == NULL){
            cout << "No item at that position.\n";
        } else {
            cout << "Item found -> " << tmp->name << " - $" << tmp->price << endl;
        }
    }

};


int main(){

   Cart c;

    c.addTail("Laptop", 1000);
    c.addTail("Phone", 700);
    c.addTail("Tablet", 400);
    c.addTail("Headphones", 150);


    c.displayCart();
    cout << "--------------------\n";


    c.searchByName("Phone");
    c.searchByName("Camera");
    cout << "--------------------\n";

    
    c.searchByPosition(3);
    c.searchByPosition(6);
    cout << "--------------------\n";


    c.deleteFront();
    c.displayCart();

    return 0;
}

