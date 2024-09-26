#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>

#define pow2(n) (1 << (n))

using namespace std;


class avl_tree 
{
   public:
      int height(avl *);
      int difference(avl *);
      avl *rr_rotat(avl *);
      avl *ll_rotat(avl *);
      avl *lr_rotat(avl*);
      avl *rl_rotat(avl *);
      avl * balance(avl *);
      avl * insert(avl*, int);
      void show(avl*, int);
      void inorder(avl *);
      void preorder(avl *);
      void postorder(avl*);
      avl_tree() 
	  {
         rightNode = NULL;
      }
};
int avl_tree::height(avl *t) {
   int h = 0;
   if (t != NULL) {
      int l_height = height(t->leftNode);
      int r_height = height(t->rightNode);
      int max_height = max(l_height, r_height);
      h = max_height + 1;
   }
   return h;
}
int avl_tree::difference(avl *t) {
   int l_height = height(t->leftNode);
   int r_height = height(t->rightNode);
   int b_factor = l_height - r_height;
   return b_factor;
}
avl *avl_tree::rr_rotat(avl *parent) {
   avl *t;
   t = parent->rightNode;
   parent->rightNode = t->leftNode;
   t->leftNode = parent;
   cout<<"Right-Right Rotation";
   return t;
}
avl *avl_tree::ll_rotat(avl *parent) {
   avl *t;
   t = parent->leftNode;
   parent->leftNode = t->rightNode;
   t->rightNode = parent;
   cout<<"Left-Left Rotation";
   return t;
}
avl *avl_tree::lr_rotat(avl *parent) {
   avl *t;
   t = parent->leftNode;
   parent->leftNode = rr_rotat(t);
   cout<<"Left-Right Rotation";
   return ll_rotat(parent);
}
avl *avl_tree::rl_rotat(avl *parent) {
   avl *t;
   t = parent->rightNode;
   parent->rightNode = ll_rotat(t);
   cout<<"Right-Left Rotation";
   return rr_rotat(parent);
}
avl *avl_tree::balance(avl *t) {
   int bal_factor = difference(t);
   if (bal_factor > 1) {
      if (difference(t->leftNode) > 0)
         t = ll_rotat(t);
      else
         t = lr_rotat(t);
   } else if (bal_factor < -1) {
      if (difference(t->rightNode) > 0)
         t = rl_rotat(t);
      else
         t = rr_rotat(t);
   }
   return t;
}
avl *avl_tree::insert(avl *rightNode, int v) {
   if (rightNode == NULL) {
      rightNode = new avl;
      rightNode->data = v;
      rightNode->leftNode = NULL;
      rightNode->rightNode = NULL;
      return rightNode;
   } else if (v< rightNode->data) {
      rightNode->leftNode = insert(rightNode->leftNode, v);
      rightNode = balance(rightNode);
   } else if (v >= rightNode->data) {
      rightNode->rightNode = insert(rightNode->rightNode, v);
      rightNode = balance(rightNode);
   } return rightNode;
}
void avl_tree::show(avl *p, int leftNode) {
   int i;
   if (p != NULL) {
      show(p->rightNode, leftNode+ 1);
      cout<<" ";
      if (p == rightNode)
         cout << "Root -> ";
      for (i = 0; i < leftNode&& p != rightNode; i++)
         cout << " ";
         cout << p->data;
         show(p->leftNode, leftNode + 1);
   }
}
void avl_tree::inorder(avl *t) {
   if (t == NULL)
      return;
      inorder(t->leftNode);
      cout << t->data << " ";
      inorder(t->rightNode);
}
void avl_tree::preorder(avl *t) {
   if (t == NULL)
      return;
      cout << t->data << " ";
      preorder(t->leftNode);
      preorder(t->rightNode);
}
void avl_tree::postorder(avl *t) {
   if (t == NULL)
      return;
      postorder(t ->leftNode);
      postorder(t ->rightNode);
      cout << t->data << " ";
}
int main() {
   int c, i;
   avl_tree avl;
   while (1) {
      cout << "1.Insert Element into the tree" << endl;
      cout << "2.show Balanced AVL Tree" << endl;
      cout << "3.InOrder traversal" << endl;
      cout << "4.PreOrder traversal" << endl;
      cout << "5.PostOrder traversal" << endl;
      cout << "6.Exit" << endl;
      cout << "Enter your Choice: ";
      cin >> c;
      switch (c) {
         case 1:
            cout << "Enter value to be inserted: ";
            cin >> i;
            rightNode = avl.insert(rightNode, i);
         break;
         case 2:
            if (rightNode == NULL) {
               cout << "Tree is Empty" << endl;
               continue;
            }
            cout << "Balanced AVL Tree:" << endl;
            avl.show(rightNode, 1);
            cout<<endl;
         break;
         case 3:
            cout << "Inorder Traversal:" << endl;
            avl.inorder(rightNode);
            cout << endl;
         break;
         case 4:
            cout << "Preorder Traversal:" << endl;
            avl.preorder(rightNode);
            cout << endl;
         break;
         case 5:
            cout << "Postorder Traversal:" << endl;
            avl.postorder(rightNode);
            cout << endl;
         break;
         case 6:
            exit(1);
         break;
         default:
            cout << "Wrong Choice" << endl;
      }
   }
   return 0;
}