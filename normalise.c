/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 13:54:39 by agrodzin          #+#    #+#             */
/*   Updated: 2018/04/16 17:20:05 by zbruce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill.h"
#include "libft.h"
#include <fcntl.h>
#include <string.h>
#define BUF_SIZE 4096

int		normalise_l_r(char **arr_a, int i)
{
	int	nums_right;
	int	j;
	int	check;

	j = 0;
	check = 0;
	nums_right = 0;
	while (arr_a[i])
	{
		j = 0;
		while (arr_a[i][j])
		{
			if (arr_a[i][j] == '#')
			{
				if (check == 0)
					nums_right = j;
				check++;
				if (nums_right > j)
					nums_right = j;
			}
			j++;
		}
		i++;
	}
	return (nums_right);
}

int		normalise_u_d(char **arr_a, int i)
{
	int	u_d;
	int	j;
	int	check;

	u_d = 0;
	j = 0;
	check = 0;
	while (arr_a[i])
	{
		j = 0;
		while (arr_a[i][j])
		{
			if (arr_a[i][j] == '#')
			{
				if (check == 0)
					u_d = i;
				check++;
				if (u_d > i)
					u_d = i;
			}
			j++;
		}
		i++;
	}
	return (u_d);
}

char	**normalise_arr(char **arr_a, int i)
{
	int nums_right;
	int	nums_down;
	int	j;

	j = 0;
	nums_right = normalise_l_r(arr_a, 0);
	nums_down = normalise_u_d(arr_a, 0);
	while (arr_a[i])
	{
		j = 0;
		while (arr_a[i][j])
		{
			if (arr_a[i][j] == '#')
			{
				arr_a[i][j] = '.';
				j = j - nums_right;
				i = i - nums_down;
				arr_a[i][j] = '#';
			}
			j++;
		}
		i++;
	}
	return (arr_a);
}
