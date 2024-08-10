#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
// #include "Libft/libft.h"
#include <stdbool.h>
#include <limits.h>
// #include "ft_printf/ft_printf.h"
#include <unistd.h>
#include <string.h>

typedef struct s_stack_node
{
    // int *a;
    // int *b;
    int num;
    int inx;
    int a_size;
    int b_size;
    struct s_stack_node *next;
    struct s_stack_node *prev;
} t_stack_node;

int check_syntax(char *num);
int check_dup(t_stack_node *a);
void free_stack(t_stack_node **stack);
int    free_errors(t_stack_node    *a, t_stack_node    *b);
void append_list(t_stack_node **list, t_stack_node *new_node);
t_stack_node *split(char *num);
t_stack_node *find_last(t_stack_node *list);
void print_list(t_stack_node *list);
t_stack_node *creat_node(char *str);
int check_max_min(char *av);
int check_list(t_stack_node *list);
long ft_atol(const char *str);
int  stack_sorted(t_stack_node *stack);
void sa(t_stack_node **a, bool print);
void sb(t_stack_node **b, bool print);
void ss(t_stack_node **a, t_stack_node **b, bool print);
void rotate(t_stack_node **stack);
void ra(t_stack_node **a, bool print);
void rb(t_stack_node **b, bool print);
void rev_rotate(t_stack_node **stack);
void rr(t_stack_node **a, t_stack_node **b, bool print);
void rra(t_stack_node **a, bool print);
void rrb(t_stack_node **b, bool print);
void rrr(t_stack_node **a, t_stack_node **b, bool print);
int count_list(t_stack_node *stack);
void indexing(t_stack_node *stack);
t_stack_node *find_max(t_stack_node *stack);
void radix_sorting(t_stack_node **a, t_stack_node **b);
void radix_sort_stack_b(t_stack_node **b, t_stack_node **a, int bit_size, int j);
void sort_three(t_stack_node **a);
void push(t_stack_node **dest, t_stack_node **src);
void pa(t_stack_node **a, t_stack_node **b, bool print);
void pb(t_stack_node **b, t_stack_node **a, bool print);
void    sort_four_or_five(t_stack_node  **a, t_stack_node   **b);
int    print_error(void);
#endif