/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 10:52:48 by kmacquet          #+#    #+#             */
/*   Updated: 2021/05/28 16:54:12 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/common.h"

int	get_next_line_tmp(char **line, int l, char c)
{
	char	*tmp;
	int		i;

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
	return (0);
}

int	get_next_line(char **line)
{
	int		l;
	int		r;
	char	c;

	r = 0;
	l = 1;
	*line = malloc(l);
	if (!*line)
		return (-1);
	(*line)[0] = 0;
	r = read(0, &c, 1);
	while (r && l++ && c != '\n')
	{
		if (get_next_line_tmp(line, l, c) < 0)
			return (-1);
		r = read(0, &c, 1);
	}
	if (c != '\n')
		write(2, "  \n", 3);
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
	data->y = 0;
	data->error = 0;
	return (data);
}

int	ft_atoi(char *s)
{
	int		i;
	int		sign;
	long	result;

	sign = 1;
	i = 0;
	result = 0;
	if (s[i] == '-' || s[i] == '+')
		if (s[i++] == '-')
			sign = -1;
	if (s[i] >= '0' && s[i] <= '9')
	{
		while (s[i] >= '0' && s[i] <= '9')
		{
			result = result * 10 + (s[i++] - '0');
			if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
				ft_error("Arguments can't be higher/lower than INT", NULL);
		}
	}
	else
		ft_error("Argument isn't an integer", NULL);
	return (result * sign);
}
