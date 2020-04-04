#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

deque<int> dq;
string t, result;
char dt[30];
int sz;
bool flag = false;


void foo(string str, int y) {
	if (flag) {
		return;
	}
	if (str == result) {
		cout << dq.size() << "\n";
		for (auto i : dq) {
			cout << i + 1 << " ";
		}
		cout << "\n";
		flag = true;
		return;
	}

	if (y > 0) {
		if (str[y - 1] == 'W') {
			swap(str[y], str[y - 1]);
			dq.push_back(y - 1);
			foo(str, y - 1);
			dq.pop_back();
			swap(str[y], str[y - 1]);
		}
	}

	if (y > 1) {
		if (str[y - 2] == 'W' && str[y - 1] == 'B') {
			swap(str[y - 2], str[y]);
			dq.push_back(y - 2);
			foo(str, y - 2);
			dq.pop_back();
			swap(str[y - 2], str[y]);
		}
	}

	if (y < sz - 1) {
		if (str[y + 1] == 'B') {
			swap(str[y], str[y + 1]);
			dq.push_back(y + 1);
			foo(str, y + 1);
			dq.pop_back();
			swap(str[y], str[y + 1]);
		}
	}

	if (y < sz - 2) {
		if (str[y + 1] == 'W' && str[y + 2] == 'B') {
			swap(str[y + 2], str[y]);
			dq.push_back(y + 2);
			foo(str, y + 2);
			dq.pop_back();
			swap(str[y + 2], str[y]);
		}
	}
}

void solve() {
	cout << "solve 함수 시작" << endl;
	cin >> t;
	if (t == "EOI") {
		return;
	}

	int n = atoi(t.c_str());

	fill(dt, dt + 30, NULL);


	for (int i = 0; i < n; i++) {
		dt[i] = 'W';
	}
	dt[n] = '0';
	for (int i = n + 1; i < 2 * n + 1; i++) {
		dt[i] = 'B';
	}

	sz = n * 2 + 1;

	result = dt;
	reverse(result.begin(), result.end());
	flag = false;
	foo(dt, n);

	cout << "solve method recursive" << endl;
	solve();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout << "1번 사용자의 algo_hw3 코드 수정테스트" << endl;
	solve();

	cout << "2번 사용자의 algo_hw3 코드 수정테스트" << endl;
	system("pause");
	return 0;
}