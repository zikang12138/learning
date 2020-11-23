# learning

## List.h

### List_HeadInsert(LinkList &L)
s->data=x;  
s->next=L->next;  
L->next=s;  

### List_TailInsert(L)
设立一个指向表尾的指针

### void reverse(LinkList &L）
遍历一次链表 将表所有节点逆转

### void find_kth()
查找链表倒数第k个（王道p42 21）

### void delete_abs(L）
王道p43 3

### void resort()
王道p44 25  
这道题综合性很强 首先要找到中间节点 采用的方法是双指针 p走一步 q走两步 q到链表尾部时 p在中间。  
然后考察了链表逆置的方法 是头插法的应用 将p（中间节点）作为头插法的"头" q指向p->next  
最后考察间隔插入的方法 可以画图理解

