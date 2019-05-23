#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n, k;
	int coin[10];
	int answer = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++)cin >> coin[i];
	for (int i = n - 1; i > -1; i--)
	{
		int t = k / coin[i];
		if (t) {
			k -= t * coin[i];
			answer += t;
		}
	}

	cout << answer;
	return 0;
}