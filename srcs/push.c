/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:23:22 by kmacquet          #+#    #+#             */
/*   Updated: 2021/03/30 18:00:08 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	pa(t_data *d)
{
	int	ma_max;
	int	mb_max;
	
	ma_max = d->ma;
	mb_max = d->mb;
	while (--ma_max > 0)
		d->ta[ma_max + 1] = d->ta[ma_max];
	d->ta[0] = d->tb;
	d->ma += 1;
	while (--mb_max > 0)
		d->tb[mb_max - 1] = d->tb[mb_max];
	d->mb -= 1;
}

void	pb(t_data *d)
{
	int	ma_max;
	int	mb_max;
	
	ma_max = d->ma;
	mb_max = d->mb;
	while (--mb_max > 0)
		d->tb[mb_max + 1] = d->tb[mb_max];
	d->tb[0] = d->ta;
	d->mb += 1;
	while (--ma_max > 0)
		d->ta[ma_max - 1] = d->ta[mb_max];
	d->ma -= 1;
}
