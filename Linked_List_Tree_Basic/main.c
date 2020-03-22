#include"ALL.h"

int main()
{
	Node *top = Add_new_node();
	int *level_order;
	int depth = 1;
	int depth_max = 1;
	
	Create_node(top, 60);
	Create_node(top, 30);
	Create_node(top, 32);
	Create_node(top, 80);
	Create_node(top, 20);
	Create_node(top, 40);
	Create_node(top, 70);
	Create_node(top, 90);
	Create_node(top, 10);
	Create_node(top, 25);
	Create_node(top, 35);
	Create_node(top, 45);
	Create_node(top, 65);
	Create_node(top, 75);
	Create_node(top, 85);
	Create_node(top, 95);
	Create_node(top, 23);
	Create_node(top, 27);
	Create_node(top, 21);
	Create_node(top, 22);
	Create_node(top, 24);
	Create_node(top, 26);
	Create_node(top, 28);
	Create_node(top, 29);
	Create_node(top, 31);
	
	Print_level_order(top); puts("");
	Delete_node_search(top,top, 60);
	Print_level_order(top); puts("");
	Delete_node_search(top,top, 30);
	Print_level_order(top); puts("");
	Delete_node_search(top,top, 32);
	Print_level_order(top); puts("");
	Delete_node_search(top,top, 80);
	Print_level_order(top); puts("");
	Delete_node_search(top,top, 20);
	Print_level_order(top); puts("");
	Delete_node_search(top,top, 40);
	Print_level_order(top); puts("");
	Delete_node_search(top,top, 70);
	Print_level_order(top); puts("");
	Delete_node_search(top,top, 90);
	Print_level_order(top); puts("");
	Delete_node_search(top,top, 10);
	Print_level_order(top); puts("");
	Delete_node_search(top,top, 25);
	Print_level_order(top); puts("");
	Delete_node_search(top,top, 35);
	Print_level_order(top); puts("");
	Delete_node_search(top,top, 45);
	Print_level_order(top); puts("");
	Delete_node_search(top,top, 65);
	Print_level_order(top); puts("");
	Delete_node_search(top,top, 75);
	Print_level_order(top); puts("");
	Delete_node_search(top,top, 85);
	Print_level_order(top); puts("");
	Print_level_order(top); puts("");
	Delete_node_search(top,top, 95);
	Print_level_order(top); puts("");
	Delete_node_search(top,top, 23);
	Print_level_order(top); puts("");
	Delete_node_search(top,top, 27);
	Print_level_order(top); puts("");
	Delete_node_search(top,top, 21);
	Print_level_order(top); puts("");
	Delete_node_search(top,top, 22);
	Print_level_order(top); puts("");
	Delete_node_search(top,top, 24);
	Print_level_order(top); puts("");
	Delete_node_search(top,top, 26);
	Print_level_order(top); puts("");
	Delete_node_search(top,top, 28);
	Print_level_order(top); puts("");
	Delete_node_search(top,top, 29);
	Print_level_order(top); puts("");
	Delete_node_search(top,top, 31);
	Print_level_order(top); puts("");

	Print_pre_order(top); puts("");
	Print_in_order(top); puts("");
	Print_post_order(top); puts("");	
	Print_level_order(top); puts("");

}

#ifdef EXAMPLE

Create_node(top, 60);
Create_node(top, 30);
Create_node(top, 80);
Create_node(top, 20);
Create_node(top, 32);
Create_node(top, 70);
Create_node(top, 90);
Create_node(top, 25);
Create_node(top, 27);
Create_node(top, 79);
Create_node(top, 71);
Create_node(top, 78);
Create_node(top, 72);
Create_node(top, 77);
Create_node(top, 73);
Create_node(top, 76);
Create_node(top, 74);


Create_node(top, 60);
Create_node(top, 30);
Create_node(top, 32);
Create_node(top, 80);
Create_node(top, 20);
Create_node(top, 40);
Create_node(top, 70);
Create_node(top, 90);
Create_node(top, 10);
Create_node(top, 25);
Create_node(top, 35);
Create_node(top, 45);
Create_node(top, 65);
Create_node(top, 75);
Create_node(top, 85);
Create_node(top, 95);
Create_node(top, 23);
Create_node(top, 27);
Create_node(top, 21);
Create_node(top, 22);
Create_node(top, 24);
Create_node(top, 26);
Create_node(top, 28);
Create_node(top, 29);
Create_node(top, 31);

