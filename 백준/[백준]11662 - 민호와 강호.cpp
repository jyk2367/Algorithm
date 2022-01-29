#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	double ax, ay, bx, by, cx, cy, dx, dy;

	cin>> ax>>ay>> bx>> by>> cx>> cy>> dx>> dy;

	double answer = 1000000;
	double denominator = 10000;
	double lgst = denominator, shst =0;

	while (lgst - shst >= 1e-6) {
		double onethree = (shst * 2 + lgst) / 3;
		double twothree = (shst + lgst * 2) / 3;

		pair<double, double> p1 = { ax + (bx - ax) * (onethree/ denominator) , ay+ (by-ay)* (onethree / denominator) };// 1/3지점 민호
		pair<double, double> p2 = { cx + (dx - cx) * (onethree / denominator), cy + (dy - cy)* (onethree / denominator) };// 1/3지점 강호

		pair<double, double> p3 = { ax + (bx - ax) * (twothree / denominator), ay + (by - ay) * (twothree / denominator) };// 2/3지점 민호
		pair<double, double> p4 = { cx + (dx - cx) * (twothree / denominator), cy + (dy - cy) * (twothree / denominator) };// 2/3지점 강호

		
		double onethreeLen = sqrt(pow(p2.second-p1.second,2)+pow(p2.first-p1.first,2));// 1/3지점에서 민호와 강호 사이 거리
		double twothreeLen = sqrt(pow(p4.second-p3.second,2)+pow(p4.first-p3.first,2));// 2/3지점에서 민호와 강호 사이 거리

		answer = min(answer, min(onethreeLen, twothreeLen));

		if (onethreeLen < twothreeLen) {
			lgst = twothree;
		}
		else
			shst = onethree;
	}
	
	
	std::cout.precision(10);
	std::cout << fixed;
	std::cout << answer << "\n";
	return 0;

}