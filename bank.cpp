#include <iostream>
#include <string>

class BankAccount {
public:
    std::string name;
    double balance;
};

int main() {
    BankAccount account1;
    account1.name = "John";
    account1.balance = 2000.25;

    std::cout << account1.name << " has " << account1.balance << " dollars " << std::endl;

    return 0;
}