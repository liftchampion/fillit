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

#ifndef FT_MATRIX_MAKER_H
# define FT_MATRIX_MAKER_H

# include "ft_tetramine_parser.h"
# include "libft.h"
# include "fillit.h"
# include "ft_stack.h"

typedef struct	s_mk_mtr_helper
{
	t_uint16	*t;
	t_uint16	row_count;
	t_uint16	col_count;
	char		**matrix;
	t_uint16	*tetras;
	t_uint16	sq_side;
}				t_mk_mtr_helper;

int				ft_fillit_get_act_char(t_uint16 c);

void			ft_print_res_matrix(t_uint16 **matrix, t_uint16 n);

t_int8			**ft_make_fillit_matrix(t_uint16 *tetras, t_uint16 tetras_count,
								t_uint16 sq_side, t_uint16 *dif_ref);

void			ft_fillit_free_matrix(int **mtr, int n);

#endif
