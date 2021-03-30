/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tobottom.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:45:26 by kmacquet          #+#    #+#             */
/*   Updated: 2021/03/30 17:30:06 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	ra(t_data *d)
{
	int tmp;
	int mtab_init;

	mtab_init = d->ma;
	tmp = d->ta[0];
	while (--mtab_init > 0)
		d->ta[mtab_init - 1] = d->ta[mtab_init];
	d->ta[d->ma - 1] = tmp;
}

void	rb(t_data *d)
{
	int tmp;
	int mtab_init;

	mtab_init = d->mb;
	tmp = d->tb[0];
	while (--mtab_init > 0)
		d->tb[mtab_init - 1] = d->tb[mtab_init];
	d->tb[d->mb - 1] = tmp;
}

void	rr(t_data *d)
{
	ra(d);
	rb(d);
}
