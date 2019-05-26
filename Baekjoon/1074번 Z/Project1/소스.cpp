#include <iostream>
using namespace std;
int N, r, c;
int answer;

void f(int x, int y, int n)
{
	if (n < 2)
	{
		if (y < r)answer += 2;
		if (x < c)answer += 1;
		return;
	}
	if (r >= y + n)
	{
		answer += n * n * 2;

		y += n;
	}
	if (c >= x + n)
	{
		answer += n * n;
		x += n;
	}
	f(x, y, n >> 1);
}
int main() {
	cin >> N >> r >> c;
	int t = 1 << N;
	int n = t >> 1;
	int x = 0, y = 0;
	f(x, y, n);
 	cout << answer;
	return 0;
  }
