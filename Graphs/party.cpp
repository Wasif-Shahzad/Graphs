#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define ls(i, a, b) for(int i = a; i < b; i++)
#define le(i,a , b) for(int i = a; i <= b; i++)
#define gt(i, a, b) for(int i = a; i > b; i--)
#define ge(i, a, b) for(int i = a; i >= b; i--)

const int N = 2000;
int graph[N][N];

int main(){
	int n;
	cin >> n;
	ll cnt = 0;
	ls(i, 0, n){
		int x;
		cin >> x;
		if(x != -1){
			graph[i][x] = 1;
			cnt++;
		}
	}
	cout << cnt << endl;
}