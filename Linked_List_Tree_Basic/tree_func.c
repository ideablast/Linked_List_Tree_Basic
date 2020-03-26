#include"ALL.h"
//ī��Ʈ(�͹̳�(�ܸ�) ī��Ʈ)
//��ġ2:ã�ư��� ���� ��ġ1���� ������
//��ġ1:�ִ�/���� ���� 
//��ġ: ���� ã��
//����Ʈ, ��, ��������, ���� ���� ���


Node *Add_new_node(int item)
{
	Node* temp = (Node*)malloc(sizeof(Node));

	temp->L_Next = NULL;
	temp->R_Next = NULL;
	temp->nData = item;

	return temp;
}


//���� ����� Ʈ���� ũ�� ������, ������ ���� ��忡 �ڽ��� ��ġ�Ѵ�.
void Create_node(Node* top, int item)
{
	Node* temp;
	if (top->nData == 0)
	{
		top->nData = item;
	}
	else
	{
		if (top->nData > item)//���� ������ ���� �θ� ����� �����Ͱ� ū ���
		{
			if (top->L_Next == NULL)
			{
				temp = Add_new_node(item);
				top->L_Next = temp;
				return;
			}
			else
			{
				Create_node(top->L_Next, item);
			}
		}

		if (top->nData < item)//���� ������ ���� �θ� ����� �����Ͱ� ���� ���
		{
			if (top->R_Next == NULL)
			{
				temp = Add_new_node(item);
				top->R_Next = temp;
				return;
			}
			else
			{
				Create_node(top->R_Next, item);
			}
		}
	}
}

void Delete_tree(Node * top, int item)
{
	Node *delete_node = top;//���� ���
	Node *candidate_node;//��ü�� ����� �� �� �ִ� �ĺ��� ���
	Node *backup_node;//���� ������ �ʱ�ȭ �ϱ����� ���



	while (1)
	{
		if (delete_node->nData == item)
		{
			if (delete_node->L_Next == NULL && delete_node->R_Next == NULL)
			{
				if (delete_node == top)
				{
					delete_node->nData = 0;
					break;
				}
				else
				{
					if (backup_node->L_Next->nData == item)
					{
						backup_node->L_Next = NULL;
						free(delete_node);
						break;
					}
					else
					{
						backup_node->R_Next = NULL;
						free(delete_node);
						break;
					}
				}
			}
			else
			{
				backup_node = delete_node;
				if (delete_node->R_Next)
				{
					candidate_node = delete_node->R_Next;
					if (candidate_node->L_Next)//��-��
					{
						backup_node = candidate_node;
						while (candidate_node->L_Next)
						{
							backup_node = candidate_node;
							candidate_node = candidate_node->L_Next;
						}
						delete_node->nData = candidate_node->nData;
						delete_node = candidate_node;
						item = candidate_node->nData;

						if (delete_node->L_Next == NULL && delete_node->R_Next == NULL)
						{
							backup_node->L_Next = NULL;
							free(delete_node);
							break;
						}
					}
					else//��
					{
						delete_node->nData = candidate_node->nData;
						delete_node = candidate_node;
						item = candidate_node->nData;
						if (delete_node->L_Next == NULL && delete_node->R_Next == NULL)
						{
							backup_node->R_Next = NULL;
							free(delete_node);
							break;
							
						}
					}
				}
				else if (delete_node->L_Next)
				{
					candidate_node = delete_node->L_Next;
					if (candidate_node->R_Next)//��-��
					{
						backup_node = candidate_node;
						while (candidate_node->R_Next)
						{
							backup_node = candidate_node;
							candidate_node = candidate_node->R_Next;
						}
						delete_node->nData = candidate_node->nData;
						delete_node = candidate_node;
						item = candidate_node->nData;
					
						if (delete_node->L_Next == NULL && delete_node->R_Next == NULL)
						{
							backup_node->R_Next = NULL;
							free(delete_node);
							break;
						}
					}
					else//��
					{
						delete_node->nData = candidate_node->nData;
						delete_node = candidate_node;
						item = candidate_node->nData;
						if (delete_node->L_Next == NULL && delete_node->R_Next == NULL)
						{
							backup_node->L_Next = NULL;
							free(delete_node);
							break;
						}
					}
				}

			}
		}
		else
		{
			if (delete_node->nData > item)
			{
				backup_node = delete_node;
				delete_node = delete_node->L_Next;
				if (delete_node == NULL)
					return;

			}
			else 
			{
				backup_node = delete_node;
				delete_node = delete_node->R_Next;
				if (delete_node == NULL)
					return;
			}
		}
	}
}
//Create�� �˰���� ���� ������ ������ ������
//pre,in,post,level_order
void Print_pre_order(Node *top)
{
	if (top)
	{
		printf("%d ", top->nData);
		Print_pre_order(top->L_Next);
		Print_pre_order(top->R_Next);
	}
}

void Print_in_order(Node *top)
{
	if (top)
	{
		Print_in_order(top->L_Next);
		printf("%d ", top->nData);
		Print_in_order(top->R_Next);
	}
}

