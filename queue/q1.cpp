// queue using array

#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;       // Array to hold the queue elements
    int front;      // Index of the front element
    int rear;       // Index of the rear element
    int capacity;   // Maximum number of elements in the queue
    int size;       // Current number of elements in the queue

public:
    // Constructor to initialize the queue
    Queue(int size) {
        arr = new int[size]; // Dynamic array allocation
        capacity = size;
        front = 0;
        rear = -1;
        this->size = 0; // Initialize size to 0
    }

    // Function to add an item to the queue
    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue Overflow! Unable to enqueue " << data << endl;
            return;
        }
        rear = (rear + 1) % capacity; // Circular increment
        arr[rear] = data; // Add data to the rear
        size++; // Increment size
        cout << data << " enqueued to queue." << endl;
    }

    // Function to remove an item from the queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Unable to dequeue." << endl;
            return -1; // Return -1 for underflow condition
        }
        int data = arr[front]; // Get front item
        front = (front + 1) % capacity; // Circular increment
        size--; // Decrement size
        return data; // Return dequeued item
    }

    // Function to return the front item from the queue without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1; // Return -1 if queue is empty
        }
        return arr[front]; // Return front item
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return size == 0; // True if size is 0
    }

    // Function to check if the queue is full
    bool isFull() {
        return size == capacity; // True if size equals capacity
    }

    // Destructor to free allocated memory
    ~Queue() {
        delete[] arr; // Free dynamically allocated memory
    }
};

int main() {
    Queue q(5); // Create a queue of capacity 5

    int choice, value;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Check if Queue is Empty\n";
        cout << "5. Check if Queue is Full\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                value = q.dequeue();
                if (value != -1) // Only print if a valid dequeue occurred
                    cout << "Dequeued element: " << value << endl;
                break;

            case 3:
                value = q.peek();
                if (value != -1) // Only print if queue is not empty
                    cout << "Front element: " << value << endl;
                break;

            case 4:
                if (q.isEmpty()) {
                    cout << "Queue is empty" << endl;
                } else {
                    cout << "Queue is not empty" << endl;
                }
                break;

            case 5:
                if (q.isFull()) {
                    cout << "Queue is full" << endl;
                } else {
                    cout << "Queue is not full" << endl;
                }
                break;

            case 6:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } 

    return 0;
}