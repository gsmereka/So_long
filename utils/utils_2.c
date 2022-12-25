/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 21:34:43 by gsmereka          #+#    #+#             */
/*   Updated: 2022/12/25 04:04:41 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

static int	ft_calculate_size(int n);
static void	ft_print_n(int size, int n, int fd);

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	size;

	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	if (n < 0 && n != -2147483648)
	{
		n *= -1;
		ft_putchar_fd('-', fd);
	}
	if (n == 0)
		ft_putchar_fd('0', fd);
	else
	{
		size = ft_calculate_size(n);
		ft_print_n(size, n, fd);
	}
}

static int	ft_calculate_size(int n)
{
	int	size;

	size = 0;
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static void	ft_print_n(int size, int n, int fd)
{
	int	temp_n;
	int	i;

	while (size > 0)
	{
		i = size - 1;
		temp_n = n;
		while (i > 0)
		{
			temp_n = temp_n / 10;
			i--;
		}
		temp_n = (temp_n % 10) + '0';
		ft_putchar_fd(temp_n, fd);
		size--;
	}
}
