/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 16:59:14 by kmacquet          #+#    #+#             */
/*   Updated: 2021/04/27 16:07:59 by kmacquet         ###   ########.fr       */
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
	ctmp = NULL;
	while (ret == 1)
	{
		i = -1;
		ret = get_next_line(&line);
		if (*line)
		{
			if (!data->command)
			{
				data->command = ft_lstnew2(NULL, NULL);
				while (line[++i])
					data->command->cmd[i] = line[i];
				data->command->cmd[i] = 0;
				ctmp = data->command;
			}
			else
			{
				tmp = data->command;
				data->command = ft_lstnew2(NULL, tmp);
				tmp->next = data->command;
				while (line[++i])
					data->command->cmd[i] = line[i];
				data->command->cmd[i] = 0;
			}
		}
		free(line);
	}
	if (ctmp)
		data->command = ctmp;
}

void	check_cmd(t_data *data)
{
	t_command	*init;

	init = data->command;
	while (data->command)
	{
		if (!ft_strncmp(data->command->cmd, "sa", 3))
			sa(data);
		else if (!ft_strncmp(data->command->cmd, "sb", 3))
			sb(data);
		else if (!ft_strncmp(data->command->cmd, "rra", 4))
			rra(data);
		else if (!ft_strncmp(data->command->cmd, "rrb", 4))
			rrb(data);
		else if (!ft_strncmp(data->command->cmd, "rrr", 4))
			rrr(data);
		else if (!ft_strncmp(data->command->cmd, "ra", 3))
			ra(data);
		else if (!ft_strncmp(data->command->cmd, "rb", 3))
			rb(data);
		else if (!ft_strncmp(data->command->cmd, "rr", 3))
			rr(data);
		else if (!ft_strncmp(data->command->cmd, "pa", 3))
			pa(data);
		else if (!ft_strncmp(data->command->cmd, "pb", 3))
			pb(data);
		else
			ft_error("Wrong commands", data);
		print_stack(data);
		data->command = data->command->next;
	}
	data->command = init;
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
			data->stack_a = ft_lstnew(NULL, tmp);
			tmp->next = data->stack_a;
			data->stack_a->i = ft_atoi(number[y]);
		}
		free(number[y]);
		y++;
	}
	free(number);
	data->stack_a = init;
}

void	parsing_nb2(t_data *data, char **av, int ac)
{
	char	**number;
	int		y;
	t_stack	*tmp;
	t_stack	*init;
	
	y = 1;
	while (y < ac && av[y])
	{
		if (!data->stack_a)
		{
			data->stack_a = ft_lstnew(NULL, NULL);
			init = data->stack_a;
			init->i = ft_atoi(av[y]);
		}
		else
		{
			tmp = data->stack_a;
			data->stack_a = ft_lstnew(NULL, tmp);
			tmp->next = data->stack_a;
			data->stack_a->i = ft_atoi(av[y]);
		}
		y++;
	}
	data->y_max = y - 1;
	data->stack_a = init;
}
