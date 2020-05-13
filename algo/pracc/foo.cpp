#include <bits/stdc++.h>

using namespace std;

void ssort(int *niz, int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = i; j > 0 && niz[j - 1] > niz[j]; --j)
			std::swap(niz[j - 1], niz[j]);
	}
}

int main(void)
{
	int size = 5;
	int niz[] = {1, 2, 0, 4, 0};
	ssort(niz, size);
	for (int i = 0; i < size; ++i)
	{
		cout << niz[i] << " ";
	}
	return 0;
}
