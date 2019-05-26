#include <iostream>
using namespace std;
int N;
int arr[2187][2187];
int answer[3];

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
		answer[arr[y][x] + 1]++;
		return;
	}
	int m = len / 3;
	for (int i = 0;i<3;i++)
		for (int j=0;j<3;j++)
			f(x+j*m, y+i*m, m);
	
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	f(0, 0, N);
	cout << answer[0] << endl << answer[1] << endl << answer[2];
	return 0;
}
