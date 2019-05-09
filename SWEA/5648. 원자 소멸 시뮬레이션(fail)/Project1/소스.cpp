#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int m[4001][4001];
int live[1001];
int answer;
int N;
int queue[1001], head, tail;

class mole {
public:
	int x;
	int y;
	int s;
	int k;
	void setM(int y, int x, int s, int k) {
		this->x = x;
		this->y = y;
		this->s = s;
		this->k = k;
	}

};
mole v[1001];
void solution() {
	int life = N;
	int x, y, s, k;
	while (head!=tail) {
		int i = queue[head++];
		head %= 1001;

		//for (int i = 1; i <= N; i++) 
		{
			if (!live[i])continue;
			x = v[i].x;
			y = v[i].y;
			s = v[i].s;
			k = v[i].k;
			
			x += dx[s];
			y += dy[s];
			if (x < 0 || x >= 4000 || y < 0 || y >= 4000) {
				live[i] = 0;
				//life--;
				continue;
			}
			if (m[y][x]) {
				live[i] = 0;
				live[m[y][x]] = 0;
				answer = answer + k + v[m[y][x]].k;
				m[y][x] = 0;
				m[v[i].y][v[i].x] = 0;
				//life -= 2;
			}
			else {
				m[v[i].y][v[i].x] = 0;
				m[y][x] = i;
				v[i].y = y;
				v[i].x = x;
				queue[tail++] = i;
				tail %= 1001;
			}
		}
	}

	
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("sample_input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		head = 0;
		tail = 0;
		answer = 0;
		cin >> N;
		for (size_t i = 1; i <= N; i++)
		{
			int x, y, s, k;
			cin >> x >> y >> s >> k;
			x = (x + 1000) << 1;
			y = (y + 1000) << 1;
			v[i].setM(y, x, s, k);
			m[y][x] = i;
			queue[tail++] = i;
			live[i] = true;
		}
		solution();
			
		std::cout << "#" << test_case << " " << answer << endl;
	}
	return 0;
}