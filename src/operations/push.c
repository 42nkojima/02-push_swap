/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 00:00:00 by nkojima           #+#    #+#             */
/*   Updated: 2025/11/08 17:53:00 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack *dst, t_stack *src)
{
	t_node	*node;

	if (!src || !src->top)
		return ;
	node = src->top;
	src->top = src->top->next;
	src->size--;
	node->next = dst->top;
	dst->top = node;
	dst->size++;
}

void	pa(t_stack *a, t_stack *b)
{
	push(a, b);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *a, t_stack *b)
{
	push(b, a);
	ft_putstr_fd("pb\n", 1);
}