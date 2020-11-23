// EE231000 Lab07 Matrix Determinant
// 109061112, 徐遠哲
// Date: 2020/11/16
// ****************************************

#include <stdio.h>
#if !defined(N)
#define N 3
#endif

int A[N][N];
int sgn = 1;
int det = 0;

int Pandita(int P[N]);
void Det(void);

int main()
{
	int x, y;

	printf("Matrix A is\n");
	for (y = 0; y < N; y++) {
		printf("  ");
		for (x = 0; x < N; x++) {
			scanf(" %d", &A[y][x]);
			printf(" %d", A[y][x]);
		}
		printf("\n");
	}
	Det();
	printf("det(A) = %d\n", det);

	return 0;
}

int Pandita(int P[N])		// to next permutation
{
	int ch;			// for change
	int j, k;		// the j, k in Pandita's algorithm
	int n;			// loop index
	
	for (n = N - 2; (n + 1) && P[n] > P[n + 1]; n--) ; 	// find j
	j = n;
	if (!(n + 1))						// not found
		return 0;
	for (n = N - 1; P[j] > P[n]; n--) ;	// find k
	k = n;
	ch = P[j];							// swap P[j] and P[k]
	P[j] = P[k];
	P[k] = ch;
	for (n = j + 1; 2 * n < N + j; n++) { // reverse P[j + 1] to P[N - 1]
		ch = P[N - n + j];
		P[N - n + j] = P[n];
		P[n] = ch;
	}

	if ((1 + (N - j))/ 2 % 2)
		sgn *= -1;

	return 1;							// found
}

void Det(void)
{
	int a[N];
	int n;
	int pi;

	for (n = 0; n < N; n++)
		a[n] = n;
		
	do {
		pi = 1;
		for (n = 0; n < N; n++)
			pi *= A[n][a[n]];
		det += sgn * pi;
	} while (Pandita(a));	
}
