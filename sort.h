#pragma once
void swap(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}
void InsertSort(int A[], int n) {
	int temp,j;
	for (int i = 1; i < n; i++)
	{
		if (A[i]<A[i-1])
		{
			temp = A[i];
			for (j=i-1; temp<A[j];j--)
			{
				A[j + 1] = A[j];
			}
			A[j + 1] = temp;
		}
	}
}
void BubbleSort(int A[], int n) {
	bool sorted = false;//���������ָ �ٶ���δ����
	while (!sorted) {
		sorted = true;//�ȼٶ�����
		for (int i = 1; i < n; i++)
		{
			if (A[i]<A[i-1])
			{
				swap(A[i], A[i - 1]);
				sorted = false;//���������Բ��ܱ�֤
			}
		}
	}
}
int partion (int A[],int lo,int hi){
	int pivot = A[lo];
	while (lo<hi)//�����˽������м�ɨ�� 
	{
		while ((lo<hi)&&(A[hi]>=pivot))//�ڲ�С��pivot��ǰ����
		{
			hi--;//������չ�Ҷ�������
		}
		A[lo] = A[hi];//С��pivot�Ĺ������������
		while ((lo<hi)&&(A[lo]<=pivot))//�ڲ�����pivot��ǰ����
		{
			lo++;//������չ���������
		}
		A[hi] = A[lo];//����pivot�����Ҳ�������
	}
	A[lo] = pivot;//������֮����¼��ǰ��������֮��
	return lo;
}//��[lo,hi]�������
void quicksort(int A[], int lo, int hi)//����ΧΪ[lo,hi)
{
	if (hi - lo < 2)return;//��Ԫ����Ȼ����
	int mi = partion(A,lo, hi - 1);
	quicksort(A,lo, mi);
	quicksort(A,mi + 1, hi);
}
void quickselect(int A[], int lo, int hi, int k)//ѡȡ��С��k����(���ÿ��ţ�
{
	if (hi - lo < 2)return;
	int mi = partion(A, lo, hi - 1);
	if (k - 1 == mi) return;//�����k���ڵ���������� ֱ�ӷ���
	else if (k - 1 > mi)quickselect(A, mi + 1, hi, k);//�����k���ڵ�������Ҳ� ˵�������඼��A{k��С �Ҳ����
	else quickselect(A, lo, mi, k);//�����k���ڵ��������� ˵������Ҳ඼��A{k��С ������
}
void SelectSort(int A[], int n) {
	for (int i = 0; i < n-1; i++)
	{
		int min = i;
		for (int j = i+1; j < n; j++)
		{
			if (A[j] < A[min])min = j;
		}
		if (min != i)swap(A[i], A[min]);
	}
}
void HeadAdjust(int A[], int k, int n){//������k���ڵ㼰������ 
	int temp = A[k];//��ʱ��¼���ڵ�
	for (int i=2*k+1; i < n; i=2*i+1)//��iָ��k������
	{
		if (i<n-1&&A[i]<A[i+1])//�������С���Һ��� ���Һ���׼������
		{
			i++;
		}
		if (temp >= A[i])break;//������ӽڵ㲻�ø��״� �����·���
		else
		{
			A[k] = A[i];
			k = i;
		}
	}
	A[k] = temp;
}
void BuildMaxHeap(int A[], int n) {
	for (int i=n/2-1;i>=0 ;i--)//����к��ӵĽڵ㿪ʼ
	{
		HeadAdjust(A, i, n);
	}
}
void HeapSort(int A[], int n) {
	BuildMaxHeap(A, n);
	
	for (int i = n - 1; i > 0; i--) {
		swap(A[i], A[0]);
		HeadAdjust(A, 0, i );
	}
	
}
void AdjustUp(int A[], int& n, int e) {
	int k = n;
	while (k>=0&&A[(k-1)/2]<e)//���ڵ���С��e
	{
		A[k] = A[(k - 1) / 2];
		k = (k - 1) / 2;//ָ���丸
	}
	A[k] = e;
}