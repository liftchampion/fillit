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

void					ft_dlx_search(t_dlx_head *dlx, int deep,
		t_stack **solution, t_int8 *found)
{
	t_dlx				*column;
	t_dlx				*down_node;
	t_dlx_helper		vars;

	if (!ft_dlx_search_preprations(dlx, found, &column, &down_node))
		return ;
	vars = (t_dlx_helper){solution, dlx, found, deep};
	while (down_node != column)
	{
		if (*ft_map_get(dlx->info, down_node->info) != (void*)(size_t)0)
		{
			ft_dlx_search_body(down_node, &column, &vars);
		}
		down_node = down_node->d;
	}
	ft_dlx_uncover(column);
}

t_uint16				ft_fillit_get_ttr_count(t_uint16 *ttrs,
					t_map *ttrs_to_count, t_uint16 *unique_ttrs, t_uint16 m)
{
	t_uint16 c;
	t_uint16 i;

	c = 0;
	i = 0;
	while (*ttrs)
	{
		if (*ft_map_get(ttrs_to_count, (void*)(size_t)*ttrs) ==
				ttrs_to_count->nil)
		{
			*ft_map_get(ttrs_to_count, (void*)(size_t)*ttrs) = 0;
			unique_ttrs[i] = *ttrs;
			i++;
		}
		(*ft_map_get(ttrs_to_count, (void*)(size_t)*ttrs))++;
		c++;
		ttrs++;
	}
	*ft_map_get(ttrs_to_count, (void*)(size_t)0) = (void*)(size_t)(m - c * 4);
	return (c);
}

void					ft_dlx_hide_empty_ttrs(t_dlx_head *dlx)
{
	t_dlx *head_t;
	t_dlx *tmp;

	head_t = dlx->head_t;
	tmp = head_t->d;
	while (tmp != head_t)
	{
		if (tmp->size == 0)
		{
			tmp->u->d = tmp->d;
			tmp->d->u = tmp->u;
		}
		tmp = tmp->d;
	}
}

void					ft_fillit_dlx_free(t_dlx_head *dlx)
{
	t_dlx **to_free;

	if (!dlx)
		return ;
	to_free = dlx->dlx_pointers;
	if (to_free)
	{
		while (*to_free)
		{
			free(*to_free);
			to_free++;
		}
	}
	free(dlx->dlx_pointers);
	ft_free_map(&dlx->ttr_to_ref_start_point);
	ft_free_map(&dlx->ttr_to_start_point);
	ft_free_map((t_map**)&dlx->info);
	free(dlx->head_t);
	free(dlx->head_c);
	free(dlx);
}

void					ft_fillit_free_mtr_to_dlx(t_mtr_to_dlx_helper *vars,
		t_uint16 *ttrs, t_dlx_head *res)
{
	ft_free_map(&vars->col_to_co);
	ft_free_map(&vars->col_to_prev_up);
	ft_free_map(&vars->ttrs_to_count);
	ft_free_map(&vars->ttr_to_start_point);
	ft_free_map(&vars->ttr_to_ref_start_point);
	free(ttrs);
	free(vars->head_c);
	vars->head_c = 0;
	ft_fillit_dlx_free(res);
}
