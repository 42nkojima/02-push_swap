/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 00:00:00 by nkojima           #+#    #+#             */
/*   Updated: 2025/11/10 00:36:13 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities/stack.h"
#include "libft.h"

void	print_stack(t_stack *stack, char *name)
{
	t_node	*current;

	ft_putstr_fd("\n=== ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(" ===\n", 2);
	if (!stack || stack->size == 0)
	{
		ft_putstr_fd("(empty)\n", 2);
		return ;
	}
	current = stack->top;
	while (current)
	{
		ft_putnbr_fd(current->value, 2);
		ft_putstr_fd(" ", 2);
		current = current->next;
	}
	ft_putstr_fd("\n---\n", 2);
}

void	print_both_stacks(t_stack *stack_a, t_stack *stack_b)
{
	print_stack(stack_a, "Stack A");
	print_stack(stack_b, "Stack B");
}
