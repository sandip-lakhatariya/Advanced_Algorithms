#include <bits/stdc++.h>

void computeLPSArray(char* P, int M, int* lps);

void KMPSearch(char* P, char* T)
{
	int M = strlen(P);
	int N = strlen(T);

	int lps[M];

	computeLPSArray(P, M, lps);

	int i = 0; 
	int j = 0; 
	while ((N - i) >= (M - j)) {

		if (P[j] == T[i]) {
			j++;
			i++;
		}

		if (j == M) {
			printf("Found Pattern at index %d ", i - j);
			j = lps[j - 1];
		}

		else if (i < N && P[j] != T[i]) {
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
}

void computeLPSArray(char* P, int M, int* lps)
{
	int len = 0;

	lps[0] = 0; 

	int i = 1;
	while (i < M) {
		if (P[i] == P[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if (len != 0) {
				len = lps[len - 1];
			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

int main()
{
	char T[] = "ABABDABACDABABCABAB";
	char P[] = "ABABCABAB";
	KMPSearch(P, T);
	return 0;
}
