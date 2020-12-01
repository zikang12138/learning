#pragma once
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void uniquify(int A[],int &n){//有序序列去重
	int i = 0;
	int	j=0;
	while(++i<n){
		if(A[j]!=A[i]){//发现不等的时候
			A[++j]=A[i];//直接前移
		}//如果相等 自动忽略
	}
	n=j+1;
}
void reverse(int A[], int lo, int hi) {//逆转[lo,hi)
	int mi = (hi - lo) / 2;
	for (int i = 0; hi - 1 - i >= mi; i++) {
		swap(A[hi - 1 - i], A[lo + i]);
	}
}
void converse(int A[],int n,int p){//将a0,a1,a2,...an-1  转变为 ap ap+1 ap+2 ..an-1 a0 a1 a2 ..ap-1
	reverse(A,0,p);//逆转[0,p)
	reverse(A,p,n);//逆转[p,n)
	reverse(A,0,n);//逆转[0,n）
}

int find_mid(int A[],int n,int B[]){//A B为非降序列 找出两者合并的中位数
	int alo=0, ahi=n-1,blo=0,bhi=n-1;
	//alo为A的首位数 
	while(alo!=ahi||blo!=bhi){
		int ami=(alo+ahi)/2;//求a的中位数
	  int bmi=(blo+bhi)/2;//求b的中位数
		if(A[ami]==B[bmi])//ab相等 完成
			return A[ami];
		if(A[ami]<B[bmi]){// a小于b 
			if((alo+ahi)%2){//若元素个数为偶
				alo=ami+1;//a的范围取中点之后
				bhi=bmi;//b取中点以前 包括中点
			}
			else{
				alo=ami;
				bhi=bmi;
			}
		}
		else{
			if((alo+ahi)%2){
				blo=bmi+1;
				ahi=ami;
			}
			else{
				blo=bmi;
				ahi=ami;
			}
		}
	}
	return A[alo]<B[blo]?A[alo]:B[blo];
}
int Majority(int A[],int n){//选主元素
	//原理 若数b在An中为主元素 则在A（n-2）仍为主元素
	int count=1;
	int temp;
	temp = A[0];//将a0作为候选主元素
	for(int i=1;i<n;i++){
		if(A[i]==temp)//如果与当前主元素相等 则数量加一
			count++;
		else
		{
			if(count>0)//不等 则数量减一
				count--;
			else{
				temp=A[i];//不够减 换主元素
				count = 1;
			}
		}
	}
	if(count>0)
		for(int i=count=0;i<n;i++)
			if(A[i]==temp)
				count++;
	if(count>n/2) return temp;
	else return -1;
}
void merge(int A[], int la,int B[],int lb ,int*C,int &lc) {
	int i, j, k;
	for (i = 0,j = 0,k = 0; (j < lb)||(i<la);)
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

