#include <iostream>
using namespace std;

int		main(void)
{
	int minj;
	int N;
	int ct = 0;
	cin >> N;
	int nums[N];
	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}

	for (int i = 0; i < N; i++)
	{
		minj = i;
		for (int j = i; j < N; j++)
		{
			if (nums[j] < nums[minj])
			{
				minj = j;
			}
		}
		swap(nums[i], nums[minj]);
		if (i != minj)
		{
			ct++;
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl << ct;
	
	return (0);
}