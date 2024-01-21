#include <iostream>
#include <vector>
#include <fstream>
using namespace std;



int main(){
    #ifndef ONLINE_JUDGE
	    freopen("input1.txt","r",stdin);
	    freopen("output1c.txt","w",stdout);
    #endif
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n;
        vector<int> arr1(n);
        for(int i = 0; i<n; i++){
            cin >> arr1[i];
        }
        cin >> m;
        vector<int> arr2(m);
        for(int i = 0; i<m; i++){
            cin >> arr2[i];
        }
        int l = 0;
        int k = 0;
        vector<int> final;
        while(k<m && l<n){
            // cout<< k << " " << l << endl;
            if(arr2[k] == arr1[l]){
                final.push_back(arr2[k]);
                k++; l++;
            }
            else if(arr2[k] < arr1[l]){
                k++;
            }
            else if(arr2[k] > arr1[l]){
                l++;
            }
            // cout << final.size() << endl;
        }
        if(final.size() > 0){
            for(auto num: final){
                cout << num << " ";
            }
        }
        else{
            cout<< "No common element found";
        }
        cout << endl;
    }
    return 0;
}