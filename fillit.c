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

#include "fillit.h"
#include "ft_stack.h"
#include "libft.h"
#include "ft_tetras_patterns1.h"
#include "ft_matrix_maker.h"
#include "ft_fillit_result_proceeding.h"

int						ft_mtr_to_dlx_preparations(t_mtr_to_dlx_helper **vars,
								t_uint16 *ttrs, t_dlx_head **res, t_uint16 m)
{
	*res = (t_dlx_head*)ft_memalloc(sizeof(t_dlx_head) * 1);
	if (!(*vars = ft_init_mtr_to_dlx_vars(ttrs, *res)))
		return (0);
	**res = (t_dlx_head){0, 0,
					(*vars)->ttrs_to_count,
					(*vars)->ttr_to_start_point,
					(*vars)->ttr_to_ref_start_point, ttrs, 0,
					(t_dlx**)ft_memalloc(sizeof(t_dlx*) * 10000), 0};
	if (!(*res)->dlx_pointers)
	{
		ft_fillit_dlx_free(*res);
		return (0);
	}
	(*vars)->ttr_count = ft_fillit_get_ttr_count(ttrs, (*vars)->ttrs_to_count,
			(*vars)->unique_ttrs, m);
	(*res)->ttr_count = (*vars)->ttr_count;
	(*vars)->prev = (*vars)->head_c;
	return (1);
}

void					ft_mtr_to_dlx_column_objs(t_mtr_to_dlx_helper *vars,
									t_uint16 *ttrs, t_dlx_head *res, t_uint16 m)
{
	int i;

	i = 0;
	while (i < m)
	{
		vars->new = ft_new_dlx_data_node(0, vars->prev, 0, vars->head_c);
		vars->new->name = (t_uint16)(i + 1);
		*ft_map_get(vars->col_to_co, (void*)(size_t)(i + 1)) = vars->new;
		*ft_map_get(vars->col_to_prev_up, (void*)(size_t)(i + 1)) = vars->new;
		vars->prev->r = vars->new;
		vars->prev = vars->new;
		res->dlx_pointers[i] = vars->new;
		i++;
	}
	res->size += i;
	vars->head_c->l = vars->prev;
	vars->prev->r = vars->head_c;
	vars->prev_up = vars->head_c;
	vars->head_t = ft_new_dlx_data_node(0, 0, ttrs, 0);
	*ft_map_get(vars->col_to_co, (void*)(size_t)(0)) = vars->head_t;
	*ft_map_get(vars->col_to_prev_up, (void*)(size_t)(0)) = vars->head_t;
}

void					ft_mtr_to_dlx_body(t_mtr_to_dlx_helper *vars, int i,
														t_uint16 m, t_uint16 n)
{
	int j;

	j = -1;
	vars->prev = 0;
	vars->row_head = 0;
	vars->prev_up = vars->prev_up->r;
	while (j < (int)m)
	{
		if (j == -1)
			ft_mtr_to_dlx_new_row_head(vars, i, j, m);
		else if (vars->matrix[i][j] == 1)
			ft_mtr_to_dlx_new_tied_data_obj(vars, i, j, m);
		if (i + 1 == n)
		{
			((t_dlx*)(*ft_map_get(vars->col_to_prev_up,
					(void*)(size_t)(j + 1))))->d =
					*ft_map_get(vars->col_to_co, (void*)(size_t)(j + 1));
			((t_dlx*)(*ft_map_get(vars->col_to_co,
			(void*)(size_t)(j + 1))))->u = *ft_map_get(vars->col_to_prev_up,
			(void*)(size_t)(j + 1));
		}
		j++;
	}
	vars->row_head->l = vars->prev;
	vars->prev->r = vars->row_head;
}

t_dlx_head				*ft_matrix_to_dlx(t_int8 **matrix, t_uint16 n,
												t_uint16 m, t_uint16 *ttrs)
{
	int					i;
	t_mtr_to_dlx_helper	*vars;
	t_dlx_head			*res;

	if (!ft_mtr_to_dlx_preparations(&vars, ttrs, &res, m))
		return (0);
	ft_mtr_to_dlx_column_objs(vars, ttrs, res, m);
	vars->matrix = matrix;
	i = 1;
	while (i < n)
	{
		ft_mtr_to_dlx_body(vars, i, m, n);
		i++;
	}
	res->head_c = vars->head_c;
	res->head_t = vars->head_t;
	ft_matrix_to_dlx_planned_frees(vars, matrix, n);
	ft_dlx_hide_empty_ttrs(res);
	return (res);
}
