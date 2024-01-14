#include<iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

int main(){

    ofstream input;
    input.open("input1.txt",ios::in);
    int testcase;
    testcase = rand()%10+1;
    input << testcase << endl;
    while(testcase--){
        int num = rand()+1;
        input << num << endl;
        for(int i=0;i<num;i++){
            input << rand()%1000+1 << " ";
        }
        input << endl;
    } 
    #ifndef ONLINE_JUDGE
	    freopen("input1.txt","r",stdin);
	    freopen("output1.txt","w",stdout);
    #endif
    int t;
    cin >> t;
    while(t--){
        int n; 
        cout << "enter size of array: ";
        cin >> n;
        // cout<<"done";
        int *arr = new int[n];
        // cout << "done";
        //generating random input
        for(int i = 0; i < n; i++){
        arr[i] = rand() % 1000;
        }
        // cout << "done";
        // for(int i = 0; i < n; i++){
        //   cin >> arr[i];
        // }
        int max1 = INT8_MIN;
        int max2 = INT8_MIN;
        for(int i = 0; i < n; i++){
            if(arr[i] > max1){
                max2 = max1;
                max1 = arr[i];
            }
            else if(arr[i] > max2){
                max2 = arr[i];
            }
        }
        cout << "maximum sum: " << max1 + max2 << endl;
    }
    return 0;
}