#pragma once

#ifndef __FUNC_H__
#define __FUNC_H__
Node *Add_new_node(int item);
void Create_node(Node* top, int item);
void Delete_tree(Node * top, int item);

/*PRINT_TREE*/
void Print_pre_order(Node * top);
void Print_in_order(Node *top);
void Print_post_order(Node *top);
void Level_order(Node *top);

int Count_tree(Node *top);
int Terminal_count(Node *top);

int Search_depth(Node *top);
int Search_TF(Node *top, int item);
void Search_Direction(Node *top, int item);
/*SIMPLE_MATH*/
double Log2(double x);
#endif
