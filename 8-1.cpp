#include <iostream>
#include <string>
using namespace std;

class Account{
	private:
		string name;
		int id;
		int balance;
	public:
		Account();
		Account (string s, int i, int b);
		string getOwner();
		int inquiry();
		void deposit(int money);
		int withdraw(int money);
};

Account::Account() {
	name = "∫Û ∞Ë¡¬";
	id = 0;
	balance = 0;
}

Account::Account(string s, int i, int b){
	name = s;
	id = i;	
	balance = b;
}
	
void Account::deposit(int money){
	balance = balance + money;
}

string Account::getOwner(){
	return name;
}

int Account::withdraw(int money){
	balance = balance - money;
	return money;
}

int Account::inquiry(){
	return balance;
}


int main(){
	Account a("¥ﬁ∞«¿Ã",1, 5000);
	a.deposit(50000);
	cout << a.getOwner() << "¿« ¿‹æ◊¿∫ " << a.inquiry() << endl;
	int money = a.withdraw(20000);
	cout << a.getOwner() << "¿« ¿‹æ◊¿∫ " << a.inquiry() << endl;
}