Create_node(top, 60);
Create_node(top, 30);
Create_node(top, 80);
Create_node(top, 20);
Create_node(top, 32);
Create_node(top, 70);
Create_node(top, 90);
Create_node(top, 25);
Create_node(top, 27);
Create_node(top, 75);
Create_node(top, 71);
Create_node(top, 73);

Create_node(top, 60);
Create_node(top, 30);
Create_node(top, 32);
Create_node(top, 84);
Create_node(top, 20);
Create_node(top, 40);
Create_node(top, 70);
Create_node(top, 90);
Create_node(top, 10);
Create_node(top, 25);
Create_node(top, 35);
Create_node(top, 45);
Create_node(top, 65);
Create_node(top, 75);
//////////////////////
Create_node(top, 76);
Create_node(top, 77);
Create_node(top, 78);
Create_node(top, 79);
Create_node(top, 80);
Create_node(top, 81);
Create_node(top, 82);
Create_node(top, 83);
Create_node(top, 84);
Create_node(top, 63);
Create_node(top, 62);
Create_node(top, 61);
//////////////////////
Create_node(top, 85);
Create_node(top, 95);
Create_node(top, 23);
Create_node(top, 27);
Create_node(top, 21);
Create_node(top, 22);
Create_node(top, 24);
Create_node(top, 26);
Create_node(top, 28);
Create_node(top, 29);
Create_node(top, 31);



		Create_node(top, 23); 
	Create_node(top, 27);
	Create_node(top, 21);
	Create_node(top, 24);
	Create_node(top, 26);
	Create_node(top, 28);


	Delete_node_search(top, top, 60);
	Delete_node_search(top, top, 30);
	Delete_node_search(top, top, 80);
	Delete_node_search(top, top, 20);
	Delete_node_search(top, top, 40);
	Delete_node_search(top, top, 70);
	Delete_node_search(top, top, 90);
	Delete_node_search(top, top, 10);
	Delete_node_search(top, top, 25);
	Delete_node_search(top, top, 35);
	Delete_node_search(top, top, 45);
	Delete_node_search(top, top, 65);
	Delete_node_search(top, top, 75);
	Delete_node_search(top, top, 85);
	Delete_node_search(top, top, 95);

	Delete_node_search(top, 60);
	Delete_node_search(top, 65);
	Delete_node_search(top, 70);
	Delete_node_search(top, 75);
	Delete_node_search(top, 80);

	Delete_node_search(top, top, 90);
	Delete_node_search(top, top, 95);
	Delete_node_search(top, top, 80);
	Delete_node_search(top, top, 85);
	Delete_node_search(top, top, 70);
	Delete_node_search(top, top, 75);
	Delete_node_search(top, top, 65);
	Delete_node_search(top, top, 60);
	Delete_node_search(top, top, 20);
	Delete_node_search(top, top, 40);
	Delete_node_search(top, top, 30);
	Delete_node_search(top, top, 10);
	Delete_node_search(top, top, 25);
	Delete_node_search(top, top, 45);
	Delete_node_search(top, top, 35);
#endif
	
#ifdef NOTYET


top->nData = 60;

top->L_Next = (Node*)malloc(sizeof(Node));
top->L_Next->nData = 30;
top->R_Next = (Node*)malloc(sizeof(Node));
top->R_Next->nData = 80;

