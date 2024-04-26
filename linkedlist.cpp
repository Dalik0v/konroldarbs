#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void append(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void printList() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr\n";
    }

    // Функция для разделения списка на две части
    void split(LinkedList& firstHalf, LinkedList& secondHalf) {
        Node* slow = head;
        Node* fast = head;
        Node* prev = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (prev != nullptr) {
            prev->next = nullptr;
        }

        firstHalf.head = head;
        secondHalf.head = slow;
    }
};

int main() {
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);

    std::cout << "Original list: ";
    list.printList();

    LinkedList firstHalf, secondHalf;
    list.split(firstHalf, secondHalf);

    std::cout << "First half: ";
    firstHalf.printList();

    std::cout << "Second half: ";
    secondHalf.printList();

    return 0;
}
