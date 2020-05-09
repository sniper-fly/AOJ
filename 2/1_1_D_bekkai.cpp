#include <iostream>
#include <algorithm>

using namespace std;

int		main(void)
{
	int maxv, minv;
	int len;
	int price[100];
	int idx;

	cin >> len;
	for (idx = 0; idx < len; idx++)
	{
		cin >> price[idx];
	}
	
	maxv = price[1] - price[0];
	minv = price[0];
	for (idx = 1; idx < len; idx++)
	{
		//最初の一回はprice[1] - minv(price[0])なのでif文はスキップされる
		maxv = max(maxv, price[idx] - minv);
		minv = min(minv, price[idx]);
		cout << "maxv = " << maxv << "," << "minv = " << minv << endl;
	}
	cout << maxv << endl;
	return (0);
}