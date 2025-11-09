/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 00:00:00 by nkojima           #+#    #+#             */
/*   Updated: 2025/11/10 00:52:08 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	int		temp;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	first = stack->top;
	second = stack->top->next;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
}

void	stack_push(t_stack *dst, t_stack *src)
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

void	stack_rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	first = stack->top;
	stack->top = stack->top->next;
	last = stack->top;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	stack_reverse_rotate(t_stack *stack)
{
	t_node	*last;
	t_node	*second_last;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	last = stack->top;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = stack->top;
	stack->top = last;
}
