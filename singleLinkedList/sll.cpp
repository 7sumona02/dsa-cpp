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

void insertAtHead(Node* &head, int val) {
    Node* temp = new Node(val);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &head, int val) {
    Node* temp = new Node(val);
    if (head == NULL) {
        head = temp;
        return;
    }

    Node* curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = temp;
}

void deleteAtHead(Node* &head) {
    if (head == NULL) {
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteAtTail(Node* &head) {
    if (head == NULL) {
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

void insertAtPos(Node* &head, int val, int pos) {
    if (pos == 0) {
        insertAtHead(head, val);
        return;
    }

    Node* temp = head;
    int curr = 1;
    while (curr < pos && temp != NULL) {
        temp = temp->next;
        curr++;
    }

    if (temp == NULL) {
        cout << "Position out of bounds" << endl;
        return;
    }

    Node* newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtPos(Node* &head, int pos) {
    if (head == NULL) {
        return;
    }
    if (pos == 0) {
        deleteAtHead(head);
        return;
    }

    Node* temp = head;
    int curr = 1;
    while (curr < pos && temp->next != NULL) {
        temp = temp->next;
        curr++;
    }

    if (temp->next == NULL) {
        cout << "Position out of bounds" << endl;
        return;
    }

    Node* del = temp->next;
    temp->next = temp->next->next;
    delete del;
}

void search(Node* head, int x) {
    Node* curr = head;
    while (curr != NULL) {
        if (curr->val == x) {
            cout << "Element found" << endl;
            return;
        }
        curr = curr->next;
    }
    cout << "Element not found" << endl;
}

void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

void reverse(Node* &head) {
    Node* prev = NULL;
    Node* curr = head;
    while (curr != NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

int main() {
    Node* head = NULL;
    int choice, value, position;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete at Head\n";
        cout << "5. Delete at Tail\n";
        cout << "6. Delete at Position\n";
        cout << "7. Search for an Element\n";
        cout << "8. Display the List\n";
        cout << "9. Reverse the List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert at head: ";
            cin >> value;
            insertAtHead(head, value);
            break;
        case 2:
            cout << "Enter value to insert at tail: ";
            cin >> value;
            insertAtTail(head, value);
            break;
        case 3:
            cout << "Enter value to insert: ";
            cin >> value;
            cout << "Enter position to insert at: ";
            cin >> position;
            insertAtPos(head, value, position);
            break;
        case 4:
            deleteAtHead(head);
            cout << "Deleted the head element.\n";
            break;
        case 5:
            deleteAtTail(head);
            cout << "Deleted the tail element.\n";
            break;
        case 6:
            cout << "Enter position to delete: ";
            cin >> position;
            deleteAtPos(head, position);
            break;
        case 7:
            cout << "Enter value to search: ";
            cin >> value;
            search(head, value);
            break;
        case 8:
            cout << "The linked list is: ";
            display(head);
            break;
        case 9:
            reverse(head);
            cout << "Reversed the linked list.\n";
            break;
        case 0:
            cout << "Exiting program.\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}