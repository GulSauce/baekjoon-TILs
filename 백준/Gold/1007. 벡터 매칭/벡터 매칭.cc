#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <list>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool combination[20];
pii coor[20];
double res = -1;
int N;

double Calc() {
	double sX, sY, eX, eY;
	sX = 0, sY = 0, eX = 0, eY = 0;
	for (int i = 0; i < N; i++) {
		if (combination[i]) {
			sX += coor[i].first;
			sY += coor[i].second;
		}
		else {
			eX += coor[i].first;
			eY += coor[i].second;
		}
	}
	double res = sqrt((sX - eX) * (sX - eX) + (sY - eY) * (sY - eY));
	return res;
}

void Solve(int iter, int r) {
	if (r == N/2) {
		if (res == -1)
			res = Calc();
		else
			res = min(res, Calc());
	}
	for (int i = iter; i < N; i++) {
		combination[i] = true;
		Solve(i+1, r + 1);
		combination[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		res = -1;
		memset(combination, 0, sizeof combination);
		cin >> N;

		for (int i = 0; i < N; i++) 
			cin >> coor[i].first >> coor[i].second;
		Solve(0, 0);
		cout.precision(100);
		cout.fixed;
		cout << res << '\n';
	}
}