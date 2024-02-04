#include <iostream>
#include <vector>
#include <climits>
#include <fstream>
using namespace std;

// float find_median(int arr1[], int arr2[], int size1, int size2){
//     int *arr = new int[size1 + size2];
//     int i = 0;
//     int j = 0;
//     int k = 0;
//     while((i <= size1 - 1) && (j <= size2 - 1)){
//         if(arr1[i] <= arr2[j]){
//             arr[k++] = arr1[i++];
//         }
//         else{
//             arr[k++] = arr2[j++];
//         }
//     }
//     while(i <= size1 - 1){
//         arr[k++] = arr1[i++];
//     }
//     while(j <= size2 - 1){
//         arr[k++] = arr2[j++];
//     }

//     //finding the median
//     if(((size1 + size2) % 2) != 0){
//         return arr[( (size1 + size2 - 1) / 2 )];
//     }
//     else if(((size1 + size2) % 2) == 0){
//         return (((arr[((size1 + size2) / 2)]) + (arr[( ( (size1 + size2) / 2) - 1 )])) / 2.0);
//     }
//     delete[] arr;
// }

double findMedian(vector<int>& nums1, vector<int>& nums2) {
    int size1 = nums1.size();
    int size2 = nums2.size();
    if (size1 > size2) return findMedian(nums2, nums1);

    int low = 0;
    int high = size1;
    int combinedMid = (size1 + size2 + 1) / 2;

    while (low <= high) {
        int partitionX = (low + high) / 2;
        int partitionY = combinedMid - partitionX;

        int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int minRightX = (partitionX == size1) ? INT_MAX : nums1[partitionX];

        int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int minRightY = (partitionY == size2) ? INT_MAX : nums2[partitionY];

        
        if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
            
            if ((size1 + size2) % 2 == 0) {
                return (double)(max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2;
            }
            
            return (double)max(maxLeftX, maxLeftY);
        } else if (maxLeftX > minRightY) { 
            high = partitionX - 1;
        } else { 
            low = partitionX + 1;
        }
    }

    
    return 0.0;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input2.txt", "r", stdin);
        freopen("output2.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    vector<int>arr1;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        arr1.push_back(a);
    }

    int m;
    cin >> m;
    vector<int>arr2;
    for(int i = 0; i < m; i++){
        int a;
        cin >> a;
        arr2.push_back(a);
    }

    cout << "the median of the arrays is " << findMedian(arr1, arr2) << endl;
    return 0;
}