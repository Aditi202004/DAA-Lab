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
    return i; //just remove this and change return type to void
}

void QS(int start, int end, int *arr, int median_ind, int &median_val){
    if(start >= end){
        if(start == median_ind){
            median_val = arr[start];
        }
        return;
    }
    int ele_ind = partition(start, end, arr);
    // cout << "ele_ind for below arr: " << ele_ind << endl;
    // Print(arr, 7);
    if(ele_ind == median_ind){
        median_val = arr[ele_ind];
        return;
    }
    QS(start, ele_ind - 1, arr, median_ind, median_val);
    QS(ele_ind + 1, end, arr, median_ind, median_val);
    return;
}

int main(){
    #ifndef ONLINE_JUDGE
	    freopen("input4.txt","r",stdin);
	    freopen("output4.txt","w",stdout);
    #endif
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int mid;
    if(n % 2 == 0){
        int median1 = -1;
        int median2 = -1;
        mid = n / 2;
        QS(0, n-1, arr, mid, median1);
        QS(0, n-1, arr, mid-1, median2);
        // cout << median1 << endl;
        // cout << median2 << endl;
        cout << "The median element is " << (median1 + median2) / 2.0;
    }
    else{
        int median = -1;
        mid = (n - 1) / 2;
        QS(0, n-1, arr, mid, median);
        cout << "The median element is " << median;
    }
    // cout << mid << endl;
    
    return 0;
}