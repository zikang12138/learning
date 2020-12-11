#pragma once
#include<queue>
#define MaxVertexType 100//顶点最大数目
typedef char VertexType;//顶点的数据类型
typedef int EdgeType;//带权图边上的权值类型
typedef struct {
	VertexType Vex[MaxVertexType];//顶点集
	EdgeType Edge[MaxVertexType][MaxVertexType];//邻接矩阵
	int vexnum, arcnum;//当前顶点数 边数
}MGraph;
//邻接表法
struct ArcNode {//边表节点
	int adjvex;
	struct ArcNode* next;
	//int weight
};
typedef struct VNode {
	VertexType data;//顶点信息
	ArcNode* first;
}VNode, AdjList[MaxVertexType];
typedef struct {
	AdjList vertices;//邻接表
	int vexnum, arcnum;
}ALGraph;
bool delete_i_j(AdjList vertices,int i,int j) {
	ArcNode* a = vertices[i].first;
	if (a==nullptr)
	{
		return false;
	}
	if (a->adjvex == j) {//检查链表的第一条边是不是i到j的路径
		//如果是 则删除
		
		vertices[i].first = a->next;
		delete a;
		return true;
	}
	//a = a->next;

	while (a->next!=nullptr)//找边表
	{
		if (a->next->adjvex==j)//边表的next为j 删除j
		{
			ArcNode* b = a->next;
			a->next = b->next;
			delete b;
			return true;
		}
	}
	return false;
}
bool visited[MaxVertexType];
void BFSTraverse(ALGraph G) {
	for (int i = 0; i < G.vexnum; i++)
	{
		visited[i] = false;
	}
	
}