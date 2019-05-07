#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int m[100][100];
int answer;
int N;
pair<int, int> hole[11][2];
int visit[11][2];

int change(int block, int dir);

void solution(int y, int x, int dir) {
	int mDir = dir;
	int nx;
	int ny;
	int score = 0;
	int X = x;
	int Y = y;
	int p;
	while (1) {
		nx = x+dx[mDir];
		ny = y+dy[mDir];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
			score++;
			mDir = (mDir + 2) % 4;
			x = nx;
			y = ny;
			continue;
		}
		int t = m[ny][nx];
		int tDir = t % 4;
		if (t > 0 && t < 6) {
			/*if (mDir == tDir)mDir = (mDir + 3) % 4;
			else if (mDir == (tDir+1)%4)mDir = (mDir + 1) % 4;
			else mDir = (mDir + 2) % 4;*/
			mDir = change(t, mDir);
			score++;
			//if (mDir < 0)mDir *= -1;
		}
		else if (t > 5 && t < 11) {
			p = 0;
			if (hole[t][0].first == ny && hole[t][0].second == nx)p = 1;
			nx = hole[t][p].second;
			ny = hole[t][p].first;
		}
		else if (t == -1 || (nx==X&&ny==Y)) {
			if (score > answer)answer = score;
			return;
		}
		x = nx;
		y = ny;
	}

	
}

int change(int block, int dir) {
	int ret = -1;
	switch (block) {
	case 1:
		if (dir == 2)ret = 3;
		else if (dir == 1)ret = 0;
		else ret = (dir + 2) % 4;
		break;
	case 2:
		if (dir == 2)ret = 1;
		else if (dir == 3)ret = 0;
		else ret = (dir + 2) % 4;
		break;
	case 3:
		if (dir == 0)ret = 1;
		else if (dir == 3)ret = 2;
		else ret = (dir + 2) % 4;
		break;
	case 4:
		if (dir == 0)ret = 3;
		else if (dir == 1)ret = 2;
		else ret = (dir + 2) % 4;
		break;
	case 5:
		ret = (dir + 2) % 4;
		break;
	}
	return ret;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("sample_input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		
		answer = 0;
		cin >> N;
		for (int i = 6; i < 11; i++)
			for (int j = 0; j < 2; j++)
				visit[i][j] = 0;
		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = 0; j < N; j++)
			{
				cin >> m[i][j];
				if (m[i][j] >= 6 && m[i][j] <= 10) {
					int t = 0;
					if (visit[m[i][j]][0] == 1)t = 1;
					visit[m[i][j]][t] = 1;
					hole[m[i][j]][t] = make_pair(i, j);
				}
			}
		}
		for(int i=0;i<N;i++)
			for (int j = 0; j < N; j++) 
				for (int k = 0; k < 4; k++)
					if(m[i][j]==0)solution(i, j, k);
			
		std::cout << "#" << test_case << " " << answer << endl;
	}
	return 0;
}