void Print_post_order(Node *top)
{
	if (top)
	{
		Print_post_order(top->L_Next);
		Print_post_order(top->R_Next);
		printf("%d ", top->nData);
	}
}
//#define STAND_ALONE
#ifdef STAND_ALONE
void Level_order(Node *top)
{

	Node *level_order[200] = { 0 };
	int idx = 1;

	if (top)
		level_order[idx] = top;
	else
		return;

	while (idx<200)
	{
		if (level_order[idx])
		{
			if (level_order[idx]->L_Next)
				level_order[idx * 2] = level_order[idx]->L_Next;
			if (level_order[idx]->R_Next)
				level_order[idx * 2 + 1] = level_order[idx]->R_Next;
		}
		idx++;
	}
	
}
#endif
void Level_order(Node *top)
{

	Node **level_order;
	int idx = 1;
	int depth_max = Search_depth(top);

	int num_of_ary = (int)pow(2, (double)depth_max);
	int new_line_idx = 2;
	int cnt = 1;



	level_order = (Node **)calloc((int)pow(2, (double)depth_max) , sizeof(Node*));

	if (top)
		level_order[idx] = top;
	else
		return;

	while (idx < num_of_ary)
	{
		if (level_order[idx])
		{
			if (level_order[idx]->L_Next)
				level_order[idx * 2] = level_order[idx]->L_Next;
			if (level_order[idx]->R_Next)
				level_order[idx * 2 + 1] = level_order[idx]->R_Next;
		}
		idx++;
	}

	puts("---------------------------------------");
	for (idx = 0; idx < num_of_ary; idx++)
	{

		if (idx != 0)
		{
			if (level_order[idx] == NULL)
				printf("%2d ", 0);
			else
				printf("%2d ", level_order[idx]->nData);

			cnt++;
		}
		else
			printf("Level %2d: ", (int)Log2((double)cnt) + 1);

		if (cnt == new_line_idx)
		{
			puts("");
			if (idx != num_of_ary - 1)
				printf("Level %2d: ", (int)Log2((double)cnt) + 1);
			new_line_idx = new_line_idx * 2;
		}
	}
	puts("---------------------------------------");
}

//����Ʈ ��� �ƴ�
//void �̿��� ��� ȣ��: ȣ���� �Լ� ���ڸ�ŭ ������ �ִ�.
int Count_tree(Node *top)
{
	int cnt = 0;
	if (top)
	{
		cnt = Count_tree(top->L_Next) + Count_tree(top->R_Next) + 1;

	}
	return cnt;
}


int Terminal_count(Node *top)
{
	int cnt = 0;
	if (top)
	{
		cnt = Terminal_count(top->L_Next) + Terminal_count(top->R_Next);

		if (top->L_Next == NULL && top->R_Next == NULL)
			cnt += 1;

	}
	return cnt;
}

int Search_depth(Node *top)
{
	int cnt = 0;
	if (top)
	{
		
		cnt = Search_depth(top->L_Next) > Search_depth(top->R_Next)? Search_depth(top->L_Next): Search_depth(top->R_Next);
		cnt = cnt + 1;

	}
	return cnt;
}


int Search_TF(Node *top, int item)
{

	if (top->nData == item)
	{
		return TRUE;//�ѹ� �����ϸ� ���� ������ ����?
	}
	else
	{
		if (top->nData > item)//���� ������ ���� �θ� ����� �����Ͱ� ū ���
		{
			if (top->L_Next == NULL)
				return FALSE;
			else
				Search_TF(top->L_Next, item);
		}
		else//���� ������ ���� �θ� ����� �����Ͱ� ���� ���
		{
			if (top->R_Next == NULL)
				return FALSE;
			else
				Search_TF(top->R_Next, item);
		}
	}
}

void Search_Direction(Node *top, int item)//�����ϴ� �׸���� ������� ������ �Լ�
{
	if (top->nData == item)
	{
		printf("END\n");
	}
	else
	{
		if (top->nData > item)//���� ������ ���� �θ� ����� �����Ͱ� ū ���
		{
			printf("LEFT ");
			Search_Direction(top->L_Next, item);
		}
		else//���� ������ ���� �θ� ����� �����Ͱ� ���� ���
		{
			printf("RIGHT ");
			Search_Direction(top->R_Next, item);
		}
	}
}

void Print_Tree(int *tree)
{
	int idx;
	int num_of_ary;
	int new_line_idx = 2;
	int cnt = 1;
	num_of_ary = _msize(tree) / sizeof(int);

	puts("---------------------------------------");
	for (idx = 0; idx < num_of_ary; idx++)
	{

		if (idx != 0)
		{
			printf("%2d ", tree[idx]);
			cnt++;
		}
		else
			printf("Level %2d: ", (int)Log2((double)cnt) + 1);

		if (cnt == new_line_idx)
		{
			puts("");
			if (idx != num_of_ary - 1)
				printf("Level %2d: ", (int)Log2((double)cnt) + 1);
			new_line_idx = new_line_idx * 2;
		}
	}
	puts("---------------------------------------");
}

