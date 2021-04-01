/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:30:01 by kmacquet          #+#    #+#             */
/*   Updated: 2021/04/01 19:45:04 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	main(void)
{
	t_data	*data;
	t_stack	*stack;
	t_stack	*stack2;
	t_stack	*stack3;

	data = malloc(sizeof(t_data));
	stack = malloc(sizeof(t_stack));
	stack2 = malloc(sizeof(t_stack));
	stack3 = malloc(sizeof(t_stack));
	data->stack_b = NULL;
	data->stack_a = stack;
	data->stack_a->i = 2;
	data->stack_a->next = stack2;
	data->stack_a->previous = NULL;
	stack2->i = 5; 
	stack2->next = stack3;
	stack2->previous = stack;
	stack3->i = 4;
	stack3->next = NULL;
	stack3->previous = stack2;

	print_stack(data);

	sa(data);
	print_stack(data);

	pb(data);
	print_stack(data);

	pb(data);
	print_stack(data);

	pb(data);
	print_stack(data);

	pa(data);
	print_stack(data);

	rb(data);
	print_stack(data);

	pa(data);
	print_stack(data);

	sa(data);
	print_stack(data);
	
	pa(data);
	print_stack(data);
}
