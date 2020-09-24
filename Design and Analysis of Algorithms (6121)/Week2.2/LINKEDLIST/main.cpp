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
            temp = p;
            p  = p->next;
            q = q->next->next;
            if(p == q ) return temp;
        }
        return NULL;
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
