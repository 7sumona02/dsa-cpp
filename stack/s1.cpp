// stack using linked list

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

class Stack {
public:
    Node* top;
    
    Stack() {
        top = NULL;
    }

    void push(int data) {
        Node* new_node = new Node(data);
        if (top == NULL) {
            top = new_node;
        } else {
            new_node->next = top;
            top = new_node;
        }
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack is empty" << endl;
        } else {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    int peek() {
        if (top == NULL) {
            cout << "Stack is empty" << endl;
            return -1; // Return -1 to indicate empty stack
        } else {
            return top->data;
        }
    }

    bool isEmpty() {
        return top == NULL; // Simplified return statement
    }
};

int main() {
    Stack s;
    int choice, value;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Check if Stack is Empty\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;

            case 2:
                s.pop();
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
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}