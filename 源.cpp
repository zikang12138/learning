#include<iostream>
#include"BinTreeNode.h"

using namespace std;


int main() {
	int A[7] = { 1,2,4,5,3,6,7 };
	int B[7] = { 4,2,5,1,6,3,7 };
	Binnode* p = create_Tree(A, B, 7);
	trave_Post(p);
	//cout << init_Height(p)<<endl;
	trave_Pre1(p);
	trave_In1(p);
}