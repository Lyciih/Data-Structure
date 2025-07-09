#include"AVLSpec.h"


//將指數乘開的函數
int exponent_Int(const int base, int n)
{
    int p = base;
    if(n == 0)
    {
        p = 1;
    }
    else
    {
        for (int i = 1; i < n; i++)
        {
            p *= base;
        }
    }
    return p;
}


//計算畫完整張圖需要的寬度
int count_picture_width(int AVL_tree_level)
{
	//return 3 * exponent_Int(2, tree_level) - 1 ;
	return exponent_Int(2, AVL_tree_level + 2) - 1 ;
}


//計算畫完整張圖需要的行數
int count_print_times(int AVL_tree_level)
{
	if(AVL_tree_level == 0)
	{
		return 0;
	}
	else if(AVL_tree_level == 1)
    {
        return 3;
    }
	else
	{
		return exponent_Int(2, AVL_tree_level);
	}
}

//計算可能的最大佇列長度
int count_queue(int AVL_tree_level)
{
	return exponent_Int(2, AVL_tree_level+1) - 1;
}



void queue_init(avl_node_t* queue[], int range)
{
	for(int i = 0 ; i < range ; i++)
	{
		queue[i] = NULL;
	}
}


void AVL_tree_level_to_queue(avl_node_t* root, avl_node_t* queue[])
{	
	int queue_head = 0;
	int queue_tail = 0;
	queue[queue_head] = root;
	while(queue_head <= queue_tail)
	{
		if(queue[queue_head]->left != NULL)
		{
			queue_tail += 1 ;
			queue[queue_tail] = queue[queue_head]->left;
		}

		if(queue[queue_head]->right != NULL)
		{
			queue_tail += 1 ;
			queue[queue_tail] = queue[queue_head]->right;
		}
		queue_head += 1;
	}
}

void print_queue_data(avl_node_t* queue[], void(*print)(avl_node_t* queue_member))
{
	int i = 0;
	while(1)
	{
		if(queue[i] != NULL)
		{
			print(queue[i]);
			i++;
		}
		else
		{
			break;
		}
	}
	printf("\n");
}


