/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_number_parser.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 00:00:00 by nkojima           #+#    #+#             */
/*   Updated: 2025/11/10 00:52:50 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

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

static int	validate_and_convert(char **tokens, int *numbers, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (!is_valid_number(tokens[i]))
			return (0);
		if (!str_to_int(tokens[i], &numbers[i]))
			return (0);
		i++;
	}
	return (1);
}

int	*parse_numbers(char **tokens, int *count)
{
	int	*numbers;

	*count = 0;
	while (tokens[*count])
		(*count)++;
	numbers = malloc(sizeof(int) * (*count));
	if (!numbers)
		return (NULL);
	if (!validate_and_convert(tokens, numbers, *count))
	{
		free(numbers);
		return (NULL);
	}
	if (has_duplicate(numbers, *count))
	{
		free(numbers);
		return (NULL);
	}
	return (numbers);
}
