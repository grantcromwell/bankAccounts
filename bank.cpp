#include <iostream>
#include <string>
#include <unistd.h>
#include <iomanip>

static void dots() {
    for (int i = 0; i < 3; i++) {
        std::cout << ".";
        std::cout.flush();
        usleep(500000);
    }
    std::cout << std::endl;
}

class BankAccount {
public:
    std::string name;
    double balance;

    void withdraw(double amount) {
        balance = balance - amount;
    }

    void deposit(double amount) {
        balance = balance + amount;
    }
};

int main() {
    BankAccount account1;
    account1.name = "John";
    account1.balance = 2000.25;

    std::cout << account1.name << " has " << account1.balance << " dollars." << std::endl;

    BankAccount account2;
    account2.name = "Mary";
    account2.balance = 3000.50;

    std::cout << account2.name << " has " << std::fixed << std::setprecision(2) << account2.balance << " dollars." << std::endl;
    dots();
    std::cout << "Mary has sent $500 to " << account1.name << "." << std::endl;
    dots();
    account2.withdraw(500);
    account1.deposit(500);
    std::cout << account1.name << " has received $500." << std::endl;
    std::cout << account1.name << " has " << std::fixed << std::setprecision(2) << account1.balance << " dollars." << std::endl;
    std::cout << account2.name << " has " << std::fixed << std::setprecision(2) << account2.balance << " dollars." << std::endl;
    return 0;
}