#include <iostream>
#include <string>
using namespace std;
int N;
int arr[64][64];

int check(int x, int y, int len)
{
	for (int i = y; i < y+len; i++)
		for (int j = x; j < x+len; j++)
			if (arr[i][j] != arr[y][x])
				return false;
	
	return true;
}
void f(int x, int y, int len)
{
	if (check(x, y, len))
	{
		cout << arr[y][x];
		return;
	}
	cout << "(";
	int m = len >> 1;
	for (int i = 0;i<2;i++)
		for (int j=0;j<2;j++)
			f(x+j*m, y+i*m, m);
	cout << ")";
}

int main() {
	cin >> N;
	char c[65];
	for (int i = 0; i < N; i++)
	{
		cin >> c;
		for (int j = 0; j < N; j++)
			arr[i][j] = c[j] - '0';
	}
	f(0, 0, N);
	return 0;
}
