/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:47:39 by kmacquet          #+#    #+#             */
/*   Updated: 2021/05/28 07:49:20 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/common.h"

char	is_charset(char c, char *charset)
{
	while (*charset)
		if (*charset++ == c)
			return (c);
	return (0);
}

int	ft_countword(char *str, char *charset)
{
	int	i;

	i = 0;
	while (*str)
	{
		while (is_charset(*str, charset) && *str)
			str++;
		if (!is_charset(*str, charset) && *str)
		{
			while (!is_charset(*str, charset) && *str)
				str++;
			i++;
		}
	}
	return (i);
}

void	ft_strcpy(char *start, char *str, char *dest)
{
	int	j;

	j = 0;
	while (start < str)
		dest[j++] = *start++;
	dest[j] = '\0';
}

char	**ft_split_str(char *s, char *charset, t_data *data)
{
	char	**dest;
	char	*start;
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	if (!s)
		return (NULL);
	dest = malloc(sizeof(char *) * ((data->y_max = ft_countword(str, charset)) + 1));
	if (!dest)
		return (NULL);
	while (*str)
	{
		if (!is_charset(*str, charset))
		{
			start = str;
			while (*str && !is_charset(*str, charset))
				str++;
			dest[i] = malloc(str - start + 1);
			ft_strcpy(start, str, dest[i]);
			i++;
		}
		else
			str++;
	}
	dest[i] = NULL;
	return (dest);
}

int	ft_atoi(char *s)
{
	int		i;
	int		sign;
	double	result;

	sign = 1;
	i = 0;
	result = 0;
	if (s[i] == '-' || s[i] == '+')
		if (s[i++] == '-')
			sign = -1;
	if (s[i] >= '0' && s[i] <= '9')
		while (s[i] >= '0' && s[i] <= '9')
			result = result * 10 + (s[i++] - '0');
	else
		ft_error("Argument isn't an integer", NULL);
	if (result > INT_MAX || result < INT_MIN)
		ft_error("Arguments can't be higher/lower than INT", NULL);
	return (result * sign);
}
