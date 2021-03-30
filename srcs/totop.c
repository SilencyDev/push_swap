/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   totop.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:55:30 by kmacquet          #+#    #+#             */
/*   Updated: 2021/03/30 17:30:29 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	rra(t_data *d)
{
	int tmp;
	int mtab_init;

	mtab_init = d->ma;
	tmp = d->ta[mtab_init - 1];
	mtab_init -= 1;
	while (--mtab_init > 0)
		d->ta[mtab_init + 1] = d->ta[mtab_init];
	d->ta[0] = tmp;
}

void	rrb(t_data *d)
{
	int tmp;
	int mtab_init;

	mtab_init = d->mb;
	tmp = d->tb[mtab_init - 1];
	mtab_init -= 1;
	while (--mtab_init > 0)
		d->tb[mtab_init + 1] = d->tb[mtab_init];
	d->tb[0] = tmp;
}

void	rrr(t_data *d)
{
	rra(d);
	rrb(d);
}
