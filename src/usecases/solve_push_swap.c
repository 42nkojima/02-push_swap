/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 00:00:00 by nkojima           #+#    #+#             */
/*   Updated: 2025/11/10 00:00:00 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

int	solve_push_swap(t_stacks *stacks)
{
	if (!stacks || !stacks->stack_a || !stacks->stack_b)
		return (0);
	if (stacks->stack_a->size == 2)
		sort_two(stacks->stack_a);
	else if (stacks->stack_a->size == 3)
		sort_three(stacks->stack_a);
	else if (stacks->stack_a->size == 4)
		sort_four(stacks->stack_a, stacks->stack_b);
	else if (stacks->stack_a->size == 5)
		sort_five(stacks->stack_a, stacks->stack_b);
	return (1);
}
