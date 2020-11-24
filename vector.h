#pragma once
void uniquify(int A[],int &n){
	int i=j=0;
	while(++i<n){
		if(A[j]!=A[i]){
			A[++j]=A[i];
		}
	}
	n=j+1;
}
void converse(int A[],int n,int p){
	reverse(A,0,p);//逆转[0,p)
	reverse(A,p,n);//逆转[p,n)
	reverse(A,0,n);
}
void reverse(int A[].int lo,int hi){//逆转[lo,hi)
	int mi=(hi-lo)/2;
	for(int i=0;hi-1-i>=mi;i++){
		swap(A[hi-1-i],A[lo+i])
	}
}
int find_mid(int A[],int n,int B[]){
	int alo=0, ahi=n-1,blo=0,bhi=n-1;
	//alo为A的首位数 
	while(alo!=ahi||blo!=bhi){
		int ami=(alo+ahi)/2;
	  int bmi=(blo+bhi)/2;
		if(A[ami]==B[bmi])
			return A[ami];
		if(A[ami]<B[bmi]){
			if((alo+ahi)%2){
				alo=ami+1;
				bhi=bmi;
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
int Majority(int A[].int n){
	int count=1;
	int temp;
	temp=A[0]
	for(int i=1;i<n;i++){
		if(A[i]==temp)
			count++;
		else
		{
			if(count>0)
				count--;
			else{
				temp=A[i];
				count=1
			}
		}
	}
	if(count>0)
		for(i=count=0;i<n;i++)
			if(A[i]==temp)
				count++;
	if(count>n/2) return temp;
	else return -1;
}
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
