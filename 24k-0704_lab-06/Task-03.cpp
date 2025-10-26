#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct Node {
    string site;
    Node* next;
    Node(string s) : site(s), next(NULL) {}
};

int main() {
    string sites[] = {"Google", "Facebook", "Twitter", "LinkedIn", "Instagram"};
    Node* head = NULL;
    stack<string> st;

    for (int i = 4; i >= 0; i--) {
        Node* n = new Node(sites[i]);
        n->next = head;
        head = n;
        st.push(sites[i]);
    }

    st.pop(); st.pop();
    head = head->next->next;

    cout << "Current Page: " << head->site;
}
