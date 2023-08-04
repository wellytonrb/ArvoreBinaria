#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class list {
private:
    Node* head;
    Node* tail;
    int size;

public:
    list() : head(nullptr), tail(nullptr), size(0) {}
    
             // complexidade     o (1)
    void insertNode(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            if (value < head->data) {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            } else if (value >= tail->data) {
                newNode->prev = tail;
                tail->next = newNode;
                tail = newNode;
            } else {
                Node* current = head->next;
                while (current->data < value) {
                    current = current->next;
                }

                newNode->prev = current->prev;
                newNode->next = current;
                current->prev->next = newNode;
                current->prev = newNode;
            }
        }

        size++;
    }

    void descprint() const {
        Node* current = tail;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->prev;
        }
        std::cout << std::endl;
    }

    void cresprint() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    int sizget() const {
        return size;
    }
};

int main() {
    list list;

    list.insertNode(20);
    list.insertNode(10);
    list.insertNode(30);
    list.insertNode(45);
    list.insertNode(9);
    list.insertNode(7);

    std::cout << "Tamanho da lista: " << list.sizget() << std::endl;

    std::cout << "Lista em ordem crescente: ";
    list.cresprint();

    std::cout << "Lista em ordem decrescente: ";
    list.descprint();

    return 0;
}
