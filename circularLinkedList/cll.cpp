#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* prev;
    Node(int data) {
        val = data;
        next = NULL;
        prev = NULL;
    }
};

void insertAtHead(Node* &head, int val) {
    Node* temp = new Node(val);
    if (head == NULL) {
        head = temp;
        head->next = head;
        head->prev = head;
        return;
    }

    Node* tail = head->prev;

    temp->next = head;
    temp->prev = tail;
    head->prev = temp;
    tail->next = temp;
    head = temp;
}

void insertAtTail(Node* &head, int val) {
    Node* temp = new Node(val);
    if (head == NULL) {
        head = temp;
        head->next = head;
        head->prev = head;
        return;
    }

    Node* tail = head->prev;

    tail->next = temp;
    temp->prev = tail;
    temp->next = head;
    head->prev = temp;
}

void deleteAtHead(Node* &head) {
    if (head == NULL) {
        return;
    }
    if (head->next == head) {
        delete head;
        head = NULL;
        return;
    }

    Node* tail = head->prev;
    Node* temp = head;

    head = head->next;
    head->prev = tail;
    tail->next = head;
    delete temp;
}

void deleteAtTail(Node* &head) {
    if (head == NULL) {
        return;
    }
    if (head->next == head) {
        delete head;
        head = NULL;
        return;
    }

    Node* tail = head->prev;
    Node* newTail = tail->prev;

    newTail->next = head;
    head->prev = newTail;
    delete tail;
}

void insertAtPos(Node* &head, int val, int pos) {
    if (pos == 0) {
        insertAtHead(head, val);
        return;
    }

    Node* temp = head;
    int curr = 1;
    while (curr < pos && temp->next != head) {
        temp = temp->next;
        curr++;
    }

    if (curr < pos) {
        cout << "Position out of bounds" << endl;
        return;
    }

    Node* newNode = new Node(val);
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
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
    while (curr < pos && temp->next != head) {
        temp = temp->next;
        curr++;
    }

    if (temp->next == head || curr < pos) {
        cout << "Position out of bounds" << endl;
        return;
    }

    Node* del = temp->next;
    temp->next = del->next;
    del->next->prev = temp;
    delete del;
}

void search(Node* head, int x) {
    if (head == NULL) {
        cout << "Element not found" << endl;
        return;
    }

    Node* curr = head;
    do {
        if (curr->val == x) {
            cout << "Element found" << endl;
            return;
        }
        curr = curr->next;
    } while (curr != head);

    cout << "Element not found" << endl;
}

void display(Node* head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->val << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

void reverse(Node* &head) {
    if (head == NULL || head->next == head) {
        return;
    }

    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    do {
        next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
    } while (curr != head);

    head->next = prev;
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
            cout << "The circular doubly linked list is: ";
            display(head);
            break;
        case 9:
            reverse(head);
            cout << "Reversed the circular doubly linked list.\n";
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