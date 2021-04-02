/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:30:01 by kmacquet          #+#    #+#             */
/*   Updated: 2021/04/02 14:46:26 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	is_solved(t_data *data)
{
	if (!data->stack_a)
		ft_status(0);
	while (data->stack_a)
	{
		if ((data->stack_a->next
			&& data->stack_a->i > data->stack_a->next->i)
			|| data->stack_b)
			ft_status(0);
		data->stack_a = data->stack_a->next;
	}
	ft_status(1);
}

void		parsing(int ac, char **av, t_data *data)
{
	int		ret;
	char	*line;
	t_command	*tmp;

	ret = 1;
	line = NULL;
	while (ret == 1)
	{
		ret = get_next_line(&line);
		printf("%s\n", line);
		if (!data->command)
			data->command = ft_lstnew2(NULL, NULL);
		else
		{
			tmp = data->command;
			data->command = ft_lstnew2(NULL, data->command->previous);
			tmp->next = data->command;
		}
	}
}

int	main(int ac, char **av)
{
	t_data	*data;
	char	**number;
	int		y;
	t_stack	*tmp;
	t_stack	*init;

	y = 0;
	// t_stack	*stack;
	// t_stack	*stack2;
	// t_stack	*stack3;
	data = malloc(sizeof(t_data));
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->command = NULL;
	number = ft_split_str(av[1], " ", data);
	while (y < data->y_max && number[y])
	{
		if (!data->stack_a)
		{
			data->stack_a = ft_lstnew(NULL, NULL);
			init = data->stack_a;
			init->i = ft_atoi(number[y]);
		}
		else
		{
			tmp = data->stack_a;
			data->stack_a = ft_lstnew(NULL, data->stack_a->previous);
			tmp->next = data->stack_a;
			data->stack_a->i = ft_atoi(number[y]);
		}
		y++;
	}
	data->stack_a = init;
	parsing(ac, av, data);
	// stack = malloc(sizeof(t_stack));
	// stack2 = malloc(sizeof(t_stack));
	// stack3 = malloc(sizeof(t_stack));
	// data->stack_b = NULL;
	// data->stack_a = stack;
	// data->stack_a->i = 2;
	// data->stack_a->next = stack2;
	// data->stack_a->previous = NULL;
	// stack2->i = 5; 
	// stack2->next = stack3;
	// stack2->previous = stack;
	// stack3->i = 4;
	// stack3->next = NULL;
	// stack3->previous = stack2;

	if (!data->stack_a)
		return (0);
	printf("test");
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

	pb(data);
	sa(data);
	pa(data);
	print_stack(data);
	
	is_solved(data);
}
