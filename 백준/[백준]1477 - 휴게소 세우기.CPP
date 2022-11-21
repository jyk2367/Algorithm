#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, L;
vector<int> arr;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M >> L;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		arr.push_back(input);
	}
	arr.push_back(0);
	arr.push_back(L);
	sort(arr.begin(), arr.end());

	int low = 1, high = L-1;
	while (low <= high) {
		int mid = (low + high) / 2;
		
		int count = 0;
		for (int i = 1; i < arr.size(); i++) {
			int dist = arr[i] - arr[i - 1];

			count += (dist / mid);
			if(dist%mid==0)
				count--;
		}

		if (count > M)
			low = mid+1;
		else
			high = mid-1;
	}

	cout << low <<"\n";


	
	return 0;

}