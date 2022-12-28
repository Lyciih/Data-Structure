#include"AVLSpec.h"

void AVL_insert(avl_node_t * element, avl_node_t ** root, int (*compare)(void * element, void * in_tree_element))
{
    if(*root == NULL)
    {
        *root = element;
        AVL_tree_height_update(*root);
    }
    else
    {
        int compare_result = compare(element, *root);

        if(compare_result == -1)
        {
            AVL_insert(element, &((*root)->left), compare);
            AVL_rotate(root);
        }
        else if(compare_result == 1)
        {
            AVL_insert(element, &((*root)->right), compare);
            AVL_rotate(root);
        }
        else if(compare_result == 0)
        {
            return;
        }
        else
        {
            printf("error\n");
            return;
        }
    } 
}