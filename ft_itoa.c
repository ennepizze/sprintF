/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguido <nguido@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 00:57:48 by franzu            #+#    #+#             */
/*   Updated: 2021/03/25 11:01:05 by nguido           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	digit_count(long n)
{
	int count;

	count = 0;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n != 0)
	{
		n /= 10;
		++count;
	}
	return (count);
}

char		*ft_itoa(long n)
{
	char	*res;
	int		d;

	if (n == -2147483648)
		return ("-2147483648");
	if (n == 0)
		return ("0");
	d = digit_count(n);
	res = (char *)malloc(sizeof(char) * d);
	if (!res)
		return (0);
	if (n < 0)
	{
		res[0] = '-';
		n *= -1;
	}
	res[d--] = '\0';
	while (n)
	{
		res[d--] = (n % 10) + '0';
		n /= 10;
	}
	return (res);
}
