#include <iostream>

class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }

};

Node *front = nullptr;
Node *rear = nullptr;

bool isEmpty();
void enqueue(int);
void dequeue();
void display();

int main() {

    enqueue(14);
    enqueue(22);
    enqueue(13);
    enqueue(-6);
    dequeue();
    dequeue();

    display();

}

bool isEmpty() {
    if (front == nullptr) return true;
    return false;
}

void enqueue(int data) {
    Node *newNode = new Node(data);
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

void dequeue() {
    if (isEmpty()) {
        std::cout << "Can't dequeue. Queue is empty\n";
        return;
    }
    if (front == rear) {
        delete front;
        front = nullptr;
        rear = nullptr;
        return;
    }
    Node *temp = front;
    front = front->next;
    rear->next = front;
    delete temp;
}

void display() {
    Node *current = front;
    if (current == nullptr) return;
    do {
        std::cout << current->data << " ";
        current = current->next;
    } while (current != front);
}