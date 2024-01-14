#include<iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

int main(){
    // int n; 
    // cout << "enter size of array: ";
    // cin >> n;
    // // cout<<"done";
    // int *arr = new int[n];
    // // cout << "done";
    // //generating random input
    // for(int i = 0; i < n; i++){
    //   arr[i] = rand() % 1000;
    // }
    // // cout << "done";
    // // for(int i = 0; i < n; i++){
    // //   cin >> arr[i];
    // // }

    ifstream myfile; 
    myfile.open("input1.txt");
    
    int n = 0;
    vector<int> arr;

    if (myfile.is_open()) {
        // Read the number of elements
        myfile >> n;

        // Read the elements
        for (int i = 0; i < n; i++) {
            int element;
            myfile >> element;
            arr.push_back(element);
        }

        myfile.close();
    } else {
        cout << "Unable to open file." << endl;
    }

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
    return 0;
}