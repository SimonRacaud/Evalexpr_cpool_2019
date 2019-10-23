/*
** EPITECH PROJECT, 2019
** CPool_evalexpr_2019
** File description:
** Combine a row of +/- symbols in one
*/

static void replace_symbols(char *ptr, int nb_symb, char symb) {
    int i = 0;

    for (int i = 1; i < nb_symbol; i++)
        *(ptr - i) = '.';
    *(ptr - nb_symbol) = symb;
}

static void check_char(char *ptr, int *count_neg, int *count_symb) {
    if (*ptr == '+' || *ptr == '-') {
        if (*ptr == '-')
            (*count_neg)++;
        (*count_symb)++;
    } else if (*count_symb != 0) {
        if (*count_neg % 2 == 0) {
            replace_symbols(ptr, *count_symb, '+');
        } else {
            replace_symbols(ptr, *count_symb, '-');
        }
        *count_neg = 0;
        *count_symb = 0;
    }
}

void combine_operators(char *expr)
{
    int count_neg = 0;
    int count_symb = 0;
    int i = 0;

    while (expr[i] != '\0') {
        check_char(&expr[i], &count_neg, &count_symb);
        i++;
    }
}
