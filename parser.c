#include "push_swap.h"
/*
int parser(int argc, char **argv)
{
    char    **args;
    // функция проверки аргументов выдает exit если все плохо, если все хорошо ничего либо возращает строку аргументов
    if (argc == 1)
        exit(0);
    if (argc == 2)
    {
        args = ft_strsplit(argv,' ');
        if (!args[1])

        else

        // Проверить длину второго аргумента, если больше 1 распоковатьего
        // если длина больше 1-го и argc > 3 exit()
        // если все ок return (1)
    }
    //
    

}
*/

t_stack    parse_arg(int argc, char **argv)
{
    char    **args;
    int     i;

    args = ft_strsplit(argv,' ');
    while (i < argc)
        printf("%s", argc[i++]);
}

void     parser(int argc, char **argv)
{

    if (argc == 0) {
        printf("Слишком мало аргументво");
        return;
    }
    if (argc == 1) {
        if (ft_str_is_numeric(argv[0])) {
            printf("%s", "Это число");
        parse_arg(int argc, char **argv);
        }
        else
        {
            parse_str();
        }
            printf("%s %d", "Это строка длины:", ft_strlen(argv[0]));
    }
}