#include"ALL.h"
//카운트(터미널(단말) 카운트)
//서치2:찾아가는 과정 서치1에서 있으면
//서치1:있다/없다 유무 
//서치: 깊이 찾는
//포스트, 인, 프리오더, 레벨 오더 출력


Node *Add_new_node()
{
	Node* temp = (Node*)malloc(sizeof(Node));

	temp->L_Next = NULL;
	temp->R_Next = NULL;
	temp->nData = 0;

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
	else if (top->nData > item)//삽입 데이터 보다 부모 노드의 데이터가 큰 경우
	{
		if (top->L_Next == NULL)
		{
			temp = Add_new_node();
			temp->nData = item;
			top->L_Next = temp;
			return;
		}
		else
		{
			Create_node(top->L_Next, item);
		}
	}

	else//삽입 데이터 보다 부모 노드의 데이터가 작은 경우
	{
		if (top->R_Next == NULL)
		{
			temp = Add_new_node();
			temp->nData = item;
			top->R_Next = temp;
			return;
		}
		else
		{
			Create_node(top->R_Next, item);
		}
	}
}
//Create의 알고리즘과 거의 유사할 것으로 예상함

void Delete_node_search(Node* r_top, Node* t_top, int item)
{
	if (t_top->nData > item)
	{
		if (t_top->L_Next->nData == item)
		{
			if (r_top->L_Next != NULL)
			{
				if ((r_top->L_Next->L_Next == NULL) && (r_top->L_Next->R_Next == NULL))
				{
					Delete_node(t_top->L_Next);
					r_top->L_Next = NULL;
				}
				else
				{
					if ((t_top->L_Next->L_Next == NULL) && (t_top->L_Next->R_Next == NULL))
					{
						Delete_node(t_top->L_Next);
						t_top->L_Next = NULL;
					}
					else
						Delete_node(t_top->L_Next);
				}
			}
			else
				Delete_node(t_top->L_Next);
			return;
		}


		else
		{
			Delete_node_search(r_top, t_top->L_Next, item);
		}
	}
	else if (t_top->nData < item)
	{
		if (t_top->R_Next->nData == item)
		{
			if (r_top->R_Next != NULL)
			{
				if ((r_top->R_Next->L_Next == NULL) && (r_top->R_Next->R_Next == NULL))
				{
					Delete_node(t_top->R_Next);
					r_top->R_Next = NULL;
				}
				else
				{
					if ((t_top->R_Next->L_Next == NULL) && (t_top->R_Next->R_Next == NULL))
					{
						Delete_node(t_top->R_Next);
						t_top->R_Next = NULL;
					}
					else
						Delete_node(t_top->R_Next);
				}

			}
			else
				Delete_node(t_top->R_Next);
			return;
		}
		else
		{
			Delete_node_search(r_top, t_top->R_Next, item);
		}
	}
	else
		Delete_node(t_top);

}
void Delete_node(Node* delete_node)//지울 노드를 부모 노드로 시작
{
	//루트를 지우고 대체할 노드가 없는 경우는 고려 x
	//우선순위 오른쪽에서 제일 작은 자식 노드/ 오른쪽/왼쪽에서 제일 큰 자식 노드/ 왼쪽/ 삭제할 노드의 자식 노드가 없으면 return;
	Node* candidate_node;
	Node* backup_node;

	if (delete_node->R_Next != NULL)//지울 노드 기준 오른쪽이 있을떄
	{
		//지울 노드보다 큰 노드들 중에 가장 작은 노드를 찾는 것이 목표
		candidate_node = delete_node->R_Next;
		if (candidate_node->L_Next != NULL)
		{
			while (candidate_node->L_Next != NULL)
			{
				backup_node = candidate_node;
				candidate_node = candidate_node->L_Next;
			}
			delete_node->nData = candidate_node->nData;
			candidate_node->nData = 0;
			if (candidate_node->R_Next != NULL)
			{
				Delete_node(candidate_node);
			}
			else
			{
				backup_node->L_Next = NULL;
				free(candidate_node);
			}
		}
		else
		{
			delete_node->nData = candidate_node->nData;
			candidate_node->nData = 0;
			if (candidate_node->R_Next != NULL)
			{
				Delete_node(candidate_node);
			}
			else
			{
				//이부분을 좀더 살펴봐야 할듯
				//candidate_node = NULL;
				delete_node->R_Next = NULL;
				free(candidate_node);
			}
		}
	}
	else if (delete_node->L_Next != NULL)//지울 노드 기준 오른쪽이 없을떄
	{
		//지울 노드보다 작은 노드들 중에 가장 큰 노드를 찾는 것이 목표
		candidate_node = delete_node->L_Next;
		if (candidate_node->R_Next != NULL)
		{
			while (candidate_node->R_Next != NULL)
			{
				backup_node = candidate_node;
				candidate_node = candidate_node->R_Next;
			}
			delete_node->nData = candidate_node->nData;
			candidate_node->nData = 0;
			if (candidate_node->L_Next != NULL)
			{
				Delete_node(candidate_node);
			}
			else
			{
				backup_node->R_Next = NULL;
				free(candidate_node);
			}
		}
		else
		{
			delete_node->nData = candidate_node->nData;
			candidate_node->nData = 0;
			if (candidate_node->L_Next != NULL)
			{
				Delete_node(candidate_node);
			}
			else
			{
				//candidate_node = NULL;
				delete_node->L_Next = NULL;
				free(candidate_node);
			}
		}
	}
	else
	{
		delete_node->nData = 0;
		//free(delete_node);
		return;
	}
}

