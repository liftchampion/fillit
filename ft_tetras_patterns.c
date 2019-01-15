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

t_int8		ft_fill_line(t_int16 ttr, char *row, t_int16 sq_side, t_uint16 pos)
{
	if (ttr == 18 || ttr == 3333)
		return (ttr == 18 ? STICK_H : STICK_V);
	else if (ttr == 77 || ttr == 733)
		return (ttr == 77 ? CUBE : L1);
	else if (ttr == 42 || ttr == 447)
		return (ttr == 42 ? L2 : L3);
	else if (ttr == 63 || ttr == 533)
		return (ttr == 63 ? L4 : J1);
	else if (ttr == 123 || ttr == 337)
		return (ttr == 123 ? J2 : J3);
	else if (ttr == 62 || ttr == 473)
		return (ttr == 62 ? J4 : ZR1);
	else if (ttr == 57 || ttr == 253)
		return (ttr == 57 ? ZR2 : ZL1);
	else if (ttr == 97 || ttr == 93)
		return (ttr == 97 ? ZL2 : T1);
	else if (ttr == 353 || ttr == 52)
		return (ttr == 353 ? T2 : T3);
	else if (ttr == 373 || ttr == 0)
		return (ttr == 373 ? T4 : FILLER);
	return (0);
}

void		ft_fillit_fill_res_ttr(t_int16 ttr, t_uint16 **mtr,
		t_row_col row_col, t_uint16 c)
{
	t_uint16 row;
	t_uint16 col;

	col = row_col.col;
	row = row_col.row;
	if (ttr == 18 || ttr == 3333)
		return (ttr == 18 ? STICK_H_F : STICK_V_F);
	else if (ttr == 77 || ttr == 733)
		return (ttr == 77 ? CUBE_F : L1_F);
	else if (ttr == 42 || ttr == 447)
		return (ttr == 42 ? L2_F : L3_F);
	else if (ttr == 63 || ttr == 533)
		return (ttr == 63 ? L4_F : J1_F);
	else if (ttr == 123 || ttr == 337)
		return (ttr == 123 ? J2_F : J3_F);
	else if (ttr == 62 || ttr == 473)
		return (ttr == 62 ? J4_F : ZR1_F);
	else if (ttr == 57 || ttr == 253)
		return (ttr == 57 ? ZR2_F : ZL1_F);
	else if (ttr == 97 || ttr == 93)
		return (ttr == 97 ? ZL2_F : T1_F);
	else if (ttr == 353 || ttr == 52)
		return (ttr == 353 ? T2_F : T3_F);
	else if (ttr == 373)
		return (T4_F);
}
