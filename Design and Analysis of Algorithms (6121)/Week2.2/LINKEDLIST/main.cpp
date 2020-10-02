//
//  main.cpp
//  LINKEDLIST
//
//  Created by Ilyas Karimov on 9/20/20.
////ALL LINKED LISTS ARE HERE
#include <stdio.h>


class ListNode
{
public:
  int data;
  ListNode *next;
  ListNode(int data) : data(data), next(NULL) {}
};

class LinkedList
{
public:
  ListNode *head, *tail;
  LinkedList()
  {
    head = NULL;
    tail = NULL;
  }

  bool Empty()
  {
    return head == NULL;
  }

    
  void addFirst(int val)
  {
    if (tail == NULL) // list is empty
    head = tail = new ListNode(val);
    else
    {
      ListNode *temp = new ListNode(val);
      temp->next = head;
      head = temp;
    }
  }

  void addLast(int val)
  {
    if (tail != NULL) // list is not empty
       {
      tail->next = new ListNode(val);
      tail = tail->next;
    }
    else head = tail = new ListNode(val);
  }

  bool removeFirst()
  {
    if (Empty()) return false;
    if (head == tail) // only one node in a list
      head = tail = NULL;
    else head = head->next;
    return true;
  }

  bool removeLast()
  {
    if (Empty()) return false;
    if (head == tail) // only one node in a list
    {
      head = tail = NULL;
       }
    else // if more than one node in the list
    {
      ListNode *temp;
      // find the predecessor of  tail
      for (temp = head; temp->next != tail; temp = temp->next);
        tail = temp; // the predecessor of  tail becomes tail
      tail->next = NULL;
    }
    return true;
  }

  void Print()
  {
    ListNode *head = this->head;
    while (head != NULL)
    {
      printf("%d ", head->data);
      head = head->next;
    }
    printf("\n");
  }
    
    // -- PROBLEM SUMMING -- 1
    int sum(ListNode *head)
    {
       int res = 0;
       while (head != NULL) {
       res += head->data;
       head = head->next; }
       return res;
    }
    // -- PROBLEM LENGTH -- 2
    int length(ListNode *head)
    {
        int res = 0;
        while (head != NULL) {
        res++;
        head = head->next; }
        return res;
    }
    // -- PROBLEM REVERSE -- 3
    void PrintReverse(ListNode *head)
    {
        if(head == NULL) return;
        PrintReverse(head->next);
        printf("%d ", head->data);
        
    }
    // -- PROBLEM Has Cycles -- 4
    int hasCycle(ListNode *head)
    {
        ListNode *p, *q;
        if(head == NULL) return 0;
        p = q = head;
        while(q->next && q ->next->next){
            p = p ->next;
            q = q ->next ->next;
            if(p == q) return 1;
        }
        return 0;
    }
    
    ListNode* detectCycle(ListNode *head)
    {
        ListNode *p, *q, *temp;
        if(head == NULL) return NULL;
        p = q = head;
        while(q->next && q->next->next){
            p  = p->next;
            q = q->next->next;
            if(p == q ) {
                while(head->next&&p->next){
                    head=head->next;
                    p=p->next;
                    if(p==head) return p;
                }
            }
        }
        return NULL;
    }
    ListNode* merge(ListNode *l1, ListNode *l2)
    {
        ListNode *head_rest = new ListNode(0);
        ListNode *result = new ListNode(0);
        head_rest = result;
        while(1){
            if(l1 == NULL){
                result ->next = l2;
                break;
            }
            if(l2 == NULL){
                result ->next = l1;
                break;
            }
            
            if(l1->data > l2->data){
                result ->next = l2;
                l2 = l2->next;
            }
            else{
                result ->next = l1;
                l1 = l1->next;
            }
        }
        return head_rest ->next;
    }
    ListNode *intersection(ListNode *l1, ListNode *l2)
        {
            ListNode *tmp1 = l1;
            ListNode *tmp2 = l2;
            
            int lenA = 0 , lenB =0, temp = 0;
            while(tmp1!= NULL){
                lenA++;
                tmp1=tmp1->next;
            }
            while(tmp2!= NULL){
                lenB++;
                tmp2=tmp2->next;
            }
            if(lenA > lenB){
                temp = lenA - lenB;
                while(temp!=0){
                    l1 = l1 ->next;
                    temp--;
                }
            }
            else{
                temp = lenB - lenA;
                while(temp!=0){
                    l2 = l2 ->next;
                    temp--;
                }
            }
            while(l1 != NULL){
                if(l1->data == l2->data){
                    return l1;
                }
                else{
                    l1 = l1->next;
                    l2 = l2->next;
                }
            }
            return 0;
        }
    ListNode* reverse(ListNode* head)
    {
        ListNode *prev = NULL, *next_node, *current;
        if(head==NULL) return NULL;
        while(current!=NULL){
            next_node = current->next;
            current->next = prev;
            prev = current;
            current = next_node;
        }
        return head;
    }
};



ListNode *temp;


int main(void)
{
  LinkedList *list = new LinkedList();
  if (list->Empty()) printf("Empty\n");
  list->addFirst(10);    list->addFirst(15);
  list->removeLast(); list->addFirst(20);
  list->Print(); // 20 15

  list->addLast(30);    list->addLast(35);
  list->addFirst(77);    list->addFirst(99);
  list->Print(); // 99 77 20 15 30 35

  list->removeFirst(); list->removeFirst();
  list->removeFirst(); list->removeLast();
  list->Print(); // 15 30
  return 0;
}
