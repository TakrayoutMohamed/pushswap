#include "./../Libft-42/libft.h"

int main()
{
    t_list *lst;

    int *i;
    int value;

    // i = malloc(sizeof(int *));
    value = ft_atoi("76");
    i = value;
    lst = ft_lstnew(i);
    // free(i);
    printf("%d",lst->content);
    return 0;
}