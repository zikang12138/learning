#pragma once
#include<iostream>
#define N 50
#include<stack>
using namespace std;
struct Binnode
{
	int data;
	Binnode* rchild;
	Binnode* lchild;
};
void visit(Binnode* p) {
	cout << p->data << endl;
}
Binnode*create_Tree(int preorder[],int inorder[],int n) {
	if (n==0)
	{
		return nullptr;
	}
	Binnode* T = new Binnode;
	T->data = preorder[0];
	int n1, n2;
	n1 = n2 = 0;
	int LPreorder[N], RPreorder[N];
	int LInorder[N], RInorder[N];
	for (int i = 0; i < n; i++)
	{
		if (i<=n1&&inorder[i]!=T->data)
		{
			LInorder[n1++] = inorder[i];
		}
		else if (inorder[i] != T->data) {
			RInorder[n2++] = inorder[i];
		}
	}
	int m1, m2;
	m1 = m2 = 0;
	for (int i = 1; i < n; i++)
	{
		if (i<=n1)
		{
			LPreorder[m1++] = preorder[i];
		}
		else
		{
			RPreorder[m2++] = preorder[i];
		}
	}
	T->lchild = create_Tree(LPreorder, LInorder, n1);
	T->rchild = create_Tree(RPreorder, RInorder, n2);
	return T;
}
void trave_Pre(Binnode* p) {
	if (p!=nullptr)
	{
		visit(p);
		trave_Pre(p->lchild);
		trave_Pre(p->rchild);
	}
}
void visitAlongLeftBranch(stack<Binnode*>&S,Binnode*p)//一直访问左侧分支
{
	while (p)
	{
		visit(p);//访问该节点
		S.push(p->rchild);//将右孩子入栈
		p = p->lchild;//沿左分支进入一层
	}
}
void trave_Pre1(Binnode*p)//先序遍历的非递归
{
	stack<Binnode*>S;
	
	while (true)
	{
		visitAlongLeftBranch(S, p);//从当前节点出发 逐批访问
		if (S.empty()) break;
		p = S.top();//弹出下一批的起点
		S.pop();
	}
}
void goAlongLeftBranch(stack<Binnode*>&S,Binnode*p)//
{
	while (p) {//将左分支入栈
		S.push(p);
		p = p->lchild;
	}
}
void trave_In1(Binnode* p) {
	stack<Binnode*>S;
	while (true)
	{
		goAlongLeftBranch(S, p);//将左分支入栈
		if (S.empty())
		{
			break;
		}
		p = S.top();//读取栈顶 （最左下侧节点）
		visit(p);
		p = p->rchild;//进入右分支
		S.pop();

	}
}
void trave_In(Binnode* p) {
	if (p != nullptr) {
		trave_In(p->lchild);
		visit(p);
		trave_In(p->rchild);
	}
}
void trave_Post(Binnode* p) {
	if (p != nullptr) {
		trave_Post(p->lchild);
		trave_Post(p->rchild);
		visit(p);
	}
}
int Height(Binnode* p, int deep) {
	static int height = 0;
	if (p!=nullptr)
	{
		if (deep>height)
		{
			height = deep;
		}
		Height(p->lchild, deep + 1);
		Height(p->rchild, deep + 1);

	}
	return height;
}
int init_Height(Binnode* p) {
	return Height(p, 0);
}
void Exchange(Binnode* p) {
	Binnode* temp;
	if (p)
	{
		temp = p->lchild; p->lchild = p->rchild; 
		Exchange(p->lchild);
		Exchange(p->rchild);
	}
}