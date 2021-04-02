/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 10:52:48 by kmacquet          #+#    #+#             */
/*   Updated: 2021/04/02 13:11:53 by kmacquet         ###   ########.fr       */
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
	if (!(*line = malloc(l)))
		return (-1);
	(*line)[0] = 0;
	while ((r = read(0, &c, 1)) && l++ && c != '\n')
	{
		if (!(tmp = malloc(l)))
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
