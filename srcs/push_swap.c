/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:30:21 by kmacquet          #+#    #+#             */
/*   Updated: 2021/05/28 12:06:56 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/common.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac >= 2)
	{
		data = *init(&data);
		if (ac == 2)
			parsing_nb(&data, av);
		else
			parsing_nb2(&data, av, ac);
		if (!data.stack_a)
			return (0);
		new_pivot(&data, 'a', count_stack(data.stack_a));
		solving(&data);
		ft_status(3, &data);
	}
	return (0);
}