/*SIMPLE_MATH*/
double Log2(double x)
{
	return log(x) / log(2);
}

#ifdef NOTYET
void Delete_tree(Node * top, int item)
{
	Node *delete_node = top;
	Node *save_node;
	Node *delete_link;
	Node *candidate_node;

	while (1)
	{
		if (delete_node)
		{
			if (delete_node->nData == item)
			{
				delete_node->nData = 0;
				save_node = delete_node;
				break;
			}
			else
			{
				if (delete_node->nData > item)
				{
					delete_link = delete_node;
					delete_node = delete_node->L_Next;
				}
				else
				{
					delete_link = delete_node;
					delete_node = delete_node->R_Next;
				}
			}
		}
		else
			break;
	}

	while (1)//��ũ�� ���϶�
	{
		if (delete_node == top&&top->L_Next == NULL &&top->R_Next == NULL)
			break;
		else
		{

			if (delete_node->R_Next)
			{
				candidate_node = delete_node->R_Next;
				if (candidate_node->L_Next)//��-��
				{
					while (candidate_node->L_Next)
					{
						delete_link = candidate_node;//�� ������  �ʿ� ���� �ñ�
						candidate_node = candidate_node->L_Next;
					}
					save_node->nData = candidate_node->nData;
					candidate_node->nData = 0;
					delete_node = candidate_node;
					save_node = delete_node;
					//���� ������ �κ�-NULL ó��
					if (delete_node->L_Next == NULL && delete_node->R_Next == NULL)
					{
						delete_link->L_Next = NULL;
						//delete_node = NULL;
					}
				}
				else//��
				{
					save_node->nData = candidate_node->nData;
					candidate_node->nData = 0;
					delete_node = candidate_node;
					save_node = delete_node;
					//���� ������ �κ�-NULL ó��
					if (delete_node->L_Next == NULL && delete_node->R_Next == NULL)
					{
						delete_link->R_Next = NULL;
						//delete_node = NULL;
					}
				}
			}
			else if (delete_node->L_Next)
			{
				candidate_node = delete_node->L_Next;
				if (candidate_node->R_Next)//��-��
				{
					while (candidate_node->R_Next)
					{
						delete_link = candidate_node;
						candidate_node = candidate_node->R_Next;
					}
					save_node->nData = candidate_node->nData;
					candidate_node->nData = 0;
					delete_node = candidate_node;
					save_node = delete_node;
					//���� ������ �κ�-NULL ó��
					if (delete_node->L_Next == NULL && delete_node->R_Next == NULL)
					{
						delete_link->R_Next = NULL;
						//delete_node = NULL;
					}
				}
				else//��
				{
					save_node->nData = candidate_node->nData;
					candidate_node->nData = 0;
					delete_node = candidate_node;
					save_node = delete_node;
					//���� ������ �κ�-NULL ó��
					if (delete_node->L_Next == NULL && delete_node->R_Next == NULL)
					{
						delete_link->L_Next = NULL;
						//delete_node = NULL;
					}
				}
			}
			else
			{
				//���� ������ �κ�-NULL ó��


				//����� �ٲ� ����� ���� ����� ���� ó��
				if (delete_link->L_Next->nData == 0)
					delete_link->L_Next = NULL;
				else
					delete_link->R_Next = NULL;

				free(delete_node);
				break;
			}

		}
	}
}



int Count_tree(Node *top)//-1�Ѱ��� ī��Ʈ ����
{
	// ������ ��꿡 �������� ������ �ʱ�ȭ�� �� �� �ʿ䰡 ����.
	if (top)//��ũ�� ������(1�� �ƴϸ� 2��)
	{
		//��ũ�� ������ �Ҵ��� �ȵ� ��쵵 �� ���� ������ �ٷ� ���ÿ� ���ٰ� if�� �ɷ��� ����
		return Count_tree(top->L_Next) + Count_tree(top->R_Next);
	}
	else//��ũ�� ������(0��)
		return 1;
}

int Terminal_count(Node *top)
{
	//�׳� �Լ��� ������ ���� ��ȯ ����
	//return ������ ���� ��� �Լ� ������ ����
	//��� ������ �޾��� ������ ������ ���� Ȱ�� ����
	//������ ���꿡 �����ϸ� �ʱ�ȭ�� �ϰ� ����ؾ���
	//�׳� ���� ������ ���̸� �� ������ �ʱ�ȭ �� �� �����Ƿ� �ʱ�ȭ �ʿ� ����

	//�͹̳��� ���� �ڽĳ�尡 ���� ���
	//�ڽĳ�尡 ���°� �Ǵ� �θ��忡�� �� �� ��尡 NULL�ΰ��
	int cnt = 0;

	if (top)//�����̴� �������̴� ��ũ�� ������ ����� ����
	{
		if (top->L_Next == NULL && top->R_Next == NULL)
			return 1;
		else
			return Terminal_count(top->L_Next) + Terminal_count(top->R_Next);
	}

	return cnt;
}
#endif
