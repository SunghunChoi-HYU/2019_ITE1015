#include <iostream>
using namespace std;

class Color{
	public:
		int red, green, blue;
		Color();
		Color(int r, int g, int b);
		show();
		friend Color operator+(Color a);
		friend bool operator==(Color a, Color b);
};

Color::Color(){
	this->red = 0;
	this->green = 0;
	this->blue = 0;
}

Color::Color(int r, int g, int b){
	this->red = r;
	this->green = g;
	this->blue = b;
}

Color::show(){
	cout << this->red << " " << this->green << " " << this->blue << endl;
}

Color operator+(Color a, Color b){
	Color temp;
	temp.red = a.red + b.red;
	temp.green = a.green + b.green;
	temp.blue = a.blue + b.blue;
	return temp;
}

bool operator==(Color a, Color b){
	if(a.red == b.red && a.green == b.green && a.blue == b.blue)
		return true;
	else
		return false;
}

int main(void){
	Color red(255, 0, 0), blue (0, 0, 255), c;
	c = red + blue;
	c.show();
	Color fuchsia(255, 0, 255);
	if (c == fuchsia)
		cout << "보라색 맞음" << endl;
	else
		cout << "보라색 아님" << endl;
}
