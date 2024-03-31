#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solution(vector <vector<int>> jobs, string names[]){
    // jobs(idx, deadline, profit)
    int n = jobs.size();

    sort(jobs.begin(), jobs.end(), [](const vector<int>&a, const vector<int>&b){
        return a[2] > b[2];
    });
    // for(auto itr : jobs){
    //     cout << itr[2] << endl;
    // }
    cout << "Following is the maximum profit sequence of jobs: [ ";
    int max_profit = 0;
    int curr_time = 0;
    for(auto itr : jobs){
        if(itr[1] - curr_time > 0){
            max_profit+=itr[2];
            cout << names[itr[0]] << " ";
            curr_time++;
        }
    }
    cout << "], Total profit = " << max_profit << endl;
    return;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input2.txt", "r", stdin);
        freopen("output2_greedy.txt", "w", stdout);
    #endif

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string *job_names = new string[n];
        vector <vector<int>> jobs(n, vector<int>(4));       // jobs(idx, deadline, profit)

        //taking input
        for(int i = 0; i < n; i++){
            jobs[i][0] = i;
            cin >> job_names[i];
        }
        for(int i = 0; i < n; i++){
            cin >> jobs[i][1];
        }
        for(int i = 0; i < n; i++){
            cin >> jobs[i][2];
        }

        solution(jobs, job_names);
    }
    return 0;
}




// greedy approach fails when for example there is an item with largest deadline as well as largest profit like
// 4
// a b c d
// 4 1 1 1
// 100 10 40 30
// max should be 140 but we get 100 by greedy