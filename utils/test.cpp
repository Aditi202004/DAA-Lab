#include <iostream>
#include <vector>
using namespace std;

int graph[18][18][2];

// Initializing dp of size =
// (2^18)*18*2.
long long dp[1 << 18][18][2];

// Recursive Function to calculate
// Minimum Cost with alternate 
// colour edges
long long minCost(int n, int m, int mask, int prev, int col)
{
	// Base case
	if (mask == ((1 << n) - 1)) {
		return 0;
	}
	// If already calculated
	if (dp[mask][prev][col == 1] != 0) {
		return dp[mask][prev][col == 1];
	}

	long long ans = 1e9;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			// Masking previous edges
			// as explained in above formula.
			if (graph[prev][i][j] && !(mask & (1 << i)) 
				&& (j != col)) {
				long long z = graph[prev][i][j] + 
							minCost(n,m,mask|(1<<i),i,j);
				ans = min(z, ans);
			}
		}
	}

	return dp[mask][prev][col == 1] = ans;
}

// Function to Adjacency
// List Representation 
// of a Graph
void makeGraph(vector<pair<pair<int,int>,
					pair<int,char>>>& vp,int m){

for (int i = 0; i < m; i++) {
	int a = vp[i].first.first - 1;
	int b = vp[i].first.second - 1;
	int cost = vp[i].second.first;
	char color = vp[i].second.second;
	graph[a][b][color == 'W'] = cost;
	graph[b][a][color == 'W'] = cost;
}
}

// Function to getCost
// for the Minimum Spanning
// Tree Formed
int getCost(int n,int m){
	
	// Assigning maximum
	// possible value.
	long long ans = 1e9;

	for (int i = 0; i < n; i++) {
		ans = min(ans, minCost(n, m, 1 << i, i, 2));
	}

	if (ans != 1e9) {
		return ans;
	}
	else {
		return -1;
	}
}

// Driver code
int main()
{
	int n = 3, m = 3;
	vector<pair<pair<int, int>, pair<int, char> > > vp = {
		{ { 1, 2 }, { 10, 'W' } },
		{ { 1, 2 }, { 3, 'B' } },
		{ { 2, 3 }, { 4, 'W' } },
		{ { 2, 3 }, { 5, 'B' } }
	};

	makeGraph(vp,m);
	cout << getCost(n,m) << '\n';
	
	return 0;
}
