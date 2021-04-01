/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:31:02 by kmacquet          #+#    #+#             */
/*   Updated: 2021/04/01 19:07:40 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_stack t_stack;
typedef struct	s_data t_data;

struct	s_data
{
	t_stack	*stack_a;
	t_stack	*stack_b;
};


struct	s_stack
{
	int		i;
	t_stack	*next;
	t_stack	*previous;
};

void	print_stack(t_data *data);
void	ft_delfront(t_stack **slst);
void	ft_lstadd_front(t_stack **slst, t_stack *new);
void	ft_lstadd_back(t_stack **alst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_lstfirst(t_stack *lst);
t_stack	*ft_lstnew(t_stack *next, t_stack *previous);
int		ft_strlen(char *s);
void	ft_error(char *s);
void	pa(t_data *data);
void	pb(t_data *data);
void	sa(t_data *stack_a);
void	sb(t_data *stack_b);
void	ss(t_data *data);
void	ra(t_data *stack_a);
void	rb(t_data *stack_b);
void	rr(t_data *data);
void	rra(t_data *stack_a);
void	rrb(t_data *stack_b);
void	rrr(t_data *d);

#endif
