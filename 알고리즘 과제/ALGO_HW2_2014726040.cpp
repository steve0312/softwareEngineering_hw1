#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

string n;
vector<int> vt;
bool visit[1501];
string res;

long long dp(vector<int>& v, int sum)
{
	map<int, long long> m, m2;
	for (int i = 0; i < (int)v.size(); i++)
	{
		m2 = m;
		for (auto it = m.begin(); it != m.end(); it++)
		{
			m2[it->first + v[i]] += it->second;
		}
		m2[v[i]]++;
		m = m2;
	}

	vector<int> t;
	t.push_back(v.back());
	visit[v.size() - 1] = true;

	int tsum = sum - v.back();
	for (int i = v.size() - 2; i >= 0; i--) {
		if (tsum - v[i] == 0) {
			t.push_back(v[i]);
			visit[i] = true;
			break;
		}
		else if (m[tsum - v[i]]) {
			t.push_back(v[i]);
			visit[i] = true;
			tsum -= v[i];
		}
	}

	sort(t.begin(), t.end());
	for (auto i : t) {
		res += to_string(i);
		res += ',';
	}
	return m[sum];
}

void solve() {
	cout << "solve 함수 시작" << endl;

	res = "";
	vt.clear();
	fill(visit, visit + 1501, false);

	cin >> n;

	if (n == "EOI") {
		return;
	}
	int nn = stoi(n);
	int tSum = 0; 

	for (int i = 0; i < nn; i++) {
		int t;
		cin >> t;
		tSum += t;
		vt.push_back(t);
	}

	if (tSum % 2) {
		cout << "0\n";
		solve();
		return;
	}

	tSum /= 2;
	sort(vt.begin(), vt.end());

	res += "{";
	long long v1 = dp(vt, tSum) / 2;
	if (v1 > ULONG_MAX) {
		cout << "NUMEROUS\n";
		solve();
		return;
	}
	cout << v1 << "\n";

	res.pop_back();
	res += "},{";
	for (int i = 0; i < nn; i++) {
		if (!visit[i]) {
			res += to_string(vt[i]);
			res += ',';
		}
	}
	res.pop_back();
	res += "}\n";

	cout << res;
	solve();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout << "1번 사용자의 algo_hw2 코드 수정테스트" << endl;
	solve();

	system("pause");
	return 0;
}