#include "inc/push_swap.h"

// void	ft_index_min(t_list **stack)
// {
// 	t_list		*tmp;
// 	int			distance;
// 	int			min;
	
// 	min = 2147483647;
// 	distance = 0;
// 	tmp = *stack;
// 	while (*stack)
// 	{
// 		if ((*stack)->data <= min)
// 			min = (*stack)->data;
// 		*stack = (*stack)->next;
// 	}
// 	*stack = tmp;
// 	while (*stack)
// 	{
// 		distance++;
// 		if ((*stack)->data == min)
// 		{
// 			(*stack)->index = 0;
// 			(*stack)->distance = distance;
// 			printf("(*stack_a)->distance = %d\n", (*stack)->distance);
// 		}
// 		*stack = (*stack)->next;
// 	}
// 	*stack = tmp;
// }

int	main(void)
{	
	char *str = "5 2 4 1 3";
	char **strr = ft_split(str, ' ');
	t_list	*stack_b = NULL;
	t_list	*stack_a = init_stack_a(strr);
	ft_index_stack(&stack_a, strr);
	printf("stack_a:\n");
	t_list *curr = stack_a;
	while (curr != NULL)
	{
		printf("%d\n", curr->index);
		curr = curr->next;
	}
	// printf("stack_b:\n");
	// curr = stack_b;
	// while (curr != NULL)
	// {
	// 	printf("%d\n", curr->index);
	// 	curr = curr->next;
	// }
	// get_min_pb(&stack_a, &stack_b);
	// printf("stack_a:\n");
	// curr = stack_a;
	// while (curr != NULL)
	// {
	// 	printf("%d\n", curr->index);
	// 	curr = curr->next;
	// }
	// printf("stack_b:\n");
	// curr = stack_b;
	// while (curr != NULL)
	// {
	// 	printf("%d\n", curr->index);
	// 	curr = curr->next;
	// }
}