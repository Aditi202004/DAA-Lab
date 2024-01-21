#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

const int N = 1e6;


void swap(int *arr, int i, int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void Print(int *arr, int n){
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	cout<<endl;
}

void merge(int *arr, int start, int mid, int end){
	int nl = mid - start + 1;
	int nr = end - mid;
	int *larr = new int[nl];
	int *rarr = new int[nr];
	for(int i = 0; i < nl; i++){
		larr[i] = arr[start + i];
	}
	for(int i = 0; i < nr; i++){
		rarr[i] = arr[mid + i + 1];
	}
	int l = 0; 
	int r = 0;
	int ind = start;
	while(l != nl || r != nr){
		if(((larr[l] < rarr[r]) && l < nl) || r >= nr){
			arr[ind] = larr[l];
			l++;
			ind++;
		}
		else{
			arr[ind] = rarr[r];
			r++;
			ind++;
		}
	}

	delete[] larr;
	delete[] rarr;
}

void mergeSort(int arr[], int start, int end){
	if(start == end){
		return;
	}
	int mid = start + (end - start)/2;
	mergeSort(arr, start, mid);
	mergeSort(arr, mid + 1, end);
	merge(arr, start, mid, end);
}


int main(){
	#ifndef ONLINE_JUDGE
	    freopen("input3.txt","r",stdin);
	    freopen("output3.txt","w",stdout);
    #endif
	// int arr[10] = {2,6,3,6,8,12,2,34,4,6};
    int n; 
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    mergeSort(arr, 0, n);
    Print(arr, n);
	return 0;
}
