#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(){
	int num;

	cin >> num;
	std::queue<string> queue;
	
	for (int i = 0; i < num; i++){
		string text;
		cin >> text;
		if (text == "front"){
			if(queue.empty()) cout << -1 << "\n";
			else cout << queue.front() << "\n";
		}
		else if(text == "back"){
			if(queue.empty()) cout << -1 << "\n";
			else cout << queue.back() << "\n";
		}
		else if(text == "push"){
			string pushstring;
			cin >> pushstring;
			queue.push(pushstring);
		}
		else if(text == "pop"){
			cout << queue.front() << "\n";
			queue.pop();
		}
		else if(text == "size")
			cout << queue.size() << "\n";
		else if(text == "empty"){
			if(queue.empty()) cout << -1 << "\n";
			else cout << 0 << "\n";
		}
	}
}
