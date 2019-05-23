#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n, l;
	int pip[1001]{};
	int temp;
	int answer = 0;
	cin >> n >> l;

	vector<int>t(n);
	for (int i = 0; i < n; i++)
	{
		cin >> t[i];
	}
	sort(t.begin(), t.end());
	for (int i = 0; i < n; i++)
	{
		if (pip[t[i]] == 0)
		{
			for (int j = 0; j < l&&t[i] + j < 1001; j++)
				pip[t[i] + j] = 1;

			answer++;
		}
	}
	cout << answer;
	return 0;
}