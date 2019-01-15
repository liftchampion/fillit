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

#include "ft_tetramine_parser.h"
#include <stdlib.h>
#include "libft.h"
#include <unistd.h>
#include "ft_stack.h"

t_prs_ttr		*ft_parse_tetramines_preparations(int fd, t_int16 *tetras)
{
	t_prs_ttr *vars;

	if (!(vars = (t_prs_ttr*)ft_memalloc(sizeof(t_prs_ttr) * 1)))
	{
		free(tetras);
		return (0);
	}
	*vars = (t_prs_ttr){0, (char*)ft_memalloc(550), 0, 0, 0, 0, 0, -1, 0, 0};
	if (!vars->buffer)
	{
		free(tetras);
		free(vars);
		return (0);
	}
	vars->buf_copy = vars->buffer;
	vars->len = read(fd, vars->buffer, 550);
	if (vars->len <= 0 || (vars->len + 1) % 21)
	{
		free(vars->buf_copy);
		free(vars);
		return (0);
	}
	return (vars);
}

t_uint8			ft_parse_tetramines_emergency_free(t_prs_ttr *vars)
{
	if (vars)
		free(vars->buf_copy);
	free(vars);
	return (0);
}

int				ft_parse_tetramines_end_of_line(t_prs_ttr *vars,
												t_int16 *tetras)
{
	vars->buffer += *vars->buffer == '\n';
	if (*vars->buffer == '\n' || vars->count_endls != 4)
	{
		return (ft_parse_tetramines_emergency_free(vars));
	}
	else
	{
		if (!ft_check_tetra(vars->tetramine_hash))
		{
			return (ft_parse_tetramines_emergency_free(vars));
		}
		tetras[vars->tetramine_count++] = vars->tetramine_hash;
		vars->tetramine_hash = 0;
		vars->tetramine_start = -1;
		vars->level = 0;
		if (vars->count_hashs != 4)
		{
			return (ft_parse_tetramines_emergency_free(vars));
		}
		vars->count_hashs = 0;
		vars->count_endls = 0;
	}
	return (1);
}

int				ft_parse_tetramines_body(t_prs_ttr *vars, t_int16 *tetras)
{
	vars->it++;
	vars->buffer++;
	if (*vars->buffer == '\n')
	{
		if (vars->it != 4)
			return (ft_parse_tetramines_emergency_free(vars));
		vars->it = 0;
		vars->count_endls++;
		vars->level += vars->tetramine_start != -1;
		vars->buffer++;
		if (*vars->buffer == '\n' || *vars->buffer == '\0')
		{
			if (!ft_parse_tetramines_end_of_line(vars, tetras))
				return (0);
		}
	}
	return (1);
}

t_uint8			ft_parse_tetramines(int fd, t_int16 *tetras)
{
	static int	pows_of_ten[4] = {1, 10, 100, 1000};
	t_prs_ttr	*vars;
	t_uint8		ttr_count;

	if (!(vars = ft_parse_tetramines_preparations(fd, tetras)))
		return (ft_parse_tetramines_emergency_free(vars));
	while (*vars->buffer)
	{
		if (*vars->buffer == '#')
		{
			if (vars->tetramine_start == -1)
				vars->tetramine_start = vars->it;
			vars->count_hashs++;
			vars->tetramine_hash += (vars->it - vars->tetramine_start + 3) *
					pows_of_ten[(int)vars->level];
		}
		else if (*vars->buffer != '.')
			return (ft_parse_tetramines_emergency_free(vars));
		if (!ft_parse_tetramines_body(vars, tetras))
			return (0);
	}
	tetras[vars->tetramine_count] = 0;
	ttr_count = vars->tetramine_count;
	return (ttr_count + (t_uint8)ft_check_tetra(-1337) +
							ft_parse_tetramines_emergency_free(vars));
}
