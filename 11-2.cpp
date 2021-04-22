#include <iostream>
#include <string>
using namespace std;

class LoopAdder{
	string name;
	int x, y, sum;
	void read();
	void write();
protected:
	LoopAdder(string name = ""){
		this->name = name;
	}
	int getX(){return x;}
	int getY(){return y;}
	virtual int calculate() = 0;
public:
	void run();
};

void LoopAdder::read(){
	cout << name << " : " << "\n";
	cout << "ó�� ������ �ι�° ������ ���մϴ�. �� ���� �Է��ϼ��� >> ";
	cin >> x >> y; 
}
void LoopAdder::write(){
	cout << x << "���� " << y << "������ �� = " << sum <<" �Դϴ�." << "\n";
}
void LoopAdder::run(){
	read();
	sum = calculate();
	write();
}

class ForLoopAdder : public LoopAdder{
	protected:
		int calculate();
	public:
		ForLoopAdder(string name) : LoopAdder(name){}
};

int ForLoopAdder::calculate(){
	int sum = 0;
	for (int i = getX(); i <= getY(); ++i)
		sum += i;
	return sum;
}

class WhileLoopAdder : public LoopAdder{
	protected:
		int calculate();
	public :
		WhileLoopAdder(string name) : LoopAdder(name){}
};

int WhileLoopAdder::calculate(){
	int sum = 0;
	for (int i = getX(); i <= getY(); i++){
		sum += i;
	}
	return sum;
}

class DoWhileLoopAdder : public LoopAdder{
	protected:
		int calculate();
	public:
		DoWhileLoopAdder(string name) : LoopAdder(name){}
};

int DoWhileLoopAdder::calculate(){
	int sum = 0;
	for (int i = getX(); i <= getY(); i++){
		sum += i;
	}
	return sum;
}

int main(){
	WhileLoopAdder whileLoop("While Loop");
	DoWhileLoopAdder doWhileLoop("Do while Loop");
	whileLoop.run();
	doWhileLoop.run();
}
