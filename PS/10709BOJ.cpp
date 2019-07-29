#include <iostream>
#include <string>
#include <queue>
#include <tuple>
using namespace std;
typedef long long ll;
typedef tuple<ll, ll, ll>tup;
typedef pair<ll, ll>p;
int n, T,cow[100010][2],cow2[100010][2],maxN;
priority_queue<tup, vector<tup>, greater<tup>>pq;
priority_queue<tup, vector<tup>, greater<tup>>q;
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (ll i = 0,eatT,arrT; i < n; i++) {
		cin >> arrT;
		cin >> eatT;
		pq.push({ arrT,eatT ,i});
	}
	T = pq.top().first + pq.top().second;
	while (!pq.empty()) {
		int tmp = pq.top().first;
		bool flag = false;
		if (T >= tmp) {
			q.push({ get<1>(pq.top()),get<0>(pq.top()),get<2>(pq.top()) });
			pq.pop();
			flag = true;
		}
		if (!flag) {
			int nowT = get<0>(q.top());
			int arrT = get<1>(q.top());
			T += nowT;	
			maxN = max(T-arrT, maxN);
		}
	}
	cout << maxN;
	return 0;
}