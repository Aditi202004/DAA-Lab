#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct profit_compare{
    bool operator()(pair<int, pair<int, int>> a, pair <int, pair <int, int>> b){
        return a.second.first < b.second.first;
    }

};

bool deadline_compare(pair<int, pair<int, int>> a, pair <int, pair <int, int>> b){
    return a.second.second < b.second.second;
}

int solution(vector<pair<int, pair<int,int>>>jobs, int n, string names[]){
    sort(jobs.begin(), jobs.end(), deadline_compare);
    vector<pair<int, pair<int,int>>> result;
    int ans = 0;
    priority_queue<pair <int, pair<int, int>>, vector<pair <int, pair<int, int>>>, profit_compare> pq;
    for(int i = n-1; i >= 0; i--){
        int slots_for_i;
        if(i == 0){
            slots_for_i = jobs[i].second.second;
        }
        else{
            slots_for_i = jobs[i].second.second - jobs[i-1].second.second;
        }
        pq.push(jobs[i]);
        while(slots_for_i > 0 && !pq.empty()){
            pair<int, pair<int,int>> job_info = pq.top();
            // cout << pq.size() << " " << job_info.second.first << endl;
            pq.pop();
            slots_for_i--;
            result.push_back(job_info);
            ans += job_info.second.first;
            int index = job_info.first;
            cout << names[index] << " ";
        }
    }
    return ans;
}

int main(){

    freopen("input2.txt","r",stdin);
    freopen("output2.txt","w",stdout);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string *job_names = new string[n];
        vector <vector<int>> job_temp(n, vector<int>(2));

        vector<pair<int, pair<int, int>>>jobs;
        for(int i = 0; i < n; i++){
            cin >> job_names[i];
        }
        for(int i = 0; i < n; i++){
            cin >> job_temp[i][0];
        }
        for(int i = 0; i < n; i++){
            cin >> job_temp[i][1];
        }

        for(int i = 0; i < n; i++){
            jobs.push_back(make_pair(i, make_pair(job_temp[i][1], job_temp[i][0])));
        }
        
        int profit = solution(jobs, n, job_names);
        cout << "with profit of : " << profit << endl;
        delete[] job_names;
    }
    return 0;
}