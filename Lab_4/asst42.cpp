#include <iostream>
#include <fstream>
using namespace std;

float find_median(int arr1[], int arr2[], int size1, int size2){
    int *arr = new int[size1 + size2];
    int i = 0;
    int j = 0;
    int k = 0;
    while((i <= size1 - 1) && (j <= size2 - 1)){
        if(arr1[i] <= arr2[j]){
            arr[k++] = arr1[i++];
        }
        else{
            arr[k++] = arr2[j++];
        }
    }
    while(i <= size1 - 1){
        arr[k++] = arr1[i++];
    }
    while(j <= size2 - 1){
        arr[k++] = arr2[j++];
    }

    //finding the median
    if(((size1 + size2) % 2) != 0){
        return arr[( (size1 + size2 - 1) / 2 )];
    }
    else if(((size1 + size2) % 2) == 0){
        return (((arr[((size1 + size2) / 2)]) + (arr[( ( (size1 + size2) / 2) - 1 )])) / 2.0);
    }
    delete[] arr;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input2.txt", "r", stdin);
        freopen("output2.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    int *arr1 = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr1[i];
    }

    int m;
    cin >> m;
    int *arr2 = new int[m];
    for(int i = 0; i < m; i++){
        cin >> arr2[i];
    }

    cout << "the median of the arrays is " << find_median(arr1, arr2, n, m) << endl;
    return 0;
}