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
    int     cost;
    bool    above_med;
    bool    cheap;
    struct s_stack_node *target;
    struct s_stack_node *next;
    struct s_stack_node *prev;
}       t_stack_node;

typedef struct s_list
{
    int            n;
    struct s_list *next;
    struct s_list *prev;
} t_list;

int check_syntax(char *num);
int check_dup(t_list *a);
void free_stack(t_stack_node **stack);
void free_errors(t_stack_node **stack);
void append_list(t_list **list, t_list *new_node);
t_list *split(char *num);
t_list *find_last(t_list *list);
void print_list(t_list *list);
t_list *creat_node(char *str);
int check_max_min(char *av);
int check_list(t_list *list);
int ft_atoi(const char *str);
int stack_sorted(t_list *stack);
#endif