void Print_pre_order(Node *top)
{//루왼오
	printf("%d ", top->nData);
	if (top->L_Next)
		Print_pre_order(top->L_Next);
	if (top->R_Next)
		Print_pre_order(top->R_Next);
	else
	{
		return;
	}
}
void Print_in_order(Node *top)
{//왼루오
	if (top->L_Next)
		Print_in_order(top->L_Next);
	else
	{
		printf("%d ", top->nData);
		if (top->R_Next)
			Print_in_order(top->R_Next);
		return;
	}
	printf("%d ", top->nData);
	if (top->R_Next)
		Print_in_order(top->R_Next);

}

void Print_post_order(Node *top)
{//왼오루
	if (top->L_Next)
		Print_post_order(top->L_Next);
	else
	{
		if (top->R_Next)
			Print_post_order(top->R_Next);
		printf("%d ", top->nData);
		return;
	}
	if (top->R_Next)
		Print_post_order(top->R_Next);
	else
	{
		printf("%d ", top->nData);
		return;
	}
	printf("%d ", top->nData);

}

void Print_level_order(Node *top)
{
	int *level_order;
	int depth = 1;
	int depth_max = 1;

	depth_max = Depth_search(top, depth, depth_max);
	level_order = (int*)calloc(pow(2, (double)depth_max), sizeof(int));
	Print_level_order_dataset(top, &level_order, 1);
	if (top->L_Next == NULL && top->R_Next == NULL)
		level_order[1] = top->nData;
	Print_Tree(level_order);
}

int Depth_search(Node *top, int depth, int depth_max)
{
	int depth_temp = 0;

	if (top->L_Next)
	{
		depth += 1;
		if (depth > depth_max)
			depth_max = depth;

		depth_temp = Depth_search(top->L_Next, depth, depth_max);
		if (depth_temp > depth_max)
			depth_max = depth_temp;
		depth -= 1;
	}
	else
	{
		if (top->R_Next)
		{
			depth += 1;
			if (depth > depth_max)
				depth_max = depth;

			depth_temp = Depth_search(top->R_Next, depth, depth_max);
			if (depth_temp > depth_max)
				depth_max = depth_temp;
			depth -= 1;
		}
		return depth_max;
	}
	if (top->R_Next)
	{
		depth += 1;
		if (depth > depth_max)
			depth_max = depth;

		depth_temp = Depth_search(top->R_Next, depth, depth_max);
		if (depth_temp > depth_max)
			depth_max = depth_temp;
		depth -= 1;
	}
	else
	{
		return depth_max;
	}
	return depth_max;
}

