#include <bits/stdc++.h>
using namespace std;

struct Student {
	string name;
	int kor, eng, math;
};


bool compare(const Student & s1, const Student& s2) {
	if (s1.kor == s2.kor) {
		if (s1.eng == s2.eng) {
			if (s1.math == s2.math)
				return s1.name < s2.name;
			else
				return s1.math > s2.math;
		}
		else
			return s1.eng < s2.eng;
	}
	else
		return s1.kor > s2.kor;
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<Student> v;
	int N;
	cin >> N;
	while (N--) {
		Student st;
		cin >> st.name >> st.kor >> st.eng >> st.math;
		v.push_back(st);
	}
	sort(v.begin(), v.end(),compare);

	int VSIZE = v.size();
	for (int i = 0; i < VSIZE; i++) {
		cout << v[i].name << "\n";
	}
	
	return 0;
}