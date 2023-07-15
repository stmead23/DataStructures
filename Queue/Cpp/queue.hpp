#ifndef QUEUE_HPP
#define QUEUE_HPP

class Queue {
private:
    int* queue;
    int max_size;
    int current_size = {0};
    int front = {0};
public:
    Queue (int s) : max_size(s), queue(new int[s]) {}

    int getSize(void);

    bool isEmpty(void);

    bool isFull(void);

    int top(void);

    void enqueue(int key);

    int dequeue(void);

    void printQueue(void);
};

#endif