/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:53:48 by ancolmen          #+#    #+#             */
/*   Updated: 2023/04/06 16:27:05 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
Returns the lowest index inside the stack
*/
int	index_lowest(t_lst *lst)
{
	int	index;

	index = lst->index;
	while (lst)
	{
		if (lst->index < index)
			index = lst->index;
		lst = lst->next;
	}
	return (index);
}

/*
Returns the highest index inside the stack
*/
int	index_highest(t_lst *lst)
{
	int	index;

	index = lst->index;
	while (lst)
	{
		if (lst->index > index)
			index = lst->index;
		lst = lst->next;
	}
	return (index);
}

/*
Calculates both stacks' size at the same time
*/
void	stacks_size(t_ps *ps)
{
	ps->a.size = ft_lstsize_ps(ps->a.lst);
	ps->b.size = ft_lstsize_ps(ps->b.lst);
}

/*
Returns the first index in the stack
*/
int	first_index(t_lst *lst)
{
	while (lst)
	{
		if (!lst->index)
			return (lst->pos);
		lst = lst->next;
	}
	return (0);
}

/*
Calculates the size of the chunks to sort
*/
void	calculate_chunk(t_ps *ps, int *num, int *i)
{
	if (ps->a.size > 100)
		ps->chunk = C_50;
	else
		ps->chunk = C_20;
	*num = ps->a.size / ps->chunk;
	*i = *num / 2;
}

// void	help_print_indices(t_ps *ps) //
// {
// 	t_lst	*a;
// 	t_lst	*b;

// 	a = ps->a.lst;
// 	printf(">>>>>this is A\n");
// 	while (a)
// 	{
// 		ft_printf("NUM : %d // INDEX : %d // POS : %d// LIS flag : %d 
// COST : %d\n", a->num, a->index, a->pos, a->f_lis, a->cost);
// 		a = a->next;
// 	}
// 	b = ps->b.lst;
// 	printf(">>>>>this is B\n");
// 	while (b)
// 	{
// 		ft_printf("NUM : %d // INDEX : %d // POS : %d // LIS flag : %d 
// COST : %d\n", b->num, b->index, b->pos, b->f_lis, b->cost);
// 		b = b->next;
// 	}
// }
