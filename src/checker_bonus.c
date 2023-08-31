/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:13:28 by anana             #+#    #+#             */
/*   Updated: 2023/04/06 18:43:34 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_ps	ps;

	i = argc - 1;
	if (i < 1)
		return (0);
	ft_bzero(&ps, sizeof(ps));
	while (i > 0)
	{
		ps.args = ft_split(argv[i], ' ');
		if (!ps.args)
			ft_exit(&ps, ERROR);
		fill_stack(&ps);
		ft_free_matrix(ps.args);
		ps.args = NULL;
		i--;
	}
	if (ps.a.lst)
		start_checker(&ps);
	ft_exit(&ps, NO_ERROR);
	return (0);
}

void	start_checker(t_ps *ps)
{
	char	*cmd;

	if (lst_is_sorted(ps->a.lst))
		return ;
	cmd = get_next_line(0);
	while (cmd)
	{
		if (check_and_execute(ps, cmd))
		{
			free(cmd);
			ft_exit(ps, ERROR);
		}
		free(cmd);
		cmd = get_next_line(0);
	}
	free(cmd);
	if (lst_is_sorted(ps->a.lst) && !ps->b.lst)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	check_and_execute(t_ps *ps, char *cmd)
{
	if (!ft_strcmp(cmd, "sa\n"))
		swap(ps, &ps->a, A);
	else if (!ft_strcmp(cmd, "sb\n"))
		swap(ps, &ps->b, B);
	else if (!ft_strcmp(cmd, "pa\n"))
		push(ps, A);
	else if (!ft_strcmp(cmd, "pb\n"))
		push(ps, B);
	else if (!ft_strcmp(cmd, "ra\n"))
		rotate(ps, &ps->a, A);
	else if (!ft_strcmp(cmd, "rb\n"))
		rotate(ps, &ps->b, B);
	else if (!ft_strcmp(cmd, "rra\n"))
		rev_rotate(ps, &ps->a, A);
	else if (!ft_strcmp(cmd, "rrb\n"))
		rev_rotate(ps, &ps->b, B);
	else
		return (check_both(ps, cmd));
	return (0);
}

int	check_both(t_ps *ps, char *cmd)
{
	if (!ft_strcmp(cmd, "ss\n"))
	{
		swap(ps, &ps->a, A);
		swap(ps, &ps->b, B);
	}
	else if (!ft_strcmp(cmd, "rr\n"))
	{	
		rotate(ps, &ps->a, A);
		rotate(ps, &ps->b, B);
	}
	else if (!ft_strcmp(cmd, "rrr\n"))
	{
		rev_rotate(ps, &ps->a, A);
		rev_rotate(ps, &ps->b, B);
	}	
	else
		return (1);
	return (0);
}
