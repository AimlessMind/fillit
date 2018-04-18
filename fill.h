/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 16:33:53 by agrodzin          #+#    #+#             */
/*   Updated: 2018/04/18 14:19:33 by zbruce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILL_H
# define FILL_H
# include <string.h>

struct	s_nums
{
	int		start;
	int		k;
	int		max;
	int		check;
	int		num_let;
	int		size;
	char	*hash_let;
	int		nums_k;
};

void	print_arr(char **brd);
char	*get_file(char *argv);
int		how_many_tetri(char	*buf2);
int		check_if_valid(char *buf2, int start);
int		check_if_valid_p3(char **arr_a, int i, int j, int check);
int		check_if_valid_p2(char *buf2);
char	**get_arr(char *buf2, size_t start);
char	**allocate_board(int size);
int		issafe_board(char **nb, int k, int l, struct s_nums *nums);
int		normalise_l_r(char **arr_a, int i);
int		normalise_u_d(char **arr_a, int i);
char	**normalise_arr(char **arr_a, int i);
int		check_board(char **board, struct s_nums *nums, char **arr_a, int l);
char	**put_board(char **arr_a, char **board, struct s_nums *nums, int l);
int		false_board(char **arr_a, char **board, struct s_nums *nums, int l);
void	alt_try_again(struct s_nums *nums);
void	try_again(char **board, struct s_nums *nums, int i, int j);
void	alt_solve(struct s_nums *nums);
int		solve(char *buf2, struct s_nums *nums, char **board, int l);
int		check_if_valid_p4(char *buf2);

#endif
