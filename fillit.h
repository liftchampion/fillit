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

#ifndef FILLIT_H
# define FILLIT_H

# define FILLIT_UNICODE 0

# include "libft.h"
# include "ft_stack.h"

typedef struct			s_dlx
{
	struct s_dlx	*l;
	struct s_dlx	*r;
	struct s_dlx	*u;
	struct s_dlx	*d;
	struct s_dlx	*c;
	struct s_dlx	*t;
	t_uint16		name;
	int				size;
	void			*info;
}						t_dlx;

typedef struct			s_dlx_head
{
	t_dlx		*head_c;
	t_dlx		*head_t;
	void		*info;
	t_map		*ttr_to_start_point;
	t_map		*ttr_to_ref_start_point;
	t_uint16	*ttrs;
	t_uint16	ttr_count;
	t_dlx		**dlx_pointers;
	t_uint16	size;
}						t_dlx_head;

typedef struct			s_mtr_to_dlx_helper
{
	t_uint16	ttr_count;
	t_uint16	*unique_ttrs;
	t_map		*col_to_co;
	t_map		*col_to_prev_up;
	t_map		*ttrs_to_count;
	t_map		*ttr_to_start_point;
	t_map		*ttr_to_ref_start_point;
	t_dlx		*head_c;
	t_dlx		*prev;
	t_dlx		*new;
	t_dlx		*row_head;
	t_dlx		*prev_up;
	t_dlx		*head_t;
	t_dlx_head	*res;
	t_int8		**matrix;
}						t_mtr_to_dlx_helper;

typedef struct			s_dlx_helper
{
	t_stack		**solution;
	t_dlx_head	*dlx;
	t_int8		*found;
	int			deep;

}						t_dlx_helper;

typedef struct			s_fill_res_mtr_helper
{
	t_int16		*ttrs;
	t_uint16	*res;
}						t_fill_res_mtr_helper;

typedef struct			s_main_helper
{
	t_int16		*tetras;
	t_uint16	tetras_count;
	int			fd;
	t_int16		delta;
	t_int8		found;
	t_dlx_head	*dlx;
	t_uint16	sq_side;
	char		**mtr;
	t_uint16	row_count;
	t_uint16	col_count;
	t_uint16	*solution;
	t_uint16	**res;
}						t_main_helper;

t_dlx					*ft_new_dlx_data_node(t_uint16 size,
		t_dlx *left, void *info, t_dlx *ttr_item);

void					ft_fill_res_matrix_fin_body(t_uint16 sq_side,
		t_uint16 ttr_count, t_uint16 **mtr, t_fill_res_mtr_helper vars);

t_uint16				**ft_fill_res_matrix_fin(t_uint16 *res,
		t_uint16 sq_side, t_uint16 ttr_count, t_int16 *ttrs);

void					ft_dlx_cover(t_dlx *column);

void					ft_dlx_uncover(t_dlx *column);

void					ft_choose_best_column_body(t_dlx *tmp, t_dlx **res,
		t_uint64 *current, t_uint64 *min);

t_dlx					*ft_choose_best_column(t_dlx *head);

void					ft_fillit_check_used_ttrs(t_map *map, t_rb_tree *node,
		t_int8 *res);

int						ft_dlx_search_preprations(t_dlx_head *dlx,
		t_int8 *found, t_dlx **column, t_dlx **down_node);

void					ft_dlx_search_body(t_dlx *down_node, t_dlx **column,
		t_dlx_helper *vars);

void					ft_dlx_search(t_dlx_head *dlx, int deep,
		t_stack **solution, t_int8 *found);

t_uint16				ft_fillit_get_ttr_count(t_uint16 *ttrs,
		t_map *ttrs_to_count, t_uint16 *unique_ttrs, t_uint16 m);

void					ft_dlx_hide_empty_ttrs(t_dlx_head *dlx);

void					ft_fillit_dlx_free(t_dlx_head *dlx);

void					ft_fillit_free_mtr_to_dlx(t_mtr_to_dlx_helper *vars,
		t_uint16 *ttrs, t_dlx_head *res);
int						ft_mtr_to_dlx_helper_check(t_mtr_to_dlx_helper *vars,
		t_uint16 *ttrs, t_dlx_head *res);

t_mtr_to_dlx_helper		*ft_init_mtr_to_dlx_vars(t_uint16 *ttrs,
		t_dlx_head *res);

void					ft_matrix_to_dlx_planned_frees(
		t_mtr_to_dlx_helper *vars, t_int8 **matrix, int row_c);

void					ft_mtr_to_dlx_new_row_head(t_mtr_to_dlx_helper *vars,
		int i, int j, int m);

void					ft_mtr_to_dlx_new_tied_data_obj(
		t_mtr_to_dlx_helper *vars, int i, int j, int m);

int						ft_mtr_to_dlx_preparations(t_mtr_to_dlx_helper **vars,
		t_uint16 *ttrs, t_dlx_head **res, t_uint16 m);

void					ft_mtr_to_dlx_column_objs(t_mtr_to_dlx_helper *vars,
		t_uint16 *ttrs, t_dlx_head *res, t_uint16 m);

void					ft_mtr_to_dlx_body(t_mtr_to_dlx_helper *vars, int i,
		t_uint16 m, t_uint16 n);

t_dlx_head				*ft_matrix_to_dlx(t_int8 **matrix, t_uint16 n,
		t_uint16 m, t_uint16 *ttrs);

#endif
