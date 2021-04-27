/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 13:45:16 by kmacquet          #+#    #+#             */
/*   Updated: 2021/04/27 16:09:24 by kmacquet         ###   ########.fr       */
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

void	ft_lstadd_back(t_stack **alst, t_stack *new)
{
	if (!new)
		return ;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	new->previous = ft_lstlast(*alst);
	new->previous->next = new;
}

t_stack	*ft_lstlast(t_stack *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

t_stack	*ft_lstfirst(t_stack *lst)
{
	while (lst)
	{
		if (!lst->previous)
			return (lst);
		lst = lst->previous;
	}
	return (lst);
}

t_stack	*ft_lstnew(t_stack *next, t_stack *previous)
{
	t_stack	*list;

	if (!(list = malloc(sizeof(t_stack))))
		return (NULL);
	list->next = next;
	list->previous = previous;
	return (list);
}

t_command	*ft_lstnew2(t_command *next, t_command *previous)
{
	t_command	*list;

	if (!(list = malloc(sizeof(t_command))))
		return (NULL);
	list->next = next;
	list->previous = previous;
	return (list);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
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
