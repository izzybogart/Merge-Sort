#include <iostream>
#include <math.h>
using namespace std;

//Print Array function
void printArr(int A[], int length){
	for(int i = 0; i < length; i++)
		cout<<A[i]<<" ";
	cout<<endl;
}

//Merge
void merge(int A[], int p, int q, int r){
//initialize the size of the left and right array
	int leftSz = q - p + 1;
	int rightSz = r - q;

	int Left[leftSz], Right[rightSz];
//divide the values of A into the left and right arrays
	for(int i = 0; i < leftSz; i++){
		Left[i] = A[p + i - 1];
	}

	for(int j = 0; j < rightSz; j++){
		Right[j] = A[q + j];
	}

	int i = 0;
	int j = 0;
	int k = p - 1;

//sorts elements of Right and Left back into A
	while (i < leftSz && j < rightSz){
        if(Left[i] <= Right[j]){
            A[k] = Left[i];
            i++;
        }
        else{
            A[k] = Right[j];
            j++;
        }
        k++;
	}
//Copies remaining elements of Left and Right into A (if any)
	while(i < leftSz){
        A[k] = Left[i];
        i++;
        k++;
	}
	while(j < rightSz){
        A[k] = Right[j];
        j++;
        k++;
	}
}

//Merge-Sort
void mergeSort(int A[], int p, int r){
	if(p < r){
		int var = (p + r)/2;
		int q = floor(var);
		mergeSort(A, p, q);
		printArr(A,r);
		mergeSort(A, q + 1, r);
		printArr(A,r);
		merge(A, p, q, r);
	}
}

int main() {
	int A[16];

	for(int i = 0; i < 16; i++)
		A[i] = rand() % 100;

	int lengthA = sizeof(A)/sizeof(A[0]);

	cout<<" Unsorted Array"<<endl;
	printArr(A, lengthA);

	cout<<"\n Merge-Sort Iterations"<<endl;
	mergeSort(A, 1, lengthA);

	cout<<"\n Sorted Array"<<endl;
	printArr(A, lengthA);

	return 0;
}
