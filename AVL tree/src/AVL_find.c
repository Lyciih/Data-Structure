#include"AVLSpec.h"

avl_node_t * AVL_find(int key, avl_node_t ** root, int (*compare)(int key, void * in_tree_element))
{
    if(*root == NULL)
    {
        return NULL;
    }
    else if(compare(key, *root) == 0)
    {
        return *root;
    }
    else if(compare(key, *root) == -1)
    {
        return AVL_find(key, &((*root)->left), compare);
    }
    else
    {
        return AVL_find(key, &((*root)->right), compare);
    }
}