#include"AVLSpec.h"

static void AVL_delete_end(avl_node_t * delete_element, avl_node_t ** root, int (*compare)(void * delete_element, void * in_tree_element))
{
    avl_node_t * temp = NULL;

    if(*root == NULL)
    {
        return;
    }
    else if(compare(delete_element, *root) == 0)
    {
        if((*root)->left == NULL && (*root)->right == NULL)
        {
            *root = NULL;
        }

        else if((*root)->left != NULL && (*root)->right == NULL)
        {
            temp = *root;
            *root = (*root)->left;
            AVL_init(temp);
        }

        else if((*root)->left == NULL && (*root)->right != NULL)
        {
            temp = *root;
            *root = (*root)->right;
            AVL_init(temp);
        }
    }
    else if(compare(delete_element, *root) == -1)
    {
        AVL_delete(delete_element, &((*root)->left), compare);
        AVL_tree_height_update(*root);
    }
    else
    {
        AVL_delete(delete_element, &((*root)->right), compare);
        AVL_tree_height_update(*root);
    }
}




void AVL_delete(avl_node_t * delete_element, avl_node_t ** root, int (*compare)(void * delete_element, void * in_tree_element))
{
    avl_node_t * temp = NULL;

    if(*root == NULL)
    {
        return;
    }
    else if(compare(delete_element, *root) == 0)
    {
        if((*root)->left == NULL && (*root)->right == NULL)
        {
            *root = NULL;
        }

        else if((*root)->left != NULL && (*root)->right == NULL)
        {
            temp = *root;
            *root = (*root)->left;
            AVL_init(temp);
        }

        else if((*root)->left == NULL && (*root)->right != NULL)
        {
            temp = *root;
            *root = (*root)->right;
            AVL_init(temp);
        }

        else if((*root)->left != NULL && (*root)->right != NULL)
        {
            temp = AVL_find_minimum((*root)->right);
            AVL_delete_end(temp, root, compare);
            temp->left = (*root)->left;
            temp->right = (*root)->right;
            AVL_init(*root);
            *root = temp;
                                 
            AVL_rotate(root);
        }
    }
    else if(compare(delete_element, *root) == -1)
    {
        AVL_delete(delete_element, &((*root)->left), compare);
        AVL_rotate(root);
    }
    else
    {
        AVL_delete(delete_element, &((*root)->right), compare);
        AVL_rotate(root);
    }
}