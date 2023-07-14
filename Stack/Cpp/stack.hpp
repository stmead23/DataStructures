#ifndef STACK_HPP
#define STACK_HPP

class Stack {
private:
    int max_size;
    int current_size = {0};
    int* stack; 
public:
    Stack(int s) : max_size(s), stack(new int[s]) {}

    ~Stack(void);

    int getSize(void);

    bool isEmpty(void);

    bool isFull(void);

    int top(void);

    void push(int key);

    int pop(void);

    void printStack(void);
};

#endif