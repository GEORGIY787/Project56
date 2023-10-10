#include"Header.h"


int main() 
{
    Bank bank("RGB Bank");

    Customer customer1("Ivanov Ivan", "12345");
    Customer customer2("Petrov Petr", "54321");

    bank.AddCustomer(customer1);
    bank.AddCustomer(customer2);

    bank.CreateBankAccount("12345-001");
    bank.CreateCreditAccount("12345-002", 0.05);
    bank.CreateBankAccount("54321-001");

    
    bank.accounts[0]->Deposit(1000.0);

    
    std::cout << "Accont Ballance " << bank.accounts[0]->GetAccountNumber() << ": " << bank.accounts[0]->GetBalance() << std::endl;

   
   
    std::cout << "Credits account ballance " << bank.accounts[1]->GetAccountNumber() << ": " << bank.accounts[1]->GetBalance() << std::endl;

    
    bank.ShowCustomerAccounts("Ivanov Ivan");

    return 0;
}