void printf_AVL_tree(avl_node_t* root,  int(*get_data)(avl_node_t* queue_member), int ascii)
{
	if(root == NULL)
	{
		return;
	}
	int level = count_AVL_tree_level(root);
	int width = count_picture_width(level);

	int queue_out = 0;
	int queue_trans = 0;
	char buffer[20];
	avl_node_t * queue[count_queue(level)];

	queue_init(queue, count_queue(level));
	AVL_tree_level_to_queue(root, queue);


    //紀錄每一個level需要列印的行數
	int step[level];
    int j = 0;
	for(int i = level ; i > 0 ; i--)
	{
        step[j] = count_print_times(i);
        j++;		
	}

	//狀態機
	char label[width];
	for(int i = 0 ;i < width ; i++)
	{
		label[i] = ' ';
	}
	
	//真正要印出來的字
	char text[width];
	for(int i = 0 ;i < width ; i++)
	{
		text[i] = ' ';
	}

	//初始化狀態機，將樹根的位置定在正中間
	label[width/2] = '*';




	
	printf("\n");
	for(int i = 0 ; i < level ; i++)
	{
		int count = step[i];
		while(count)
		{
			for(int j = 0 ;j < width ; j++)
			{
				text[j] = ' ';
			}

			for(int k = 0 ;k < width ; k++)
			{
				if(label[k] == 'L')
				{
					text[k] = '/';
				}

				if(label[k] == 'R')
				{
					text[k] = '\\';
				}

				if(label[k] == '*')
				{
					if(ascii == 1)
					{
						sprintf(buffer, "%c", (char)(get_data(queue[queue_out])));
					}
					else
					{
						sprintf(buffer, "%d", get_data(queue[queue_out]));
					}
					

					if(i == 0)
                    {
                        if(strlen(buffer) == 1)
                        {
                            text[k] = buffer[0];
                        }

                        if(strlen(buffer) == 2)
                        {
                            text[k-1] = buffer[0];
                            text[k] = buffer[1];
                        }

                        if(strlen(buffer) == 3)
                        {
                            text[k-1] = buffer[0];
                            text[k] = buffer[1];
                            text[k+1] = buffer[2];
                        }
                    }

					if(label[k+1] == '<')
                    {
                        if(strlen(buffer) == 1)
                        {
                            text[k] = buffer[0];
                        }

                        if(strlen(buffer) == 2)
                        {
                            text[k] = buffer[0];
                            text[k+1] = buffer[1];
                        }

                        if(strlen(buffer) == 3)
                        {
                            text[k] = buffer[0];
                            text[k+1] = buffer[1];
                            text[k+2] = buffer[2];
                        }
                    
						label[k+1] = ' ';     
                    }

                    if(label[k-1] == '>')
                    {
                        if(strlen(buffer) == 1)
                        {
                            text[k] = buffer[0];
                        }

                        if(strlen(buffer) == 2)
                        {
                            text[k-1] = buffer[0];
                            text[k] = buffer[1];
                        }

                        if(strlen(buffer) == 3)
                        {
                            text[k-2] = buffer[0];
                            text[k-1] = buffer[1];
                            text[k] = buffer[2];
                        }
						label[k-1] = ' ';
                    }		

					queue_out += 1;
					
				}
			}

			for(int l = 0 ;l < width ; l++)
			{
				printf("%c", text[l]);
			}
			

			for(int m = 0 ; m < width ; m++)
			{
				if(text[m] == '/')
				{
					label[m] = ' ';
					label[m-1] = 'L';
				}

				if(text[m] == '\\')
				{
					label[m] = ' ';
					label[m+1] = 'R';
				}

				if(label[m] == '*')
				{
					if(queue[queue_trans]->left != NULL)
					{
						label[m-1] = 'L';
					}

					if(queue[queue_trans]->right != NULL)
					{
						label[m+1] = 'R';
					}					
					
					label[m] = ' ';
					queue_trans += 1;
				}
			}
			printf("\n");
			count--;			
		}

		if(count == 0)
		{
			for(int i = 0 ;i < width ; i++)
			{
				if(label[i] == 'L')
				{
					label[i] = '*';
					label[i+1] = '<';
				}

				if(label[i] == 'R')
				{
					label[i] = '*';
					label[i-1] = '>';
				}
			}
		}
		
	}

	//印出最後一層
	for(int j = 0 ;j < width ; j++)
	{
		text[j] = ' ';
	}

	for(int k = 0 ;k < width ; k++)
	{
		if(label[k] == '*')
		{				
			if(ascii == 1)
			{
				sprintf(buffer, "%c", (char)(get_data(queue[queue_out])));
			}
			else
			{
				sprintf(buffer, "%d", get_data(queue[queue_out]));
			}

			if(label[k+1] == '<')
            {
                if(strlen(buffer) == 1)
                {
                    text[k] = buffer[0];
                }

                if(strlen(buffer) == 2)
                {
                    text[k] = buffer[0];
                    text[k+1] = buffer[1];
                }

                if(strlen(buffer) == 3)
                {
                    text[k] = buffer[0];
                    text[k+1] = buffer[1];
                    text[k+2] = buffer[2];
                }
				label[k+1] = ' ';
            }

            if(label[k-1] == '>')
            {
                if(strlen(buffer) == 1)
                {
                    text[k] = buffer[0];
                }

                if(strlen(buffer) == 2)
                {
                    text[k-1] = buffer[0];
                    text[k] = buffer[1];
                }

                if(strlen(buffer) == 3)
                {
                    text[k-2] = buffer[0];
                    text[k-1] = buffer[1];
                    text[k] = buffer[2];
                }
				label[k-1] = ' ';
            }		
			
			queue_out += 1;
		}
	}

	for(int i = 0 ;i < width ; i++)
	{
		printf("%c", text[i]);
	}
	printf("\n");
}
