#include <stdio.h>

int		main(void)
{
	int		row;
	int		n[200000];
	int		maxv;
	int		minv;

	scanf("%d", &row);
	for (int i = 0; i < row; i++)
		scanf("%d", &n[i]);

	// 最小値を保持
	// 現在見ている値と最小値を引き算して、差分の最大値を保持
	maxv = n[1] - n[0];
	minv = n[0];

	for (int i = 1; i < row; i++)
	{
		if (maxv < n[i] - minv)
			maxv = n[i] - minv;
		if (minv > n[i])
			minv = n[i];
	}
	printf("%d\n", maxv);
}
