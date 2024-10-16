#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int data) {
        val = data;
        next = NULL;
    }
};

class cLL {
public:
    Node* head;

    cLL() {
        head = NULL;
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->val << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    void insertAtHead(int val) {
        Node* temp = new Node(val);
        if (head == NULL) {
            head = temp;
            temp->next = head;
            return;
        }

        Node* curr = head;
        while (curr->next != head) {
            curr = curr->next;
        }
        curr->next = temp;
        temp->next = head;
        head = temp;
    }

    void insertAtTail(int val) {
        Node* temp = new Node(val);
        if (head == NULL) {
            head = temp;
            temp->next = head;
            return;
        }

        Node* curr = head;
        while (curr->next != head) {
            curr = curr->next;
        }
        curr->next = temp;
        temp->next = head;
    }

    void deleteAtHead() {
        if (head == NULL) {
            cout << "List is empty. Cannot delete.\n";
            return;
        }

        if (head->next == head) {
            // Only one node in the list
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        Node* curr = head;
        while (curr->next != head) {
            curr = curr->next;
        }
        head = head->next;
        curr->next = head;
        delete temp;
    }

    void deleteAtTail() {
        if (head == NULL) {
            cout << "List is empty. Cannot delete.\n";
            return;
        }

        if (head->next == head) {
            // Only one node in the list
            delete head;
            head = NULL;
            return;
        }

        Node* curr = head;
        while (curr->next->next != head) {
            curr = curr->next;
        }
        Node* del = curr->next;
        curr->next = head;
        delete del;
    }

    void reverse() {
        if (head == NULL || head->next == head) {
            // Empty list or single node
            return;
        }

        Node *prev = NULL, *current = head, *nextNode = NULL;
        Node* tail = head;  // Keep track of the tail

        do {
            nextNode = current->next;  // Store the next node
            current->next = prev;       // Reverse the link
            prev = current;              // Move prev to current
            current = nextNode;          // Move to next node
        } while (current != head);

        head->next = prev;  // Complete the circular link
        head = prev;        // Update head to the new head (tail before reversal)
    }
};

int main() {
    cLL c;
    int choice, val;

    do {
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Delete at Head\n";
        cout << "4. Delete at Tail\n";
        cout << "5. Display\n";
        cout << "6. Reverse\n"; // Option to reverse the list
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                c.insertAtHead(val);
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> val;
                c.insertAtTail(val);
                break;
            case 3:
                c.deleteAtHead();
                break;
            case 4:
                c.deleteAtTail();
                break;
            case 5:
                c.display();
                break;
            case 6:
                c.reverse(); // Call the reverse function
                cout << "List reversed.\n";
                break;
            case 7:
                cout << "Exiting\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 7);

    return 0;
}