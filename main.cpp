#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;

int n;
vi a;
vi incr;
vi decr;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n;
	a = vi(n);
	incr = vi(n, 1);
	decr = vi(n, 1);

	for (auto i = 0; i < n; ++i) {
		cin >> a[i];

		for (auto j = 0; j < i; ++j) {
			if (a[j] < a[i]) {
				incr[i] = max(incr[i], incr[j] + 1);
			}
		}
	}

	for (auto i = n - 1; 0 <= i; --i) {
		for (auto j = n - 1; i < j; --j) {
			if (a[j] < a[i]) {
				decr[i] = max(decr[i], decr[j] + 1);
			}
		}
	}

	auto ans = int{ 0 };
	for (auto i = 0; i < n; ++i) {
		const auto& temp = incr[i] + decr[i] - 1;
		if (ans < temp) {
			ans = temp;
		}
	}

	cout << ans;

	return 0;
}