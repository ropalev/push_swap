int     min_max(int *stack_a, int *stack_b)
{
    if (stack_b[1] > stack_a[stack_a[1] - 1] || stack_b[1] < stack_a[1])
        return 1;
    return 0;
}

int     find_max_idx(int *stack)
{
    int     max;
    int     i;
    int     idx;

    idx = 1;
    i = 0;
    max = stack[1];
    while (i < stack[0])
    {
        if (stack[i] > max)
        {
            max = stack[i];
            idx = i;
        }
        i++;
    }
    return idx;
}