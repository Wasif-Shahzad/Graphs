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
vector<vector<int>> cc;
vector<int> c_cc;

void dfs(int v){
	vis[v] = 1;
	c_cc.pb(v);
	for(auto child: graph[v]){
		if(!vis[child]){
			dfs(child);
		}
	}
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
	int c =0;
	le(i, 1, n){
		if(!vis[i]){
			c_cc.clear();
			dfs(i);
			cc.pb(c_cc);
			c++;
		}
	}
	cout << cc.size() << endl;
	for(auto x: cc){
		for(auto y: x){
			cout << y << " ";
		}
		cout << "\n";
	}
}
