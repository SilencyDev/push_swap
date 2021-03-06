/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 11:03:14 by kmacquet          #+#    #+#             */
/*   Updated: 2021/05/28 15:44:05 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/common.h"

void	ft_error(char *s, t_data *data)
{
	write(2, "Error\n", 6);
	write(2, s, ft_strlen(s));
	write(2, "\n", 1);
	if (data)
	{
		ft_free(data->stack_a);
		ft_free(data->stack_b);
		ft_free2(data->command);
	}
	exit(1);
}

void	ft_status(int status, t_data *data)
{
	if (status == 1)
		write(1, "OK\n", 3);
	else if (status == 0)
		write(1, "KO\n", 3);
	if (data)
	{
		ft_free(data->stack_a);
		ft_free(data->stack_b);
		ft_free2(data->command);
	}
	exit(0);
}

void	ft_free(t_stack *stack)
{
	if (stack && stack->next)
	{
		stack->next->previous = NULL;
		ft_free(stack->next);
	}
	if (stack && stack->previous)
	{
		stack->previous->next = NULL;
		ft_free(stack->previous);
	}
	if (stack)
	{
		free(stack);
		stack = NULL;
	}
}

void	ft_free2(t_command *command)
{
	if (command && command->next)
	{
		command->next->previous = NULL;
		ft_free2(command->next);
	}
	if (command && command->previous)
	{
		command->previous->next = NULL;
		ft_free2(command->previous);
	}
	if (command)
	{
		free(command);
		command = NULL;
	}
}
