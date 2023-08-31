/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:58:16 by ancolmen          #+#    #+#             */
/*   Updated: 2023/04/05 18:06:03 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define NO_ERROR 0
# define ERROR 1
# define A 'a'
# define B 'b'
# define C_20 20
# define C_50 50

# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_lst
{
	int				num;
	int				pos;
	int				index;
	int				f_lis;
	int				cost;
	struct s_lst	*next;
}	t_lst;

typedef struct s_stack
{
	t_lst	*lst;
	int		size;
	int		lis_count;
}	t_stack;

typedef struct s_ps
{
	t_stack	a;
	t_stack	b;
	char	**args;
	t_list	*cmd;
	int		chunk;
}	t_ps;

/*FILL AND CHECK*/
void	fill_stack(t_ps *ps);
int		ft_atoi_ps(const char *nptr, int *val);
int		check_doubles(t_ps *ps);

/*START*/
void	start_program(t_ps *ps);

/*INSTRUCTIONS*/
void	push(t_ps *ps, int id);
void	swap(t_ps *ps, t_stack *stack, int id);
void	rotate(t_ps *ps, t_stack *stack, int id);
void	rev_rotate(t_ps *ps, t_stack *stack, int id);

/*SORT*/
void	sort_3(t_ps *ps);
void	sort_5(t_ps *ps);
void	sort(t_ps *ps);
void	chunk_sort(t_ps *ps, t_lst **stack);

/*LIS*/
void	lis(t_ps *ps, t_lst *stack);
int		lis_check(t_ps *ps, t_lst *actual, t_lst *iter);
void	lis_flag(t_ps *ps, t_lst *stack);

/*COST*/
void	get_move_cost(t_ps *ps, t_lst **stack, int id);
int		get_index_cost(t_ps *ps, t_lst *stack, int index);
int		find_target(t_lst *stack, int index);
void	cheapest_move(t_ps *ps, t_lst *stack_a, t_lst *stack_b);
void	move_cheapest(t_ps *ps, int cost_a, int cost_b);

/*LIST UTILS*/
void	add_to_lst(t_ps *ps, int val);
void	stacks_size(t_ps *ps);
int		ft_lstsize_ps(t_lst *lst);
int		lst_is_sorted(t_lst *lst);
void	lst_index(t_lst *lst);
void	lst_position(t_lst **lst);
void	ft_lstadd_front_ps(t_lst **lst, t_lst *new);
void	ft_lstadd_back_ps(t_lst **lst, t_lst *new);
t_lst	*ft_lstlast_ps(t_lst *lst);

/*UTILS*/
int		index_highest(t_lst *lst);
int		index_lowest(t_lst *lst);
int		first_index(t_lst *lst);
void	calculate_chunk(t_ps *ps, int *num, int *i);

/*COMMANDS*/
void	print_cmd(t_ps *ps);
void	stock_cmd(t_ps *ps, char *cmd);
int		check_cmd_join(char *cmd1, char *cmd2);

/*END*/
void	ft_exit(t_ps *ps, int error);
void	ft_lstclear_ps(t_lst *lst);
void	ft_lstclear_cmd(t_list *cmd);

/*BONUS*/
void	start_checker(t_ps *ps);
int		check_and_execute(t_ps *ps, char *cmd);
int		check_both(t_ps *ps, char *cmd);

void	help_print_indices(t_ps *ps);

#endif
