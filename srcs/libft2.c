/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:47:39 by kmacquet          #+#    #+#             */
/*   Updated: 2021/05/28 11:58:06 by kmacquet         ###   ########.fr       */
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
	char	*str;

	str = (char *)s;
	start = NULL;
	if (!s)
		return (NULL);
	dest = malloc(sizeof(char *)
			* ((data->y_max = ft_countword(str, charset)) + 1));
	if (!dest)
		return (NULL);
	split_loop(str, dest, charset, start);
	return (dest);
}

void	split_loop(char *str, char **dest, char *charset, char *start)
{
	int	i;

	i = 0;
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
}
