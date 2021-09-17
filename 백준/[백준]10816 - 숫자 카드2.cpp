#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;

    cin >> N;
    vector<int> card;
    while (N--) {
        int num;
        cin >> num;
        card.push_back(num);
    }
    sort(card.begin(), card.end());

    int SIZE = card.size();
    cin >> M;
    while (M--) {
        int num;
        cin >> num;
        cout<<upper_bound(card.begin(),card.end(), num)-lower_bound(card.begin(),card.end(),num)<<"\n";
    }
}