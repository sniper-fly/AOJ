#include <iostream>
#include <algorithm>
using namespace std;

int		main(void)
{
	int Nin;
	int n_ar[200000];
	int idx1, idx2;
	int max;

	cin >> Nin;
	for (idx1 = 0; idx1 < Nin; idx1++)
	{
		cin >> n_ar[idx1];
	}

	max = n_ar[1] - n_ar[0];
	for (idx1 = 0; idx1 < Nin - 1; idx1++)
	{
		for (idx2 = idx1 + 1; idx2 < Nin; idx2++)
		{
			if (max < n_ar[idx2] - n_ar[idx1])
			{
				max = n_ar[idx2] - n_ar[idx1];
			}
		}
	}
	cout << max << endl;

	return (0);
}