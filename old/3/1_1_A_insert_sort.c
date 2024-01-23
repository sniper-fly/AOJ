#include <stdio.h>

void	printnums(int *nums, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d", nums[i]);
	}
	printf("\n");
}

int		main(void)
{
	int idx, j, v, len;
	int nums[100];
	int flag = 0;

	scanf("%d", &len);
	for (idx = 0; idx < len; idx++)
	{
		scanf("%d", &nums[idx]);
	}
	
	for (idx = 1; idx < len; idx++)
	{
		v = nums[idx];
		j = idx - 1;
		flag = 0;
		while (j >= 0 && nums[j] > v)
		{
			nums[j + 1] = nums[j];
			flag = 1;
			printnums(nums, len);
			j--;
		}
		if (flag == 0)
		{
			printnums(nums, len);
		}
		nums[j + 1] = v;
	}
	printnums(nums, len);
	return (0);
}