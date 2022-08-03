/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 08:49:27 by mraymond          #+#    #+#             */
/*   Updated: 2022/04/29 14:06:34 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	writehex(long unsigned int nbr, char capitalx, int *i, int turn1)
{
	char	c;

	if (turn1 == 1 && capitalx == 'p')
	{
		write(1, "0x", 2);
		i[LEN] += 2;
	}
	if (capitalx == 'p')
		capitalx = 'x';
	if (turn1 == 1 && nbr == 0)
	{
		write(1, "0", 1);
		i[LEN] += 1;
	}
	if (nbr != 0)
	{
		writehex(nbr / 16, capitalx, i, 0);
		if (nbr % 16 < 10)
			c = nbr % 16 + '0';
		else
			c = nbr % 16 + (capitalx - 33);
		write(1, &c, 1);
		i[LEN] += 1;
	}
}

void	ft_hexnumber(char letter, va_list ap, int *i)
{
	long unsigned	hexnumber;

	if (letter == 'x' || letter == 'X')
		hexnumber = va_arg(ap, unsigned);
	else
		hexnumber = va_arg(ap, long unsigned);
	writehex(hexnumber, letter, i, 1);
}

//definelen = 1 if is a char else str
int	write_n_count(const char *str, int definelen)
{
	int	len;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	if (definelen == 1)
		len = 1;
	else
		len = ft_strlen(str);
	if (len > 0)
		write(1, str, len);
	return (len);
}

//cspdiuxX%
void	arg_add(char letter, va_list ap, int *i)
{
	char	c;
	char	*str;

	if (letter == 'c')
	{
		c = va_arg(ap, int);
		i[LEN] += write_n_count(&c, 1);
	}
	if (letter == 's')
		i[LEN] += write_n_count(va_arg(ap, char *), 0);
	else if (letter == 'd' || letter == 'i' || letter == 'u')
	{
		if (letter == 'u')
			str = ft_ltoa((long int)va_arg(ap, unsigned int));
		else
			str = ft_ltoa((long int)va_arg(ap, int));
		i[LEN] += write_n_count(str, 0);
		free(str);
	}
	else if (letter == 'x' || letter == 'X' || letter == 'p')
		ft_hexnumber(letter, ap, i);
	else if (letter == '%')
		i[LEN] += write_n_count(&letter, 1);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i[2];

	va_start(ap, format);
	i[INDEX] = -1;
	i[LEN] = 0;
	while (format[++i[INDEX]] != '\0')
	{
		if (format[i[INDEX]] == '%')
			arg_add(format[++i[INDEX]], ap, i);
		else
			i[LEN] += write_n_count(&format[i[INDEX]], 1);
	}
	va_end(ap);
	return (i[LEN]);
}
