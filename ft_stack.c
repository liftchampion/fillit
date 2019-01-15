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

t_int8		ft_stack_push(t_stack **stack, void *data)
{
	t_stack *new;

	if (!stack)
		return (0);
	new = (t_stack*)malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->data = data;
	new->next = 0;
	if (*stack == 0)
	{
		*stack = new;
		return (1);
	}
	new->next = *stack;
	*stack = new;
	return (1);
}

void		ft_stack_pop(t_stack **stack, void (*free_func)(void*))
{
	t_stack *tmp;

	if (!stack || !*stack)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	if (free_func)
		free_func(tmp->data);
	free(tmp);
}

t_stack		*ft_stack_pop_node(t_stack **stack)
{
	t_stack *tmp;

	if (!stack || !*stack)
		return (0);
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = 0;
	return (tmp);
}

void		ft_stack_push_node(t_stack **stack, t_stack *node)
{
	if (!stack || !node)
		return ;
	if (!*stack)
	{
		*stack = node;
		return ;
	}
	node->next = *stack;
	*stack = node;
}

void		**ft_stack_get(t_stack *stack)
{
	if (!stack)
		return (0);
	return (&(stack->data));
}
