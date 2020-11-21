typedef int ElemType;
typedef sturct LNode{//
  ElemType data;
  struct LNode *next;
}LNode *LinkList;

bool find_kth(LinkList L,int k）{
  LNode* p=L->next;
  LNode* q=L->next;
  int count=0;
  while(p!=nullptr)
  {
    if(count<k)count++;
    else q=q->next;
    p=p->next;
  }
  if(count<k)
    return false;
  else{
    cout<<q->data;
    return true;}
}
