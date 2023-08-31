/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:53:48 by ancolmen          #+#    #+#             */
/*   Updated: 2023/03/22 19:17:53 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
This function launches the center of the program, and calls the different 
operations needed. It measures the A stack, gives it indexes and positions, 
checks if it is sorted and launches the sorting algorithms
*/
void	start_program(t_ps *ps)
{
	ps->a.size = ft_lstsize_ps(ps->a.lst);
	if (lst_is_sorted(ps->a.lst))
		return ;
	else
	{
		lst_index(ps->a.lst);
		lst_position(&ps->a.lst);
		if (ps->a.size == 2)
			swap(ps, &ps->a, A);
		else if (ps->a.size == 3)
			sort_3(ps);
		else if (ps->a.size > 3 && ps->a.size <= 5)
			sort_5(ps);
		else
			sort(ps);
	}
}

/*
This function checks if the list is already sorted
*/
int	lst_is_sorted(t_lst *lst)
{
	while (lst && lst->next)
	{
		if (lst->num < lst->next->num)
			lst = lst->next;
		else
			return (0);
	}
	return (1);
}

/*
This function stocks the index (wanted final position) for each number
*/
void	lst_index(t_lst *lst)
{
	t_lst	*tmp;
	t_lst	*iter;

	tmp = lst;
	iter = lst;
	while (lst)
	{
		tmp = iter;
		while (tmp)
		{
			if (lst->num > tmp->num)
				lst->index += 1;
			tmp = tmp->next;
		}
		lst = lst->next;
	}
}

/*
This function stocks the current position in the stack for each number
*/
void	lst_position(t_lst **lst)
{
	int		i;
	t_lst	*iter;

	i = 0;
	iter = *lst;
	while (iter)
	{
		iter->pos = i;
		iter = iter->next;
		i++;
	}
}
