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

int						ft_mtr_to_dlx_helper_check(t_mtr_to_dlx_helper *vars,
		t_uint16 *ttrs, t_dlx_head *res)
{
	if (!vars->unique_ttrs || !vars->col_to_co || !vars->col_to_prev_up ||
			!vars->ttrs_to_count || !vars->ttr_to_start_point ||
			!vars->ttr_to_ref_start_point)
	{
		ft_fillit_free_mtr_to_dlx(vars, ttrs, res);
		return (0);
	}
	return (1);
}

t_mtr_to_dlx_helper		*ft_init_mtr_to_dlx_vars(t_uint16 *ttrs,
		t_dlx_head *res)
{
	t_mtr_to_dlx_helper	*vars;
	t_dlx				*head_c;

	if (!res)
		return (0);
	if (!(head_c = ft_new_dlx_data_node(0, 0, ttrs, 0)))
	{
		free(res);
		return (0);
	}
	if (!(vars = (t_mtr_to_dlx_helper*)malloc(sizeof(t_mtr_to_dlx_helper) * 1)))
	{
		free(res);
		free(head_c);
		return (0);
	}
	*vars = (t_mtr_to_dlx_helper){0, (t_uint16*)ft_memalloc(sizeof(t_uint16) *
	20), ft_make_custom_value_map(UINT16_T, 0),
	ft_make_custom_value_map(UINT16_T, 0), ft_make_std_map(INT32_T, INT32_T),
	ft_make_custom_value_map(UINT16_T, 0), ft_make_custom_value_map(UINT16_T
		, 0), head_c, head_c, 0, 0, head_c, 0, res, 0};
	if (!ft_mtr_to_dlx_helper_check(vars, ttrs, res))
		return (0);
	return (vars);
}

void					ft_matrix_to_dlx_planned_frees(
		t_mtr_to_dlx_helper *vars, t_int8 **matrix, int row_c)
{
	ft_fillit_free_matrix((int**)matrix, row_c);
	ft_free_map(&vars->col_to_co);
	ft_free_map(&vars->col_to_prev_up);
	free(vars->unique_ttrs);
	free(vars);
}

void					ft_mtr_to_dlx_new_row_head(t_mtr_to_dlx_helper *vars,
		int i, int j, int m)
{
	vars->row_head = ft_new_dlx_data_node(0, 0,
			(void*)(size_t)vars->unique_ttrs[i / m], vars->row_head);
	vars->row_head->name = (t_uint16)((i) % m);
	vars->prev = vars->row_head;
	vars->row_head->c = 0;
	vars->row_head->r = 0;
	vars->row_head->u = *ft_map_get(vars->col_to_prev_up,
			(void*)(size_t)(j + 1));
	((t_dlx*)(*ft_map_get(vars->col_to_prev_up, (void*)(size_t)(j + 1))))->d =
			vars->row_head;
	*ft_map_get(vars->col_to_prev_up, (void*)(size_t)(j + 1)) = vars->row_head;
	((t_dlx*)(*ft_map_get(vars->col_to_co, (void*)(size_t)(j + 1))))->size++;
	vars->res->dlx_pointers[vars->res->size++] = vars->row_head;
}

void					ft_mtr_to_dlx_new_tied_data_obj(
		t_mtr_to_dlx_helper *vars, int i, int j, int m)
{
	vars->new = ft_new_dlx_data_node((t_uint16)i, vars->prev,
			(void*)(size_t)vars->unique_ttrs[i / m], vars->row_head);
	vars->new->name = (t_uint16)-1;
	if (*ft_map_get(vars->ttr_to_start_point,
			(void*)(size_t)vars->unique_ttrs[i / m]) ==
			vars->ttr_to_start_point->nil)
	{
		*ft_map_get(vars->ttr_to_start_point,
				(void*)(size_t)vars->unique_ttrs[i / m]) = vars->row_head;
		*ft_map_get(vars->ttr_to_ref_start_point,
				(void*)(size_t)vars->unique_ttrs[i / m]) = vars->row_head;
	}
	vars->row_head->size++;
	if (vars->row_head->r == 0)
		vars->row_head->r = vars->new;
	vars->new->c = *ft_map_get(vars->col_to_co, (void*)(size_t)(j + 1));
	vars->new->u = *ft_map_get(vars->col_to_prev_up, (void*)(size_t)(j + 1));
	((t_dlx*)(*ft_map_get(vars->col_to_prev_up,
			(void*)(size_t)(j + 1))))->d = vars->new;
	*ft_map_get(vars->col_to_prev_up, (void*)(size_t)(j + 1)) = vars->new;
	((t_dlx*)(*ft_map_get(vars->col_to_co, (void*)(size_t)(j + 1))))->size++;
	vars->prev->r = vars->new;
	vars->prev = vars->new;
	vars->res->dlx_pointers[vars->res->size++] = vars->new;
}
