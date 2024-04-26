#include <iostream>
#include <vector>

class Stack {
private:
    std::vector<int> data; 

public:
    
    void push(int value) {
        data.push_back(value);
    }

    
    void pop() {
        if (!data.empty()) {
            data.pop_back();
        } else {
            std::cout << "Stack is empty, nothing to pop.\n";
        }
    }

    int top() {
        if (!data.empty()) {
            return data.back();
        } else {
            std::cout << "Stack is empty.\n";
            return -1; 
        }
    }


    bool isEmpty() {
        return data.empty();
    }

 
    void printStack() {
        std::cout << "Stack from top to bottom: ";
        for (auto it = data.rbegin(); it != data.rend(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    Stack myStack;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.printStack(); 

    std::cout << "Top element: " << myStack.top() << "\n"; 

    myStack.pop();
    myStack.printStack(); 

    std::cout << "Is stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << "\n"; 
    return 0;
}
