/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:24:44 by kmacquet          #+#    #+#             */
/*   Updated: 2021/03/31 17:32:20 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/common.h"

void	sa(t_data *data)
{
	int	init;

	init = data->stack_a->i;
	data->stack_a->i = data->stack_a->next->i;
	data->stack_a->next->i = init;
}

void	sb(t_data *data)
{
	int	init;

	init = data->stack_b->i;
	data->stack_b->i = data->stack_b->next->i;
	data->stack_b->next->i = init;
}

void	ss(t_data *data)
{
	sa(data);
	sb(data);
}
