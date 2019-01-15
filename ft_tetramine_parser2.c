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
#include "libft.h"

t_int16			*ft_make_tetr_reference(void)
{
	t_int16 *ref;

	if (!(ref = (t_int16*)ft_memalloc(sizeof(t_int16) * 3400)))
		return (0);
	ref[3333] = 1;
	ref[18] = 1;
	ref[77] = 1;
	ref[337] = 1;
	ref[62] = 1;
	ref[63] = 1;
	ref[733] = 1;
	ref[123] = 1;
	ref[533] = 1;
	ref[447] = 1;
	ref[42] = 1;
	ref[473] = 1;
	ref[57] = 1;
	ref[93] = 1;
	ref[353] = 1;
	ref[253] = 1;
	ref[97] = 1;
	ref[52] = 1;
	ref[373] = 1;
	return (ref);
}

t_int16			ft_check_tetra(int ttr)
{
	static t_int16 *reference = 0;

	if ((ttr > 3333 || ttr < 0) && ttr != -1337)
		return (0);
	if (reference == 0)
		reference = ft_make_tetr_reference();
	if (ttr == -1337)
	{
		free(reference);
		return (0);
	}
	return (reference[ttr]);
}
