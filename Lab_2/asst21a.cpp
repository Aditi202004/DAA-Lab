#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
	    freopen("input1.txt","r",stdin);
	    freopen("output1a.txt","w",stdout);
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
        vector<int> final(m+n);
        while(a < m+n){
            if((k!=m && l==n) || (k!=m && arr2[k] <= arr1[l])){
                final[a] = arr2[k];
                a++; k++;
            }
            else if((l!=n && k==m) || (l!=n && arr2[k] > arr1[l])){
                final[a] = arr1[l];
                a++; l++;
            }
        }
        for(int i = 0; i<m+n; i++){
            cout << final[i] << " ";
        }
        cout << endl;
    }

}