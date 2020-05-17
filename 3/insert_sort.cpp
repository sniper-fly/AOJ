#include <iostream>
#include <cstdlib>
using namespace std;

int		bubble_sort(int N, int *ar);

int		main(void)
{
	int N;
	int *ar;

	cin >> N;
	ar = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) cin >> ar[i];
	bubble_sort(N, ar);
	for (int j = 0; j < N; j++) cout << ar[j] << " ";

	return (0);
}

int		bubble_sort(int N, int *ar)
{
	int v;
	int j;

	for (int i = 1; i < N; i++)
	{
		v = ar[i];
		j = i - 1;
		while (j > -1 && ar[j] > v)
		{
			ar[j + 1] = ar[j];
			j--;
			for (int k = 0; k < N; k++) cout << ar[k] << " ";
			cout << endl;
		}
		ar[j + 1] = v;
		for (int k = 0; k < N; k++) cout << ar[k] << " ";
		cout << endl;
	}
}