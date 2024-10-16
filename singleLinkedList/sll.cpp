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
    insertAtHead(head, 6);
    insertAtHead(head, 2);
    insertAtTail(head, 5);
    deleteAtHead(head);
    deleteAtTail(head);
    insertAtPos(head, 3, 1);
    deleteAtPos(head, 1);
    reverse(head);
    display(head);
    search(head, 3);
    search(head, 7);

    return 0;
}