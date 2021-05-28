/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 13:45:16 by kmacquet          #+#    #+#             */
/*   Updated: 2021/05/28 08:34:28 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/common.h"

void	ft_lstadd_front(t_data *data, t_stack *new)
{
	if (data->stack_a)
		data->stack_a->previous = new;
	new->next = data->stack_a;
	data->stack_a = new;
}

void	ft_lstadd_frontb(t_data *data, t_stack *new)
{
	if (data->stack_b)
		data->stack_b->previous = new;
	new->next = data->stack_b;
	data->stack_b = new;
}

t_stack	*ft_lstnew(t_stack *next, t_stack *previous)
{
	t_stack	*list;

	list = malloc(sizeof(t_stack));
	if (!list)
		return (NULL);
	list->next = next;
	list->previous = previous;
	return (list);
}

t_command	*ft_lstnew2(t_command *next, t_command *previous)
{
	t_command	*list;

	list = malloc(sizeof(t_command));
	if (!list)
		return (NULL);
	list->next = next;
	list->previous = previous;
	return (list);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	i = 0;
	while ((c1[i] || c2[i]) && i < n)
	{
		if (c1[i] < c2[i])
			return (-1);
		if (c1[i] > c2[i])
			return (1);
		i++;
	}
	return (0);
}
