/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:31:02 by kmacquet          #+#    #+#             */
/*   Updated: 2021/05/28 15:44:30 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack		t_stack;
typedef struct s_data		t_data;
typedef struct s_command	t_command;

struct			s_data
{
	int			y;
	int			error;
	int			group;
	int			ret;
	int			pivot;
	int			y_max;
	int			a_size;
	int			b_size;
	int			group_size;
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_command	*command;
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

int				pre_solved(t_data *data);
int				count_group(t_stack *stack);
int				count_stack(t_stack *stack);
void			s_algo(t_data *data);
void			s_algo_a(t_data *data, int nb_left);
void			s_algo_b(t_data *data, int nb_left);
void			s_algo_presolved(t_data *data);
void			xs_algo(t_data *data);
void			xxs_algo(t_data *data);
void			xxs_ralgob(t_data *data);
void			solving(t_data *data);
void			parsing_nb2(t_data *data, char **av, int ac);
void			ft_free2(t_command *command);
void			ft_free(t_stack *data);
void			check_cmd(t_data *data, char *line);
t_data			*init(t_data *data);
void			parsing_nb(t_data *data, char **av);
t_command		*ft_lstnew2(t_command *next, t_command *previous);
int				ft_atoi(char *s);
char			is_charset(char c, char *charset);
char			**ft_split_str(char *s, char *charset, t_data *data);
void			split_loop(char *str, char **dest, char *charset, char *start);
void			ft_strcpy(char *start, char *str, char *dest);
int				ft_countword(char *str, char *charset);
int				get_next_line(char **line);
int				get_next_line_tmp(char **line, int l, char c);
void			parsing_cmd(t_data *data);
void			is_solved(t_data *data);
int				is_solved2(t_data *data);
int				is_solved_tab(int *av, t_data *data);
void			ft_status(int status, t_data *data);
void			print_stack(t_data *data);
void			ft_lstadd_front(t_data *data, t_stack *new);
void			ft_lstadd_frontb(t_data *data, t_stack *new);
void			ft_lstadd_back(t_stack **alst, t_stack *new);
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
