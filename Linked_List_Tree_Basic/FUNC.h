#pragma once

#ifndef __FUNC_H__
#define __FUNC_H__
Node *Add_new_node();
void Create_node(Node* top, int item);
void Delete_node(Node* delete_node);
void Delete_node_search(Node* r_top, Node* t_top, int item);

/*PRINT_TREE*/
void Print_pre_order(Node * top);
void Print_in_order(Node * top);
void Print_post_order(Node * top);
void Print_level_order(Node *top);
int Print_level_order_dataset(Node *top, int **level_order, int idx);
int Depth_search(Node *top, int depth, int depth_max);
void Print_Tree(int *tree);
/*SIMPLE_MATH*/
double Log2(double x);
#endif
