#include"bstSpec.h"



void Bst_init(btreeNode_t * node)
{
    node->left = NULL;
    node->right = NULL;
}



void insert_child_node(btreeNode_t * insert_element, btreeNode_t * root, int(*compare)(btreeNode_t * insert_element, btreeNode_t * in_tree_element))
{
    if(compare(insert_element, root) == -1)
    {
        if(root->left == NULL)
        {
            root->left = insert_element;
            return;
        }
        else
        {
            root = root->left;
            insert_child_node(insert_element, root, compare);
            return;
        }        
    }

    if(compare(insert_element, root) == 1)
    {
        if(root->right == NULL)
        {
            root->right = insert_element;
            return;
        }
        else
        {
            root = root->right;
            insert_child_node(insert_element, root, compare);
            return;
        }        
    }

    if(compare(insert_element, root) == 2)
    {
        printf("node already exists ");
    }
}


void insertNode(btreeNode_t * insert_element, btreeNode_t ** root, int(*compare)(btreeNode_t * insert_element, btreeNode_t * in_tree_element))
{

    if((btreeNode_t *)*root == NULL)
    {
        *root = insert_element;
    }
    else
    {
        insert_child_node(insert_element, *root, compare);
    }
}








btreeNode_t * find_child_node(int key, btreeNode_t * root, int(*compare)(int key, btreeNode_t * in_tree_element))
{
    if(compare(key, root) == 1)
    {
        if(root->right != NULL)
        {
            if(compare(key, root->right) == 2)
            {
                return root->right;
            }
            else
            {
                return find_child_node(key, root->right, compare);
            }
        }
        else
        {
            printf("no\n");
            return NULL;
        }
    }

    if(compare(key, root) == -1)
    {
        if(root->left != NULL)
        {
            if(compare(key, root->left) == 2)
            {
                return root->left;
            }
            else
            {
                return find_child_node(key, root->left, compare);
            }
        }
        else
        {
            printf("no\n");
            return NULL;
        }
    }

    return NULL;
}




btreeNode_t * findNode(int key, btreeNode_t * root, int(*compare)(int key, btreeNode_t * in_tree_element))
{
    if(root == NULL)
    {
        printf("no tree\n");
        return NULL;
    }

    if(compare(key, root) == 2)
    {
        return root;
    }

    return find_child_node(key, root, compare);
}


btreeNode_t * findMinNode(btreeNode_t * root)
{
    if(root == NULL)
    {
        printf("no tree\n");
        return NULL;
    }

    if(root->left == NULL)
    {
        return root;
    }
    else
    {
        return findMinNode(root->left);
    }
}

btreeNode_t * findMaxNode(btreeNode_t * root)
{
    if(root == NULL)
    {
        printf("no tree\n");
        return NULL;
    }

    if(root->right == NULL)
    {
        return root;
    }
    else
    {
        return findMaxNode(root->right);
    }
}








void delete_child_node(btreeNode_t * delete_node, btreeNode_t * root, int(*compare)(btreeNode_t * delete_node, btreeNode_t * in_tree_element))
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


void inOrder(btreeNode_t * root, void(*print)(btreeNode_t * root))
{
    if(root == NULL)
    {
        printf("no node\n");
    }
    else
    {
        if(root->left != NULL)
        {
            inOrder(root->left, print);
        }

        print(root);

        if(root->right != NULL)
        {
            inOrder(root->right, print);
        }
    }

}