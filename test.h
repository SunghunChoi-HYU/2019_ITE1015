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
	cout << "���� ID : " << accID << endl << "�̸� : " << cusName << endl << "�ܾ� : " << balance << endl;
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
	cout << "1. ���� ����" << endl;
	cout << "2. �Ա�" << endl;
	cout << "3. ���" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void AccountHandler::MakeAccount(){
    int id;
    char name[NAME_LEN];
    int balance;

    cout << "[���°���]" << endl;
    cout << "���� ID: ";
	cin >> id;
    cout << "�̸�: ";
	cin >> name;
    cout << "�Աݾ�: ";
	cin >> balance;
    cout << endl;

    accArr[accNum++] = new Account(id, balance, name);
}

void AccountHandler::DepositMoney(){
    int money;
    int id;
    
    cout << "[�Ա�]" << endl;
    cout << "���� ID: ";
	cin >> id;
    cout << "�Աݾ�: ";
	cin >> money;

    for (int i = 0; i < accNum; i++){
        if (accArr[i]->GetAccID() == id){
            accArr[i]->Deposit(money);
            cout << "�ԱݿϷ�" << endl << endl;
            return;
        }
    }
    cout << "��ȿ���� ���� ID �Դϴ�." << endl;
}

void AccountHandler::WithdrawMoney(){
    int money;
    int id;
    cout << "[���]" << endl;
    cout << "���� ID: ";
	cin >> id;
    cout << "��ݾ�: ";
	cin >> money;

    for (int i = 0; i < accNum; i++){
        if (accArr[i]->GetAccID() == id){
            if (accArr[i]->Withdraw(money) == 0){
                cout << "�ܾ׺���" << endl << endl;
                return;
            }
            cout << "��ݿϷ�" << endl << endl;
            return;
        }
    }
    cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
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

