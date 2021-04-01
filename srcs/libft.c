/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 13:45:16 by kmacquet          #+#    #+#             */
/*   Updated: 2021/04/01 18:51:45 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/common.h"

void	ft_lstadd_front(t_stack **slst, t_stack *new)
{
	new->next = *slst;
	*slst = new;
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
	list->previous;
	return (list);
}

void	ft_delfront(t_stack **slst)
{
	if ((*slst)->next)
	{
		(*slst) = (*slst)->next;
		free((*slst)->previous);
		(*slst)->previous = NULL;
	}
	else
	{
		free((*slst));
		(*slst) = NULL;
	}
}
