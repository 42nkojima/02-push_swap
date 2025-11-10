/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 01:02:12 by nkojima           #+#    #+#             */
/*   Updated: 2025/11/10 01:22:59 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	str_len;
	char	*ptr;

	str_len = ft_strlen(str);
	ptr = malloc(str_len + 1);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, str, str_len + 1);
	return (ptr);
}
