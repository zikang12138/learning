#pragma once
#include<iostream>
#define N 50
#define  BinTree Binnode*
#include<stack>
using namespace std;
; 
struct Binnode
{
	int data;
	Binnode* rchild;
	Binnode* lchild;
};
void visit(Binnode* p) {
	cout << p->data << endl;
}
void create_Tree_1(BinTree& T) {//如输入：AB#D##CE#F### 则建立如下图所示二叉树的二叉链表
	int a;
	cin >>a;
	if (a==-1)
	{
		T = nullptr;
	}
	else
	{
		BinTree T = new Binnode;
		T->data = a;
		create_Tree_1(T->lchild);
		create_Tree_1(T->rchild);
	}
}
BinTree create_Tree(int preorder[],int inorder[],int n) {//创建树 利用先序和中序遍历
	if (n==0)
	{
		return nullptr;
	}
	BinTree T = new Binnode;
	T->data = preorder[0];//先序遍历的第一个为树根
	int n1, n2;
	n1 = n2 = 0;
	int LPreorder[N], RPreorder[N];//分别对中序先序划分左右
	int LInorder[N], RInorder[N];
	for (int i = 0; i < n; i++)
	{
		if (i<=n1&&inorder[i]!=T->data)//遍历中序序列 直到到达根节点，左边为左子树中序遍历序列 右边为右子树遍历序列
		{
			LInorder[n1++] = inorder[i];//
		}
		else if (inorder[i] != T->data) {
			RInorder[n2++] = inorder[i];
		}
	}
	int m1, m2;
	m1 = m2 = 0;
	for (int i = 1; i < n; i++)//再根据中序遍历得到的个数 选出左子树的先序遍历与右子树的先序遍历
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
	T->lchild = create_Tree(LPreorder, LInorder, n1);//递归
	T->rchild = create_Tree(RPreorder, RInorder, n2);
	return T;
}
void trave_Pre(Binnode* p) {//先序遍历
	if (p!=nullptr)
	{
		visit(p);
		trave_Pre(p->lchild);
		trave_Pre(p->rchild);
	}
}
//非递归方法先序遍历
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
//非递归中序遍历
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
//查找值为x的一个节点
Binnode* find_x(Binnode* T, int x) {
	BinTree bt;
	if (T)
	{
		if (T->data == x)return T;
		bt = find_x(T->lchild, x);
		if (bt==NULL)
		{
			find_x(T->rchild, x);
		}
		return bt;
	}
	return nullptr;
}
void LeafCount(BinTree T, int& count)//统计叶子节点
{
	if (T)
	{
		if ((T->lchild == NULL) && (T->rchild == NULL))    count++;
		LeafCount(T->lchild, count);
		LeafCount(T->rchild, count);
	}
}
bool Insert_SortTree(BinTree& T, int e) {
	//在二叉排序树中插入 如果相同插入失败 
	//如果小于当前节点 则遍历左子树 反正 遍历右子树 到空位置插入
	if (T==nullptr)
	{
		BinTree s = new Binnode;
		s->data = e;
		s->lchild = s->rchild = nullptr;
		T = s;
		return true;
	}
	if (T->data == e)
	{
		return false;
	}
	else if (T->data > e)
	{
		return Insert_SortTree(T->lchild, e);
	}
	else
		return Insert_SortTree(T->rchild, e);
}
