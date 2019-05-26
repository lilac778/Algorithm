#include <iostream>
using namespace std;
long long max(long long a, long long b)
{
	return a > b ? a : b;
}
long long min(long long a, long long b)
{
	return a > b ? b : a;
}
int n;
int arr[100001];
long long sum[100001];

int f(int s, int e)
{
	if (s == e)return arr[s];
	int mid = (s + e) / 2;
	int result = max(f(s, mid), f(mid + 1, e));

	int l = mid, r = mid + 1;
	int Min = min(arr[mid], arr[mid + 1]);
	result = max(result, Min*(r-l+1));
	while (l > s || r < e)
	{
		if (l == s||(r<e&&arr[r + 1]>arr[l - 1]))
		{
			r++;
			Min = min(Min, arr[r]);
		}
		else {
			l--;
			Min = min(Min, arr[l]);
		}
		result = max(result, (r-l+1)*Min);
	}
	return result;

}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << f(0, n-1);
	return 0;
}
