#include <iostream>
using namespace std;

class Account {
    string name = "";
    int saldo = 0;

public:
    Account(){cout << "Account() @ " << this << endl;}
    ~Account(){cout << "~Account() @ " << this << endl;}
    Account(const Account&) = delete;
    Account& operator = (const Account&) = delete;

    string getName() {return name;}
    int getSaldo() {return saldo;}
    void setName(string n) {name = n;}
    void updateSaldo(int v) {saldo += v;}

};

int main() {

    Account* acc1 = new Account();
    acc1->setName("Ivan");
    acc1->updateSaldo(5000000);
    std::cout << "Account1: " << acc1->getName() << ", saldo: " << acc1->getSaldo() << endl;

    //Account acc2 = *acc1;
    //std::cout << "Account2: " << acc2.getName() << ", saldo: " << acc2.getSaldo() << endl;

    return 0;
}
