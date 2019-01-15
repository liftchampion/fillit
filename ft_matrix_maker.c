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

#include "ft_matrix_maker.h"
#include <stdlib.h>
#include "ft_tetramine_parser.h"
#include "libft.h"
#include "fillit.h"
#include "ft_stack.h"
#include "ft_tetras_patterns1.h"

void				ft_fillit_free_matrix(int **mtr, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		free(mtr[i]);
		i++;
	}
	free(mtr);
}

t_mk_mtr_helper		*ft_make_fillit_matrix_preparations(t_uint16 *tetras,
		t_uint16 tetras_count, t_uint16 sq_side, t_uint16 *dif_ref)
{
	t_mk_mtr_helper	*vars;
	int				i;
	t_uint16		diff_ttrs;

	if (!(vars = (t_mk_mtr_helper*)malloc(sizeof(t_mk_mtr_helper) * 1)))
		return (0);
	*vars = (t_mk_mtr_helper){(t_uint16*)ft_memalloc(sizeof(t_uint16) * 4000),
						0, sq_side * sq_side, 0, tetras, sq_side};
	if (!vars->t)
	{
		free(vars);
		return (0);
	}
	i = -1;
	diff_ttrs = 0;
	while (++i < tetras_count)
		if (vars->t[tetras[i]] == 0)
		{
			vars->t[tetras[i]]++;
			diff_ttrs++;
		}
	*dif_ref = diff_ttrs;
	vars->row_count = diff_ttrs * sq_side * sq_side + (t_uint16)1;
	return (vars);
}

int					ft_make_fillit_matrix_create(t_mk_mtr_helper *vars)
{
	int i;

	if (!(vars->matrix = (char**)ft_memalloc(sizeof(char*) * vars->row_count)))
	{
		free(vars->t);
		free(vars);
		return (0);
	}
	i = 0;
	while (i < vars->row_count)
		if (!(vars->matrix[i++] = (char*)ft_memalloc(sizeof(char) *
				vars->col_count)))
		{
			ft_free_matrix((void**)&(vars->matrix), (size_t)i - 1);
			free(vars->t);
			free(vars);
			return (0);
		}
	i = 0;
	while (i < vars->col_count)
	{
		vars->matrix[0][i] = (t_int8)i;
		i++;
	}
	return (1);
}

void				ft_make_fillit_matrix_body(t_mk_mtr_helper *vars,
								t_uint16 sq_side, int j, int *h)
{
	int i;

	if (vars->t[vars->tetras[j]] == 1)
	{
		vars->t[vars->tetras[j]]++;
		i = -1;
		while (++i < sq_side * sq_side)
			ft_fill_line(vars->tetras[j], vars->matrix[1 + i + *h * sq_side *
									sq_side], sq_side, (t_uint16)i);
		(*h)++;
	}
}

t_int8				**ft_make_fillit_matrix(t_uint16 *tetras,
			t_uint16 tetras_count, t_uint16 sq_side, t_uint16 *dif_ref)
{
	t_mk_mtr_helper	*vars;
	char			**matrix;
	int				j;
	int				h;

	if (!(vars = ft_make_fillit_matrix_preparations(tetras, ++tetras_count,
			sq_side, dif_ref)))
		return (0);
	if (!ft_make_fillit_matrix_create(vars))
		return (0);
	j = -1;
	h = 0;
	while (++j < tetras_count)
	{
		ft_make_fillit_matrix_body(vars, sq_side, j, &h);
	}
	matrix = vars->matrix;
	free(vars->t);
	free(vars);
	return (matrix);
}
