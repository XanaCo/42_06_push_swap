/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_and_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:53:48 by ancolmen          #+#    #+#             */
/*   Updated: 2023/03/17 20:39:38 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
This function will allocate and stock the orders of the program to check them 
and change them afterwards if necessary, in the rrr, rr and ss cases
*/
void	stock_cmd(t_ps *ps, char *cmd)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		ft_exit(ps, ERROR);
	new->content = (void *)cmd;
	new->next = NULL;
	if (!ps->cmd)
		ps->cmd = new;
	else
		ft_lstadd_back(&ps->cmd, new);
}

/*
This function will check calling the check_cmd_join function and change 
the orders in the needed cases or print the existing already stocked
*/
void	print_cmd(t_ps *ps)
{
	t_list	*tmp;

	tmp = ps->cmd;
	while (tmp)
	{
		if (tmp->next && (check_cmd_join((char *)tmp->content,
					(char *)tmp->next->content)))
			tmp = tmp->next;
		else
			ft_printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
}

/*
This functions is called by print_cmd to check the strings at each node 
and change if necessary, printing the change
*/
int	check_cmd_join(char *cmd1, char *cmd2)
{
	if ((!ft_strncmp(cmd1, "ra", 2) && !ft_strncmp(cmd2, "rb", 2))
		|| (!ft_strncmp(cmd1, "rb", 2) && !ft_strncmp(cmd2, "ra", 2)))
	{	
		ft_printf("rr\n");
		return (1);
	}
	else if ((!ft_strncmp(cmd1, "rra", 3) && !ft_strncmp(cmd2, "rrb", 3))
		|| (!ft_strncmp(cmd1, "rrb", 3) && !ft_strncmp(cmd2, "rra", 3)))
	{	
		ft_printf("rrr\n");
		return (1);
	}
	else if ((!ft_strncmp(cmd1, "sa", 2) && !ft_strncmp(cmd2, "sb", 2))
		|| (!ft_strncmp(cmd1, "sb", 2) && !ft_strncmp(cmd2, "sa", 2)))
	{	
		ft_printf("ss\n");
		return (1);
	}
	return (0);
}
