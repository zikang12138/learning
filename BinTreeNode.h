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
void visitAlongLeftBranch(stack<Binnode*>&S,Binnode*p)//һֱ��������֧
{
	while (p)
	{
		visit(p);//���ʸýڵ�
		S.push(p->rchild);//���Һ�����ջ
		p = p->lchild;//�����֧����һ��
	}
}
void trave_Pre1(Binnode*p)//��������ķǵݹ�
{
	stack<Binnode*>S;
	
	while (true)
	{
		visitAlongLeftBranch(S, p);//�ӵ�ǰ�ڵ���� ��������
		if (S.empty()) break;
		p = S.top();//������һ�������
		S.pop();
	}
}
void goAlongLeftBranch(stack<Binnode*>&S,Binnode*p)//
{
	while (p) {//�����֧��ջ
		S.push(p);
		p = p->lchild;
	}
}
void trave_In1(Binnode* p) {
	stack<Binnode*>S;
	while (true)
	{
		goAlongLeftBranch(S, p);//�����֧��ջ
		if (S.empty())
		{
			break;
		}
		p = S.top();//��ȡջ�� �������²�ڵ㣩
		visit(p);
		p = p->rchild;//�����ҷ�֧
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