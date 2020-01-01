#include "push_swap.h"


void quicksort(int *list, int low, int high)
{
    int pivot, i, j, temp;
    if (low < high)
    {
        pivot = low;
        i = low;
        j = high;
        while (i < j)
        {
            while (list[i] <= list[pivot] && i <= high)
            {
                i++;
            }
            while (list[j] > list[pivot] && j >= low)
            {
                j--;
            }
            if (i < j)
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
        temp = list[j];
        list[j] = list[pivot];
        list[pivot] = temp;
        quicksort(list, low, j - 1);
        quicksort(list, j + 1, high);
    }
}

int     choose_median(t_stack stack)
{
    int     median;
    int     *sort_array;
    int     i;
    int     idx;

    i = 0;
    sort_array = (int *)malloc(sizeof(int) * (stack.array[0] + 1));
    while(i <= stack.array[0])
    {
        sort_array[i]  = stack.array[i];
        i++;
    }
    quicksort(sort_array, 1 ,sort_array[0]);
    //median = sort_array[0] % 2 != 0 ? sort_array[sort_array[0] / 2] : (sort_array[sort_array[0] / 2] + sort_array[sort_array[0] / 2]) / 2;
    if (sort_array[0] < 4)
        return (sort_array[sort_array[0]]);
    median = sort_array[sort_array[0] - 2];
    free(sort_array);
    return (median);
}

void    to_sort(t_stack stack_a) {
    if (stack_a.array[0] == 1)
        return ;
    else if (stack_a.array[0] == 2)
    {
        if (stack_a.array[1] > stack_a.array[2])
            command_sa(stack_a.array);
        return ;
    }
    if (stack_a.array[1] < stack_a.array[2] && stack_a.array[2] < stack_a.array[3])
        return;
    else if (stack_a.array[1] < stack_a.array[3] && stack_a.array[2] > stack_a.array[3]) {
        command_ra(stack_a.array);
        command_sa(stack_a.array);
        command_rra(stack_a.array);
    } else if (stack_a.array[1] > stack_a.array[2] && stack_a.array[1] < stack_a.array[3])
        command_sa(stack_a.array);
    else if (stack_a.array[1] < stack_a.array[2] && stack_a.array[1] > stack_a.array[3]) {
        command_ra(stack_a.array);
        command_sa(stack_a.array);
        command_rra(stack_a.array);
        command_sa(stack_a.array);
    } else if (stack_a.array[1] > stack_a.array[3] && stack_a.array[3] > stack_a.array[2]) {
        command_sa(stack_a.array);
        command_ra(stack_a.array);
        command_sa(stack_a.array);
        command_rra(stack_a.array);
    } else if (stack_a.array[1] > stack_a.array[2] && stack_a.array[2] > stack_a.array[3]) {
        command_ra(stack_a.array);
        command_sa(stack_a.array);
        command_rra(stack_a.array);
        command_sa(stack_a.array);
    }
}

int randd(t_stack stack)
{
    static int i;
    static unsigned long int next;
    next += stack.array[0] - (i % 2 ? -i : i);
    next = (next * 1103515245 / 65536 * 2768) % stack.array[0];
    i++;
    if (i == 7)
        i = 0;
    return stack.array[(int)((unsigned int)(next))];
}
