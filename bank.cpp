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

    BankAccount(std::string accountName) : name(accountName), balance(0.0) {}

    void withdraw(double amount) {
        balance = balance - amount;
    }

    void deposit(double amount) {
        balance = balance + amount;
    }

    void printBalance() {
        std::cout << name << " has " << std::fixed << std::setprecision(2) << balance << " dollars." << std::endl;
    }

    void transferReceivedNotification(double amount, std::string sender) {
        std::cout << name << " has received $" << std::fixed << std::setprecision(2) << amount << " from " << sender << "." << std::endl;
    }

    void transferSentNotification(double amount, std::string receiver) {
        std::cout << name << " has sent $" << std::fixed << std::setprecision(2) << amount << " to " << receiver << "." << std::endl;
    }
    void setBalance(double amount) {
        balance = amount;
    }
private:
    double balance;
};

int main() {
    BankAccount account1("John");
    account1.setBalance(2000.25);

    account1.printBalance();

    BankAccount account2("Mary");
    account2.setBalance(3000.50);

    account2.printBalance();
    dots();
    account2.transferSentNotification(500, "John");
    dots();
    account2.withdraw(500);
    account1.deposit(500);
    account1.transferReceivedNotification(500, "Mary");
    account1.printBalance();
    account2.printBalance();
    return 0;
}