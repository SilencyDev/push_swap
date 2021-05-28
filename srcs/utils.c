/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 10:52:48 by kmacquet          #+#    #+#             */
/*   Updated: 2021/05/28 09:06:43 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/common.h"

int	get_next_line(char **line)
{
	int		i;
	int		l;
	int		r;
	char	c;
	char	*tmp;

	r = 0;
	l = 1;
	*line = malloc(l);
	if (!*line)
		return (-1);
	(*line)[0] = 0;
	while ((r = read(0, &c, 1)) && l++ && c != '\n')
	{
		tmp = malloc(l);
		if (!tmp)
		{
			free(*line);
			return (-1);
		}
		i = -1;
		while (++i < l - 2)
			tmp[i] = (*line)[i];
		tmp[i] = c;
		tmp[i + 1] = 0;
		free(*line);
		*line = tmp;
	}
	return (r);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

t_data	*init(t_data *data)
{
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->command = NULL;
	data->a_size = 0;
	data->b_size = 0;
	data->group_size = 0;
	data->ret = 0;
	data->group = 0;
	data->pivot = 0;
	data->y_max = 0;
	return (data);
}

void	presort_tab(int *av, t_data *data)
{
	int	tmp;
	int	i;

	i = 0;
	while (data->y_max > i && !is_solved_tab(av, data))
	{
		if (data->y_max - 1 != i && av[i] > av[i + 1])
		{
			tmp = av[i];
			av[i] = av[i + 1];
			av[i + 1] = tmp;
		}
		i++;
	}
	if (!is_solved_tab(av, data))
		presort_tab(av, data);
}
