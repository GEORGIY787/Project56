#pragma once
#include <iostream>
#include <vector>
#include <string>


class Customer {
private:
    std::string name;
    std::string accountNumber;

public:
    Customer(const std::string& _name, const std::string& _accountNumber)
        : name(_name), accountNumber(_accountNumber) {}

    std::string GetName() const {
        return name;
    }

    std::string GetAccountNumber() const {
        return accountNumber;
    }
};


class BankAccount {
private:
    std::string accountNumber;
    double balance;

public:
    BankAccount(const std::string& _accountNumber)
        : accountNumber(_accountNumber), balance(0.0) {}

    std::string GetAccountNumber() const {
        return accountNumber;
    }

    double GetBalance() const {
        return balance;
    }

    void Deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    bool Withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }
};


class CreditAccount : public BankAccount {
private:
    double interestRate;

public:
    CreditAccount(const std::string& _accountNumber, double _interestRate)
        : BankAccount(_accountNumber), interestRate(_interestRate) {}

    double GetInterestRate() const {
        return interestRate;
    }

    void ApplyInterest() {
        double currentBalance = GetBalance();
        double interest = currentBalance * interestRate;
        Deposit(interest);
    }
};


class Bank 
{
public:

    std::string name;
    std::vector<Customer> customers;
    std::vector<BankAccount*> accounts;

    Bank(const std::string& _name)
        : name(_name) {}

    std::string GetName() const {
        return name;
    }

    void AddCustomer(const Customer& customer) {
        customers.push_back(customer);
    }

    void CreateBankAccount(const std::string& accountNumber) {
        BankAccount* account = new BankAccount(accountNumber);
        accounts.push_back(account);
    }

    void CreateCreditAccount(const std::string& accountNumber, double interestRate) {
        CreditAccount* account = new CreditAccount(accountNumber, interestRate);
        accounts.push_back(account);
    }

    void ShowCustomerAccounts(const std::string& customerName) const {
        std::cout << "Customer accounts " << customerName << ":" << std::endl;
        for (const BankAccount* account : accounts) {
            if (account->GetAccountNumber().find(customerName) != std::string::npos) {
                std::cout << "Accounts ¹" << account->GetAccountNumber() << ", Ballance: " << account->GetBalance() << std::endl;
            }
        }
    }

    ~Bank() {
        for (BankAccount* account : accounts) {
            delete account;
        }
    }
};

