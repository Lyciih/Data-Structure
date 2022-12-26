#include"AVLSpec.h"

int count_AVL_tree_level(avl_node_t * root)
{
    int temp_left = 0;
    int temp_right = 0;
    if(root->left != NULL)
    {
        temp_left += count_AVL_tree_level(root->left) + 1;
    }

    if(root->right != NULL)
    {
        temp_right += count_AVL_tree_level(root->right) + 1;
    }
    
    if(temp_left < temp_right)
    {
        return temp_right;
    }
    else
    {
        return temp_left;
    }
}