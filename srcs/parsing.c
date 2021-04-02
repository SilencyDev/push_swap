/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 16:59:14 by kmacquet          #+#    #+#             */
/*   Updated: 2021/04/02 18:09:49 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/common.h"

void		parsing_cmd(t_data *data)
{
	int		ret;
	char	*line;
	t_command	*tmp;
	t_command	*ctmp;
	int		i;

	ret = 1;
	line = NULL;
	while (ret == 1)
	{
		i = 0;
		ret = get_next_line(&line);
		if (!data->command)
		{
			data->command = ft_lstnew2(NULL, NULL);
			while (*line)
				data->command->cmd[i++] = *line++;
			data->command->cmd[i] = 0;
			ctmp = data->command;
		}
		else
		{
			tmp = data->command;
			data->command = ft_lstnew2(NULL, data->command->previous);
			tmp->next = data->command;
			while (*line)
				data->command->cmd[i++] = *line++;
			data->command->cmd[i] = 0;
		}
	}
	data->command = ctmp;
}

void	check_cmd(t_data *data)
{
	while (data->command)
	{
		if (data->command->cmd[0] && data->command->cmd[0] == 's')
		{
			if (data->command->cmd[1] && data->command->cmd[1] == 'a'
				&& !data->command->cmd[2])
				sa(data);
			else if (data->command->cmd[1] && data->command->cmd[1] == 'b'
				&& !data->command->cmd[2])
				sb(data);
			else if (data->command->cmd[1] && data->command->cmd[1] == 's'
				&& !data->command->cmd[2])
				ss(data);
			else
				ft_error("Wrong commands");
		}
		else if (data->command->cmd[0] && data->command->cmd[0] == 'r')
		{
			if (data->command->cmd[1] && data->command->cmd[1] == 'a'
				&& !data->command->cmd[2])
				ra(data);
			else if (data->command->cmd[1] && data->command->cmd[1] == 'b'
				&& !data->command->cmd[2])
				rb(data);
			else if (data->command->cmd[1] && data->command->cmd[1] == 'r'
				&& !data->command->cmd[2])
				rr(data);
			else
				ft_error("Wrong commands");
		}
		else if (data->command->cmd[0] && data->command->cmd[0] == 'r'
				&& data->command->cmd[1] && data->command->cmd[1] == 'r')
		{
			if (data->command->cmd[2] && data->command->cmd[2] == 'a'
				&& !data->command->cmd[3])
				rra(data);
			else if (data->command->cmd[2] && data->command->cmd[2] == 'b'
				&& !data->command->cmd[3])
				rrb(data);
			else if (data->command->cmd[2] && data->command->cmd[2] == 'r'
				&& !data->command->cmd[3])
				rrr(data);
			else
				ft_error("Wrong commands");
		}
		else if (data->command->cmd[0] && data->command->cmd[0] == 'p')
		{
			if (data->command->cmd[1] && data->command->cmd[1] == 'a'
				&& !data->command->cmd[2])
				pa(data);
			else if (data->command->cmd[1] && data->command->cmd[1] == 'b'
				&& !data->command->cmd[2])
				pb(data);
			else
				ft_error("Wrong commands");
		}
		else
			ft_error("Wrong commands");
		print_stack(data);
		data->command = data->command->next;
	}
}

void	parsing_nb(t_data *data, char **av)
{
	char	**number;
	int		y;
	t_stack	*tmp;
	t_stack	*init;
	
	y = 0;
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
}
