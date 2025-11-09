/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 02:32:00 by nkojima           #+#    #+#             */
/*   Updated: 2025/11/10 03:20:26 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../interfaces/operations/operations.h"
#include "solver.h"

static void	normalize_to_ranks(t_stack *a)
{
	t_node	*current;
	t_node	*compare;
	int		rank;

	current = a->top;
	while (current)
	{
		rank = 0;
		compare = a->top;
		while (compare)
		{
			if (compare->value < current->value)
				rank++;
			compare = compare->next;
		}
		current->rank = rank;
		current = current->next;
	}
}

static int	get_max_bits(t_stack *a)
{
	int	max_rank;
	int	bits;

	max_rank = a->size - 1;
	bits = 0;
	while ((1 << bits) <= max_rank)
		bits++;
	return (bits);
}

static int	get_bit(int value, int bit_pos)
{
	return ((value >> bit_pos) & 1);
}

void	sort_radix(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	bit;
	int	size;
	int	i;

	normalize_to_ranks(a);
	max_bits = get_max_bits(a);
	bit = 0;
	while (bit < max_bits)
	{
		size = a->size;
		i = 0;
		while (i < size)
		{
			if (get_bit(a->top->rank, bit) == 0)
				pb(a, b);
			else
				ra(a);
			i++;
		}
		while (b->size > 0)
			pa(a, b);
		bit++;
	}
}
