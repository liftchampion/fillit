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

void					ft_choose_best_column_body(t_dlx *tmp, t_dlx **res,
		t_uint64 *current, t_uint64 *min)
{
	t_dlx *tmp2;
	t_dlx *tmp3;

	tmp2 = tmp->d;
	while (tmp2 != tmp)
	{
		tmp3 = tmp2->r;
		while (tmp3 != tmp2)
		{
			if (tmp3->c != 0)
				*current += (10000000u + tmp3->c->size);
			tmp3 = tmp3->r;
		}
		tmp2 = tmp2->d;
	}
	if (*current < *min)
	{
		*min = *current;
		*res = tmp;
	}
}

t_dlx					*ft_choose_best_column(t_dlx *head)
{
	t_uint64			min;
	t_uint64			current;
	t_dlx				*res;
	t_dlx				*tmp;

	min = 9223372036854775807;
	res = head;
	tmp = head->r;
	while (tmp != head)
	{
		if (tmp->size == 0)
		{
			return (0);
		}
		current = tmp->size * 10000000000u;
		ft_choose_best_column_body(tmp, &res, &current, &min);
		tmp = tmp->r;
	}
	return (res);
}

void					ft_fillit_check_used_ttrs(t_map *map, t_rb_tree *node,
		t_int8 *res)
{
	if (node == map->nil)
	{
		return ;
	}
	if (node == 0)
	{
		if (map->root->value != 0)
		{
			(*res)++;
		}
		ft_fillit_check_used_ttrs(map, map->root->left, res);
		ft_fillit_check_used_ttrs(map, map->root->right, res);
		return ;
	}
	if (node->value != 0)
	{
		(*res)++;
	}
	ft_fillit_check_used_ttrs(map, node->left, res);
	ft_fillit_check_used_ttrs(map, node->right, res);
}

int						ft_dlx_search_preprations(t_dlx_head *dlx,
		t_int8 *found, t_dlx **column, t_dlx **down_node)
{
	t_dlx				*head;
	t_int8				used_all;

	if (*found != 0)
		return (0);
	head = dlx->head_c;
	used_all = 0;
	if (head->r == head)
	{
		ft_fillit_check_used_ttrs(dlx->info, 0, &used_all);
		if (used_all != 0)
			return (0);
		*found = 1;
		return (0);
	}
	*column = ft_choose_best_column(head);
	if (!*column)
		return (0);
	ft_dlx_cover(*column);
	*down_node = (*column)->d;
	return (1);
}

void					ft_dlx_search_body(t_dlx *down_node, t_dlx **column,
		t_dlx_helper *vars)
{
	t_dlx *right_node;

	ft_stack_push(vars->solution, down_node);
	--(*ft_map_get(vars->dlx->info, down_node->info));
	right_node = down_node->r;
	while (right_node != down_node)
	{
		ft_dlx_cover(right_node->c);
		right_node = right_node->r;
	}
	ft_dlx_search(vars->dlx, vars->deep + 1, vars->solution, vars->found);
	down_node = *ft_stack_get(*(vars->solution));
	ft_stack_pop(vars->solution, 0);
	++(*ft_map_get(vars->dlx->info, down_node->info));
	*column = down_node->c;
	right_node = down_node->l;
	while (right_node != down_node)
	{
		ft_dlx_uncover(right_node->c);
		right_node = right_node->l;
	}
}
