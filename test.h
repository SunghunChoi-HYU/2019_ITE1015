#include <iostream>
#include <cstring>
using namespace std;

const int NAME_LEN = 20;
enum {MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

class Account{
	private :
		int accID;
		int balance;
		char* cusName;
	public:
		Account (int ID, int money, char* name);
		Account (const Account& ref);
		int GetAccID() const;
		void Deposit(int money);
		int Withdraw(int money);
		void ShowAccInfo() const;
		~Account();
};

Account::Account(int ID, int money, char* name) : accID(ID), balance(money){
	int len = strlen(name) + 1;
	cusName = new char[len];
	strcpy(cusName, name);
}

Account::Account(const Account& ref) : accID(ref.accID), balance(ref.balance){
	int len = strlen(ref.cusName) + 1;
	cusName = new char[len];
	strcpy(cusName, ref.cusName);
}

int Account::GetAccID() const{
	return accID;
}

void Account::Deposit(int money){
	balance += money;
}

int Account::Withdraw(int money){
	if(balance - money >= 0)
		balance -= money;
	else
		return 0;
}

void Account::ShowAccInfo() const{
	cout << "계좌 ID : " << accID << endl << "이름 : " << cusName << endl << "잔액 : " << balance << endl;
}

Account::~Account(){
	delete[] cusName;
}

class AccountHandler{
	private:
		Account* accArr[100];
		int accNum;
	public :
		AccountHandler();
		void ShowMenu() const;
		void MakeAccount();
		void DepositMoney();
		void WithdrawMoney();
		void ShowAllAccInfo() const;
		~AccountHandler();
};

AccountHandler::AccountHandler() : accNum(0) {}

void AccountHandler::ShowMenu() const{
	cout << "-----------Menu-----------" << endl;
	cout << "1. 계좌 개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void AccountHandler::MakeAccount(){
    int id;
    char name[NAME_LEN];
    int balance;

    cout << "[계좌개설]" << endl;
    cout << "계좌 ID: ";
	cin >> id;
    cout << "이름: ";
	cin >> name;
    cout << "입금액: ";
	cin >> balance;
    cout << endl;

    accArr[accNum++] = new Account(id, balance, name);
}

void AccountHandler::DepositMoney(){
    int money;
    int id;
    
    cout << "[입금]" << endl;
    cout << "계좌 ID: ";
	cin >> id;
    cout << "입금액: ";
	cin >> money;

    for (int i = 0; i < accNum; i++){
        if (accArr[i]->GetAccID() == id){
            accArr[i]->Deposit(money);
            cout << "입금완료" << endl << endl;
            return;
        }
    }
    cout << "유효하지 않은 ID 입니다." << endl;
}

void AccountHandler::WithdrawMoney(){
    int money;
    int id;
    cout << "[출금]" << endl;
    cout << "계좌 ID: ";
	cin >> id;
    cout << "출금액: ";
	cin >> money;

    for (int i = 0; i < accNum; i++){
        if (accArr[i]->GetAccID() == id){
            if (accArr[i]->Withdraw(money) == 0){
                cout << "잔액부족" << endl << endl;
                return;
            }
            cout << "출금완료" << endl << endl;
            return;
        }
    }
    cout << "유효하지 않은 ID 입니다." << endl << endl;
}

void AccountHandler::ShowAllAccInfo() const{
    for (int i = 0; i < accNum; i++){
        accArr[i]->ShowAccInfo();
        cout << endl;
    }
}

AccountHandler::~AccountHandler(){
    for (int i = 0; i < accNum; i++)
        delete accArr[i];
}

