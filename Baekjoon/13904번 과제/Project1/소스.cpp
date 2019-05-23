#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n;
	int cal[1001]{};
	int answer = 0;
	vector<pair<int, int>>v;
	int d = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
		if (a > d)d = a;

	}
	sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b) {
		return a.second > b.second;
	});
	for (int i = 0; i <n; i++)
	{
		for(int j=v[i].first;j>0;j--)
			if (!cal[j]) {
				cal[j] = 1;
				answer += v[i].second;
				break;
			}
	}

	cout << answer;
	return 0;
}