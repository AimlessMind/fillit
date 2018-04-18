/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_try.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 15:14:35 by agrodzin          #+#    #+#             */
/*   Updated: 2018/04/18 14:16:01 by zbruce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill.h"
#include "libft.h"
#include <fcntl.h>
#include <string.h>
#define BUF_SIZE 4096
#include <stdio.h>

int		solve(char *buf2, struct s_nums *nums, char **board, int l)
{
	char	**arr_a;

	if (nums->max >= how_many_tetri(buf2))
		return (1);
	arr_a = get_arr(buf2, nums->start);
	arr_a = normalise_arr(arr_a, 0);
	nums->k = 0;
	while (nums->k <= nums->size)
	{
		l = 0;
		while (l <= nums->size)
		{
			if (check_board(board, nums, arr_a, l))
			{
				put_board(arr_a, board, nums, l);
				alt_solve(nums);
				if (solve(buf2, nums, board, l))
					return (1);
				try_again(board, nums, 0, 0);
			}
			l++;
		}
		nums->k++;
	}
	return (0);
}

void	alt_main(struct s_nums *nums)
{
	int		through_alph;
	char	alph;

	nums->k = 0;
	alph = 'A';
	through_alph = 0;
	nums->max = 0;
	nums->start = 0;
	nums->hash_let = malloc(26);
	nums->size = 2;
	nums->num_let = 0;
	nums->check = 0;
	while (alph < 'Z')
	{
		nums->hash_let[through_alph] = alph;
		alph++;
		through_alph++;
	}
}

void	alt_main_2(struct s_nums *nums)
{
	nums->max = 0;
	nums->start = 0;
	nums->num_let = 0;
	nums->nums_k = 0;
	nums->check = 0;
	nums->size++;
}

int		check_arg(int argc)
{
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit input_file\n");
		return (0);
	}
	return (1);
}

int		main(int argc, char *argv[])
{
	char			*buf2;
	char			**board;
	struct s_nums	nums;

	if (check_arg(argc) == 0)
		return (0);
	buf2 = get_file(argv[1]);
	alt_main(&nums);
	board = allocate_board(nums.size);
	if (check_if_valid(buf2, 4) == 0 || check_if_valid_p2(buf2) == 0 ||
			check_if_valid_p4(buf2) == 0)
	{
		ft_putendl("error");
		return (0);
	}
	while (!solve(buf2, &nums, &*board, 0))
	{
		if (!solve(buf2, &nums, &*board, 0))
		{
			alt_main_2(&nums);
			board = allocate_board(nums.size);
		}
	}
	print_arr(board);
	return (0);
}
