#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class EvenRandom{
	public:
		Random();
		int next();
		int nextInRange(int num1, int num2);
};

EvenRandom::Random(){
	srand((unsigned)time(0));
}

int EvenRandom::next(){
	int randomnum = rand();
	if(randomnum % 2 == 1)
		randomnum --;
	return randomnum;
}

int EvenRandom::nextInRange(int num1, int num2){
	int randomnum = rand() % (num2 - num1 + 1) + num1;
	if(randomnum % 2 == 1)
		randomnum --;
	return randomnum;
}

int main(){
	EvenRandom r;
	cout << "--0���� " << RAND_MAX << "������ ���� ���� 10�� --" << endl;
	for (int i =0; i < 10; ++i){
		cout << r.next() << ' ';
	}
	cout << endl << "--2����" <<"10���� ���� ���� 10�� --" << endl;
	for (int i = 0; i < 10; ++i){
		int n = r.nextInRange(2,10);
		cout << n << ' ';
	}
	cout << endl;
}
