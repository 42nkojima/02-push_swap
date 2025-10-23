/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 11:12:59 by nkojima           #+#    #+#             */
/*   Updated: 2025/10/23 20:35:38 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**create_tokens(int ac, char **av)
{
	char **tokens;
	char	*joined;
	char *temp;
	int i;

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
	if (!temp)
		return (NULL);
	return (tokens);
}

void free_tokens(char **tokens)
{
	int i;

	if (!tokens)
		return;

	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

int is_valid_number(char *str)
{
	int i;
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

int	main(int ac, char **av)
{
	char	**tokens;
	int i;
	int count;
	int *numbers;

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
		i++;
	}

	free_tokens(tokens);
	free(numbers);
	return (0);
}
