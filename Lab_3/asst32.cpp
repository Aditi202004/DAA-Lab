#include <iostream>
using namespace std;

int large_sum(int start, int end, int *arr, int size){
//    1 -3 -6 9 6 3 -2 6 5
//    -2 -9 3 15 9 1 4 11
    if(start == end){
        return arr[start];
    }
    int ind = start + (end - start) / 2;

    int sum = arr[ind];
    int i = ind - 1;
    int max_left_sum = sum;
    while(i >= start){
        // if(sum <= sum + arr[i]){
        //     sum += arr[i];
        //     i--;
        // }
        // else{
        //     break;
        // }
        sum += arr[i];
        if(sum >= max_left_sum){
            max_left_sum = sum;
        }
        i--;
    }
    sum = arr[ind];
    i = ind + 1;
    int max_right_sum = sum;
    while(i <= end){
        // if(sum <= sum + arr[i]){
        //     sum += arr[i];
        //     i++;
        // }
        // else{
        //     break;
        // }
        sum += arr[i];
        if(sum >= max_right_sum){
            max_right_sum = sum;
        }
        i++;
    }
    sum = max_left_sum + max_right_sum - arr[ind];
    int sum_left = INT16_MIN;
    int sum_right = INT16_MIN;
    if(start >= 0 && (ind - 1) <= (size - 1) && (ind - 1) >= 0 && start <= (size - 1) && start <= (ind - 1)){
        sum_left = large_sum(start, ind - 1, arr, size);
    }
    if((ind + 1) >= 0 && (ind + 1) <= (size - 1) && end <= (size - 1) && end >= 0 && (ind + 1) <= end){
        sum_right = large_sum(ind + 1, end, arr, size);
    }
    
    // cout << "max sum from index " << start << " to " << end << " : " << max(sum, max(sum_left, sum_right)) << endl;
    return max(sum, max(sum_left, sum_right));  
}

int main(){
    #ifndef ONLINE_JUDGE
	    freopen("input2.txt","r",stdin);
	    freopen("output2.txt","w",stdout);
    #endif
    int n;
    cin >> n;
    int *array = new int[n];
    for(int i = 0; i < n; i++){
        cin >> array[i];
    }
    cout << "largest sum of the array is: " << large_sum(0, n-1, array, n) << endl;
    return 0;
}