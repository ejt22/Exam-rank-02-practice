/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejoo-tho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:48:17 by ejoo-tho          #+#    #+#             */
/*   Updated: 2022/06/03 14:16:10 by ejoo-tho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;
	int	count;
	
	count = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		count = 6;
	}
	else
	{
		i = 0;
		while (s[i])
		{
			write(1, s + i, 1);
			count++;
			i++;
		}
	}
	return (count);
}

int	ft_nbrlen(long int nbr, char *base)
{
	int	count;
	int	numbase;

	if (!base)
		return (0);
	numbase = ft_strlen(base);
	count = 1;
	if (nbr <  0)
	{
		count += 1;
		nbr = -nbr;
	}
	while (nbr / numbase)
	{
		nbr = nbr / numbase;
		count++;
	}
	return (count);
}

int	ft_putnbr_base(long int nbr, char *base)
{
	int numbase;

	if (!base)
		return (0);
	numbase = ft_strlen(base);
	if (nbr >= 0 && nbr < numbase)
		ft_putchar(base[nbr]);
	else if (nbr >= numbase)
	{
		ft_putnbr_base(nbr / numbase, base);
		ft_putnbr_base(nbr % numbase, base);
	}
	else if (nbr < 0)
	{
		ft_putchar ('-');
		ft_putnbr_base(-nbr, base);
	}
	return (ft_nbrlen(nbr, base));
}

int	is_conv(char c, char *set)
{
	if (!set)
		return (0);
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

int	do_conv(va_list args, char c)
{
	int count;

	if (c == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (c == 'd')
		count = ft_putnbr_base(va_arg(args, int), "0123456789");
	else if (c == 'x')
		count = ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
	else
		count = 0;
	return (count);
}

int ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	if (!str)
		return (0);
	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && is_conv(str[i + 1], "sdx"))
		{
			count += do_conv(args, str[i + 1]);
			i += 2;
		}
		else if (str[i] == '%' && !is_conv(str[i + 1], "sdx"))
		   i++;
		else
		{
			count += ft_putchar(str[i]);
			i++;
		}	
	}
	va_end(args);
	return (count);
}

#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int n = -21;

	int u1, u2;

	u1 = ft_printf("Hello this is: %x and", n);
	printf(" %d", u1);
	printf("\n");
	u2 = printf("Hello this is: %x and", n);
	printf(" %d", u2);
	
	return (0);
}
