#include <iostream>

class Node {
public:
    int data;
    Node* next;
};

Node* front = nullptr;
Node* rear = nullptr;

bool isEmpty();
void enqueue();
void dequeue();
void display();

int main() {

}

bool isEmpty() {
    if (front == nullptr) return true;
    return false;
}