#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<set>
using namespace std;

int m[300];
int visit[7];
int answer;
int n, k, l;

int num[128];
int main(int argc, char** argv)
{
	int test_case;
	int T;
	string s;
	set<int, greater<int>>se;
	for (int i = '0'; i <= '9'; i++)num[i] = i - '0';
	for (int i = 'A'; i <= 'F'; i++)num[i] = 10 + i - 'A';
	freopen("sample_input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		se.clear();
		cin >> n >> k >> s;
		s += s;
		l = n >> 2;
		for (size_t i = 0; i < n; i++)
		{
			int sum = 0;
			for (size_t j = 0; j < l; j++)
			{
				int temp = (num[s.at(i + j)] << (4*(l-1-j)));
				sum += temp;
			}
			se.insert(sum);
		}
		int i = 0;
		for (auto it : se) {
			i++;
			if (i == k) {
				answer = it;
				break;
			}
		}
			
		cout << "#" << test_case << " " << answer << endl;
	}
	return 0;
}