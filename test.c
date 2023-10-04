#include "inc/push_swap.h"

int	main(void)
{
	char *str = "1 2 3 4 5 6";
	char **strr = ft_split(str, ' ');
	t_list	*stack_a;

	t_list *curr = make_stack_b(stack_a, strr);;
	while (curr != NULL)
	{
		printf("%d\n", curr->content);
		curr = curr->next;
	}
}