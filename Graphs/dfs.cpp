#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define ls(i, a, b) for(int i = a; i < b; i++)
#define le(i,a , b) for(int i = a; i <= b; i++)
#define gt(i, a, b) for(int i = a; i > b; i--)
#define ge(i, a, b) for(int i = a; i >= b; i--)

const int N = 1e5+10;
vector<int> graph[N];
bool vis[N];

void dfs(int v){
	vis[v] = 1;
	for(auto child: graph[v]){
		if(vis[child]) continue;
		dfs(child);
	}
	cout << v << " ";
}

int main(){
	int n, m;
	cin >> n >> m;
	ls(i, 0, m){
		int v1, v2;
		cin >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	dfs(1);
	return 0;
}