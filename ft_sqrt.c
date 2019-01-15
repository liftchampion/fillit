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

#include "ft_sqrt.h"

double		ft_round(double n, double p)
{
	double	res;
	int		l;
	int		m;

	res = n;
	l = (int)n;
	m = l + 1;
	if (n - l < p)
		res = l;
	else if (m - n < p)
		res = m;
	return (res);
}

int			ft_get_range(double *l, double *r, double s, double p)
{
	double mid;
	double mid2;

	mid = (*r + *l) / 2;
	mid2 = mid * mid;
	if (s < mid2 - p)
	{
		*r = mid;
		return (-1);
	}
	else if (s > mid2 + p)
	{
		*l = mid;
		return (1);
	}
	else
		return (0);
}

double		ft_sqrt(double n, double p)
{
	double res;
	double l;
	double r;

	l = 0;
	r = n / 2;
	if (n < 0)
		return (-1);
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	if (n <= 4)
		r = n;
	while (ft_get_range(&l, &r, n, p))
	{
	}
	res = (l + r) / 2;
	return (ft_round(res, p));
}
