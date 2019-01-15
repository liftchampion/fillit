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

#ifndef FT_STACK_H
# define FT_STACK_H

# include "libft.h"

typedef struct	s_stack
{
	struct s_stack	*next;
	void			*data;

}				t_stack;

t_stack			*ft_stack_new(void *data);

t_int8			ft_stack_push(t_stack **stack, void *data);

void			ft_stack_pop(t_stack **stack, void (*free_func)(void*));

void			**ft_stack_get(t_stack *stack);

void			ft_stack_push_node(t_stack **stack, t_stack *node);

t_stack			*ft_stack_pop_node(t_stack **stack);

void			ft_stack_reverse(t_stack **old);

#endif
