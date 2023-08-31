/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:54:26 by ancolmen          #+#    #+#             */
/*   Updated: 2023/03/16 20:29:00 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
This function will clean the map parsing and checking part, 
it will call end_game if needed and exit
*/
void	ft_exit(t_ps *ps, int error)
{
	if (error == ERROR)
	{
		ft_putstr_fd("Error\n", 2);
	}
	if (ps && ps->a.lst)
		ft_lstclear_ps(ps->a.lst);
	if (ps && ps->b.lst)
		ft_lstclear_ps(ps->b.lst);
	if (ps && ps->args)
		ft_free_matrix(ps->args);
	if (ps && ps->cmd)
		ft_lstclear_cmd(ps->cmd);
	exit(0);
}

/*
This will clear the linked list properly
*/
void	ft_lstclear_ps(t_lst *lst)
{
	t_lst	*tmp;

	tmp = NULL;
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}

/*
This will clear the command linked list properly
*/
void	ft_lstclear_cmd(t_list *cmd)
{
	t_list	*tmp;

	tmp = NULL;
	while (cmd)
	{
		tmp = cmd;
		cmd = cmd->next;
		free(tmp);
	}
}
