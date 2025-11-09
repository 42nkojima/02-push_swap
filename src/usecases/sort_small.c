/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 00:00:00 by nkojima           #+#    #+#             */
/*   Updated: 2025/11/10 00:00:00 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"
#include "../interfaces/operations/operations.h"

void	sort_two(t_stack *a)
{
	if (!a || a->size < 2)
		return ;
	if (a->top->value > a->top->next->value)
		sa(a);
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

void	sort_four(t_stack *a, t_stack *b)
{
	int	min_pos;

	if (!a || !b || a->size != 4)
		return ;
	min_pos = find_min_position(a);
	if (min_pos == 1)
		ra(a);
	else if (min_pos == 2)
	{
		ra(a);
		ra(a);
	}
	else if (min_pos == 3)
		rra(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
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
