#include <iostream>
using namespace std;

class findarea{
public :
	int height, length;
	Area();
	Area(int height, int length);
	int area();
};

findarea::Area() : Area (1,1){};	
	
findarea::Area(int x, int y) {height = x; length = y;}

findarea::area(){
	return height*length;
}

int main (void){
	int area;
	
	findarea unitsquare();
	area = unitsquare.area
	cout << "�簢���� ���̴� : " << area << " �Դϴ�.";
	
	findarea square(3,5);
	area = square.area
	cout << "������� ���̴� : " << area << " �Դϴ�.";
	
}
