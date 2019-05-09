#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
class Shark {
public:
	int r;
	int c;
	int s;
	int d;
	int z;
	void setInfo(int r, int c, int s, int d, int z)
	{
		this->r = r;
		this->c = c;
		this->s = s;
		this->d = d;
		this->z = z;
	}
};

int m[100][100];
vector<Shark> v;
int answer;
int R, C, M;
void fishing(int j) {
	for (int i = 0; i < R; i++)
	{
		if (m[i][j])
		{
			for (auto p=v.begin();p!=v.end();p++) 
			{
				if ((*p).r == i && (*p).c == j)
				{
					answer += (*p).z;
					m[p->r][p->c] = 0;
					v.erase(p);
					
					break;
				}
			}
			break;
		}
	}
}
void fighting() {
	for (auto p = v.begin(); p != v.end();)
	{
		if (m[p->r][p->c] > p->z)
		{
			p=v.erase(p);
		}
		else
			p++;
	}
}
void moving() {
	for (auto p : v)
		m[p.r][p.c] = 0;
	for (auto it = v.begin(); it != v.end(); it++)
	{
		int x = it->c;
		int y = it->r;

		int dist = (*it).s;
		if ((*it).d % 2)
		{
			dist %= 2 * (R - 1);
		}else 
		{
			dist %= 2 * (C - 1);
		}

		for (int i = 0; i < dist; i++)
		{
			x += dx[it->d];
			y += dy[it->d];
			if (x < 0 || x >= C)
			{
				x -= dx[it->d] << 1;
				it->d = (it->d + 2) % 4;
			}
			else if (y < 0 || y >= R)
			{
				y -= dy[it->d] << 1;
				it->d = (it->d + 2) % 4;
			}
		}
		if (m[y][x] < it->z)m[y][x] = it->z;
		it->r = y;
		it->c = x;
	}
	
}
void init() {
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			m[i][j] = 0;
}
int main(int argc, char** argv)
{
	answer = 0;
	cin >> R >> C >> M;
	if (!M)
	{
		cout << 0;
		return 0;
	}
	Shark shark;
	for (size_t i = 1; i <= M; i++)
	{
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		switch (d) {
		case 1:
			d = 3;
			break;
		case 2:
			d = 1;
			break;
		case 3:
			d = 0;
			break;
		case 4:
			d = 2;
			break;
		}
		shark.setInfo(--r, --c, s, d, z);
		v.push_back(shark);
		m[r][c] = z;
	}
	for (int i = 0; i < C; i++)
	{
		fishing(i);
		moving();
		fighting();
	}
	cout << answer;
	return 0;
}


