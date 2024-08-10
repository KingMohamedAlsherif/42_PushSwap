#include "push_swap.h"
#include <unistd.h>

int     main(int    ac, char**  av)
{
    t_stack_node          *a;
    t_stack_node          *b;
    int                    j;
    t_stack_node          *list;
    t_stack_node          *new_node;
    int count;

    a = NULL;
    b = NULL;
    count = 0;
    j = 1;
    if (ac == 1 || (ac == 2 && !av[1][0]))
        return (1);
    else if (ac >= 2)
    {
        while (av[j])
        {
            if (!check_max_min(av[j]))
                return (printf("Error: %s is out of range for int.\n", av[j]), 1);
            if (check_syntax(av[j]))
                return (1);
            j++;
        }
    }
    j = 1;
    while (j < ac)
    {
        new_node = split(av[j]);
        // printf("ac = %d\n", ac);
        if (!new_node)
            // free_list(list); // TO DO
            return (printf("malloc Error in New Node"), 0);
        append_list(&a, new_node);
        j++;
    }
    if (!check_dup(a))
        return (printf("There Is Duplicated Nums "), 0);
    if (stack_sorted(a))
        return (printf("Stack is already sorted "), 0);
    
    // print_list(a);
    indexing(a);
    // print_list(a);
    // while (a)
    //     pb(&b , &a, false);
    // printf("List b :");
    // print_list(b);
    // printf("List a :");
    // print_list(a);
    // while (b)
    //     pa(&a , &b, false);
    // printf("List b :");
    // print_list(b);
    // printf("List a :");
    // print_list(a);
    // ra(&a, false);
    // print_list(a);
    if (!stack_sorted(a))
    {
        count = count_list(a);
        // printf("count :%d\n", count);
        if (count == 2)
            sa(&a, false);
        else if (count == 3)
        {
            // printf("It's == 3\n");
            sort_three(&a);
        }
        else if (count_list(a) == 4 || count_list(a) == 5)
            sort_four_or_five(&a, &b);
        else
        {
            radix_sorting(&a, &b);
            // printf("mian\n");
            // print_list(a);
            // printf("\n");
            //print_list(b);
        }
    }
    // print_list(a);
    // pb(&b, &a, false);
    // pb(&b, &a, false);
    // printf("Stack B: ");
    // print_list(b);
    // pa(&a, &b, false);
    // pa(&a, &b, false);
    // printf("Stack A: ");
    // print_list(a);
    // printf("Stack B: ");
    // print_list(b);
    // rra(&a, false);
    // if (stack_sorted(a))
    // {
    //     printf("Alhamdullah We Did It");
    // }
    // free_stack(&a);
    // free_stack(&b);
    return (0);
}