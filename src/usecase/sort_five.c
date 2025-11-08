/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 00:00:00 by nkojima           #+#    #+#             */
/*   Updated: 2025/11/08 00:00:00 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_position(t_stack *a)
{
	t_node	*current;
	int		min_value;
	int		min_pos;
	int		pos;

	current = a->top;
	min_value = current->value;
	min_pos = 0;
	pos = 0;
	while (current)
	{
		if (current->value < min_value)
		{
			min_value = current->value;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (min_pos);
}

static void	move_min_to_top(t_stack *a)
{
	int	min_pos;
	int	i;

	min_pos = find_min_position(a);
	if (min_pos <= a->size / 2)
	{
		i = 0;
		while (i < min_pos)
		{
			ra(a);
			i++;
		}
	}
	else
	{
		i = min_pos;
		while (i < a->size)
		{
			rra(a);
			i++;
		}
	}
}

void	sort_five(t_stack *a, t_stack *b)
{
	if (!a || !b || a->size != 5)
		return ;
	move_min_to_top(a);
	pb(a, b);
	move_min_to_top(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
	pa(a, b);
}
