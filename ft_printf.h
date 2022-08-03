/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 12:33:52 by mraymond          #+#    #+#             */
/*   Updated: 2022/04/29 10:47:07 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

enum	e_index
{
	LEN,
	INDEX
};

void	*ft_calloc(size_t count, size_t size);
int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *s);
char	*ft_ltoa(long long int n);
void	ft_bzero(void *s, size_t n);

#endif