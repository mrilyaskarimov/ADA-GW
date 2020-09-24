//
//  main.cpp
//  Problem A
//
//  Created by Ilyas Karimov on 9/23/20.
//

#include <stdio.h>

class TreeNode
{
public:
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Tree
{
public:
  TreeNode *head;
  Tree() : head(NULL) {};

  void Insert(int val)
  {
    Insert(head, val);
  }

  void Insert(TreeNode *&tree, int val)
  {
    if (tree == NULL)
    {
      tree = new TreeNode(val);
      return;
    }
    if (val < tree->val)
      Insert(tree->left, val);
    else
      Insert(tree->right, val);
  }
};

class Solution
{
public:
  TreeNode *Find(TreeNode *tree, int element)
  {
    if (tree == NULL) return NULL;
    if (element == tree->val) return tree;
    if (element < tree->val) return Find(tree->left, element);
    else return Find(tree->right, element);
  }
};

int n, i, val, element;

int main(void)
{
  //freopen("10063.in","r",stdin);
  Tree *t = new Tree();
  scanf("%d", &n);
  for (i = 0; i < n; i++)
  {
    scanf("%d", &val);
    t->Insert(val);
  }

  scanf("%d", &element);

  Solution s;
  TreeNode *ptr = s.Find(t->head, element);

  if (ptr == NULL) printf("NO\n");
  else if (ptr->val == element) printf("YES\n");
  else printf("\n");

  return 0;
}
