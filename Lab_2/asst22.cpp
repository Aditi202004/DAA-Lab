#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


int main(){
    #ifndef ONLINE_JUDGE
	    freopen("input2.txt","r",stdin);
	    freopen("output2.txt","w",stdout);
    #endif
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int *arr = new int[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        for(int k = m; k < n; k++){
            int val = arr[k];
            int j = k - 1;
            while(j >= 0 && arr[j] > val){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = val;
        }
        for(int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}