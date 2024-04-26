#include <iostream>
#include <stack>

class Queue {
private:
    std::stack<int> enqueueStack;  
    std::stack<int> dequeueStack;  

   
    void transferStacks() {
        while (!enqueueStack.empty()) {
            dequeueStack.push(enqueueStack.top());
            enqueueStack.pop();
        }
    }

public:
    
    void enqueue(int x) {
        enqueueStack.push(x);
    }

   
    int dequeue() {
        if (dequeueStack.empty()) {
            if (enqueueStack.empty()) {
                std::cerr << "Queue is empty, cannot dequeue\n";
                return -1; 
            }
            transferStacks();
        }
        int x = dequeueStack.top();
        dequeueStack.pop();
        return x;
    }

    
    int front() {
        if (dequeueStack.empty()) {
            if (enqueueStack.empty()) {
                std::cerr << "Queue is empty\n";
                return -1;  
            }
            transferStacks();
        }
        return dequeueStack.top();
    }

    
    bool empty() {
        return enqueueStack.empty() && dequeueStack.empty();
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    std::cout << "Dequeue: " << q.dequeue() << std::endl;  
    std::cout << "Front: " << q.front() << std::endl;  
    q.enqueue(4);
    std::cout << "Dequeue: " << q.dequeue() << std::endl;  
    std::cout << "Dequeue: " << q.dequeue() << std::endl;  
    std::cout << "Dequeue: " << q.dequeue() << std::endl;  
    std::cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << std::endl;  
    return 0;
}
