/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_tokenizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 00:00:00 by nkojima           #+#    #+#             */
/*   Updated: 2025/11/10 00:53:30 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "input.h"

static char	*join_with_space(char *s1, char *s2, int add_space)
{
	char	*temp;
	char	*result;

	if (add_space)
	{
		temp = ft_strjoin(s1, " ");
		if (!temp)
			return (NULL);
		result = ft_strjoin(temp, s2);
		free(temp);
	}
	else
		result = ft_strjoin(s1, s2);
	return (result);
}

static char	*join_arguments(int ac, char **av)
{
	char	*joined;
	char	*temp;
	int		i;

	joined = ft_strdup("");
	if (!joined)
		return (NULL);
	i = 1;
	while (i < ac)
	{
		temp = join_with_space(joined, av[i], i > 1);
		free(joined);
		if (!temp)
			return (NULL);
		joined = temp;
		i++;
	}
	return (joined);
}

char	**create_tokens(int ac, char **av)
{
	char	**tokens;
	char	*joined;

	joined = join_arguments(ac, av);
	if (!joined)
		return (NULL);
	tokens = ft_split(joined, ' ');
	free(joined);
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
