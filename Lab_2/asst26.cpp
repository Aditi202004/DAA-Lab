#include <iostream>
using namespace std;


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

int partition(int start, int end, int *arr){
    int pivot = arr[end];
    int i = start-1;
    int j = start;
    while(j < end){
        if(arr[j] >= pivot){
            j++;
        }
        else if(arr[j] < pivot){
            i++;
            swap(arr, i, j);
            j++;
        }
    }
    i++;
    swap(arr, i, j);
    return i;
}

void QS(int start, int end, int *arr){
    if(start >= end){
        return;
    }
    int pivot = partition(start, end, arr);
    QS(start, pivot - 1, arr);
    QS(pivot + 1, end, arr);
    return;
}

int main(){
    #ifndef ONLINE_JUDGE
	    freopen("input4.txt","r",stdin);
	    freopen("output6.txt","w",stdout);
    #endif
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    QS(0, n - 1, arr);
    Print(arr, n);
    
    return 0;
}