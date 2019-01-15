/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapka.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:25:22 by ggerardy          #+#    #+#             */
/*   Updated: 2018/11/29 16:09:36 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_tetras_patterns1.h"

t_int8		ft_fill_cells_stick_v(char *row, t_int16 sq_side, t_uint16 pos)
{
	t_uint16 row_num;

	row_num = pos / sq_side;
	if (row_num < sq_side - 3)
	{
		row[pos] = 1;
		row[pos + sq_side] = 1;
		row[pos + sq_side + sq_side] = 1;
		row[pos + sq_side + sq_side + sq_side] = 1;
		return (1);
	}
	return (0);
}

t_int8		ft_fill_cells_stick_h(char *row, t_int16 sq_side, t_uint16 pos)
{
	t_uint16 col_num;

	col_num = pos % sq_side;
	if (col_num < sq_side - 3)
	{
		row[pos] = 1;
		row[pos + 1] = 1;
		row[pos + 1 + 1] = 1;
		row[pos + 1 + 1 + 1] = 1;
		return (1);
	}
	return (0);
}

t_int8		ft_fill_cells_cube(char *row, t_int16 sq_side, t_uint16 pos)
{
	t_uint16 col_num;
	t_uint16 row_num;

	col_num = pos % sq_side;
	row_num = pos / sq_side;
	if (row_num < sq_side - 1 && col_num < sq_side - 1)
	{
		row[pos] = 1;
		row[pos + 1] = 1;
		row[pos + sq_side] = 1;
		row[pos + sq_side + 1] = 1;
		return (1);
	}
	return (0);
}

t_int8		ft_fill_cells_l1(char *row, t_int16 sq_side, t_uint16 pos)
{
	t_uint16 row_num;
	t_uint16 col_num;

	col_num = pos % sq_side;
	row_num = pos / sq_side;
	if (row_num < sq_side - 2 && col_num < sq_side - 1)
	{
		row[pos] = 1;
		row[pos + sq_side] = 1;
		row[pos + sq_side + sq_side] = 1;
		row[pos + sq_side + sq_side + 1] = 1;
		return (1);
	}
	return (0);
}

t_int8		ft_fill_cells_l2(char *row, t_int16 sq_side, t_uint16 pos)
{
	t_uint16 row_num;
	t_uint16 col_num;

	col_num = pos % sq_side;
	row_num = pos / sq_side;
	if (row_num < sq_side - 1 && col_num < sq_side - 2)
	{
		row[pos] = 1;
		row[pos + 1] = 1;
		row[pos + 2] = 1;
		row[pos + sq_side] = 1;
		return (1);
	}
	return (0);
}
