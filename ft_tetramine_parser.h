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

#ifndef FT_TETRAMINE_PARSER_H
# define FT_TETRAMINE_PARSER_H

# include "libft.h"
# include "ft_stack.h"

typedef struct	s_prs_ttr
{
	ssize_t	len;
	char	*buffer;
	char	*buf_copy;
	t_int8	count_hashs;
	t_int16	tetramine_hash;
	t_int8	it;
	t_int8	level;
	t_int8	tetramine_start;
	t_int8	count_endls;
	t_uint8	tetramine_count;
}				t_prs_ttr;

t_uint8			ft_parse_tetramines(int fd, t_int16 *tetras);

t_int16			*ft_make_tetr_reference(void);

t_int16			ft_check_tetra(int ttr);

#endif
