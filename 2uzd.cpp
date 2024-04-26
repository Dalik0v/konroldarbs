#include <iostream>
#include <vector>

class Stack {
private:
    std::vector<int> data; // Используем вектор для хранения элементов стека

public:
    // Добавление элемента на вершину стека
    void push(int value) {
        data.push_back(value);
    }

    // Удаление элемента с вершины стека
    void pop() {
        if (!data.empty()) {
            data.pop_back();
        } else {
            std::cout << "Stack is empty, nothing to pop.\n";
        }
    }

    // Получение элемента на вершине стека
    int top() {
        if (!data.empty()) {
            return data.back();
        } else {
            std::cout << "Stack is empty.\n";
            return -1; // Возвращаем -1 или другое специфическое значение, указывающее на ошибку
        }
    }

    // Проверка стека на пустоту
    bool isEmpty() {
        return data.empty();
    }

    // Вывод содержимого стека (для демонстрации)
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
    myStack.printStack(); // Вывод: 30 20 10

    std::cout << "Top element: " << myStack.top() << "\n"; // Вывод: 30

    myStack.pop();
    myStack.printStack(); // Вывод: 20 10

    std::cout << "Is stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << "\n"; // Вывод: No

    return 0;
}
