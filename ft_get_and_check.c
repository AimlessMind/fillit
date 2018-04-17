/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_and_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 19:11:02 by agrodzin          #+#    #+#             */
/*   Updated: 2018/04/16 20:10:12 by zbruce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill.h"
#include "libft.h"
#include <fcntl.h>
#include <string.h>
#define BUF_SIZE 4096

void	print_arr(char **brd)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (brd[i])
	{
		j = 0;
		while (brd[i][j])
		{
			ft_putchar(brd[i][j]);
			j++;
		}
		i++;
	}
	ft_putchar('\n');
}

char	*get_file(char *argv)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];
	char	*buf2;

	ft_bzero(buf, BUF_SIZE + 1);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_putstr("Error\n");
	ret = read(fd, buf, BUF_SIZE);
	buf2 = buf;
	return (buf2);
}

int		how_many_tetri(char *buf2)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (buf2[i])
	{
		if ((buf2[i] == '\n' && buf2[i + 1] == '\n') || buf2[i + 1] == '\0')
			num++;
		i++;
	}
	return (num);
}

int		check_if_valid(char *buf2, int start)
{
	int	is_valid;
	int	up;

	is_valid = 1;
	up = 1;
	while (buf2[start])
	{
		if (buf2[start] != '\n' && buf2[start - 1] != '\0')
			return (0);
		if (buf2[start] == '\n' && buf2[start + 1] != '\n')
		{
			start = start + 5;
			up++;
		}
		else
		{
			start = start + 6;
			up = 0;
		}
		if (up > 5)
			return (0);
	}
	if (up > 0 && up < 4)
		return (0);
	return (1);
}

int		check_if_valid_p3(char **arr_a, int i, int j, int check)
{
	while (arr_a[i])
	{
		j = 0;
		while (arr_a[i][j])
		{
			if (arr_a[i][j] == '#')
			{
				if (i < 3 && arr_a[i + 1][j] == '#')
					check++;
				if (i > 0 && arr_a[i - 1][j] == '#')
					check++;
				if (j < 3 && arr_a[i][j + 1] == '#')
					check++;
				if (j > 0 && arr_a[i][j - 1] == '#')
					check++;
			}
			j++;
		}
		i++;
	}
	if (check == 8 || check == 6)
		return (1);
	return (0);
}
