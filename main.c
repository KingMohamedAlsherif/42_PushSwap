#include "push_swap.h"
#include <unistd.h>

int     main(int    ac, char**  av)
{
    // t_stack_node    *a;
    // t_stack_node    *b;
    int             j;
    t_list          *list;
    t_list          *new_node;
    t_list          *tmp;
    int tmp_int;

    // a = NULL;
    // b = NULL;
    j = 1;
    if (ac == 1 || (ac == 2 && !av[1][0]))
        return (1);
    else if (ac >= 2)
    {
        while (av[j])
        {
            if (!check_max_min(av[j]))
            {
                printf("Error: %s is out of range for int.\n", av[j]);
                return EXIT_FAILURE;
            }
            if (check_syntax(av[j]))
                return (printf("INPUT ERROR"), 1);
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
        append_list(&list, new_node);
        j++;
    }
    if (!check_dup(list))
        return (printf("THere Is Duplicated Nums "), 0);
    if (!stack_sorted(list))
        return (printf("Stack is already sorted "), 0);
    print_list(list);

    // init_stack_a(&a, av[1] + 1); //still
    // if (!stack_sorted(a))
    // {
    //     if (stack_len(a) == 2)
    //         sa(&a, false); //still
    //     else if (stack_len(a) == 3)
    //         sort_three(&a);//still
    //     else
    //         sort_stacks(&a, &b);//still
    // }
    // free_stack(&a);
    return (0);
}