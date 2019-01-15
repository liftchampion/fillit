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

void		ft_fill_cells_t1_f(t_uint16 **mtr, t_uint16 row, t_uint16 col,
												t_uint16 c)
{
	mtr[row][col + 1] = c;
	mtr[row + 1][col] = c;
	mtr[row + 1][col + 1] = c;
	mtr[row + 1][col + 2] = c;
}

void		ft_fill_cells_t2_f(t_uint16 **mtr, t_uint16 row, t_uint16 col,
												t_uint16 c)
{
	mtr[row][col + 1] = c;
	mtr[row + 1][col] = c;
	mtr[row + 1][col + 1] = c;
	mtr[row + 2][col + 1] = c;
}

void		ft_fill_cells_t3_f(t_uint16 **mtr, t_uint16 row, t_uint16 col,
													t_uint16 c)
{
	mtr[row][col] = c;
	mtr[row][col + 1] = c;
	mtr[row][col + 2] = c;
	mtr[row + 1][col + 1] = c;
}

void		ft_fill_cells_t4_f(t_uint16 **mtr, t_uint16 row, t_uint16 col,
											t_uint16 c)
{
	mtr[row][col] = c;
	mtr[row + 1][col] = c;
	mtr[row + 1][col + 1] = c;
	mtr[row + 2][col] = c;
}
