#include "push_swap.h"

void    sort_func(t_stack stack_a, t_stack stack_b)
{
    int median;
    int idx;
    int len;
    int rev_cnt;

    rev_cnt = 0;
    idx = 1;
    //printf_stack(stack_a.array, 'A');
    //printf_stack(stack_b.array, 'B');
    /*
     * если В не пустой запустить процесс поиска мединаы и перекинуть числа в А
     */
    if (is_ascending(stack_a.array) && stack_b.array[0] == 0)
        return ;
    else if (is_ascending(stack_a.array) && stack_b.array[0] != 0)
    {
        stack_a.sort_flag = 1;
        stack_a.len_sort = stack_a.array[0];
        from_b_to_a(stack_a, stack_b);
    }


    /*
     * Если А отсортирован конец, если нет запустить процес сортировке на данных размера: Длинна А - Длинна отсортированой части А
     * Нужно написать функици нахождения мелианны только от части массива
     * Если Длинна массива - длинна отсортированой части > 3, повторить процесс поиска медианны
     * Если <= 3 отсортировать
     * ?Если В не пустой, найти медиану и перикунуть данные в А ?
     * ПОвторить пока А не будет полностью отсортирован, а В не будет пустым
     */
    else {
        len = stack_a.array[0] - stack_a.len_sort; // DELETE
        if (stack_a.array[0] - stack_a.len_sort > 3) {
            median = choose_median(stack_a);
            //printf("Amedian %d\n", median);
            //printf("rand %d\n", randd(stack_a));
            while (idx <= len) {
                if (stack_a.array[1] < median)
                    command_pb(stack_a.array, stack_b.array);
                else {
                    rev_cnt++;
                    command_ra(stack_a.array);
                }
                idx++;
            }
            while (stack_a.sort_flag && rev_cnt--)
                command_rra(stack_a.array);
        }
        if (stack_a.array[0] - stack_a.len_sort < 4 && !is_ascending(stack_a.array)) {
            stack_a.sort_flag = 1;
            to_sort(stack_a);
            stack_a.len_sort = stack_a.array[0];
        }
        sort_func(stack_a, stack_b);
    }
}

void    from_b_to_a(t_stack stack_a, t_stack stack_b)
{
    int median;
    int idx;
    int len;
    idx = 1;

    if (stack_b.array[0] < 4)
    {
        command_pa(stack_a.array,stack_b.array);
        command_pa(stack_a.array, stack_b.array);
        command_pa(stack_a.array, stack_b.array);
    }
    median = choose_median(stack_b);
    //printf("bmedian %d\n", median);
    len = stack_b.array[0];
    while (idx <= len)
    {
        //printf_stack(stack_a.array,'A');
        if (stack_b.array[1] > median)
            command_pa(stack_a.array, stack_b.array);
        else
            command_rb(stack_b.array);
        idx++;
    }
    sort_func(stack_a, stack_b);
}
