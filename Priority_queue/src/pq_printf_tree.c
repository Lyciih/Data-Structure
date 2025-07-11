#include"pqSpec.h"

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
int count_picture_width(int pq_tree_level)
{
	return exponent_Int(2, pq_tree_level + 2) - 1 ;
}



//算出每一個level需要列印的行數
int count_print_times(int pq_tree_level)
{
	if(pq_tree_level == 0)
	{
		return 0;
	}
	else if(pq_tree_level == 1)
    {
        return 3;
    }
	else
	{
		return exponent_Int(2, pq_tree_level);
	}
}

void pq_printf_tree(PQ_t* pq,  char*(*get_data)(void* queue_member))
{   
    if(pq->heap.numElementds == 0)
    {
        return;
    }
    int level = count_pq_level(pq);
    int width = count_picture_width(level);
    int queue_out = 0;
    int queue_trans = 1;
    int offset_direct = 0;
	char buffer[20];


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
        offset_direct = 0;
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
                    offset_direct++;
					sprintf(buffer, "%s", get_data(*((void**)pq->heap.elements + queue_out)));

                    if(offset_direct % 2 == 1)
                    {
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
                        else
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
                        }     
                    }

                    if(offset_direct % 2 == 0)
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
					if(queue_trans * 2 <= pq->heap.numElementds)
					{
						label[m-1] = 'L';
					}

					if(queue_trans * 2 + 1 <= pq->heap.numElementds)
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
				}

				if(label[i] == 'R')
				{
					label[i] = '*';
				}
			}
		}
		
	}

	//印出最後一層
	for(int j = 0 ;j < width ; j++)
	{
		text[j] = ' ';
	}

    offset_direct = 0;

	for(int k = 0 ;k < width ; k++)
	{
        
		if(label[k] == '*')
		{	
            offset_direct++;			
			sprintf(buffer, "%s", get_data(*((void**)pq->heap.elements + queue_out)));

            if(offset_direct % 2 == 1)
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
            }

            if(offset_direct % 2 == 0)
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
