/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:30:01 by kmacquet          #+#    #+#             */
/*   Updated: 2021/03/31 17:50:17 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	main(void)
{
	t_data	data;
	t_stack	stack;
	t_stack	stack2;
	t_stack	stack3;

	data.stack_a->i = 2;
	data.stack_a->next = &stack2;
	data.stack_a->previous = NULL;
	stack2.i = 5; 
	stack2.next = &stack3;
	stack2.previous = &stack;
	stack3.i = 4;
	stack3.next = NULL;
	stack3.previous = &stack2;

	printf("-------\n");
	printf("%d\n", data.stack_a->i);
	printf("%d\n", data.stack_a->next->i);
	printf("%d\n", data.stack_a->next->next->i);
	printf("-------\n");

	sa(&data);
	printf("-------\n");
	printf("%d\n", data.stack_a->i);
	printf("%d\n", data.stack_a->next->i);
	printf("%d\n", data.stack_a->next->next->i);
	printf("-------\n");
}
