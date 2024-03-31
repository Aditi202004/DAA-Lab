#include <iostream>
#include <algorithm>
#include <climits>
#include <vector> 
using namespace std;

void solution(vector <vector<int>> jobs, string names[]){
    // jobs(idx, deadline, profit)
    int n = jobs.size();

    sort(jobs.begin(), jobs.end(), [](const vector<int>&a, const vector<int>&b){
        return a[1] <= b[1];
    });

    int max_total = INT_MIN;
    int local_max = INT_MIN;
    int local_max_id = 0; 
    int curr_profit = INT_MIN;
    int curr_deadline = 0;

    cout << "Following is the maximum profit sequence of jobs: [ ";
    for(auto job : jobs){
        curr_profit = job[2];
        if(job[1] == curr_deadline){
            if(local_max < curr_profit){
                local_max = curr_profit;
                local_max_id = job[0];
            }
        }
        else{
            max_total += local_max;
            if(curr_profit != 0){ cout << names[local_max_id] << " "; } // if condition is to avoid printing the last job again 
            local_max = curr_profit;
            curr_deadline = job[1];
        }
    }
    cout << "], Total profit = " << max_total << endl;

}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input2.txt", "r", stdin);
        freopen("output2.txt", "w", stdout);
    #endif

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string *job_names = new string[n+1];
        vector <vector<int>> jobs(n+1, vector<int>(4));       // jobs(idx, deadline, profit)

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
        job_names[n] = "padding";
        jobs[n][0] = n;
        jobs[n][1] = INT_MAX;
        jobs[n][2] = 0;

        solution(jobs, job_names);
    }
    return 0;
}