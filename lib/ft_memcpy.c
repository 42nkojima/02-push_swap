/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 01:00:15 by nkojima           #+#    #+#             */
/*   Updated: 2025/11/10 01:22:54 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t cpy_size)
{
	unsigned char		*dst_ptr;
	const unsigned char	*src_ptr;

	if (cpy_size == 0 || dst == src)
		return (dst);
	dst_ptr = (unsigned char *)dst;
	src_ptr = (const unsigned char *)src;
	while (cpy_size--)
		*dst_ptr++ = *src_ptr++;
	return (dst);
}
