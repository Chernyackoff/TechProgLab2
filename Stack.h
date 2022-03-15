//
// Created by Matebook on 10.03.2022.
//

#ifndef LAB2_STACK_H
#define LAB2_STACK_H


class Stack{
public:
    Stack();
    ~Stack();
    void operator++();
    void operator--();
    void operator--(int);
    void operator+=(int a);
    operator int();
    void show();
    friend void operator++(Stack &s, int);
private:
    struct item{
        int value;
        item* next;
    };
    item* head;
    int amt;
};


#endif //LAB2_STACK_H