int Print_level_order_dataset(Node *top, int **level_order,int idx)
{
	if (top->L_Next)
	{
		idx = idx * 2;
		if ((*level_order)[idx] == 0)
			(*level_order)[idx] = top->L_Next->nData;
		idx = Print_level_order_dataset(top->L_Next, level_order, idx);
		idx = idx / 2;
		if ((*level_order)[idx] == 0)
			(*level_order)[idx] = top->nData;
	}
	else
	{
		if (top->R_Next)
		{
			idx = idx * 2 + 1;
			if ((*level_order)[idx] == 0)
				(*level_order)[idx] = top->R_Next->nData;
			idx = Print_level_order_dataset(top->R_Next, level_order, idx);
			idx = idx / 2;
			if ((*level_order)[idx] == 0)
				(*level_order)[idx] = top->nData;
		}
		return idx;
	}
	if (top->R_Next)
	{
		idx = idx * 2 + 1;
		if ((*level_order)[idx] == 0)
			(*level_order)[idx] = top->R_Next->nData;
		idx = Print_level_order_dataset(top->R_Next, level_order, idx);
		idx = idx / 2;
		if ((*level_order)[idx] == 0)
			(*level_order)[idx] = top->nData;
		return idx;
	}
	else
		return idx;
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
/*void Print_level_order(Node *top, Node ***level_order,int level)
{//높은 레벨부터 레벨 순으로 출력
	(*level_order)[level] = (Node**)malloc((level+1) * sizeof(Node*));


	void traverse_all(Node *top)
	{
	if (top->L_Next)
	traverse_all(top->L_Next);
	else
	{
	if (top->R_Next)
	traverse_all(top->R_Next);
	return;
	}
	if (top->R_Next)
	traverse_all(top->R_Next);
	}

	void Print_terminal(Node * top, int depth)
	{
	if (top->L_Next == NULL || top->R_Next == NULL)
	{
	printf("%d,%d\n", top->nData, depth);
	return;
	}
	else
	{
	depth += 1;
	Print_terminal(top->L_Next, depth);
	if (top->R_Next != NULL)
	{
	if(top->L_Next == NULL)
	depth += 1;
	Print_terminal(top->R_Next, depth);
	}
	}

	}
	void Terminal_count(Node * top, int cnt)
	{
	Node *Left = top->L_Next;
	Node *Right = top->R_Next;

	if (Left == NULL)
	{
	printf("%d\n", cnt);
	return;
	}
	else
	{
	if (Left == NULL&&Right == NULL)
	cnt++;
	Terminal_count(Left,cnt);
	if (Right != NULL)
	Terminal_count(Right,cnt);
	}

	}
}*/
#ifdef SAVE
void Print_post_order(Node *top)
{//왼오루
	if (top->L_Next)
		Print_post_order(top->L_Next);
	else
	{
		if (top->R_Next)
			Print_post_order(top->R_Next);
		printf("%d ", top->nData);
		return;
	}
	if (top->R_Next)
		Print_post_order(top->R_Next);
	else
		return;

	printf("%d ", top->nData);

}

void Delete_node_search(Node* r_top, Node* t_top, int item)
{
	if (t_top->nData > item)
	{
		if (t_top->L_Next->nData == item)
		{
			Delete_node(t_top->L_Next);
			if ((r_top->L_Next->L_Next == NULL) && (r_top->L_Next->R_Next == NULL))
				r_top->L_Next = NULL;
			return;
		}
		else
		{
			Delete_node_search(r_top, t_top->L_Next, item);
		}
	}

	else if (t_top->nData < item)
	{
		if (t_top->R_Next->nData == item)
		{
			Delete_node(t_top->R_Next);
			if ((r_top->R_Next->L_Next == NULL) && (r_top->R_Next->R_Next == NULL))
				r_top->R_Next = NULL;
			return;
		}
		else
		{
			Delete_node_search(r_top, t_top->R_Next, item);
		}
	}
	else
		Delete_node(t_top);

}

void Delete_node_search(Node* top, int item)
{
	if (top->nData > item)
	{
		if (top->L_Next->nData == item)
		{
			Delete_node(top->L_Next);
			return;
		}
		else
		{
			Delete_node_search(top->L_Next, item);
		}
	}

	else if (top->nData < item)
	{
		if (top->R_Next->nData == item)
		{
			Delete_node(top->R_Next);
			return;
		}
		else
		{
			Delete_node_search(top->R_Next, item);
		}
	}
	else
		Delete_node(top);

}


void Create_node(Node* top, int item)
{
	Node* temp;

	if (top->nData > item)//삽입 데이터 보다 부모 노드의 데이터가 큰 경우
	{
		if (top->L_Next == NULL)
		{
			temp = Add_new_node();
			temp->nData = item;
			top->L_Next = temp;
			return;
		}
		else
		{
			Create_node(top->L_Next, item);
		}
	}

	else//삽입 데이터 보다 부모 노드의 데이터가 작은 경우
	{
		if (top->R_Next == NULL)
		{
			temp = Add_new_node();
			temp->nData = item;
			top->R_Next = temp;
			return;
		}
		else
		{
			Create_node(top->R_Next, item);
		}
	}
}

void Create_node(Node* top, int item)
{
	Node* temp;

	if (top != NULL)
	{
		if (top->nData > item)//삽입 데이터 보다 부모 노드의 데이터가 큰 경우
			Create_node(top->L_Next, item);

		else//삽입 데이터 보다 부모 노드의 데이터가 작은 경우
			Create_node(top->R_Next, item);
	}
	else
	{
		temp = Add_new_node();
		temp->nData = item;
		return;
	}

}
#endif
#ifdef NOTYET

Node* Root_finder(Node* top, int item)
{
	if (top->nData > item)//삽입 데이터 보다 부모 노드의 데이터가 큰 경우
	{
		if (top->L_Next != NULL)
			Root_finder(top->L_Next, item);
		else
			return top->L_Next;
	}
	else//삽입 데이터 보다 부모 노드의 데이터가 작은 경우
	{
		if (top->R_Next != NULL)
			Root_finder(top->R_Next, item);
		else
			return top->R_Next;
	}
}

#endif