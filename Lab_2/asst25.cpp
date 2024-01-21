#include <iostream>
using namespace std;


int *minimas(int *arr, int n, int *mins){
    // mins = new int[2];
    int min1 = INT16_MAX;
    int min2 = INT16_MAX;
    int i = 0;
    while(i < n){
        if(arr[i] < min1){
            min2 = min1;
            min1 = arr[i];
            i++;
            // cout << i <<endl;
        }
        else if(arr[i] < min2){
            min2 = arr[i];
            i++;
            // cout << i <<endl;
        }
        else{
            i++;
            // cout << i <<endl;
        }
    } 
    // cout << min1 << endl;
    // cout << min2 << endl;
    mins[0] = min1;
    mins[1] = min2;
    return mins;
}

int main(){
     #ifndef ONLINE_JUDGE
	    freopen("input4.txt","r",stdin);
	    freopen("output5.txt","w",stdout);
    #endif
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int *mins = new int[2];
    mins = minimas(arr, n, mins);
    cout << "First minima is " << mins[0] << endl;
    cout << "Second minima is " << mins[1] << endl;
    delete[] mins;
    return 0;
}