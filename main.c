/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapka.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:25:22 by ggerardy          #+#    #+#             */
/*   Updated: 2018/12/09 04:37:14 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fillit.h"
#include <zconf.h>
#include "ft_stack.h"
#include "ft_tetramine_parser.h"
#include "ft_matrix_maker.h"
#include "ft_tetras_patterns1.h"
#include "ft_fillit_result_proceeding.h"
#include <fcntl.h>
#include "dlx_fillit_find_right_solution.h"
#include "ft_sqrt.h"

int					ft_fillit_emergency_free_main_vars(t_main_helper *vars)
{
	if (vars->fd >= 3)
		close(vars->fd);
	free(vars->tetras);
	ft_fillit_dlx_free(vars->dlx);
	ft_free_matrix((void**)vars->res, vars->sq_side);
	free(vars->solution);
	free(vars);
	return (0);
}

t_main_helper		*ft_fillit_input(int argc, char **argv)
{
	int				fd;
	t_main_helper	*vars;

	if (!(vars = ft_memalloc(sizeof(t_main_helper) * 1)))
		return (0);
	*vars = (t_main_helper){(t_int16*)ft_memalloc(sizeof(t_int16) * 30),
						0, argc * -1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	if (!vars->tetras)
	{
		ft_fillit_emergency_free_main_vars(vars);
		ft_putstr("error\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	vars->fd = fd;
	if (fd == -1)
	{
		ft_fillit_emergency_free_main_vars(vars);
		ft_putstr("error\n");
		return (0);
	}
	return (vars);
}

int					ft_fillit_find_sq_size(t_main_helper *vars,
		t_uint16 diff_ttrs, t_stack *stack)
{
	double sqr;

	while (vars->found != 1)
	{
		vars->found = 0;
		sqr = ft_sqrt(vars->tetras_count * 4, 0.0001);
		if (sqr > (int)sqr)
			sqr += 1;
		vars->sq_side = (t_uint16)sqr + vars->delta;
		if (!(vars->mtr = ft_make_fillit_matrix((t_uint16*)vars->tetras,
				vars->tetras_count, vars->sq_side, &diff_ttrs)))
			return (ft_fillit_emergency_free_main_vars(vars));
		vars->row_count = diff_ttrs * vars->sq_side * vars->sq_side +
				(t_uint16)1;
		vars->col_count = vars->sq_side * vars->sq_side;
		if (!(vars->dlx = ft_matrix_to_dlx(vars->mtr, vars->row_count,
				vars->col_count, (t_uint16*)vars->tetras)))
			return (ft_fillit_emergency_free_main_vars(vars));
		ft_dlx_search(vars->dlx, 0, &stack, &vars->found);
		if (!vars->found)
			ft_fillit_dlx_free(vars->dlx);
		vars->delta++;
	}
	return (1);
}

int					main(int argc, char **argv)
{
	t_main_helper *vars;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (0);
	}
	if (!(vars = ft_fillit_input(argc, argv)))
		return (0);
	vars->tetras_count = ft_parse_tetramines(vars->fd, vars->tetras);
	if (vars->tetras_count == 0)
	{
		ft_putstr("error\n");
		return (ft_fillit_emergency_free_main_vars(vars));
	}
	if (!ft_fillit_find_sq_size(vars, 0, 0))
		return (ft_fillit_emergency_free_main_vars(vars));
	if (!(vars->solution = ft_fillit_find_right_solution(vars->dlx)))
		return (ft_fillit_emergency_free_main_vars(vars));
	if (!(vars->res = ft_fill_res_matrix_fin(vars->solution, vars->sq_side,
			vars->tetras_count, vars->tetras)))
		return (ft_fillit_emergency_free_main_vars(vars));
	ft_print_res_matrix(vars->res, vars->sq_side);
	return (ft_fillit_emergency_free_main_vars(vars));
}
