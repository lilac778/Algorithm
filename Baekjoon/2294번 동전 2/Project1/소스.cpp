#include <iostream>
#include <vector>
using namespace std;
int N, K;
int answer;
int coin[100], dp[101][10001];
int min(int a, int b) { return a < b ? a : b; }
const int IMP = 100000000;
int f(int n, int k)
{
	if (n == N)return k==0?0: IMP;
	if (dp[n][k] != -1)return dp[n][k];
	int result = f(n+1, k);
	if (coin[n] <= k)
		result = min(result, f(n, k - coin[n])+1);
	dp[n][k] = result;
	return result;
}
int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> coin[i];

	for(int i=0;i<=N;i++)
		for (int j = 0; j <= K; j++)
			dp[i][j] = -1;
	
	answer = f(0, K);
	if (answer == IMP)answer = -1;
 	cout << answer;
	return 0;
  }
