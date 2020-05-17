#include <iostream>
using namespace std;

int		bubbleSort(int *nums, int size);

int		main(void)
{

}

int		bubbleSort(int *nums, int size)
{
	int flag = 1;
	int j;
	while (flag)
	{
		flag = 0;
		for (j = size - 1; j > 0; j--)
		{
			if (nums[j] < nums[j - 1])
			{
				swap(nums[j], nums[j - 1]);
				flag = 1;
			}
		}
	}
}