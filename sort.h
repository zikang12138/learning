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
	bool sorted = false;//整体排序标指 假定先未排序
	while (!sorted) {
		sorted = true;//先假定有序
		for (int i = 1; i < n; i++)
		{
			if (A[i]<A[i-1])
			{
				swap(A[i], A[i - 1]);
				sorted = false;//整体有序性不能保证
			}
		}
	}
}
int partion (int A[],int lo,int hi){
	int pivot = A[lo];
	while (lo<hi)//从两端交替向中间扫描 
	{
		while ((lo<hi)&&(A[hi]>=pivot))//在不小于pivot的前提下
		{
			hi--;//向左扩展右端子向量
		}
		A[lo] = A[hi];//小于pivot的归入左侧子序列
		while ((lo<hi)&&(A[lo]<=pivot))//在不大于pivot的前提下
		{
			lo++;//向右扩展左端子向量
		}
		A[hi] = A[lo];//大于pivot归入右侧子序列
	}
	A[lo] = pivot;//将备份之轴点记录于前后子向量之间
	return lo;
}//在[lo,hi]构造轴点
void quicksort(int A[], int lo, int hi)//排序范围为[lo,hi)
{
	if (hi - lo < 2)return;//单元素自然有序
	int mi = partion(A,lo, hi - 1);
	quicksort(A,lo, mi);
	quicksort(A,mi + 1, hi);
}
void quickselect(int A[], int lo, int hi, int k)//选取最小的k个数(利用快排）
{
	if (hi - lo < 2)return;
	int mi = partion(A, lo, hi - 1);
	if (k - 1 == mi) return;//如果第k个节点正好是轴点 直接返回
	else if (k - 1 > mi)quickselect(A, mi + 1, hi, k);//如果第k个节点在轴点右侧 说明轴点左侧都比A{k】小 右侧待排
	else quickselect(A, lo, mi, k);//如果第k个节点在轴点左侧 说明轴点右侧都比A{k】小 左侧待排
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
void HeadAdjust(int A[], int k, int n){//调整第k个节点及其子树 
	int temp = A[k];//暂时记录父节点
	for (int i=2*k+1; i < n; i=2*i+1)//让i指向k的左孩子
	{
		if (i<n-1&&A[i]<A[i+1])//如果左孩子小于右孩子 则右孩子准备交换
		{
			i++;
		}
		if (temp >= A[i])break;//如果孩子节点不让父亲大 则无事发生
		else
		{
			A[k] = A[i];
			k = i;
		}
	}
	A[k] = temp;
}
void BuildMaxHeap(int A[], int n) {
	for (int i=n/2-1;i>=0 ;i--)//最靠下有孩子的节点开始
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
	while (k>=0&&A[(k-1)/2]<e)//父节点若小于e
	{
		A[k] = A[(k - 1) / 2];
		k = (k - 1) / 2;//指向其父
	}
	A[k] = e;
}