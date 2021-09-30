//Author:   Nick Seyler
//Date:     3/30/17
//File:     displayBinTree.cpp

#include <iostream>
#include "bintree.h"

using namespace main_savitch_10;

//postcondition: basic bintree is created
binary_tree_node<int>* create_bst()
{
	binary_tree_node<int>* t1 = new binary_tree_node<int>(10);
	binary_tree_node<int>* t2 = new binary_tree_node<int>(66);
	binary_tree_node<int>* t3 = new binary_tree_node<int>(40, NULL, t2);
	binary_tree_node<int>* t4 = new binary_tree_node<int>(17, t1, t3);
	return t4;
}

//precondition:  node_ptr points to a node, depth is the depth of the node, and maxDepth is the maximum depth of the binary tree
//postcondition: binary tree is displayed with NULL on levels with 1 or more data
void display(binary_tree_node<int>* node_ptr, int depth, int maxDepth)
{
   if (node_ptr != NULL)
   {
      display(node_ptr->right(), depth + 1, maxDepth);
      std::cout << std::setw(8*depth) << "";
      std::cout << node_ptr->data( ) << std::endl;
      display(node_ptr->left(), depth + 1, maxDepth);
   }
   else
   {
      if (depth <= maxDepth)
      {
         std::cout << std::setw(8*depth) << "";
         std::cout << "NULL" << std::endl;
      }
   }
}    

//precondition:  node_ptr is the pointer to a node in the binary tree
//postcondition: the maximum depth from the node being pointed to is returned. If the pointer is NULL, 0 is returned.
int max_depth(binary_tree_node<int>* node_ptr, int maxDepth)
{
   int leftMax = 0;
   int rightMax = 0;
   if (node_ptr != NULL)
   {
      leftMax = max_depth(node_ptr -> left(), maxDepth);
      rightMax = max_depth(node_ptr -> right(), maxDepth);
      
      if (leftMax > rightMax)
         return leftMax + 1;
      else
         return rightMax + 1;
   }
   else
      return maxDepth;
}

int main()
{
	binary_tree_node<int>* bst = create_bst();
   int maxDepth = max_depth(bst, 0);
   //std::cout << maxDepth << std::endl; (check maxDepth)
   display(bst, 1, maxDepth);
   return 0;
}