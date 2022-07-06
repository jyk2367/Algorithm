#include <bits/stdc++.h>
#include <unordered_set>


using namespace std;

long long X, Y,Z;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> X >> Y;
	
	Z = Y*100 / X;

	long long left = 0, right = 1'000'000'000;
	while (left <= right) {
		long long mid = (left + right) / 2;

		long long nowZ = ((Y+mid)*100) / (X + mid);
		if (nowZ != Z) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	if (left != 1'000'000'001)
		cout << left << "\n";
	else
		cout << "-1" << "\n";

	return 0;
}