top->L_Next->L_Next = (Node*)malloc(sizeof(Node));
top->L_Next->L_Next->nData = 20;
top->L_Next->R_Next = (Node*)malloc(sizeof(Node));
top->L_Next->R_Next->nData = 40;
top->R_Next->L_Next = (Node*)malloc(sizeof(Node));
top->R_Next->L_Next->nData = 70;
top->R_Next->R_Next = (Node*)malloc(sizeof(Node));
top->R_Next->R_Next->nData = 90;
//항상 초기화에 주의 하자
//메모리가
top->L_Next->L_Next->L_Next = (Node*)malloc(sizeof(Node));
top->L_Next->L_Next->L_Next->nData = 10;
top->L_Next->L_Next->L_Next->L_Next = NULL;
top->L_Next->L_Next->L_Next->R_Next = NULL;
top->L_Next->L_Next->R_Next = (Node*)malloc(sizeof(Node));
top->L_Next->L_Next->R_Next->nData = 25;
top->L_Next->L_Next->R_Next->L_Next = NULL;
top->L_Next->L_Next->R_Next->R_Next = NULL;
top->L_Next->R_Next->L_Next = (Node*)malloc(sizeof(Node));
top->L_Next->R_Next->L_Next->nData = 35;
top->L_Next->R_Next->L_Next->L_Next = NULL;
top->L_Next->R_Next->L_Next->R_Next = NULL;
top->L_Next->R_Next->R_Next = (Node*)malloc(sizeof(Node));
top->L_Next->R_Next->R_Next->nData = 45;
top->L_Next->R_Next->R_Next->L_Next = NULL;
top->L_Next->R_Next->R_Next->R_Next = NULL;
top->R_Next->L_Next->L_Next = (Node*)malloc(sizeof(Node));
top->R_Next->L_Next->L_Next->nData = 65;
top->R_Next->L_Next->L_Next->L_Next = NULL;
top->R_Next->L_Next->L_Next->R_Next = NULL;
top->R_Next->L_Next->R_Next = (Node*)malloc(sizeof(Node));
top->R_Next->L_Next->R_Next->nData = 75;
top->R_Next->L_Next->R_Next->L_Next = NULL;
top->R_Next->L_Next->R_Next->R_Next = NULL;
top->R_Next->R_Next->L_Next = (Node*)malloc(sizeof(Node));
top->R_Next->R_Next->L_Next->nData = 85;
top->R_Next->R_Next->L_Next->L_Next = NULL;
top->R_Next->R_Next->L_Next->R_Next = NULL;
top->R_Next->R_Next->R_Next = (Node*)malloc(sizeof(Node));
top->R_Next->R_Next->R_Next->nData = 95;
top->R_Next->R_Next->R_Next->L_Next = NULL;
top->R_Next->R_Next->R_Next->R_Next = NULL;
//-------------------------------------------
Node *top = Add_new_node();

top->nData = 10;

top->L_Next = (Node*)malloc(sizeof(Node));
top->L_Next->nData = 7;
top->R_Next = (Node*)malloc(sizeof(Node));
top->R_Next->nData = 20;

top->L_Next->L_Next = (Node*)malloc(sizeof(Node));
top->L_Next->L_Next->nData = 5;
top->L_Next->R_Next = (Node*)malloc(sizeof(Node));
top->L_Next->R_Next->nData = 9;
top->R_Next->L_Next = (Node*)malloc(sizeof(Node));
top->R_Next->L_Next->nData = 15;
top->R_Next->R_Next = (Node*)malloc(sizeof(Node));
top->R_Next->R_Next->nData = 25;

top->L_Next->L_Next->L_Next = (Node*)malloc(sizeof(Node));
top->L_Next->L_Next->L_Next->nData = 4;
top->L_Next->L_Next->R_Next = (Node*)malloc(sizeof(Node));
top->L_Next->L_Next->R_Next->nData = 6;
top->L_Next->R_Next->L_Next = (Node*)malloc(sizeof(Node));
top->L_Next->R_Next->L_Next->nData = 8;
top->L_Next->R_Next->R_Next = (Node*)malloc(sizeof(Node));
top->L_Next->R_Next->R_Next->nData = 10;
top->R_Next->L_Next->L_Next = (Node*)malloc(sizeof(Node));
top->R_Next->L_Next->L_Next->nData = 13;
top->R_Next->L_Next->R_Next = (Node*)malloc(sizeof(Node));
top->R_Next->L_Next->R_Next->nData = 16;
top->R_Next->R_Next->L_Next = (Node*)malloc(sizeof(Node));
top->R_Next->R_Next->L_Next->nData = 24;
top->R_Next->R_Next->R_Next = (Node*)malloc(sizeof(Node));
top->R_Next->R_Next->R_Next->nData = 30;
#endif