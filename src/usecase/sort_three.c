/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 00:00:00 by nkojima           #+#    #+#             */
/*   Updated: 2025/11/08 00:00:00 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max_position(t_stack *a)
{
	t_node	*current;
	int		max_value;
	int		max_pos;
	int		pos;

	current = a->top;
	max_value = current->value;
	max_pos = 0;
	pos = 0;
	while (current)
	{
		if (current->value > max_value)
		{
			max_value = current->value;
			max_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (max_pos);
}

void	sort_three(t_stack *a)
{
	int	max_pos;

	if (!a || a->size != 3)
		return ;
	max_pos = find_max_position(a);
	if (max_pos == 0)
		ra(a);
	else if (max_pos == 1)
		rra(a);
	if (a->top->value > a->top->next->value)
		sa(a);
}