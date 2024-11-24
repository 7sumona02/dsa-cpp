#include <iostream>
using namespace std;

class Heap {
protected: // Changed from private to protected
    int* arr;       // Array to store the heap
    int capacity;   // Maximum capacity of the heap
    int size;       // Current number of elements in the heap

    // Function to heapify a subtree rooted at index `i`
    void heapify(int i) {
        int largest = i;          // Initialize largest as root
        int left = 2 * i + 1;     // Left child
        int right = 2 * i + 2;    // Right child

        // Check if left child is larger than root
        if (left < size && arr[left] > arr[largest]) {
            largest = left;
        }

        // Check if right child is larger than the largest so far
        if (right < size && arr[right] > arr[largest]) {
            largest = right;
        }

        // If largest is not root
        if (largest != i) {
            swap(arr[i], arr[largest]); // Swap and recursively heapify
            heapify(largest);
        }
    }

public:
    // Constructor
    Heap(int cap) {
        capacity = cap;
        size = 0;
        arr = new int[cap];
    }

    // Destructor
    ~Heap() {
        delete[] arr;
    }

    // Function to insert a new element into the heap
    void insert(int value) {
        if (size == capacity) {
            cout << "Heap is full. Cannot insert " << value << ".\n";
            return;
        }

        // Insert at the end
        size++;
        int i = size - 1;
        arr[i] = value;

        // Move up to maintain heap property
        while (i != 0 && arr[(i - 1) / 2] < arr[i]) {
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    // Function to delete the root of the heap
    void deleteRoot() {
        if (size == 0) {
            cout << "Heap is empty. Cannot delete.\n";
            return;
        }

        // Replace root with the last element
        arr[0] = arr[size - 1];
        size--;

        // Restore the heap property
        heapify(0);
    }

    // Function to perform heap sort
    void heapSort() {
        int originalSize = size; // Save original size

        // Build a max-heap
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(i);
        }

        // Extract elements from the heap one by one
        for (int i = size - 1; i > 0; i--) {
            swap(arr[0], arr[i]); // Move current root to the end
            size--;
            heapify(0);          // Restore heap property
        }

        size = originalSize; // Restore original size
    }

    // Display the heap
    void display() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Priority Queue using the Heap class
class PriorityQueue : public Heap {
public:
    PriorityQueue(int cap) : Heap(cap) {}

    // Function to get the maximum element
    int getMax() {
        if (size == 0) {
            cout << "Priority queue is empty.\n";
            return -1;
        }
        return arr[0];
    }
};

int main() {
    // Example usage
    Heap heap(10);

    // Insert elements
    heap.insert(10);
    heap.insert(20);
    heap.insert(15);
    heap.insert(40);
    heap.insert(50);
    heap.insert(100);
    heap.insert(25);
    heap.insert(45);

    cout << "Heap after insertions: ";
    heap.display();

    // Delete root
    heap.deleteRoot();
    cout << "Heap after deleting root: ";
    heap.display();

    // Heap sort
    heap.heapSort();
    cout << "Heap after heap sort: ";
    heap.display();

    // Priority Queue example
    PriorityQueue pq(10);
    pq.insert(5);
    pq.insert(15);
    pq.insert(10);

    cout << "Priority Queue max element: " << pq.getMax() << endl;

    return 0;
}