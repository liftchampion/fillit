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

#include "dlx_fillit_find_right_solution.h"
#include <stdlib.h>
#include "libft.h"
#include "fillit.h"

int				ft_fillit_put_ttr(t_dlx_head *dlx, int n, t_uint16 *res,
					t_dlx **filled)
{
	t_dlx		*start;
	t_dlx		*right_node;
	t_dlx		*down_node;

	start = *ft_map_get(dlx->ttr_to_start_point, (void*)(size_t)dlx->ttrs[n]);
	while (start->size != 4 && (t_uint16)start->info == dlx->ttrs[n])
		start = start->d;
	if ((t_uint16)start->info != dlx->ttrs[n])
		return (0);
	res[n] = start->r->c->name - (t_uint16)1;
	filled[n] = start;
	start->size -= 4;
	*ft_map_get(dlx->ttr_to_start_point, (void*)(size_t)dlx->ttrs[n]) = start;
	right_node = start->r;
	while (right_node != start)
	{
		down_node = right_node->d;
		while (down_node != right_node)
		{
			--down_node->t->size;
			down_node = down_node->d;
		}
		right_node = right_node->r;
	}
	return (1);
}

void			ft_fillit_unput_ttr(t_dlx_head *dlx, int n, t_dlx **filled)
{
	t_dlx		*start;
	t_dlx		*right_node;
	t_dlx		*down_node;

	start = filled[n];
	*ft_map_get(dlx->ttr_to_start_point,
			(void*)(size_t)dlx->ttrs[n]) = start->d;
	start->size += 4;
	right_node = start->r;
	while (right_node != start)
	{
		down_node = right_node->d;
		while (down_node != right_node)
		{
			++down_node->t->size;
			down_node = down_node->d;
		}
		right_node = right_node->r;
	}
	*ft_map_get(dlx->ttr_to_start_point,
			(void*)(size_t)dlx->ttrs[n]) = start->d;
}

int				ft_fillit_go_back(t_dlx_head *dlx, int n, t_dlx **filled)
{
	if (n == 0)
		return (0);
	*ft_map_get(dlx->ttr_to_start_point, (void*)(size_t)dlx->ttrs[n]) =
			*ft_map_get(dlx->ttr_to_ref_start_point,
					(void*)(size_t)dlx->ttrs[n]);
	ft_fillit_unput_ttr(dlx, n - 1, filled);
	return (1);
}

int				ft_fillit_find_right_solution_body(t_dlx_head *dlx,
								t_uint16 *res, t_dlx **filled, int *i)
{
	if (ft_fillit_put_ttr(dlx, *i, res, filled))
		(*i)++;
	else if (ft_fillit_go_back(dlx, (*i)--, filled) == 0)
	{
		free(res);
		free(filled);
		return (0);
	}
	return (1);
}

t_uint16		*ft_fillit_find_right_solution(t_dlx_head *dlx)
{
	int			i;
	t_uint16	*res;
	t_dlx		**filled;

	i = 0;
	res = (t_uint16*)ft_memalloc(sizeof(t_uint16) * dlx->ttr_count);
	if (!res)
		return (0);
	filled = (t_dlx**)ft_memalloc(sizeof(t_dlx*) * dlx->ttr_count);
	if (!filled)
	{
		free(res);
		return (0);
	}
	while (i < dlx->ttr_count)
		if (!ft_fillit_find_right_solution_body(dlx, res, filled, &i))
			return (0);
	free(filled);
	return (res);
}
