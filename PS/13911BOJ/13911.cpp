#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>p;
ll n, m, Mnum, Snum, Mcon, Scon;
vector<vector<p>>vec;
ll dist[10010][2];
int home[10010];
void func(int start, int  idx, bool flag)
{
	priority_queue<p, vector<p>, greater<p>>pq;
	pq.push(make_pair(0, start));
	dist[start][idx] = 0;
	while (!pq.empty()) {
		ll here = pq.top().second;
		ll weight = pq.top().first;
		pq.pop();
		if (dist[here][idx] < weight)continue;
		dist[here][idx] = weight;
		for (int i = 0; i < vec[here].size(); i++) {
			int nextN = vec[here][i].first;
			int nextD = vec[here][i].second + weight;
			if (dist[nextN][idx] >nextD ) {
				dist[nextN][idx] = nextD;
				pq.push(make_pair(nextD, nextN));
			}
		}
	}
}

int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	vec.resize(10020);
	for (int i = 0, a, b, w; i < m; i++) {
		cin >> a >> b >> w;
		vec[a].push_back(make_pair(b, w));
		vec[b].push_back(make_pair(a, w));
	}
	cin >> Mnum >> Mcon;
	for (int i = 0, tmp; i < Mnum; i++) {
		cin >> tmp; home[tmp] = 1;
		vec[0].push_back(make_pair(tmp, 0));
	}
	cin >> Snum >> Scon;
	for (int i = 0, tmp; i < Snum; i++) {
		cin >> tmp; home[tmp] = 1;
		vec[10009].push_back(make_pair(tmp, 0));
	}
	for (int i = 0; i <= n; i++) {
		dist[i][0] = dist[i][1] = LLONG_MAX;
	}
	dist[0][0] = 0;
	func(0, 0,false);
	dist[10009][1] = 0;
	func(10009, 1,false);
	bool flag = false;
	ll ans = LLONG_MAX;
	for (int i = 1; i <= n; i++) {
		if(home[i] == 1)continue;
		if (dist[i][0] <= Mcon && dist[i][1] <= Scon) {
			flag = true;
			ans = min(dist[i][0] + dist[i][1], ans);
		}
	}
	if (Snum == 0 || Mnum == 0)flag = false;
	if (!flag)cout << "-1";
	else cout << ans;
	return 0;
}