#include <iostream>
using namespace std;
long long a, b, c;

int f(int x, int y)
{
	if (y == 0)return 1;

	long long t = f(x, y >> 1);
	t = (long long)t*t%c;
	if (y % 2)t = t * x % c;
	return t;
}

int main() {
	cin >> a >> b >> c;
	cout << f(a, b);
	return 0;
}
