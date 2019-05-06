#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

const int d = 400;
int m[800][800][2];
int visit[7];
int answer;
int N, M, K;

priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>>* q;

void solution() {
	priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>>*t, *p = new priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>>;
	

	int time = K;
	while (time--) {
		while (!q->empty()) {
			int hp = q->top().first;
			int x = q->top().second.second;
			int y = q->top().second.first;
			q->pop();
			if (--m[y][x][1] == hp - 1)
			{
				for (int i = 0; i < 4; i++) {
					int ny = y + dy[i];
					int nx = x + dx[i];
					if (!m[ny][nx][0]) {
						m[ny][nx][0] = hp;
						m[ny][nx][1] = hp * 2;
						p->push(make_pair(hp, make_pair(ny, nx)));
					}
				}
			}
			if (m[y][x][1])p->push(make_pair(hp, make_pair(y, x)));

		}
		t = q;
		q = p;
		p = t;
	}
	answer = q->size();
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("sample_input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		for(int i=d-50-(K/2);i<d+50+(K/2);i++)
			for (int j = d - 50 - (K / 2); j < d + 50 + (K / 2); j++) {
				m[i][j][0] = 0;
				m[i][j][1] = 0;
			}
		answer = 0;
		cin >> N >> M >> K;
		q = new priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>>;
		for (size_t i = d; i < d + N; i++)
		{
			for (size_t j = d; j < d + M; j++)
			{
				int temp;

				cin >> temp;
				m[i][j][0] = temp;
				if (temp) {
					m[i][j][1] = temp * 2;
					q->push(make_pair(temp, make_pair(i, j)));
				}
			}
		}
		solution();
		cout << "#" << test_case << " " << answer << endl;
	}
	return 0;
}