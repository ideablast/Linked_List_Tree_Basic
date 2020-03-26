#include"ALL.h"
//카운트(터미널(단말) 카운트)
//서치2:찾아가는 과정 서치1에서 있으면
//서치1:있다/없다 유무 
//서치: 깊이 찾는
//포스트, 인, 프리오더, 레벨 오더 출력


Node *Add_new_node(int item)
{
	Node* temp = (Node*)malloc(sizeof(Node));

	temp->L_Next = NULL;
	temp->R_Next = NULL;
	temp->nData = item;

	return temp;
}


//지금 만드는 트리는 크면 오른쪽, 작으면 왼쪽 노드에 자식이 위치한다.
void Create_node(Node* top, int item)
{
	Node* temp;
	if (top->nData == 0)
	{
		top->nData = item;
	}
	else
	{
		if (top->nData > item)//삽입 데이터 보다 부모 노드의 데이터가 큰 경우
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

		if (top->nData < item)//삽입 데이터 보다 부모 노드의 데이터가 작은 경우
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
	Node *delete_node = top;//지울 노드
	Node *candidate_node;//교체의 대상이 될 수 있는 후보자 노드
	Node *backup_node;//연결 정보를 초기화 하기위한 노드



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
					if (candidate_node->L_Next)//오-왼
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
					else//오
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
					if (candidate_node->R_Next)//왼-오
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
					else//왼
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
//Create의 알고리즘과 거의 유사할 것으로 예상함
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

//딜리트 재귀 아님
//void 이외의 재귀 호출: 호출한 함수 숫자만큼 리턴이 있다.
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
		return TRUE;//한번 리턴하면 값을 끝까지 리턴?
	}
	else
	{
		if (top->nData > item)//삽입 데이터 보다 부모 노드의 데이터가 큰 경우
		{
			if (top->L_Next == NULL)
				return FALSE;
			else
				Search_TF(top->L_Next, item);
		}
		else//삽입 데이터 보다 부모 노드의 데이터가 작은 경우
		{
			if (top->R_Next == NULL)
				return FALSE;
			else
				Search_TF(top->R_Next, item);
		}
	}
}

void Search_Direction(Node *top, int item)//존재하는 항목들을 대상으로 실행할 함수
{
	if (top->nData == item)
	{
		printf("END\n");
	}
	else
	{
		if (top->nData > item)//삽입 데이터 보다 부모 노드의 데이터가 큰 경우
		{
			printf("LEFT ");
			Search_Direction(top->L_Next, item);
		}
		else//삽입 데이터 보다 부모 노드의 데이터가 작은 경우
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

	while (1)//링크가 참일때
	{
		if (delete_node == top&&top->L_Next == NULL &&top->R_Next == NULL)
			break;
		else
		{

			if (delete_node->R_Next)
			{
				candidate_node = delete_node->R_Next;
				if (candidate_node->L_Next)//오-왼
				{
					while (candidate_node->L_Next)
					{
						delete_link = candidate_node;//이 과정의  필요 유무 궁금
						candidate_node = candidate_node->L_Next;
					}
					save_node->nData = candidate_node->nData;
					candidate_node->nData = 0;
					delete_node = candidate_node;
					save_node = delete_node;
					//좀더 봐야할 부분-NULL 처리
					if (delete_node->L_Next == NULL && delete_node->R_Next == NULL)
					{
						delete_link->L_Next = NULL;
						//delete_node = NULL;
					}
				}
				else//오
				{
					save_node->nData = candidate_node->nData;
					candidate_node->nData = 0;
					delete_node = candidate_node;
					save_node = delete_node;
					//좀더 봐야할 부분-NULL 처리
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
				if (candidate_node->R_Next)//왼-오
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
					//좀더 봐야할 부분-NULL 처리
					if (delete_node->L_Next == NULL && delete_node->R_Next == NULL)
					{
						delete_link->R_Next = NULL;
						//delete_node = NULL;
					}
				}
				else//왼
				{
					save_node->nData = candidate_node->nData;
					candidate_node->nData = 0;
					delete_node = candidate_node;
					save_node = delete_node;
					//좀더 봐야할 부분-NULL 처리
					if (delete_node->L_Next == NULL && delete_node->R_Next == NULL)
					{
						delete_link->L_Next = NULL;
						//delete_node = NULL;
					}
				}
			}
			else
			{
				//좀더 봐야할 부분-NULL 처리


				//지우고 바꿀 대상이 없는 경우의 예외 처리
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



int Count_tree(Node *top)//-1한것이 카운트 갯수
{
	// 변수가 계산에 참여하지 않으면 초기화를 해 줄 필요가 없다.
	if (top)//링크가 있으면(1개 아니면 2개)
	{
		//링크는 있지만 할당이 안된 경우도 들어감 들어는 가지만 바로 스택에 들어갔다가 if문 걸려서 리턴
		return Count_tree(top->L_Next) + Count_tree(top->R_Next);
	}
	else//링크가 없으면(0개)
		return 1;
}

int Terminal_count(Node *top)
{
	//그냥 함수가 끝나면 값을 반환 못함
	//return 만나면 값을 들고 함수 밖으로 나감
	//들고 나가도 받아줄 변수가 없으면 값으 활용 못함
	//변수가 연산에 참여하면 초기화를 하고 사용해야함
	//그냥 값을 저장할 뿐이면 그 값으로 초기화 할 수 있으므로 초기화 필요 없음

	//터미널의 조건 자식노드가 없는 경우
	//자식노드가 없는것 판단 부모노드에서 좌 우 노드가 NULL인경우
	int cnt = 0;

	if (top)//왼쪽이던 오른쪽이던 링크가 있으면 여기로 들어옴
	{
		if (top->L_Next == NULL && top->R_Next == NULL)
			return 1;
		else
			return Terminal_count(top->L_Next) + Terminal_count(top->R_Next);
	}

	return cnt;
}
#endif
