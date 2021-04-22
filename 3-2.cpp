#include <iostream>
#include <cstring>
using namespace std;

void swap(char &a, char &b);
void flip(char* s);

int main(){
	char str[100];
	
	cin >> str;
	flip(str);
	cout << str << endl;
	
	return 0;
}

void flip (char* s){
	for (int i = 0; i < strlen(s)/2; i++)
		swap(s[i], s[strlen(s)-1-i]);
}

void swap(char &a, char &b){
	char temp;
	
	temp = a;
	a = b;
	b = temp;
}
