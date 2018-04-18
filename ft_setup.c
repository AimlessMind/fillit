/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 13:44:07 by agrodzin          #+#    #+#             */
/*   Updated: 2018/04/18 14:42:16 by zbruce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill.h"
#include "libft.h"
#include <fcntl.h>
#include <string.h>
#define BUF_SIZE 4096

int		check_if_valid_p2(char *buf2)
{
	int		i;
	int		j;
	int		pos;
	char	**arr_a;

	i = 0;
	j = 0;
	pos = 0;
	while (i < how_many_tetri(buf2))
	{
		arr_a = get_arr(buf2, pos);
		j = 0;
		while (j <= 19)
		{
			if (buf2[j] == '#' && buf2[j - 1] != '#' && buf2[j + 1] != '#' &&
				buf2[j + 5] != '#' && buf2[j - 5] != '#')
				return (0);
			j++;
		}
		if (!check_if_valid_p3(arr_a, 0, 0, 0))
			return (0);
		pos = pos + 21;
		i++;
	}
	return (1);
}

char	**get_arr(char *buf2, size_t start)
{
	char	**arr_b;
	int		up_pos;
	int		side_pos;

	up_pos = 0;
	side_pos = 0;
	arr_b = malloc(5 * sizeof(char*));
	arr_b[4] = NULL;
	while (up_pos < 4)
	{
		arr_b[up_pos] = malloc(6 * sizeof(char));
		side_pos = 0;
		while (side_pos < 4)
		{
			arr_b[up_pos][side_pos] = buf2[start];
			side_pos++;
			start++;
		}
		arr_b[up_pos][4] = '\n';
		arr_b[up_pos][5] = '\0';
		up_pos++;
		start++;
	}
	return (arr_b);
}

char	**allocate_board(int size)
{
	char	**board;
	int		i;
	int		j;

	i = 0;
	j = 0;
	board = (char**)malloc(size * size + size);
	board[i] = (char*)malloc(size + 1);
	while (i < size)
	{
		j = 0;
		board[i] = (char*)malloc(size + 1);
		while (j < size)
		{
			board[i][j] = '.';
			j++;
		}
		board[i][j] = '\n';
		board[i][j + 1] = '\0';
		i++;
	}
	board[i] = NULL;
	return (board);
}

int		issafe_board(char **nb, int k, int l, struct s_nums *nums)
{
	int	i;

	i = 0;
	if (k >= nums->size)
	{
		return (0);
	}
	if (l >= nums->size && k < nums->size)
	{
		return (0);
	}
	if (nb[k][l] == '\n')
		return (0);
	while (nums->hash_let[i])
	{
		if (nb[k][l] == nums->hash_let[i])
			return (0);
		i++;
	}
	return (1);
}

int		check_if_valid_p4(char *buf2)
{
	if (how_many_tetri(buf2) > 26)
		return (0);
	return (1);
}
