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

#include "libft.h"
#include "fillit.h"

int					ft_fillit_get_act_char(t_uint16 c)
{
	if (c == '.')
		return (0x1f943);
	return (c - 'Z' < 50 ? 0x1F300 + c : 0x1F400 + c);
}

void				ft_print_res_matrix(t_uint16 **matrix, t_uint16 n)
{
	t_uint16 i;
	t_uint16 j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (FILLIT_UNICODE)
				ft_putchar_u_fd(ft_fillit_get_act_char(matrix[i][j]), 1);
			else
				ft_putchar((char)matrix[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
