#include <iostream>
#include <string>
using namespace std;

class Point{
	int x,y;
	public:
		void set(int x, int y){
			this->x = x;
			this->y = y;
		}
		void showPoint(){
			cout << "(" << x << "," << y << ")" << endl;
		}
};

class ColorPoint : public Point{
	string color;
	public:
		void SetColor(string color){
			this->color = color;
		}
		void ShowColorPoint();
};

void ColorPoint::ShowColorPoint(){
	cout << color << " : ";
	showPoint();
}

int main(){
	Point P;
	ColorPoint cp;
	cp.set(3,4);
	cp.SetColor("Red");
	cp.ShowColorPoint();
}
