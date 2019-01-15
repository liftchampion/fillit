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

#ifndef FT_TETRAS_PATTERNS1_H
# define FT_TETRAS_PATTERNS1_H

# include "libft.h"

typedef struct	s_row_col
{
	t_uint16 row;
	t_uint16 col;
}				t_row_col;

# define STICK_H ft_fill_cells_stick_h(row, sq_side, pos)
# define STICK_V ft_fill_cells_stick_v(row, sq_side, pos)
# define CUBE ft_fill_cells_cube(row, sq_side, pos)
# define L1 ft_fill_cells_l1(row, sq_side, pos)
# define L2 ft_fill_cells_l2(row, sq_side, pos)
# define L3 ft_fill_cells_l3(row, sq_side, pos)
# define L4 ft_fill_cells_l4(row, sq_side, pos)
# define J1 ft_fill_cells_j1(row, sq_side, pos)
# define J2 ft_fill_cells_j2(row, sq_side, pos)
# define J3 ft_fill_cells_j3(row, sq_side, pos)
# define J4 ft_fill_cells_j4(row, sq_side, pos)
# define ZR1 ft_fill_cells_zr1(row, sq_side, pos)
# define ZR2 ft_fill_cells_zr2(row, sq_side, pos)
# define ZL1 ft_fill_cells_zl1(row, sq_side, pos)
# define ZL2 ft_fill_cells_zl2(row, sq_side, pos)
# define T1 ft_fill_cells_t1(row, sq_side, pos)
# define T2 ft_fill_cells_t2(row, sq_side, pos)
# define T3 ft_fill_cells_t3(row, sq_side, pos)
# define T4 ft_fill_cells_t4(row, sq_side, pos)
# define FILLER ft_fill_cells_filler(row, sq_side, pos)

# define STICK_H_F ft_fill_cells_stick_h_f(mtr, row, col, c)
# define STICK_V_F ft_fill_cells_stick_v_f(mtr, row, col, c)
# define CUBE_F ft_fill_cells_cube_f(mtr, row, col, c)
# define L1_F ft_fill_cells_l1_f(mtr, row, col, c)
# define L2_F ft_fill_cells_l2_f(mtr, row, col, c)
# define L3_F ft_fill_cells_l3_f(mtr, row, col, c)
# define L4_F ft_fill_cells_l4_f(mtr, row, col, c)
# define J1_F ft_fill_cells_j1_f(mtr, row, col, c)
# define J2_F ft_fill_cells_j2_f(mtr, row, col, c)
# define J3_F ft_fill_cells_j3_f(mtr, row, col, c)
# define J4_F ft_fill_cells_j4_f(mtr, row, col, c)
# define ZR1_F ft_fill_cells_zr1_f(mtr, row, col, c)
# define ZR2_F ft_fill_cells_zr2_f(mtr, row, col, c)
# define ZL1_F ft_fill_cells_zl1_f(mtr, row, col, c)
# define ZL2_F ft_fill_cells_zl2_f(mtr, row, col, c)
# define T1_F ft_fill_cells_t1_f(mtr, row, col, c)
# define T2_F ft_fill_cells_t2_f(mtr, row, col, c)
# define T3_F ft_fill_cells_t3_f(mtr, row, col, c)
# define T4_F ft_fill_cells_t4_f(mtr, row, col, c)

