/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 11:12:59 by nkojima           #+#    #+#             */
/*   Updated: 2025/11/08 22:14:18 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**create_tokens(int ac, char **av)
{
	char	**tokens;
	char	*joined;
	char	*temp;
	int		i;

	joined = ft_strdup("");
	if (!joined)
		return (NULL);
	i = 1;
	while (i < ac)
	{
		temp = ft_strjoin(joined, av[i]);
		free(joined);
		if (!temp)
			return (NULL);
		joined = temp;
		if (i < ac - 1)
		{
			temp = ft_strjoin(joined, " ");
			free(joined);
			if (!temp)
				return (NULL);
			joined = temp;
		}
		i++;
	}
	tokens = ft_split(joined, ' ');
	free(joined);
	if (!tokens)
		return (NULL);
	return (tokens);
}

void	free_tokens(char **tokens)
{
	int	i;

	if (!tokens)
		return ;
	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	str_to_int(const char *str, int *result)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		num = num * 10 + (str[i] - '0');
		if (sign == 1 && num > INT_MAX)
			return (0);
		if (sign == -1 && -num < INT_MIN)
			return (0);
		i++;
	}
	*result = (int)(sign * num);
	return (1);
}

int	has_duplicate(int *numbers, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (numbers[i] == numbers[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_sorted(int *numbers, int count)
{
	int	i;

	i = 0;
	while (i < count - 1)
	{
		if (numbers[i] > numbers[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	char	**tokens;
	int		i;
	int		count;
	int		*numbers;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac == 1)
		return (0);
	tokens = create_tokens(ac, av);
	if (!tokens || !tokens[0])
	{
		free_tokens(tokens);
		return (0);
	}
	count = 0;
	while (tokens[count])
		count++;
	numbers = malloc(sizeof(int) * count);
	if (!numbers)
	{
		free_tokens(tokens);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	i = 0;
	while (tokens[i])
	{
		if (!is_valid_number(tokens[i]))
		{
			free_tokens(tokens);
			free(numbers);
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		if (!str_to_int(tokens[i], &numbers[i]))
		{
			free_tokens(tokens);
			free(numbers);
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		i++;
	}
	if (has_duplicate(numbers, count))
	{
		free_tokens(tokens);
		free(numbers);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	free_tokens(tokens);
	if (is_sorted(numbers, count))
	{
		free(numbers);
		return (0);
	}
	stack_a = init_stack();
	stack_b = init_stack();
	if (!stack_a || !stack_b)
	{
		free(numbers);
		free_stack(stack_a);
		free_stack(stack_b);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	i = 0;
	while (i < count)
	{
		push_back(stack_a, numbers[i]);
		i++;
	}
	free(numbers);
	if (stack_a->size == 2)
		sort_two(stack_a);
	else if (stack_a->size == 3)
		sort_three(stack_a);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
