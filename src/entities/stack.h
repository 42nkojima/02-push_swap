/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 00:00:00 by nkojima           #+#    #+#             */
/*   Updated: 2025/11/10 01:24:35 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stddef.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

/* Stack basic operations */
t_stack	*init_stack(void);
void	push_back(t_stack *stack, int value);
void	free_stack(t_stack *stack);

/* Stack operations (pure functions) */
void	stack_swap(t_stack *stack);
void	stack_push(t_stack *dst, t_stack *src);
void	stack_rotate(t_stack *stack);
void	stack_reverse_rotate(t_stack *stack);

#endif
