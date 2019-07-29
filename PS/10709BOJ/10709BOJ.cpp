#include <iostream>
#include <string>
#include <queue>
#include <tuple>
using namespace std;
int n, m; char a;
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int lastidx = -1;
		for (int j = 0; j < m; j++) {
			cin >> a;
			if (a == 'c') {
				if (j == m - 1)cout << "0";
				else cout << "0 ";
				lastidx = j;
			}
			else {
				if (lastidx == -1) {
					if (j == m - 1)cout << "-1";
					else cout << "-1 ";
				}
				else {
					if (lastidx == -1)cout << j - lastidx;
					else cout << j - lastidx <<" ";
				}
			}
		}
		cout << "\n";
	}
	return 0;
}