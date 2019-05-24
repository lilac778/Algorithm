#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int x, y, z, n;
int answer, suc;
vector<pair<int, int>>v;

void f(int nx, int ny, int nz)
{
	if (!suc)return;
	if (!nx || !ny || !nz)return;
	for (auto &p : v)
	{
		if (p.second && nx >= p.first&&ny >= p.first&&nz >= p.first)
		{
			answer++;
			p.second--;
			f(nx, ny, nz - p.first);
			f(p.first, ny-p.first, p.first);
			f(nx-p.first, ny, p.first);
			return;
		}
	}
	suc = false;
}

int main() {
	suc = true;
	cin >> x >> y >> z >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(1<<a, b));

	}
	sort(v.rbegin(), v.rend());
	f(x, y, z);
	cout << (suc?answer:-1);
	return 0;
}