#include <iostream>
using namespace std;

int whatsMax(int *arr1, int size1);
int whatsMin(int *arr2, int size2);
float whatsAvg(int *arr3, int size3);

int main(){
	int arr[100];
	int size = -1;
	
	for (int i = 0; i < 100; i++){
		cin >> arr[i];
		size++;
		if(arr[i]==-1)
			break;
	}

	whatsMax(arr, size);
	whatsMin(arr, size);
	whatsAvg(arr, size);
	
	return 0;
}

int whatsMax(int *arr1, int size1){
	int max = -1;
	
	for (int i = 0; i < size1; i++){
		if(max < arr1[i])
			max = arr1[i];
	}
	
	cout << "Max of array is " << max << "\n";
	
	return 0;
}

int whatsMin(int *arr2, int size2){
	int min = 100;
	
	for (int i = 0; i < size2; i++){
		if (min > arr2[i])
			min = arr2[i];
	}
	
	cout << "Min of array is " << min << "\n";
	
	return 0;
}

float whatsAvg(int *arr3, int size3){
	int sum = 0;
	float avg;
	
	for (int i = 0; i < size3; i++)
		sum += arr3[i];
	
	avg = (float) sum / (float) size3;
	
	cout << "Avg of array is " << avg << "\n";
	
	return 0;
}
