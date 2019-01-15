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

#include "ft_stack.h"
#include "libft.h"
#include <stdlib.h>

t_stack		*ft_stack_new(void *data)
{
	t_stack *new;

	new = (t_stack*)malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->data = data;
	new->next = 0;
	return (new);
}

void		ft_stack_reverse(t_stack **old)
{
	t_stack *new;

	if (!old || !*old)
		return ;
	new = 0;
	while (*old)
	{
		ft_stack_push_node(&new, ft_stack_pop_node(old));
	}
	*old = new;
}
