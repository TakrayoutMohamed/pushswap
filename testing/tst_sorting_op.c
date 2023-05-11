#include "./../operations/liboperation.h"
#include "./../Libft-42/libft.h"
#include "./../libpushswap.h"

static void	fill_indexes_of_a(t_list **a)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *a;
	if (ft_lstsize(*a) > 0)
	{
		while (tmp != NULL)
		{
			tmp->index = i++;
			tmp = tmp->next;
		}
	}
}

void	print_lst(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (lst != NULL)
	{
		// write(1 ," here1 ",7);
		printf("**v=%d, i=%d, p=%d** -> ",lst->content,lst->index,lst->position);
		// write(1 ," here ",7);
		lst = lst->next;
	}
	lst = tmp;
	printf("\n");
}

// static void del(int content)
// {
// 	content = 0;
// 	(void)content;
// }

int main()
{
	t_list  *a;
	t_list  *b;
	char **matrix = ft_split("45 56 67 89 90 456 34 58", ' ');
	a = matrix_to_lst(matrix);
	// b = malloc(sizeof(t_list));
	b = NULL;
	free_matrix(matrix);
	fill_positions_of_a(&a);
	fill_indexes_of_a(&a);
	print_lst(a);
	printf("*****************the test starts***********\n");
	printf("***************** pb ***********\n");
		pb(&b, &a);
		printf("list a :");
		print_lst(a);
		printf("list b :");
		print_lst(b);
	printf("***************** pb ***********\n");
		pb(&b, &a);
		printf("list a :");
		print_lst(a);
		printf("list b :");
		print_lst(b);
	printf("***************** pb ***********\n");
		pb(&b, &a);
		printf("list a :");
		print_lst(a);
		printf("list b :");
		print_lst(b);
	// printf("***************** pa ***********\n");
	// 	pa(&a, &b);
	// 	printf("list a :");
	// 	print_lst(a);
	// 	printf("list b :");
	// 	print_lst(b);
	printf("***************** sa ***********\n");
		sa(&a);
		printf("list a :");
		print_lst(a);
	printf("***************** sb ***********\n");
		sb(&b);
		printf("list b :");
		print_lst(b);
	printf("***************** ss ***********\n");
		ss(&a, &b);
		printf("list a :");
		print_lst(a);
		printf("list b :");
		print_lst(b);
	printf("***************** ra ***********\n");
		ra(&a);
		printf("list a :");
		print_lst(a);
	printf("***************** rb ***********\n");
		rb(&b);
		printf("list b :");
		print_lst(b);
	printf("***************** rr ***********\n");
		rr(&a, &b);
		printf("list a :");
		print_lst(a);
		printf("list b :");
		print_lst(b);
	printf("***************** rra ***********\n");
		rra(&a);
		printf("list a :");
		print_lst(a);
	printf("***************** rrb ***********\n");
		rrb(&b);
		printf("list b :");
		print_lst(b);
	printf("***************** rrr ***********\n");
		rrr(&a, &b);
		printf("list a :");
		print_lst(a);
		printf("list b :");
		print_lst(b);
	// ft_lstclear(&a, del);
	ft_lstclear(&b, del);
	return (0);
}

//to run the tests use the command :
// gcc tst_sorting_op.c ./../pushswap_utils.c ./../operations/*.c  ./../sorting_algo/sorting_utils/*.c ./../Libft-42/libft.a 
// but first you need to go to tests directory