#include <iostream>
using namespace std;
int main() {
	int l, p, v, i;
	i = 0;
	while (i++)
	{
		cin >> l >> p >> v;
		if (l == 0)break;
		cout << "Case " << i << ": " << v / p * l + (v%p < l ? v % p : l) << endl;
	}
	return 0;
}