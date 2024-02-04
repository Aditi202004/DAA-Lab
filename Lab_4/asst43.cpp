#include <iostream>
#include <fstream>
using namespace std;

void swap(int arr[], int i, int j){
    int c = arr[i];
    arr[i] = arr[j];
    arr[j] = c;
}

// int bubble(int arr[], int size, int k){
//     int i = size - 1;
//     int end = 0;
//     while(end != k){
//         i = size - 1;
//         while(i > end){
//             if(arr[i] > arr[i-1]){
//                 swap(arr, i, i-1);
//             }
//             i--;
//         }
//         end++;
//     }
//     return arr[k-1];
// }

// void merge(int *arr, int start, int mid, int end){
// 	int nl = mid - start + 1;
// 	int nr = end - mid;
// 	int *larr = new int[nl];
// 	int *rarr = new int[nr];
// 	for(int i = 0; i < nl; i++){
// 		larr[i] = arr[start + i];
// 	}
// 	for(int i = 0; i < nr; i++){
// 		rarr[i] = arr[mid + i + 1];
// 	}
// 	int l = 0; 
// 	int r = 0;
// 	int ind = start;
// 	while(l != nl || r != nr){
// 		if(((larr[l] < rarr[r]) && l < nl) || r >= nr){
// 			arr[ind] = larr[l];
// 			l++;
// 			ind++;
// 		}
// 		else{
// 			arr[ind] = rarr[r];
// 			r++;
// 			ind++;
// 		}
// 	}

// 	delete[] larr;
// 	delete[] rarr;
// }

// void mergeSort(int arr[], int start, int end){
// 	if(start == end){
// 		return;
// 	}
// 	int mid = start + (end - start)/2;
// 	mergeSort(arr, start, mid);
// 	mergeSort(arr, mid + 1, end);
// 	merge(arr, start, mid, end);
// }

// int merge_sort(int arr[], int size, int k){
//     mergeSort(arr, 0, size-1);
//     return arr[size - k];
// }

int partition(int arr[], int start, int end){
    int pivot = arr[end];
    int i = start - 1;
    int j = start;
    while(j < end){
        if(arr[j] < pivot){
            swap(arr, ++i, j);
        }
        j++;
    }
    swap(arr, ++i, j);
    return i;
}

int K_largest(int arr[], int start, int end, int k, int size){
    if(start < end){
        int p = partition(arr, start, end);
        if(size - k == p){
            return arr[p];
        }
        else if(size - k > p){
            return K_largest(arr, p + 1, end, k, size);
        }
        else if(size - k < p){
            return K_largest(arr, start, p - 1, k, size);
        }
        
    }
    return arr[start];
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input3.txt", "r", stdin);
        freopen("output3.txt", "w", stdout);
    #endif

    int n, k;
    cin >> n >> k;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << k << "th largest element is " << K_largest(arr, 0, n - 1, k, n) << endl;
    return 0;
}