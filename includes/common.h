/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:31:02 by kmacquet          #+#    #+#             */
/*   Updated: 2021/04/30 17:44:24 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct	s_stack t_stack;
typedef struct	s_data t_data;
typedef struct	s_command t_command;

struct			s_data
{
	int			current_group;
	int			next_group;
	int			pivot;
	int			y_max;
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_command 	*command;
};

struct			s_command
{
	char		cmd[4];
	t_command	*next;
	t_command	*previous;
};


struct			s_stack
{
	int			i;
	int			group;
	t_stack		*next;
	t_stack		*previous;
};

int				count_group(t_stack *stack, int group);
int				count_stack(t_stack *stack);
void			s_algo(t_data *data);
void			xs_algo(t_data *data);
void			xxs_algo(t_data *data);
void			solving(t_data *data, int ac);
void			parsing_nb2(t_data *data, char **av, int ac);
void			ft_free2(t_command *command);
void			ft_free(t_stack *data);
void			check_cmd(t_data *data);
t_data			*init(t_data *data);
void			parsing_nb(t_data *data, char **av);
t_command		*ft_lstnew2(t_command *next, t_command *previous);
long int		ft_atoi(char *s);
char			is_charset(char c, char *charset);
char			**ft_split_str(char *s, char *charset, t_data *data);
void			ft_strcpy(char *start, char *str, char *dest);
int				ft_countword(char *str, char *charset);
int				get_next_line(char **line);
void			parsing_cmd(t_data *data);
void			is_solved(t_data *data, int push_swap);
int				is_solved2(t_data *data, int push_swap);
void			ft_status(int status, t_data *data);
void			print_stack(t_data *data);
void			ft_lstadd_front(t_data *data, t_stack *new);
void			ft_lstadd_frontb(t_data *data, t_stack *new);
void			ft_lstadd_back(t_stack **alst, t_stack *new);
t_stack			*ft_lstlast(t_stack *lst);
t_stack			*ft_lstfirst(t_stack *lst);
t_stack			*ft_lstnew(t_stack *next, t_stack *previous);
int				ft_strlen(char *s);
void			ft_error(char *s, t_data *data);
void			pa(t_data *data);
void			pb(t_data *data);
void			sa(t_data *stack_a);
void			sb(t_data *stack_b);
void			ss(t_data *data);
void			ra(t_data *stack_a);
void			rb(t_data *stack_b);
void			rr(t_data *data);
void			rra(t_data *stack_a);
void			rrb(t_data *stack_b);
void			rrr(t_data *d);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			presort_tab(int *av, t_data *data);
void			new_pivot(t_data *data, char c, int size);

#endif
