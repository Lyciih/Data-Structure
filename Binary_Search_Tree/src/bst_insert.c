#include"bstSpec.h"



static void insert_child_node(btreeNode_t* insert_element, btreeNode_t* root, int(*compare)(btreeNode_t* insert_element, btreeNode_t* in_tree_element))
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


void insertNode(btreeNode_t* insert_element, btreeNode_t** root, int(*compare)(btreeNode_t* insert_element, btreeNode_t* in_tree_element))
{

    if((btreeNode_t*)*root == NULL)
    {
        *root = insert_element;
    }
    else
    {
        insert_child_node(insert_element, *root, compare);
    }
}
