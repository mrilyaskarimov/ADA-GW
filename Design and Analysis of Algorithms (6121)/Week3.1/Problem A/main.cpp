//
//  main.cpp
//  Problem A
//
//  Created by Ilyas Karimov on 9/23/20.
//

#include <stdio.h>
#include <algorithm>
using namespace std;
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
    int minDepth(TreeNode *tree){
        if(tree == NULL) return 0;
        if(tree->left !=NULL) return 1+ minDepth(tree->left);
        if(tree->right != NULL) return 1 + minDepth(tree->right);
        
        return 1 +  min(minDepth(tree->left), minDepth(tree->right));
    }
    int sumLeft(TreeNode *tree)
    {
        if(tree == NULL)
        if((tree->left != NULL) &&(tree->left->left == NULL) && (tree->left->right == NULL))
        return tree->left->val + sumLeft(tree->right);
        
        return sumLeft(tree->left) + sumLeft(tree->right);
    }
    TreeNode *Maximum(TreeNode *tree)
    {
        if(tree == NULL) return NULL;
        while(tree->right!=NULL) tree= tree->right;
        return tree;
    }
//    TreeNode *Prev(TreeNode *tree)
//    {
//        if(tree->left!=NULL) return Maximum(tree->left);
//        TreeNode *prev = tree->parent;
//        while(prev!=NULL && tree = prev->left){
//            tree= prev;
//            prev = prev->parent;
//        }
//        return prev;
//    }
    bool isSame(TreeNode *tree1, TreeNode *tree2)
    {
        if(tree1  == NULL & tree2  == NULL) return 1;
        if(tree1 !=NULL && tree2 == NULL) return 0;
        if(tree2 !=NULL && tree1 == NULL) return 0;
        
        return isSame(tree1->left, tree2->left) && isSame(tree2->right, tree1->right);
    }
//    bool isBalanced(TreeNode* root)
//    {
//        if(root == NULL) return 1;
//        if(root)
//    }
    bool isSymmetric(TreeNode *tree)
    {
        if(tree==NULL) return 1;
        if(tree->left == tree->right) return 1;
        return isSymmetric(tree->left) && isSymmetric(tree->right);
    }
    TreeNode* Invert(TreeNode* tree)
    {
        if(tree == NULL) return NULL;
        
        TreeNode *right, *left;
        left = tree->left;
        right = tree->right;
        tree->left = right;
        tree->right = left;
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
