#include <iostream>
using namespace std;

int sum (int num1, int num2);
int sub (int num1, int num2);
int mul (int num1, int num2);
int div (int num1, int num2);

int main (){
	int num1, num2;
	char oper;
	
	cout << "�� ������ +,-,*,/ �� �ϳ��� �����ڸ� �Է��ϼ��� -> ";
	cin >> num1 >> num2 >> oper;
	
	if('+' == oper)
		sum(num1, num2);
	else if('-' == oper)
		sub(num1, num2);
	else if('*' == oper)
		mul(num1, num2);
	else{
		if(num2 == 0)
			cout << "���� 0���� ���� �� �����ϴ�.";
		else
			div(num1, num2);
	}
	
	return 0;
}

int sum(int num1, int num2){
	cout << num1 << " + " << num2 << " = " << num1 + num2;
	
	return 0;
}

int sub(int num1, int num2){
	cout << num1 << " - " << num2 << " = " << num1 - num2;
	
	return 0;
}

int mul(int num1, int num2){
	cout << num1 << " * " << num2 << " = " << num1 * num2;
	
	return 0;
}

int div(int num1, int num2){
	cout << num1 << " / " << num2 << " = " << num1 / num2;
	
	return 0;
}
