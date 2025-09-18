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
        Node*tmp = head;
        while(tmp != NULL){
            cout<<tmp->name<<"-$"<<tmp->price<<" , ";
            tmp = tmp->next;
        }
    }
    
    void Search(string n){
        Node* tmp = head;
        while(tmp != NULL){
            if(tmp->name == n){
                cout<<tmp->name<<"->"<<tmp->price<<endl;
                return;
            }
            tmp= tmp->next;
        }
        cout<<"Not Existed";
    }
};


int main(){

    Cart c;


    c.addEnd("Laptop", 1000);
    c.addEnd("Phone", 700);
    c.addEnd("Tablet", 400);
    c.addEnd("Headphones", 150);

    c.addStart("Smartwatch", 200);
    c.addEnd("Keyboard", 80);
    c.addAnypos("Monitor", 300, 3);

    cout << "Shopping Cart Items:\n";
    c.displayCart();

    cout << "\nSearching:\n";
    c.Search("Tablet");   
    c.Search("Camera");   

    return 0;
}

