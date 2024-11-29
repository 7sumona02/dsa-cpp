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

class dLL {
public:
    Node* head;
    Node* tail;
    int size;
    dLL() {
        head = tail = NULL;
        size = 0;
    }

    void insertAtHead(int val) {
        Node* temp = new Node(val);
        if (head == NULL) {
            head = tail = temp;
        } else {
            head->prev = temp;
            temp->next = head;
            head = temp;
        }
        size++;
    }

    void insertAtTail(int val) {
        Node* temp = new Node(val);
        if (head == NULL) {
            head = tail = temp;
        } else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        size++;
    }

    bool isEmpty() {
        return size == 0;
    }

    int deleteAtHead() {
        if (!isEmpty()) {
            Node* temp = head;
            int delValue = temp->val;

            if (head == tail) {
                head = tail = NULL;
            } else {
                head = head->next;
                head->prev = NULL;
            }

            delete temp;
            size--;
            return delValue;
        }
    }

    int deleteAtTail() {
        if (!isEmpty()) {
            Node* temp = tail;
            int delValue = temp->val;

            if (head == tail) {
                head = tail = NULL;
            } else {
                tail = tail->prev;
                tail->next = NULL;
            }

            delete temp;
            size--;
            return delValue;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void search(int x) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->val == x) {
                cout << "Found\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Not found\n";
    }

    Node* reverse(){
        Node* prev = NULL;
        Node* curr = head;
        Node* next;

        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

int main() {
    dLL d;
    int choice, val;

    while (true) {
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Delete at Head\n";
        cout << "4. Delete at Tail\n";
        cout << "5. Display\n";
        cout << "6. Search\n";
        cout << "7. Reverse\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> val;
            d.insertAtHead(val);
            break;
        case 2:
            cout << "Enter value to insert: ";
            cin >> val;
            d.insertAtTail(val);
            break;
        case 3:
            d.deleteAtHead();
            break;
        case 4:
            d.deleteAtTail();
            break;
        case 5:
            d.display();
            break;
        case 6:
            cout << "Enter value to search: ";
            cin >> val;
            d.search(val);
            break;
        case 7:
            cout << "reversed: ";
            d.reverse();
            break;
        case 8:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } 

    return 0;
}