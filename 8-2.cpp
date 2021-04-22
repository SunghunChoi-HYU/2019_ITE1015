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
	cout << "--0에서 " << RAND_MAX << "까지의 랜덤 정수 10개 --" << endl;
	for (int i =0; i < 10; ++i){
		cout << r.next() << ' ';
	}
	cout << endl << "--2에서" <<"10까지 랜덤 정수 10개 --" << endl;
	for (int i = 0; i < 10; ++i){
		int n = r.nextInRange(2,10);
		cout << n << ' ';
	}
	cout << endl;
}
