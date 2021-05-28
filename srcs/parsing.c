/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 16:59:14 by kmacquet          #+#    #+#             */
/*   Updated: 2021/05/28 11:59:00 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/common.h"

t_command	*parsing_cmd2(t_data *data, char *line,
	t_command *ctmp, t_command *tmp)
{
	if (*line)
	{
		check_cmd(data, line);
		if (!data->command)
		{
			data->command = ft_lstnew2(NULL, NULL);
			ctmp = data->command;
		}
		else
		{
			tmp = data->command;
			data->command = ft_lstnew2(NULL, tmp);
			tmp->next = data->command;
		}
		while (line[++data->y])
			data->command->cmd[data->y] = line[data->y];
		data->command->cmd[data->y] = 0;
	}
	return (ctmp);
}

void	parsing_cmd(t_data *data)
{
	int			ret;
	char		*line;
	t_command	*tmp;
	t_command	*ctmp;

	ret = 1;
	line = NULL;
	ctmp = NULL;
	tmp = NULL;
	while (ret == 1)
	{
		data->y = -1;
		ret = get_next_line(&line);
		ctmp = parsing_cmd2(data, line, ctmp, tmp);
		free(line);
	}
	if (ctmp)
		data->command = ctmp;
}

void	check_cmd(t_data *data, char *line)
{
	if (!ft_strncmp(line, "sa", 3))
		sa(data);
	else if (!ft_strncmp(line, "sb", 3))
		sb(data);
	else if (!ft_strncmp(line, "rra", 4))
		rra(data);
	else if (!ft_strncmp(line, "rrb", 4))
		rrb(data);
	else if (!ft_strncmp(line, "rrr", 4))
		rrr(data);
	else if (!ft_strncmp(line, "ra", 3))
		ra(data);
	else if (!ft_strncmp(line, "rb", 3))
		rb(data);
	else if (!ft_strncmp(line, "rr", 3))
		rr(data);
	else if (!ft_strncmp(line, "pa", 3))
		pa(data);
	else if (!ft_strncmp(line, "pb", 3))
		pb(data);
	else
		ft_error("Wrong commands", data);
}

void	parsing_nb(t_data *data, char **av)
{
	char	**number;
	t_stack	*tmp;
	t_stack	*init;

	data->y = 0;
	number = ft_split_str(av[1], " ", data);
	while (data->y < data->y_max && number[data->y])
	{
		if (!data->stack_a)
		{
			data->stack_a = ft_lstnew(NULL, NULL);
			init = data->stack_a;
		}
		else
		{
			tmp = data->stack_a;
			data->stack_a = ft_lstnew(NULL, tmp);
			tmp->next = data->stack_a;
		}
		data->stack_a->i = ft_atoi(number[data->y]);
		data->stack_a->group = 0;
		free(number[data->y++]);
	}
	free(number);
	data->stack_a = init;
}

void	parsing_nb2(t_data *data, char **av, int ac)
{
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
		}
		else
		{
			tmp = data->stack_a;
			data->stack_a = ft_lstnew(NULL, tmp);
			tmp->next = data->stack_a;
		}
		data->stack_a->i = ft_atoi(av[y++]);
		data->stack_a->group = 0;
	}
	data->y_max = y - 1;
	data->stack_a = init;
}
