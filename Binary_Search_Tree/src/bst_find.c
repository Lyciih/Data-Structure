#include"bstSpec.h"



static btreeNode_t* find_child_node(int key, btreeNode_t* root, int(*compare)(int key, btreeNode_t* in_tree_element))
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




btreeNode_t* findNode(int key, btreeNode_t* root, int(*compare)(int key, btreeNode_t* in_tree_element))
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