t_int8			ft_fill_cells_stick_v(char *row, t_int16 sq_side, t_uint16 pos);
t_int8			ft_fill_cells_stick_h(char *row, t_int16 sq_side, t_uint16 pos);
t_int8			ft_fill_cells_cube(char *row, t_int16 sq_side, t_uint16 pos);
t_int8			ft_fill_cells_l1(char *row, t_int16 sq_side, t_uint16 pos);
t_int8			ft_fill_cells_l2(char *row, t_int16 sq_side, t_uint16 pos);
t_int8			ft_fill_cells_l3(char *row, t_int16 sq_side, t_uint16 pos);
t_int8			ft_fill_cells_l4(char *row, t_int16 sq_side, t_uint16 pos);
t_int8			ft_fill_cells_j1(char *row, t_int16 sq_side, t_uint16 pos);
t_int8			ft_fill_cells_j2(char *row, t_int16 sq_side, t_uint16 pos);
t_int8			ft_fill_cells_j3(char *row, t_int16 sq_side, t_uint16 pos);
t_int8			ft_fill_cells_j4(char *row, t_int16 sq_side, t_uint16 pos);
t_int8			ft_fill_cells_zr1(char *row, t_int16 sq_side, t_uint16 pos);
t_int8			ft_fill_cells_zr2(char *row, t_int16 sq_side, t_uint16 pos);
t_int8			ft_fill_cells_zl1(char *row, t_int16 sq_side, t_uint16 pos);
t_int8			ft_fill_cells_zl2(char *row, t_int16 sq_side, t_uint16 pos);
t_int8			ft_fill_cells_t1(char *row, t_int16 sq_side, t_uint16 pos);
t_int8			ft_fill_cells_t2(char *row, t_int16 sq_side, t_uint16 pos);
t_int8			ft_fill_cells_t3(char *row, t_int16 sq_side, t_uint16 pos);
t_int8			ft_fill_cells_t4(char *row, t_int16 sq_side, t_uint16 pos);
t_int8			ft_fill_cells_filler(char *row, t_int16 sq_side, t_uint16 pos);
t_int8			ft_fill_line(t_int16 ttr, char *row, t_int16 sq_side,
			t_uint16 pos);
void			ft_fill_cells_stick_v_f(t_uint16 **mtr, t_uint16 row,
			t_uint16 col, t_uint16 c);
void			ft_fill_cells_stick_h_f(t_uint16 **mtr, t_uint16 row,
			t_uint16 col, t_uint16 c);
void			ft_fill_cells_cube_f(t_uint16 **mtr, t_uint16 row, t_uint16 col,
			t_uint16 c);
void			ft_fill_cells_l1_f(t_uint16 **mtr, t_uint16 row, t_uint16 col,
			t_uint16 c);
void			ft_fill_cells_l2_f(t_uint16 **mtr, t_uint16 row, t_uint16 col,
			t_uint16 c);
void			ft_fill_cells_l3_f(t_uint16 **mtr, t_uint16 row, t_uint16 col,
			t_uint16 c);
void			ft_fill_cells_l4_f(t_uint16 **mtr, t_uint16 row, t_uint16 col,
			t_uint16 c);
void			ft_fill_cells_j1_f(t_uint16 **mtr, t_uint16 row, t_uint16 col,
			t_uint16 c);
void			ft_fill_cells_j2_f(t_uint16 **mtr, t_uint16 row, t_uint16 col,
			t_uint16 c);
void			ft_fill_cells_j3_f(t_uint16 **mtr, t_uint16 row, t_uint16 col,
			t_uint16 c);
void			ft_fill_cells_j4_f(t_uint16 **mtr, t_uint16 row, t_uint16 col,
			t_uint16 c);
void			ft_fill_cells_zr1_f(t_uint16 **mtr, t_uint16 row, t_uint16 col,
			t_uint16 c);
void			ft_fill_cells_zr2_f(t_uint16 **mtr, t_uint16 row, t_uint16 col,
			t_uint16 c);
void			ft_fill_cells_zl1_f(t_uint16 **mtr, t_uint16 row, t_uint16 col,
			t_uint16 c);
void			ft_fill_cells_zl2_f(t_uint16 **mtr, t_uint16 row, t_uint16 col,
			t_uint16 c);
void			ft_fill_cells_t1_f(t_uint16 **mtr, t_uint16 row, t_uint16 col,
			t_uint16 c);
void			ft_fill_cells_t2_f(t_uint16 **mtr, t_uint16 row, t_uint16 col,
			t_uint16 c);
void			ft_fill_cells_t3_f(t_uint16 **mtr, t_uint16 row, t_uint16 col,
			t_uint16 c);
void			ft_fill_cells_t4_f(t_uint16 **mtr, t_uint16 row, t_uint16 col,
			t_uint16 c);
void			ft_fillit_fill_res_ttr(t_int16 ttr, t_uint16 **mtr,
			t_row_col row_col, t_uint16 c);

#endif
