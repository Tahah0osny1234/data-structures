#include <iostream>
using namespace std;

 
struct StackNode {
    char data;
    StackNode* next;
};

 
class Stack {
private:
    StackNode* top;
public:
    Stack() {
        top = nullptr;
    }

    void push(char value) {
        StackNode* temp = new StackNode{value, top};
        top = temp;
    }

    char pop() {
        if (isEmpty()) return '\0';  // handle underflow
        StackNode* temp = top;
        char val = temp->data;
        top = top->next;
        delete temp;
        return val;
    }

    char peek() {
        if (isEmpty()) return '\0';
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void clear() {
        while (!isEmpty()) pop();
    }
};

 
bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

 
bool isBalanced(const string& str) {
    Stack s;

    for (char ch : str) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            char topChar = s.pop();
            if (!isMatching(topChar, ch)) return false;
        }
    }

    return s.isEmpty();
}

 
int main() {
    string input;

    cout << "Enter expression: ";
    getline(cin, input);

    if (isBalanced(input)) {
        cout << "Balanced" << endl;
    } else {
        cout << "Not Balanced" << endl;
    }

    return 0;
}
