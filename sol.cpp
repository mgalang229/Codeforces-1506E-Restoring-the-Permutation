#include <bits/stdc++.h>
using namespace std;

void test_case(int& tc) {
	int n;
	cin >> n;
	int q[n];
	for (int i = 0; i < n; i++)
		cin >> q[i];
	int ans[n], p = -1;
	memset(ans, -1, sizeof(ans));
	set<int> s;
	for (int i = 0; i < n; i++) {
		if (q[i] != p) {
			ans[i] = q[i];
			s.insert(q[i]);
		}
		p = q[i];
	}
	vector<int> vec;
	for (int i = 1; i <= n; i++) {
		if (s.find(i) == s.end())
			vec.push_back(i);
	}
	// minimal:
	int index = 0;
	for (int i = 0; i < n; i++) {
		if (ans[i] == -1 && index < (int) vec.size()) {
			cout << vec[index];
			index++;
		} else {
			cout << ans[i];
		}
		cout << " ";
	}
	cout << "\n";

	// maximal:
	s.clear();
	for (int& x : vec)
		s.insert(x);
	for (int i = 0; i < n; i++) {
		if (ans[i] == -1) {
			auto it = s.lower_bound(q[i]);
			int pr = *prev(it, 1);
			cout << pr;
			s.erase(pr);
		} else {
			cout << ans[i];
		}
		cout << " ";
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T = 1;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
		test_case(tc);
}
