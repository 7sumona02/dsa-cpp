// stack using queue
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

class StackQueue {
private:
    Node* front;
    Node* rear;

public:
    StackQueue() {
        front = rear = NULL;
    }

    void push(int data) {
        Node* newNode = new Node(data);
        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int pop() {
        if (front == NULL) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        int data = front->data;
        Node* temp = front;
        front = front->next;
        if (front == NULL) {
            rear = NULL; // If the queue becomes empty
        }
        delete temp;
        return data;
    }

    int peek() {
        if (front == NULL) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return front->data;
    }

    bool isEmpty() {
        return front == NULL; // Returns true if stack is empty
    }

    void print() {
        if (front == NULL) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    StackQueue s; // Create an instance of StackQueue
    int choice, value;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Check if Stack is Empty\n";
        cout << "5. Print Stack\n";
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
                s.print();
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