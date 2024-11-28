#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;       // Array to hold the stack elements
    int top;        // Index of the top element
    int capacity;   // Maximum number of elements in the stack

public:
    // Constructor to initialize the stack
    Stack(int size) {
        arr = new int[size]; // Dynamic array allocation
        capacity = size;
        top = -1; // Stack is initially empty
    }

    // Function to add an item to the stack
    void push(int data) {
        if (isFull()) {
            cout << "Stack Overflow! Unable to push " << data << endl;
            return;
        }
        arr[++top] = data; // Increment top and add data
        cout << data << " pushed onto stack." << endl;
    }

    // Function to remove an item from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Unable to pop." << endl;
            return -1; // Return -1 for underflow condition
        }
        return arr[top--]; // Return top item and decrement top
    }

    // Function to return the top item from the stack without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1; // Return -1 if stack is empty
        }
        return arr[top]; // Return the top item
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == -1; // True if top is -1
    }

    // Function to check if the stack is full
    bool isFull() {
        return top == capacity - 1; // True if top equals capacity - 1
    }

    // Destructor to free allocated memory
    ~Stack() {
        delete[] arr; // Free dynamically allocated memory
    }
};

int main() {
    Stack s(5); // Create a stack of capacity 5

    int choice, value;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Check if Stack is Empty\n";
        cout << "5. Check if Stack is Full\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;

            case 2:
                value = s.pop();
                if (value != -1) // Only print if a valid pop occurred
                    cout << "Popped element: " << value << endl;
                break;

            case 3:
                value = s.peek();
                if (value != -1) // Only print if stack is not empty
                    cout << "Top element: " << value << endl;
                break;

            case 4:
                if (s.isEmpty()) {
                    cout << "Stack is empty" << endl;
                } else {
                    cout << "Stack is not empty" << endl;
                }
                break;

            case 5:
                if (s.isFull()) {
                    cout << "Stack is full" << endl;
                } else {
                    cout << "Stack is not full" << endl;
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