#include <iostream>
#include <cstring>
using namespace std;

void updown(char* arr);
int isLow(char a);
int isUp(char b);
void toLow(char &c);
void toUp(char &d);

int main(){
	char word[101];
	
	cout << "Input an English word\n";
	cin >> word;
	
	updown(word);
	cout << word << "\n";
	
	return 0;
}

void updown(char *arr){
	for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
		if(isLow(arr[i]))
			toUp(arr[i]);
		else if(isUp(arr[i]))
			toLow(arr[i]);
	}
}

int isLow(char a){
	if((int) a >= 97 && (int) a <= 122)
		return 1;
	else
		return 0;
}

int isUp (char b){
	if( (int) b >= 65 && (int) b <= 90)
		return 1;
	else
		return 0;
}

void toLow(char &c){
	c = c + 32;
}

void toUp(char &d){
	d = d - 32;
}
