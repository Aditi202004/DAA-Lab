#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


//do dry run
int main(){
    #ifndef ONLINE_JUDGE
	    freopen("input1.txt","r",stdin);
	    freopen("output1b.txt","w",stdout);
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
        int a = 0;
        vector<int> final;
        while(k<m || l<n){
            // cout<< k << " " << l << endl;
            if((k!=m && l==n) || (k!=m && arr2[k] <= arr1[l])){
                if(a>0 && (final[a-1] != arr2[k])){ 
                    final.push_back(arr2[k]);
                    a++;
                }
                else if(a == 0){
                    final.push_back(arr2[k]);
                    a++;
                }
                k++;
            }
            else if((l!=n && k==m) || (l!=n && arr2[k] > arr1[l])){
                if(a>0 && (final[a-1] != arr1[l])){ 
                    final.push_back(arr1[l]);
                    a++;
                }
                else if(a == 0){
                    final.push_back(arr1[l]);
                    a++;
                }
                l++;
            }
            // cout << final.size() << endl;
        }
        // for(int i = 0; i<a; i++){
        //     cout << final[i] << " ";
        // }
        // cout << final.size() << endl;
        for(auto num: final){
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}