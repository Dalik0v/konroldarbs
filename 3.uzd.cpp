#include <iostream>
#include <stack>

class Queue {
private:
    std::stack<int> enqueueStack;  // Stack used for enqueue operations
    std::stack<int> dequeueStack;  // Stack used for dequeue operations

    // Helper function to move elements from enqueueStack to dequeueStack
    void transferStacks() {
        while (!enqueueStack.empty()) {
            dequeueStack.push(enqueueStack.top());
            enqueueStack.pop();
        }
    }

public:
    // Enqueue element x to the back of the queue
    void enqueue(int x) {
        enqueueStack.push(x);
    }

    // Dequeue the front element from the queue
    int dequeue() {
        if (dequeueStack.empty()) {
            if (enqueueStack.empty()) {
                std::cerr << "Queue is empty, cannot dequeue\n";
                return -1;  // or throw an exception
            }
            transferStacks();
        }
        int x = dequeueStack.top();
        dequeueStack.pop();
        return x;
    }

    // Get the front element
    int front() {
        if (dequeueStack.empty()) {
            if (enqueueStack.empty()) {
                std::cerr << "Queue is empty\n";
                return -1;  // or throw an exception
            }
            transferStacks();
        }
        return dequeueStack.top();
    }

    // Check if the queue is empty
    bool empty() {
        return enqueueStack.empty() && dequeueStack.empty();
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    std::cout << "Dequeue: " << q.dequeue() << std::endl;  // Outputs 1
    std::cout << "Front: " << q.front() << std::endl;  // Outputs 2
    q.enqueue(4);
    std::cout << "Dequeue: " << q.dequeue() << std::endl;  // Outputs 2
    std::cout << "Dequeue: " << q.dequeue() << std::endl;  // Outputs 3
    std::cout << "Dequeue: " << q.dequeue() << std::endl;  // Outputs 4
    std::cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << std::endl;  // Outputs Yes
    return 0;
}
