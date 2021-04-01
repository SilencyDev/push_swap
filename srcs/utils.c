/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 11:08:55 by kmacquet          #+#    #+#             */
/*   Updated: 2021/04/01 19:34:33 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/common.h"

int		ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	print_stack(t_data *data)
{
	t_stack *a;
	t_stack *b;

	a = data->stack_a;
	b = data->stack_b;
	printf("------\n");
	while (data->stack_a || data->stack_b)
	{
		printf("|%d  %d|", data->stack_a ? data->stack_a->i : 0, data->stack_b ? data->stack_b->i : 0);
		printf("\n");
		if (data->stack_a && data->stack_a->next)
			data->stack_a = data->stack_a->next;
		else
			data->stack_a = NULL;
		if (data->stack_b && data->stack_b->next)
			data->stack_b = data->stack_b->next;
		else
			data->stack_b = NULL;
	}
	printf("------\n");
	data->stack_a = a;
	data->stack_b = b;
}
