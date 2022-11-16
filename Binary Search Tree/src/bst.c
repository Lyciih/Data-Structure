#include"bstSpec.h"


bst_tree_head_t * bst_head()
{
    bst_tree_head_t * temp = (bst_tree_head_t *)malloc(sizeof(bst_tree_head_t));
    temp->root = NULL;
}




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


void insertNode(btreeNode_t * insert_element, bst_tree_head_t * head, int(*compare)(btreeNode_t * insert_element, btreeNode_t * in_tree_element))
{
    if(head->root == NULL)
    {
        head->root = insert_element;
    }
    else
    {
        insert_child_node(insert_element, head->root, compare);
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




btreeNode_t * findNode(int key, bst_tree_head_t * head, int(*compare)(int key, btreeNode_t * in_tree_element))
{
    if(head->root == NULL)
    {
        printf("no tree\n");
        return NULL;
    }

    if(compare(key, head->root) == 2)
    {
        printf("is root");
        return head->root;
    }

    return find_child_node(key, head->root, compare);
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


void delete_node(btreeNode_t * delete_node, bst_tree_head_t * head, int(*compare)(btreeNode_t * delete_node, btreeNode_t * in_tree_element))
{
    btreeNode_t * temp;

    if(head->root == NULL)
    {
        printf("no tree\n");
    }

    if(compare(delete_node, head->root) == 2)
    {
        if(head->root->left == NULL && head->root->right == NULL)
        {
            head->root = NULL;
        }

        else if(head->root->left != NULL && head->root->right == NULL)
        {
            temp = head->root->left;
            head->root->left = NULL;
            head->root = temp;
        }

        else if(head->root->left == NULL && head->root->right != NULL)
        {
            temp = head->root->right;
            head->root->right = NULL;
            head->root = temp;
        }

        else if(head->root->left != NULL && head->root->right != NULL)
        {
            temp = findMinNode(head->root->right);
            delete_child_node(findMinNode(head->root->right), head->root, compare);
            temp->left = head->root->left;
            temp->right = head->root->right;
            head->root = temp;
        }
    }
    else
    {
        delete_child_node(delete_node, head->root, compare);
    }
}
