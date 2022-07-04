#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

stack<long long> st;
string input[100'000];
int idx = 0;
int N;
bool state = true;

bool IsSizeOK() {
	return st.size() >= 2;
}

bool NUMX(string num) {
	if (abs(stoi(num)) > 1'000'000'000)
		return false;
	st.push(stoi(num));
	return true;
}
bool POP() {
	if (st.empty())
		return false;
	st.pop();
	return true;
}
bool INV() {
	if (st.empty())
		return false;
	int tmp = st.top();
	st.pop();
	st.push(-tmp);
	return true;
}
bool DUP() {
	if (st.empty())
		return false;
	st.push(st.top());
	return true;
}
bool SWP() {
	if (!IsSizeOK())
		return false;
	long long tmp1 = st.top();
	st.pop();
	long long tmp2 = st.top();
	st.pop();

	st.push(tmp1);
	st.push(tmp2);
	return true;
}
bool ADD() {
	if (!IsSizeOK())
		return false;
	long long tmp1 = st.top();
	st.pop();
	long long tmp2 = st.top();
	st.pop();

	if (abs(tmp1 + tmp2) > 1'000'000'000)
		return false;

	st.push(tmp1 + tmp2);
	return true;
}
bool SUB() {
	if (!IsSizeOK())
		return false;
	long long tmp1 = st.top();
	st.pop();
	long long tmp2 = st.top();
	st.pop();
	if (abs(tmp2- tmp1) > 1'000'000'000)
		return false;
	st.push(tmp2-tmp1);
	return true;
}
bool MUL() {
	if (!IsSizeOK())
		return false;
	long long tmp1 = st.top();
	st.pop();
	long long tmp2 = st.top();
	st.pop();

	if (abs(tmp1 * tmp2) > 1'000'000'000)
		return false;
	st.push(tmp1 * tmp2);
	return true;
}
bool DIV() {
	if (st.size() < 2)
		return false;
	long long tmp1 = st.top();
	st.pop();
	long long tmp2 = st.top();
	st.pop();

	if (tmp1 == 0||abs(tmp2 / tmp1) > 1'000'000'000)
		return false;

	long long absdiv = abs(tmp2) / abs(tmp1);
	
	if (tmp1 < 0 && tmp2 < 0 || tmp1>=0 && tmp2>=0)
		st.push(absdiv);
	else
		st.push(-absdiv);
	return true;
}
bool MOD() {
	if (st.size() < 2)
		return false;
	long long tmp1 = st.top();
	st.pop();
	long long tmp2 = st.top();
	st.pop();

	if (tmp1 == 0||abs(tmp2 % tmp1) > 1'000'000'000)
		return false;

	long long absmod = abs(tmp2) % abs(tmp1);

	if (tmp2>=0)
		st.push(absmod);
	else
		st.push(-absmod);

	return true;
}

bool GetCommand() {
	idx = 0;
	while (idx < 100'000) {
		cin >> input[idx];
		if (input[idx].compare("NUM") == 0) {
			string tmp;
			cin >> tmp;
			input[idx] += tmp;
		}
		if (input[idx].compare("END") == 0)
			return true;
		if (input[idx].compare("QUIT")==0)
			return false;
		idx++;
	}
	return true;
}

bool CommandManager(string &cmd){
	if (cmd.substr(0, 3).compare("NUM") == 0) {
		return NUMX(cmd.substr(3));
	}
	else if (cmd.substr(0, 3).compare("POP") == 0) {
		return POP();
	}
	else if (cmd.substr(0, 3).compare("INV") == 0) {
		return INV();
	}
	else if (cmd.substr(0, 3).compare("DUP") == 0) {
		return DUP();
	}
	else if (cmd.substr(0, 3).compare("SWP") == 0) {
		return SWP();
	}
	else if (cmd.substr(0, 3).compare("ADD") == 0) {
		return ADD();
	}
	else if (cmd.substr(0, 3).compare("SUB") == 0) {
		return SUB();
	}
	else if (cmd.substr(0, 3).compare("MUL") == 0) {
		return MUL();
	}
	else if (cmd.substr(0, 3).compare("DIV") == 0) {
		return DIV();
	}
	else if (cmd.substr(0, 3).compare("MOD") == 0) {
		return MOD();
	}
}

bool Program() {
	for (int i = 0; i < idx; i++) {
		if (!CommandManager(input[i])) {
			return false;//실패
		}
	}
	return true;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (state) {
		if (!GetCommand())
			break;
		cin >> N;
		for (int i = 0; i < N; i++) {
			long long num;
			cin >> num;

			st.push(num);

			if (!Program() || st.size() != 1 || st.empty()) {
				cout << "ERROR" << "\n";
			}
			else {
				cout << st.top() << "\n";
			}

			//스택 초기화
			while (!st.empty()) {
				st.pop();
			}
		}
		cout << "\n";
	}

	return 0;
}