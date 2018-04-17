/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_put_board.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 12:49:52 by agrodzin          #+#    #+#             */
/*   Updated: 2018/04/15 13:47:26 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill.h"
#include <fcntl.h>
#include <string.h>
#define BUF_SIZE 4096

int		check_board(char **board, struct s_nums *nums, char **arr_a, int l)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	nums->check = 0;
	while (arr_a[i])
	{
		j = 0;
		while (arr_a[i][j])
		{
			if (arr_a[i][j] == '#')
			{
				nums->check++;
				if (!issafe_board(board, nums->k + i, l + j, nums))
					return (0);
			}
			if (nums->check >= 4)
				return (1);
			j++;
		}
		i++;
	}
	return (1);
}

char	**put_board(char **arr_a, char **board, struct s_nums *nums, int l)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	nums->check = 0;
	while (arr_a[i])
	{
		j = 0;
		while (arr_a[i][j])
		{
			if (arr_a[i][j] == '#')
			{
				board[nums->k + i][l + j] = nums->hash_let[nums->num_let];
				nums->check++;
				if (nums->check >= 4)
					return (board);
			}
			j++;
		}
		i++;
	}
	return (board);
}
