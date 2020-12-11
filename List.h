typedef int ElemType;
#include<iostream>
using namespace std;
typedef struct LNode{//
  ElemType data;
  struct LNode *next;
}LNode,*LinkList,*CirList;
void List_HeadInsert(LinkList&mL,int n,int A[]){
    
    mL->next=NULL;
   // LNode* s;
  for (int i = 0; i < n; i++) {
      LNode* s = new LNode;
      //s = (LinkList)malloc(sizeof(LNode));
      s->data = A[i];
      s->next = mL->next;
      mL->next = s;
  }
}
void List_TailInsert(LinkList &L){
  int x=0;
  
  LNode* r=L;//r为队尾节点
  cin>>x;
  while(x!=9999){
    LNode* s=new LNode;
    s->data=x;
    r->next=s;//在队尾节点后插入
    r=s;//r指向新的队尾节点
    cin>>x;
  }
  r->next=nullptr;//队尾指向空
  //return L;
}
void Create_CircleList(CirList& L,int n,int A[]) {//利用尾插法创立带尾指针的循环列表
    LNode* rear=new LNode;
    for (int i = 0; i < n; i++)
    {
        LNode* p = new LNode;
        p->data = A[i];
        if (i==0)
        {
            L = rear = p;
        }
        else
        {
            rear->next = p;
            rear = p;
        }
    }
    rear->next = L;
    L = rear;
}
bool find_post_kth(LinkList L,int k){
    LNode* p = L->next;
    LNode*  q= L->next;
    int count=0;
  while(p!=nullptr)
  {
      if (count < k)count++;//计数 如果count<k只移动p
      else q = q->next; //如果count=k 则p q同时移动
    p=p->next;
  }
  if(count<k)
    return false;
  else{
    cout<<q->data;
    return true;}
}
void delete_abs(LinkList &L,int n){//删除绝对值相等的点（只留一个）
  int *A=new int [n+1];
  for(int i=0;i<=n;i++){
    A[i]=0;
  }
  LNode* p=L->next;
  LNode* pre=L;
  while(p!=nullptr){
    if(A[abs(p->data)]){
      //若该绝对值已经出现过，则删除
      LNode* t=new LNode;
      pre->next=p->next;//将p的前一个指针指向p的下一个指针
      t=p;
      delete t;
      p=pre->next;
    }
         else{
           A[abs(p->data)]=1;
           p=p->next;
           pre=pre->next;
         }
  }
}
void resort(LinkList &L){//将序列a1 a2 a3..an 输出为a1 an a2 an-1...
  LNode* p=L;
  LNode* q=L;
  LNode* r=new LNode;
  LNode* s=new LNode;
  while(q->next!=nullptr){//寻找中间节点
    p=p->next;//p走一步 q走两步
    q=q->next;
    while(q->next!=nullptr)q=q->next;
  }
  q=p->next;//p为中间节点 q为后半链表的首节点
  p->next=nullptr;
  while(q!=nullptr){//将链表后半部分逆置 头插法（中间节点p为头）
    r=q->next;
    q->next=p->next;
    p->next=q;
    q=r;
  }
  s = L->next;//s是前半段第一个节点 即插入点
  q = p->next;//q是后半段第一个数据节点
  
  while (q != nullptr) {
    r=q->next;//先让r过桥
    q->next=s->next;//将q所指之节点插入s所指节点之后
    s->next=q;
    s=q->next;//s指向前半段的下一个节点
    q=r;//q原来的下一个节点
    
  }
    
}
void reverse(LinkList &L){//本题更适合不带头节点的逆置
  LNode *p=L->next;
  LNode *cur=L->next;
  LNode *pre=nullptr;
  while(p!=nullptr){
    p=p->next;//先让p过桥
    cur->next=pre;//拆桥
    pre=cur;//让cur的前一个节点pre过桥到cur
    cur=p;//再利用p让cur过桥
  }
  L->next=pre;
}
void reverse_1(LinkList&L) {//带头节点的逆置
    LNode* p = L->next;
    L->next = nullptr;
    LNode* r = new LNode;
    while (p!=nullptr)
    {
        r = p->next;
        p->next = L->next;
        L->next = p;
        p = r;
    }
}
void reverse_cir(CirList& L) {//单循环链表的原地逆置
    LNode* cur = L;
    LNode* pre = L;
    LNode* p = L->next;
    if (p==L)
    {
        return;
    }
    do
    {
        cur = p;
        p = p->next;
        cur->next = pre;
        pre = cur;
    } while (cur!=L);
}