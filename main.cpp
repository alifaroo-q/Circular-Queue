#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }

};

Node* front = nullptr;
Node* rear = nullptr;

bool isEmpty();
void enqueue(int);
void dequeue();
void display();

int main() {

    enqueue(20);
    enqueue(30);
    enqueue(42);
    enqueue(12);

    display();

}

bool isEmpty() {
    if (front == nullptr) return true;
    return false;
}

void enqueue(int data) {
    Node* newNode = new Node(data);
    if (isEmpty()) {
        front = newNode;
        newNode->next = front;
        rear = newNode;
        return;
    }
    rear->next = newNode;
    newNode->next = front;
    rear = newNode;
}

void display() {
    Node* current = front;
    do {
        std::cout << current->data << " ";
        current = current->next;
    } while (current != front);
}