#include"bstSpec.h"



static void delete_child_node(btreeNode_t * delete_node, btreeNode_t * root, int(*compare)(btreeNode_t * delete_node, btreeNode_t * in_tree_element))
{
   
    btreeNode_t * temp;

    if(compare(delete_node, root) == 1)
    {
        
        if(root->right != NULL)
        {
            
            if(compare(delete_node, root->right) == 2)
            {
                
                if(root->right->left == NULL && root->right->right == NULL)
                {
                    root->right = NULL;
                    
                }

                else if(root->right->left != NULL && root->right->right == NULL)
                {
                    temp = root->right->left;
                    root->right->left = NULL;
                    root->right = temp;
                }

                else if(root->right->left == NULL && root->right->right != NULL)
                {
                    temp = root->right->right;
                    root->right->right = NULL;
                    root->right = temp;
                }

                else if(root->right->left != NULL && root->right->right != NULL)
                {
                    temp = findMinNode(root->right->right);
                    delete_child_node(findMinNode(root->right->right), root, compare);
                    temp->left = root->right->left;
                    temp->right = root->right->right;
                    root->right = temp;
                }                           
            }
            else
            {
                delete_child_node(delete_node, root->right, compare);
            }
        }
        else
        {
            printf("no\n");
        }
    }


    if(compare(delete_node, root) == -1)
    {
        if(root->left != NULL)
        {
            if(compare(delete_node, root->left) == 2)
            {
                if(root->left->left == NULL && root->left->right == NULL)
                {
                    root->left = NULL;
                }

                else if(root->left->left != NULL && root->left->right == NULL)
                {
                    temp = root->left->left;
                    root->left->left = NULL;
                    root->left = temp;
                }

                else if(root->left->left == NULL && root->left->right != NULL)
                {
                    temp = root->left->right;
                    root->left->right = NULL;
                    root->left = temp;
                }

                else if(root->left->left != NULL && root->left->right != NULL)
                {
                    temp = findMinNode(root->left->right);
                    delete_child_node(findMinNode(root->left->right), root, compare);
                    temp->left = root->left->left;
                    temp->right = root->left->right;
                    root->left = temp;
                }
            }
            else
            {
                delete_child_node(delete_node, root->left, compare);
            }
        }
        else
        {
            printf("no\n");
        }
    }
}


void deleteNode(btreeNode_t * delete_node, btreeNode_t ** root, int(*compare)(btreeNode_t * delete_node, btreeNode_t * in_tree_element))
{
    btreeNode_t * temp;

    if(*root == NULL)
    {
        printf("no tree\n");
    }

    if(compare(delete_node, *root) == 2)
    {
        if((*root)->left == NULL && (*root)->right == NULL)
        {
            *root = NULL;
        }

        else if((*root)->left != NULL && (*root)->right == NULL)
        {
            temp = (*root)->left;
            (*root)->left = NULL;
            *root = temp;
        }

        else if((*root)->left == NULL && (*root)->right != NULL)
        {
            temp = (*root)->right;
            (*root)->right = NULL;
            *root = temp;
        }

        else if((*root)->left != NULL && (*root)->right != NULL)
        {
            temp = findMinNode((*root)->right);
            delete_child_node(findMinNode((*root)->right), *root, compare);
            temp->left = (*root)->left;
            temp->right = (*root)->right;
            *root = temp;
        }
    }
    else
    {
        delete_child_node(delete_node, *root, compare);
    }
}