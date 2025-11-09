/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkojima <nkojima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 01:00:47 by nkojima           #+#    #+#             */
/*   Updated: 2025/11/10 01:00:52 by nkojima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	put_unbr_fd(unsigned int uint_num, int fd)
{
	if (uint_num >= 10)
		put_unbr_fd(uint_num / 10, fd);
	ft_putchar_fd((uint_num % 10) + '0', fd);
}

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	uint_num;

	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		uint_num = (unsigned int)-nb;
	}
	else
		uint_num = (unsigned int)nb;
	put_unbr_fd(uint_num, fd);
}
