#pragma once
#include<queue>
#define MaxVertexType 100//���������Ŀ
typedef char VertexType;//�������������
typedef int EdgeType;//��Ȩͼ���ϵ�Ȩֵ����
typedef struct {
	VertexType Vex[MaxVertexType];//���㼯
	EdgeType Edge[MaxVertexType][MaxVertexType];//�ڽӾ���
	int vexnum, arcnum;//��ǰ������ ����
}MGraph;
//�ڽӱ�
struct ArcNode {//�߱�ڵ�
	int adjvex;
	struct ArcNode* next;
	//int weight
};
typedef struct VNode {
	VertexType data;//������Ϣ
	ArcNode* first;
}VNode, AdjList[MaxVertexType];
typedef struct {
	AdjList vertices;//�ڽӱ�
	int vexnum, arcnum;
}ALGraph;
bool delete_i_j(AdjList vertices,int i,int j) {
	ArcNode* a = vertices[i].first;
	if (a==nullptr)
	{
		return false;
	}
	if (a->adjvex == j) {//�������ĵ�һ�����ǲ���i��j��·��
		//����� ��ɾ��
		
		vertices[i].first = a->next;
		delete a;
		return true;
	}
	//a = a->next;

	while (a->next!=nullptr)//�ұ߱�
	{
		if (a->next->adjvex==j)//�߱��nextΪj ɾ��j
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