#pragma once

void merge(int A[], int la,int B[],int lb ,int*C,int &lc) {
	for (int i = 0, int j = 0, int k = 0; (j < lb)||(i<la);)
	{
		if (i<la&&j<lb)
		{
			if (A[la]<=B[lb])
			{
				C[k++] = A[i++];
			}
			else
			{
				C[k++] = B[j++];
			}
		}
		else if (i<la)
		{
			C[k++] = A[i++];
		}
		else
		{
			C[k++] = B[j++];
		}
	}

}
int uniquify(int A[], int n) {
	int i = 0, j = 0;
	while (++j<n)
	{
		if (A[i]!=A[j])
		{
			A[++i] = A[j];
		}
	}
	n = ++i;
	return j - i;
}
