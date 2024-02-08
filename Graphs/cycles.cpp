#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define le(i, a, b) for(int i = a; i <= b; i++)
#define ls(i, a, b) for(int i = a; i < b; i++)
#define ge(i, a, b) for(int i = a; i >= b; i--)
#define gr(i, a, b) for(int i = a; i > b; i--) 
#define io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define test_cases int t; cin >> t; while(t--)

const int N = 1e+5;
vector<int> graph[N];
bool vis[N];

bool dfs(int v, int p){
	vis[v] = 1;
	bool isLoop = false;
	for(auto c: graph[v]){
		if(vis[c] && c == p) continue;
		if(vis[c]) return true;

		isLoop |= dfs(c, v);
	}
	return isLoop;
}

int main(){
	io
	int n, e;
	cin >> n >> e;
	ls(i, 0, e){
		int x, y;
		cin >> x >> y;
		graph[x].pb(y);
		graph[y].pb(x);
	}
	bool loop = false;
	le(i, 1, n){
		if(vis[i]) continue;
		if(dfs(i, 0)){
			loop = true;
			break;
		}
	}
	cout << loop << endl;
}