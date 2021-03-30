/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:24:44 by kmacquet          #+#    #+#             */
/*   Updated: 2021/03/30 16:44:06 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	sa(t_data *d)
{
	int tmp;

	tmp = d->ta[0];
	d->ta[0] = d->ta[1];
	d->ta[1] = tmp;
}

void	sb(t_data *d)
{
	int tmp;

	tmp = d->tb[0];
	d->tb[0] = d->tb[1];
	d->tb[1] = tmp;
}

void	ss(t_data *d)
{
	sa(d);
	sb(d);
}
