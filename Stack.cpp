//
// Created by Matebook on 10.03.2022.
//
#include "Stack.h"
#include <iostream>
#include <random>


Stack::Stack() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist15(0, 15);
    int size = dist15(gen);
    std::cout << "Size of stack: " << size << std::endl;
    head = nullptr;
    amt = 0;

    for (int i = 0; i < size; i++) {
        *this += dist15(gen);
    }
}

Stack::~Stack() {
    while (amt) --(*this);
}

void Stack::operator++() {
    int temp;
    std::cout << "Enter value: " << std::endl;
    std::cin >> temp;
    while (std::cin.fail()) {
        std::cout << "Wrong input" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // fool proofing
        std::cin >> temp;
    }

    *this += temp;
}

void Stack::operator--() {
    if (not amt) return;
    std::cout << "Popped: " << head->value << std::endl;
    auto temp = head;
    head = temp->next;
    amt--;
    delete temp;
}

void Stack::operator--(int) {
    if (amt < 2) return;
    --(*this);
    --(*this);
}

void Stack::operator+=(int a) {
    std::cout << "Added to stack: " << a << std::endl;
    auto *temp = new item{a, head};
    head = temp;
    amt++;
}

void operator++(Stack &s, int) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist15(0, 15);

    s += dist15(gen);
    s += dist15(gen);
}

Stack::operator int() {
    return head->value;
}

void Stack::show(){
    std::cout << "Stack items:" << std::endl;
    auto temp = head;
    while (temp){
        std::cout << temp->value << std::endl;
        temp = temp->next;
    }
}