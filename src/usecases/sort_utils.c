/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 00:00:00 by nkojima           #+#    #+#             */
/*   Updated: 2025/11/10 00:00:00 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"
#include "../interfaces/operations/operations.h"

int	find_min_position(t_stack *a)
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

int	find_max_position(t_stack *a)
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

static void	rotate_to_top(t_stack *a, int pos)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		ra(a);
		i++;
	}
}

static void	reverse_rotate_to_top(t_stack *a, int pos)
{
	int	i;

	i = pos;
	while (i < a->size)
	{
		rra(a);
		i++;
	}
}

void	move_min_to_top(t_stack *a)
{
	int	min_pos;

	min_pos = find_min_position(a);
	if (min_pos <= a->size / 2)
		rotate_to_top(a, min_pos);
	else
		reverse_rotate_to_top(a, min_pos);
}
