/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 11:03:14 by kmacquet          #+#    #+#             */
/*   Updated: 2021/04/02 16:26:31 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/common.h"

void	ft_error(char *s)
{
	write(1, "Error\n", 6);
	write(1, s, ft_strlen(s));
	exit(1);
}

void	ft_status(int status)
{
	if (status > 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	exit(0);
}
