/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:31:02 by kmacquet          #+#    #+#             */
/*   Updated: 2021/03/31 17:35:19 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include <stdio.h>

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
