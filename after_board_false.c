/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   after_board_false.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 12:55:21 by agrodzin          #+#    #+#             */
/*   Updated: 2018/04/16 17:19:58 by zbruce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill.h"
#include "libft.h"
#include <fcntl.h>
#include <string.h>
#define BUF_SIZE 4096

int		false_board(char **arr_a, char **board, struct s_nums *nums, int l)
{
	int	i;

	i = 0;
	nums->k = 0;
	while (board[nums->k])
	{
		l = 0;
		while (board[nums->k][l])
		{
			if (!check_board(board, nums, arr_a, l))
				l++;
			else
			{
				i = 1;
				break ;
			}
		}
		if (i == 1)
			break ;
		nums->k++;
	}
	return (l);
}

void	alt_try_again(struct s_nums *nums)
{
	nums->start = nums->start - 21;
	nums->num_let = nums->num_let - 1;
	nums->max = nums->max - 1;
	nums->check = 0;
}

void	try_again(char **board, struct s_nums *nums, int i, int j)
{
	nums->check = 0;
	alt_try_again(nums);
	while (board[i])
	{
		j = 0;
		while (board[i][j])
		{
			if (board[i][j] == nums->hash_let[nums->num_let])
			{
				board[i][j] = '.';
				nums->check++;
				if (nums->check == 1)
					nums->k = i;
				if (nums->check >= 4)
					break ;
			}
			j++;
		}
		if (nums->check >= 4)
			break ;
		i++;
	}
}

void	alt_solve(struct s_nums *nums)
{
	nums->num_let++;
	nums->max++;
	nums->start = nums->start + 21;
}
