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

t_dlx					*ft_new_dlx_data_node(t_uint16 size,
		t_dlx *left, void *info, t_dlx *ttr_item)
{
	t_dlx *node;

	node = (t_dlx*)malloc(sizeof(t_dlx));
	if (!node)
		return (0);
	*node = (t_dlx){left, 0, 0, 0, 0, ttr_item, 0, size, info};
	return (node);
}

void					ft_fill_res_matrix_fin_body(t_uint16 sq_side,
		t_uint16 ttr_count, t_uint16 **mtr, t_fill_res_mtr_helper vars)
{
	t_uint16			pos;
	t_uint16			i;
	t_int16				ttr;

	i = 0;
	while (i < sq_side * sq_side)
	{
		mtr[i / sq_side][i % sq_side] = '.';
		i++;
	}
	i = 0;
	while (i < ttr_count)
	{
		ttr = vars.ttrs[i];
		pos = vars.res[i];
		if (ttr == 63)
			pos -= 2;
		if (ttr == 533 || ttr == 57 || ttr == 93 || ttr == 353 || ttr == 253)
			pos -= 1;
		ft_fillit_fill_res_ttr(ttr, mtr,
				(t_row_col){pos / sq_side, pos % sq_side}, i + (t_uint16)'A');
		i++;
	}
}

t_uint16				**ft_fill_res_matrix_fin(t_uint16 *res,
		t_uint16 sq_side, t_uint16 ttr_count, t_int16 *ttrs)
{
	t_uint16 **mtr;
	t_uint16 i;

	mtr = (t_uint16**)ft_memalloc(sizeof(t_uint16*) * sq_side);
	if (!mtr)
		return (0);
	i = 0;
	while (i < sq_side)
	{
		mtr[i] = (t_uint16*)malloc(sizeof(t_uint16) * sq_side);
		if (!mtr[i])
		{
			ft_free_matrix((void**)mtr, i);
			return (0);
		}
		i++;
	}
	ft_fill_res_matrix_fin_body(sq_side, ttr_count, mtr,
			(t_fill_res_mtr_helper){ttrs, res});
	return (mtr);
}

void					ft_dlx_cover(t_dlx *column)
{
	t_dlx *down_node;
	t_dlx *right_node;

	if (!column)
		return ;
	column->r->l = column->l;
	column->l->r = column->r;
	down_node = column->d;
	while (down_node != column)
	{
		right_node = down_node->r;
		while (right_node != down_node)
		{
			right_node->d->u = right_node->u;
			right_node->u->d = right_node->d;
			if (right_node->c)
				right_node->c->size--;
			right_node = right_node->r;
		}
		down_node = down_node->d;
	}
}

void					ft_dlx_uncover(t_dlx *column)
{
	t_dlx *upper_node;
	t_dlx *left_node;

	if (!column)
		return ;
	upper_node = column->u;
	while (upper_node != column)
	{
		left_node = upper_node->l;
		while (left_node != upper_node)
		{
			if (left_node->c)
				left_node->c->size++;
			left_node->d->u = left_node;
			left_node->u->d = left_node;
			left_node = left_node->l;
		}
		upper_node = upper_node->u;
	}
	column->r->l = column;
	column->l->r = column;
}
