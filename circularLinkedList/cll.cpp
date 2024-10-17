#include <iostream>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
    Node(int data){
        val = data;
        next = NULL;
    }
};

class cLL{
    public:
        Node* head;

    cLL(){
        head = NULL;
    }

    void display(){
        Node* temp = head;

        while(temp!=head){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    void insertAtHead( int val){
        Node* temp = new Node(val);

        if(head==NULL){
            head=temp;
            temp->next = head;
            return;
        }

        Node* curr = head;
        while(curr->next!=head){
            curr = curr->next;
        }
        curr->next = temp;
        temp->next = head;
        head = temp;
    }

    void insertAtTail(int val){
        Node* temp = new Node(val);

        if(head==NULL){
            head=temp;
            temp->next = head;
            return;
        }

        Node* curr = head;
        while(curr->next!=head){
            curr = curr->next;
        }
        curr->next = temp;
        temp->next = head;
    }

    void deleteAtHead(){
        if(head==NULL){
            return;
        }
        Node* temp = head;
        Node* curr = head;
        while(curr->next!=head){
            curr = curr->next;
        }
        head = head->next;
        curr->next = head;
        free(temp);
    }

    void deleteAtTail(){
        if(head==NULL){
            return;
        }
        Node* temp = head;
        Node* curr = head;
        while(curr->next->next!=head){
            curr = curr->next;
        }
        Node* del = curr->next;
        curr->next = head;
        free(temp);
    }
};

int main(){

    return 0;
}
