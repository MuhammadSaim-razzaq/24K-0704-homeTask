#include <iostream>
using namespace std;

class MinHeap {
public:
    int* arr;       
    int size;       
    int capacity;   

    MinHeap(int cap) {
        arr = new int[cap];
        size = 0;
        capacity = cap;
    }

    // Fix heap from bottom to top-------------
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;

            //------min-heap: parent <= child---
            if (arr[parent] > arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else break;
        }
    }

    void insert(int priority) {
        if (size == capacity) {
            cout << "Heap is full!\n";
            return;
        }

        //----1 Insert at last index------
        arr[size] = priority;

        //----2 Fix heap------------------
        heapifyUp(size);

        size++;
    }

    void printHeap() {
        cout << "Min Heap: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MinHeap heap(10);

    
    heap.insert(1);
    heap.insert(3);
    heap.insert(4);
    heap.insert(5);
    heap.insert(7);

    cout << "Before insertion: ";
    heap.printHeap();

    cout << "Inserting priority 2...\n";
    heap.insert(2);

    cout << "After insertion: ";
    heap.printHeap();

    return 0;
}
