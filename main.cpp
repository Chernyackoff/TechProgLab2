#include <iostream>
#include "Stack.h"
#include "Float.h"
#include <numeric>

template <typename T>
T correct_input(){
    T temp;
    std::cin >> temp;
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // fool proofing
        std::cout << "Wrong input! Enter correct value" << std::endl;
        std::cin >> temp;
    }
    return temp;
}

void stack_main() {
    std::cout << "Creating Stack..." << std::endl;
    Stack s;
    std::cout << "Creation complete." << std::endl;
    int choice;
    while (true) {
        std::cout << "Choose an action:\n"
                     "1. ++Stack\n"
                     "2. Stack++\n"
                     "3. --Stack\n"
                     "4. Stack--\n"
                     "5. Show stack\n"
                     "6. Exit\n";
        choice = correct_input<int>();
        switch (choice) {
            case 1: {
                ++s;
                break;
            }
            case 2: {
                s++;
                break;
            }
            case 3: {
                --s;
                break;
            }
            case 4: {
                s--;
                break;
            }
            case 5: {
                s.show();
                break;
            }
            case 6:
                return;
            default: {
                std::cout << "No such command! Try again!" << std::endl;
                break;
            }
        }
    }
}

void float_main() {
    std::cout << "Entering Float mode..." << std::endl;
    std::cout << "Enter value for a FLOAT:" << std::endl;
    double f;
    std::cin >> f;
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // fool proofing
        std::cout << "Wrong input! Enter correct value" << std::endl;
        std::cin >> f;
    }
    Float a{f};
    Float b{3.1415};

    while (true) {
        int choice;
        std::cout << "Choose an action:\n"
                     "1. Float + Float\n"
                     "2. Float - (user's input)\n"
                     "3. (user's input) - Float\n"
                     "4. Float / (user's input)\n"
                     "5. (user's input) / Float\n"
                     "6. Float * Float\n"
                     "7. Float = (user's input)\n"
                     "8. Float = Float\n"
                     "9. Exit" << std::endl;
        choice = correct_input<int>();
        switch (choice) {
            case 1:{
                std::cout << "A:" << a << "\t" << "B:" << b << std::endl;
                std::cout << "A + B = " << a + b << std::endl;
                break;
            }
            case 2:{
                std::cout << "Please enter value to subtract:" << std::endl;
                auto temp = correct_input<double>();
                std::cout << "A - temp =" << a - temp <<  std::endl;
                break;

            }
            case 3:{
                std::cout << "Please enter value to subtract from:" << std::endl;
                auto temp = correct_input<double>();
                std::cout << "temp - A =" << temp - a <<  std::endl;
                break;

            }
            case 4:{
                std::cout << "Please enter value to divide on:" << std::endl;
                auto temp = correct_input<double>();
                std::cout << "A / temp = " << a / temp << std::endl;
                break;
            }
            case 5:{
                std::cout << "Please enter value to divide:" << std::endl;
                auto temp = correct_input<double>();
                std::cout << "temp / A = " << temp / a << std::endl;
                break;
            }
            case 6:{
                std::cout << "A * B = " << a * b << std::endl;
                break;
            }
            case 7: {
                std::cout << "Please enter new value for Float B:" << std::endl;
                auto temp = correct_input<double>();
                b = temp;
                break;
            }
            case 8:{
                std::cout << "A = " << double(a) << '\t' << "B = " << double(b) << std::endl;
                a = b;
                std::cout << "A = B"<< std::endl;
                std::cout << "A = " << double(a) << '\t' << "B = " << double(b) << std::endl;
                break;
            }
            case 9:
                return;
            default: {
                std::cout << "No such command! Try again!" << std::endl;
                break;
            }
        }
    }

};

int main() {
    int choice;
    while (true) {
        std::cout << "Choose:\n"
                     "1. Stack\n"
                     "2. Float\n"
                     "3. Exit" << std::endl;

        choice = correct_input<int>();

        switch (choice) {
            case 1: {
                stack_main();
                break;
            }
            case 2: {
                float_main();
                break;
            }
            case 3:
                return 0;
            default: {
                std::cout << "Wrong command! Try again!" << std::endl;
                break;
            }
        }
    }
}