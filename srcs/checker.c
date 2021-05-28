/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:30:01 by kmacquet          #+#    #+#             */
/*   Updated: 2021/05/28 14:31:15 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/common.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac >= 2)
	{
		if (!av[1][0])
			return (0);
		data = *init(&data);
		if (ac == 2)
			parsing_nb(&data, av);
		else
			parsing_nb2(&data, av, ac);
		parsing_cmd(&data);
		if (!data.stack_a)
			return (0);
		new_pivot(&data, 'a', count_stack(data.stack_a));
		is_solved(&data);
	}
	return (0);
}
