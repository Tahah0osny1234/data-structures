#include <iostream>
using namespace std;

 struct Node {
    char data;
    Node* next;
};

 class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue() {
        front = rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(char value) {
        Node* temp = new Node{value, nullptr};
        if (!rear) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
    }

    char dequeue() {
        if (isEmpty()) throw runtime_error("Queue is empty");
        Node* temp = front;
        char val = temp->data;
        front = front->next;
        if (!front) rear = nullptr;
        delete temp;
        return val;
    }

    void display() {
        Node* curr = front;
        while (curr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    friend void reverseQueue(Queue& q);
};

 void reverseQueue(Queue& q) {
    if (q.isEmpty()) return;
    char val = q.dequeue();
    reverseQueue(q);
    q.enqueue(val);
}

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

    bool isEmpty() {
        return top == nullptr;
    }

    void push(char value) {
        StackNode* temp = new StackNode{value, top};
        top = temp;
    }

    char pop() {
        if (isEmpty()) throw runtime_error("Stack is empty");
        StackNode* temp = top;
        char val = temp->data;
        top = top->next;
        delete temp;
        return val;
    }

    char peek() {
        if (isEmpty()) throw runtime_error("Stack is empty");
        return top->data;
    }
};

 char toLowerCase(char ch) {
    if (ch >= 'A' && ch <= 'Z') return ch + 32;
    return ch;
}

 bool isLetter(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

 bool isPalindrome(const string& str) {
    Queue q;
    Stack s;

    for (int i = 0; str[i] != '\0'; ++i) {
        char ch = str[i];
        if (isLetter(ch)) {
            ch = toLowerCase(ch);
            q.enqueue(ch);
            s.push(ch);
        }
    }

    while (!q.isEmpty()) {
        if (q.dequeue() != s.pop()) return false;
    }

    return true;
}

 int main() {
    Queue q;
    q.enqueue('a');
    q.enqueue('b');
    q.enqueue('c');
    q.enqueue('d');

    cout << "Original Queue: ";
    q.display();

    reverseQueue(q);

    cout << "Reversed Queue: ";
    q.display();

    string word1 = "rotator";
    string word2 = "data";

    cout << word1 << ": " << (isPalindrome(word1) ? "Palindrome" : "Not Palindrome") << endl;
    cout << word2 << ": " << (isPalindrome(word2) ? "Palindrome" : "Not Palindrome") << endl;

    return 0;
}
