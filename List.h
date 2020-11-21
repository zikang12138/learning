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
