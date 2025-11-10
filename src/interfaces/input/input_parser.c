/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 00:00:00 by nkojima           #+#    #+#             */
/*   Updated: 2025/11/10 00:53:26 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "input.h"

static t_stacks	*init_stacks(int *numbers, int count)
{
	t_stacks	*stacks;
	int			i;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		return (NULL);
	stacks->stack_a = init_stack();
	stacks->stack_b = init_stack();
	if (!stacks->stack_a || !stacks->stack_b)
	{
		free_stack(stacks->stack_a);
		free_stack(stacks->stack_b);
		free(stacks);
		return (NULL);
	}
	i = 0;
	while (i < count)
	{
		push_back(stacks->stack_a, numbers[i]);
		i++;
	}
	return (stacks);
}

static t_stacks	*process_tokens(char **tokens)
{
	int			*numbers;
	int			count;
	t_stacks	*stacks;

	numbers = parse_numbers(tokens, &count);
	if (!numbers)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	if (is_sorted(numbers, count))
	{
		free(numbers);
		return (NULL);
	}
	stacks = init_stacks(numbers, count);
	free(numbers);
	if (!stacks)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	return (stacks);
}

t_stacks	*parse_input(int ac, char **av)
{
	char		**tokens;
	t_stacks	*stacks;

	if (ac == 1)
		return (NULL);
	tokens = create_tokens(ac, av);
	if (!tokens || !tokens[0])
	{
		free_tokens(tokens);
		return (NULL);
	}
	stacks = process_tokens(tokens);
	free_tokens(tokens);
	return (stacks);
}

void	free_stacks(t_stacks *stacks)
{
	if (!stacks)
		return ;
	free_stack(stacks->stack_a);
	free_stack(stacks->stack_b);
	free(stacks);
}
