#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;
    LinkedList() {
        head = nullptr;
    }

    void addFirst(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void deleteFirst() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void addRandom(int data) {
        if (head == nullptr) {
            addFirst(data);
            return;
        }
        Node* newNode = new Node(data);
        int pos = rand() % (size() + 1);
        if (pos == 0) {
            addFirst(data);
            return;
        }
        Node* curr = head;
        for (int i = 0; i < pos - 1; i++) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }

    void deleteRandom(int data) {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        if (head->data == data) {
            deleteFirst();
            return;
        }
        Node* curr = head;
        while (curr->next != nullptr && curr->next->data != data) {
            curr = curr->next;
        }
        if (curr->next == nullptr) {
            cout << "Element not found" << endl;
            return;
        }
        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }

    void addEnd(int data) {
        if (head == nullptr) {
            addFirst(data);
            return;
        }
        Node* newNode = new Node(data);
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
    }

    void deleteEnd() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        if (head->next == nullptr) {
            deleteFirst();
            return;
        }
        Node* curr = head;
        while (curr->next->next != nullptr) {
            curr = curr->next;
        }
        Node* temp = curr->next;
        curr->next = nullptr;
        delete temp;
    }

    int peek() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return -1;
        }
        return head->data;
    }

    int size() {
        int count = 0;
        Node* curr = head;
        while (curr != nullptr) {
            count++;
            curr = curr->next;
        }
        return count;
    }

    void print() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};
