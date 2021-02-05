#include <iostream>
#include <math.h>
using namespace std;

//Merge

void merge(int A[], int p, int q, int r){
	//initialize the size of the left and right array
	int leftSz = q - p + 1;
	int rightSz = r - q;
	
	int Left[leftSz + 1], Right[rightSz + 1];
	//divide the values of A into the left and right arrays
	for(int i = 0; i <= leftSz; i++)
		Left[i] = A[p + i - 1];

	for(int j = 0; j <= rightSz; j++)
		Right[j] = A[q + j];
	//since my program only generates random numbers between 0 and 100, 101 will work as infinity
	Left[leftSz + 1] = 101;
	Right[rightSz + 1] = 101;
	
	int i = 1;
	int j = 1;
	for(int k = p; k <= r; k++){
		if(Left[i] <= Right[j]){
			A[k] = Left[i];
			i++;
		}
		else{
			A[k] = Right[j];
			j++;
		}
	}
}

//Merge-Sort
void mergeSort(int A[], int p, int r){
	if(p < r){
		int var = (p + r)/2;
		int q = floor(var);
		mergeSort(A, p, q);
		mergeSort(A, q + 1, r);
		merge(A, p, q, r);
	}
}

//Print Array function
void printArr(int A[], int length){
	for(int i = 0; i < length; i++)
		cout<<A[i]<<" ";
	cout<<endl;
}

int main() {
	int A[16];

	for(int i = 0; i < 16; i++)
		A[i] = rand() % 100;

	int lengthA = sizeof(A)/sizeof(A[0]);
	
	cout<<"Unsorted Array"<<endl;
	printArr(A, lengthA);
	
	mergeSort(A, 1, lengthA);

	cout<<"Sorted Array"<<endl;
	printArr(A, lengthA);

	return 0;
}
