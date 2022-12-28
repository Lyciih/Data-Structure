#include"AVLSpec.h"

int maximum(int a, int b)
{
    if(a > b){return a;}
    if(a < b){return b;}
    else
    {
        return a;
    }   
}

void AVL_init(avl_node_t * node)
{
    node->height = 0;
    node->left = NULL;
    node->right = NULL;
}

void AVL_tree_height_update(avl_node_t * root)
{
    if(root->left == NULL && root->right == NULL){root->height = 0;}
    if(root->left != NULL && root->right == NULL){root->height = root->left->height + 1;}
    if(root->left == NULL && root->right != NULL){root->height = root->right->height + 1;}
    if(root->left != NULL && root->right != NULL){root->height = maximum(root->left->height, root->right->height) + 1;}
}


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



int AVL_get_height(avl_node_t * root)
{
    if(root == NULL)
    {
        return -1;
    }
    else
    {
        return root->height;
    }
}

int AVL_height_compare(avl_node_t ** root)
{
    if(*root == NULL)
    {
        return 0;
    }
    else
    {
        int left_height = AVL_get_height((*root)->left);
        int right_height = AVL_get_height((*root)->right);


        if(left_height - right_height == 2)
        {
            if(AVL_get_height((*root)->left->left) > AVL_get_height((*root)->left->right))
            {
                //printf("LL type\n");
                return 1;
            }
            else
            {
                //printf("LR type\n");
                return 2;
            }
        }

        if(left_height - right_height == -2)
        {
            if(AVL_get_height((*root)->right->left) > AVL_get_height((*root)->right->right))
            {
                //printf("RL type\n");
                return 3;
            }
            else
            {
                //printf("RR type\n");
                return 4;
            }
        }
    }
    return 0;
}

void AVL_LL(avl_node_t ** root)
{
    avl_node_t * temp = NULL;

    temp = *root;   
    *root = (*root)->left;
    temp->left = (*root)->right;
    (*root)->right = temp;

    AVL_tree_height_update((*root)->right);
}

void AVL_RR(avl_node_t ** root)
{
    avl_node_t * temp = NULL;


    temp = *root;   
    *root = (*root)->right;
    temp->right = (*root)->left;
    (*root)->left = temp;

    AVL_tree_height_update((*root)->left);
}

void AVL_LR(avl_node_t ** root)
{
    avl_node_t * temp = NULL;

    AVL_RR(&((*root)->left));

    temp = *root;   
    *root = (*root)->left;
    temp->left = (*root)->right;
    (*root)->right = temp;

    AVL_tree_height_update((*root)->right);
}

void AVL_RL(avl_node_t ** root)
{
    avl_node_t * temp = NULL;

    AVL_LL(&((*root)->right));

    temp = *root;   
    *root = (*root)->right;
    temp->right = (*root)->left;
    (*root)->left = temp;

    AVL_tree_height_update((*root)->left);
    
}




void AVL_rotate(avl_node_t ** root)
{
    int compare_result = AVL_height_compare(root);

    if(compare_result == 1)
    {
        AVL_LL(root);      
    }

    if(compare_result == 2)
    {
        AVL_LR(root);      
    }

    if(compare_result == 3)
    {
        AVL_RL(root);      
    }

    if(compare_result == 4)
    {
        AVL_RR(root);      
    } 

    AVL_tree_height_update(*root);
}

