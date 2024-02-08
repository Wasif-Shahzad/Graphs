#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define ls(i, a, b) for(int i = a; i < b; i++)
#define le(i,a , b) for(int i = a; i <= b; i++)
#define gt(i, a, b) for(int i = a; i > b; i--)
#define ge(i, a, b) for(int i = a; i >= b; i--)

const int N = 1e3+10;
int graph[N][N];

vector<int> listgraph[N];

int main(){
	int n, m;
	cin >> n >> m;
	ls(i, 0, m){
		int v1, v2, wt;
		cin >> v1 >> v2 >> wt;
		graph[v1][v2] = wt;
		graph[v2][v1] = wt;
		listgraph[v1].push_back({v2, wt});
		listgraph[v2].push_back({v1, wt});
	}
	return 0;
}
