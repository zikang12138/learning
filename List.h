typedef int ElemType;
typedef sturct LNode{//
  ElemType data;
  struct LNode *next;
}LNode *LinkList;

bool find_kth(LinkList L,int k）{
  LNode* p=L->next;//p q都指示第一个节点
  LNode* q=L->next;
  int count=0;
  while(p!=nullptr)
  {
    if(count<k)count++;//计数 如果count<k只移动p
    else q=q->next； //如果count=k 则p q同时移动
    p=p->next;
  }
  if(count<k)
    return false;
  else{
    cout<<q->data;
    return true;}
}
void delete_abs(LinkList &L,int n){
  int *A=new int [n+1];
  for(int i=0;i<=n;i++){
    A[i]=0;
  }
  LNode* p=L->next;
  LNode* pre=L;
  while(p!=nullptr){
    if(A[abs(p->data]){//若该绝对值已经出现过 则删去
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
void resort(LinkList L){
  LNode* p=L;
  LNode* q=L;
  LNode* r=new LNode;
  while(q->next!=nullptr){//寻找中间节点
    p=p->next;//p走一步 q走两步
    q=q->next;
    while(q->next!=nullptr)q=q->next;
  }
  q=p->next;//p为中间节点 q为后半链表的首节点
  p->next=nullptr;
  while(q!=nullptr){//将链表后半段逆置 实际上和头插法很像 只不过这次头节点为p了
    
  }
  
}
