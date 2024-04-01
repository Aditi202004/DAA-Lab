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
    bool *slots = new bool[n];
    cout << "Following is the maximum profit sequence of jobs: [ ";
    int max_profit = 0;
    int curr_time = 0;

    for(auto job : jobs){
        int curr_deadline = job[1];
        for(int i = curr_deadline - 1; i >= 0; i--){
            if(slots[i] == 0){
                slots[i] = 1;
                max_profit += job[2];
                cout << names[job[0]] << " ";
                break;
            }
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