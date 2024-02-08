#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define le(i, a, b) for(int i = a; i <= b; i++)
#define ls(i, a, b) for(int i = a; i < b; i++)
#define ge(i, a, b) for(int i = a; i >= b; i--)
#define gr(i, a, b) for(int i = a; i > b; i--) 

int dp[500005];

int main(){
	int n, w;
	cin >> n >> w;
	vector<int> a(n), b;
	ls(i, 0, n){
		cin >> a[i];
	}
	int curr = 0;
	ls(i, 0, w){
		curr += a[i];
	}
	int mn = curr; int mi = 1;
	ls(i, w, n){
		curr += a[i] - a[i - w];
		if(curr < mn){
			mn = curr;
			mi = i - w + 2;
		}
	}
	cout << mi << endl;
}