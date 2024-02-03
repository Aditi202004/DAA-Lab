#include <iostream>
#include <fstream>
using namespace std;


int merge(int arr[], int temp[], int start, int mid, int end){
    int inv = 0;
    int i = start;
    int j = mid;
    int k = start;
    while((i <= mid - 1) && (j <= end)){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
            inv = inv + (mid - i);
        }
    }
    while(i <= mid - 1){
        temp[k++] = arr[i++];
    }
    while(j <= end){
        temp[k++] = arr[j++];
    }

    //copyying all elements of temp from start to end into  arr
    for(int m = start; m <= end; m++){
        arr[m] = temp[m];
    }

    return inv;
}

int mergesort(int arr[], int temp[], int start, int end){
    int inv = 0;
    if(start < end){
        int mid = start + (end - start) / 2 ;
        inv = inv + mergesort(arr, temp, start, mid);
        inv = inv + mergesort(arr, temp, mid + 1, end);
        inv = inv + merge(arr, temp, start, mid + 1, end);
    }
    return inv;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input1.txt", "r", stdin);
        freopen("output1.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int *temp = new int[n];
    cout << "the number of inversion counts in the array is " << mergesort(arr, temp, 0, n-1) << endl;
    return 0;
}