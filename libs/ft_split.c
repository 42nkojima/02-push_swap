/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 00:59:19 by nkojima           #+#    #+#             */
/*   Updated: 2025/11/10 00:59:31 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *str, char delim)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != delim && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*str == delim)
			in_word = 0;
		str++;
	}
	return (count);
}

static void	free_split(char **array, size_t filled)
{
	size_t	i;

	i = 0;
	while (i < filled)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static char	*word_dup(char const *start, size_t len)
{
	char	*word;

	word = malloc(len + 1);
	if (!word)
		return (NULL);
	ft_memcpy(word, start, len);
	word[len] = '\0';
	return (word);
}

static int	populate_result(char **result, const char *str, char delim)
{
	size_t		i;
	const char	*start;

	i = 0;
	while (*str)
	{
		if (*str != delim)
		{
			start = str;
			while (*str && *str != delim)
				str++;
			result[i] = word_dup(start, str - start);
			if (!result[i])
			{
				free_split(result, i);
				return (0);
			}
			i++;
			continue ;
		}
		str++;
	}
	result[i] = NULL;
	return (1);
}

char	**ft_split(char const *str, char delim)
{
	char	**result;
	size_t	words;

	words = word_count(str, delim);
	result = malloc(sizeof(*result) * (words + 1));
	if (!result)
		return (NULL);
	if (!populate_result(result, str, delim))
		return (NULL);
	return (result);
}
