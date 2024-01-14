#include<iostream>
#include<vector>
#include<climits>
#include<fstream>
using namespace std;

int knap(vector<vector<int>>&dp, int i, int w, int weights[], int profits[]){
    //out of range condition
    if(w < 0 || i < 0){
        return INT_MIN;
    }

    //if the cell is already computed then return it's value
    if(dp[i][w] != -1){
        return dp[i][w];
    }

    //base case
    if(w == 0 || i == 0){
        return dp[i][w] = 0;
    }
    if(w < weights[i-1]){
        return dp[i][w] = knap(dp, i-1, w, weights, profits);
    }
    return dp[i][w] = max((profits[i-1]+knap(dp, i-1, w-weights[i-1], weights, profits)), knap(dp, i-1, w, weights, profits));
}

int main(){
    ofstream input;
    input.open("input2.txt",ios::in);
    int testcase;
    testcase = rand()%10+1;
    input << testcase << endl;
    while(testcase--){
        int num = rand()%10+1;
        input << num << endl;
        input << rand()%10 << endl;//W
        for(int i=0;i<num;i++){
            input << rand()%10+1 << " ";//v[i]
        }
        input << endl;
        for(int i=0;i<num;i++){
            input << rand()%10+1 << " ";//w[i]
        }
        input << endl;
    } 
    #ifndef ONLINE_JUDGE
	    freopen("input2.txt","r",stdin);
	    freopen("output2.txt","w",stdout);
    #endif

    int t;
    cin >> t;
    while(t--){
        int N, W;
        cin >> N;
        cin >> W;
        int *weights = new int[N];
        int *values = new int[N];
        for(int i = 0; i<N; i++){
            cin >> weights[i];
        }
        for(int i = 0; i < N; i++){
            cin >> values[i];
        }
        vector<vector<int>>dp(N + 1, vector<int>(W + 1));
        for(int i = 0; i <= N; i++){
            for(int j = 0; j<=W; j++){
                dp[i][j] = -1;
            }
        }
        cout << "max value: " << knap(dp, N, W, weights, values) << endl;
    }
    
    return 0;
}