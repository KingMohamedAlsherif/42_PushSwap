#ifndef PUSH_SWAP_H
#   define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
// #include "Libft/libft.h"
#include <stdbool.h>
#include <limits.h>
#include "ft_printf/ft_printf.h"
#include <unistd.h>
#include <string.h>

typedef struct s_stack_node
{
    int     num;
    int     i;
    struct s_stack_node *next;
    struct s_stack_node *prev;
}       t_stack_node;

int check_syntax(char *num);
int check_dup(t_stack_node *a);
void free_stack(t_stack_node **stack);
void free_errors(t_stack_node **stack);
void append_list(t_stack_node **list, t_stack_node *new_node);
t_stack_node *split(char *num);
t_stack_node *find_last(t_stack_node *list);
void print_list(t_stack_node *list);
t_stack_node *creat_node(char *str);
int check_max_min(char *av);
int check_list(t_stack_node *list);
long ft_atol(const char *str);
bool stack_sorted(t_stack_node *stack);
void sa(t_stack_node **a, bool print);
void sb(t_stack_node **b, bool print);
void ss(t_stack_node **a, t_stack_node **b, bool print);
void ra(t_stack_node **a, bool print);
void rb(t_stack_node **b, bool print);
void rr(t_stack_node **a, t_stack_node **b, bool print);
void rra(t_stack_node **a, bool print);
void rrb(t_stack_node **b, bool print);
void rrr(t_stack_node **a, t_stack_node **b, bool print);

#endif