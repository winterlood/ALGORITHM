#include <iostream>
#include <string>
#include <queue>
#include <tuple>
using namespace std;
char map[11][11];
typedef pair<int, int>p;
queue<tuple<p, p, int>>q;
bool Rgoal, Bgoal;
bool ans;
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	p R, B, G;
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R') {
				R = { i,j };
				map[i][j] = '.';
			}
			if (map[i][j] == 'B') {
				B = { i,j };
				map[i][j] = '.';
			}
			if (map[i][j] == 'O') {
				G = { i,j };
			}
		}
	}
	q.push({ R,B,1 });
	while (!q.empty()) {
		int nowRx = get<0>(q.front()).first;
		int nowRy = get<0>(q.front()).second;
		int nowBx = get<1>(q.front()).first;
		int nowBy = get<1>(q.front()).second;
		int Rx = nowRx;
		int Ry = nowRy;
		int Bx = nowBx;
		int By = nowBy;
		int cnt = get<2>(q.front());
		q.pop();
		if (cnt > 10)break;
		//up
		bool Rc = false, Bc = false;
		Rgoal = false; Bgoal = false;
		for (int i = 1; ; i++) {
			if (!Rc)
			{
				if (map[nowRx - i][nowRy] == 'O') {
					Rgoal = true;
					Rc = true;
				}
				else if (map[nowRx - i][nowRy] == '#') {
					Rc = true;
					nowRx -= i - 1;
				}
			}
			if (!Bc)
			{
				if (map[nowBx - i][nowBy] == 'O') {
					Bgoal = true;
					Bc = true;
				}
				else if (map[nowBx - i][nowBy] == '#') {
					Bc = true;
					nowBx -= i - 1;
				}
			}
			if (Rc && Bc)break;
		}
		if (Rgoal && !Bgoal) {
			ans = true;
			cout << cnt; break;
		}
		else if (!Bgoal && !Rgoal) {
			if (nowRx == nowBx && nowRy == nowBy) {
				(Rx > Bx) ? nowRx += 1 : nowBx += 1;
			}
			if (!(Rx == nowRx && Ry == nowRy && Bx == nowBx && By == nowBy))
			{
				q.push({ {nowRx,nowRy},{nowBx,nowBy},cnt + 1 });
			}
		}
		//down
		nowRx = Rx;
		nowRy = Ry;
		nowBx = Bx;
		nowBy = By;
		Rc = false; Bc = false;
		Rgoal = false; Bgoal = false;
		for (int i = 1; ; i++) {
			if (!Rc)
			{
				if (map[nowRx + i][nowRy] == 'O') {
					Rgoal = true;
					Rc = true;
				}
				else if (map[nowRx + i][nowRy] == '#') {
					Rc = true;
					nowRx += i - 1;
				}
			}
			if (!Bc)
			{
				if (map[nowBx + i][nowBy] == 'O') {
					Bgoal = true;
					Bc = true;
				}
				else if (map[nowBx + i][nowBy] == '#') {
					Bc = true;
					nowBx += i - 1;
				}
			}
			if (Rc && Bc)break;
		}
		if (Rgoal && !Bgoal) {
			ans = true;
			cout << cnt; break;
		}
		else if (!Bgoal && !Rgoal) {
			if (nowRx == nowBx && nowRy == nowBy) {
				(Rx < Bx) ? nowRx -= 1 : nowBx -= 1;
			}
			if (!(Rx == nowRx && Ry == nowRy && Bx == nowBx && By == nowBy))
			{
				q.push({ { nowRx,nowRy },{ nowBx,nowBy },cnt + 1 });
			}
		}
		//left
		nowRx = Rx;
		nowRy = Ry;
		nowBx = Bx;
		nowBy = By;
		Rc = false; Bc = false;
		Rgoal = false; Bgoal = false;
		for (int i = 1; ; i++) {
			if (!Rc)
			{
				if (map[nowRx][nowRy - i] == 'O') {
					Rgoal = true;
					Rc = true;
				}
				else if (map[nowRx][nowRy - i] == '#') {
					Rc = true;
					nowRy -= i - 1;
				}
			}
			if (!Bc)
			{
				if (map[nowBx][nowBy - i] == 'O') {
					Bgoal = true;
					Bc = true;
				}
				else if (map[nowBx][nowBy - i] == '#') {
					Bc = true;
					nowBy -= i - 1;
				}
			}
			if (Rc && Bc)break;
		}
		if (Rgoal && !Bgoal) {
			ans = true;
			cout << cnt; break;
		}
		else if (!Bgoal && !Rgoal) {
			if (nowRx == nowBx && nowRy == nowBy) {
				(Ry < By) ? nowBy += 1 : nowRy += 1;
			}
			if (!(Rx == nowRx && Ry == nowRy && Bx == nowBx && By == nowBy))
			{
				q.push({ { nowRx,nowRy },{ nowBx,nowBy },cnt + 1 });
			}
		}
		//right
		nowRx = Rx;
		nowRy = Ry;
		nowBx = Bx;
		nowBy = By;
		Rc = false; Bc = false;
		Rgoal = false; Bgoal = false;
		for (int i = 1; ; i++) {
			if (!Rc)
			{
				if (map[nowRx][nowRy + i] == 'O') {
					Rgoal = true;
					Rc = true;
				}
				else if (map[nowRx][nowRy + i] == '#') {
					Rc = true;
					nowRy += i - 1;
				}
			}
			if (!Bc)
			{
				if (map[nowBx][nowBy + i] == 'O') {
					Bgoal = true;
					Bc = true;
				}
				else if (map[nowBx][nowBy + i] == '#') {
					Bc = true;
					nowBy += i - 1;
				}
			}
			if (Rc && Bc)break;
		}
		if (Rgoal && !Bgoal) {
			ans = true;
			cout << cnt; break;
		}
		else if (!Bgoal && !Rgoal) {
			if (nowRx == nowBx && nowRy == nowBy) {
				(Ry < By) ? nowRy -= 1 : nowBy -= 1;
			}
			if (!(Rx == nowRx && Ry == nowRy && Bx == nowBx && By == nowBy))
			{
				q.push({ { nowRx,nowRy },{ nowBx,nowBy },cnt + 1 });
			}
		}
	}
	if (!ans)cout << "-1";
	return 0;
}