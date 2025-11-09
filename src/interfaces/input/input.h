/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 00:00:00 by nkojima           #+#    #+#             */
/*   Updated: 2025/11/10 00:53:48 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "../../entities/stack.h"
# include <limits.h>

/* Stacks structure */
typedef struct s_stacks
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_stacks;

/* Input parsing */
t_stacks	*parse_input(int ac, char **av);
void		free_stacks(t_stacks *stacks);

/* Tokenization */
char		**create_tokens(int ac, char **av);
void		free_tokens(char **tokens);

/* Validation */
int			is_valid_number(char *str);
int			str_to_int(const char *str, int *result);
int			has_duplicate(int *numbers, int count);
int			is_sorted(int *numbers, int count);
int			*parse_numbers(char **tokens, int *count);

#endif
