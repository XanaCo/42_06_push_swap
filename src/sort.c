/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:53:48 by ancolmen          #+#    #+#             */
/*   Updated: 2023/04/05 14:32:31 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
This function will sort three numbers directly contemplating the 
few posible order cases 
*/
void	sort_3(t_ps	*ps)
{
	int	highest;

	highest = index_highest(ps->a.lst);
	if (ps->a.lst->index == highest)
		rotate(ps, &ps->a, A);
	else if (ps->a.lst->next->index == highest)
		rev_rotate(ps, &ps->a, A);
	if (ps->a.lst->index > ps->a.lst->next->index)
		swap(ps, &ps->a, A);
}

/*
This function will push the two smallest numbers into B, use sort_3 on A 
and then repush to A from B
*/
void	sort_5(t_ps	*ps)
{
	while (ps->a.size > 3)
	{
		if (ps->a.lst->index < 2)
			push(ps, B);
		else
			rotate(ps, &ps->a, A);
	}
	sort_3(ps);
	if (lst_is_sorted(ps->b.lst))
		swap(ps, &ps->b, B);
	while (ps->b.lst)
		push(ps, A);
}

/*
This function is the heart of the program. It will sort the big lists. 
It will use LIS, flag its numbers, then pre-sort them by chunks and 
aply all the cost algorithms and such. At the end, the list should be sorted
*/
void	sort(t_ps	*ps)
{
	lis(ps, ps->a.lst);
	lis_flag(ps, ps->a.lst);
	chunk_sort(ps, &ps->a.lst);
	while (ps->b.lst)
	{
		stacks_size(ps);
		get_move_cost(ps, &ps->a.lst, A);
		get_move_cost(ps, &ps->b.lst, B);
		cheapest_move(ps, ps->a.lst, ps->b.lst);
	}
	lst_position(&ps->a.lst);
	while (!lst_is_sorted(ps->a.lst)
		&& ps->a.lst->index != index_lowest(ps->a.lst))
	{
		if (first_index(ps->a.lst) < ps->a.size / 2)
			rotate(ps, &ps->a, A);
		else
			rev_rotate(ps, &ps->a, A);
	}
}

/*
This function is a pre-sort algorithm, it will calculate chunks depending on 
the total size of numbers in the list and will push them from the center 
to the extremes (size / 2 up and down by chunks)
*/
void	chunk_sort(t_ps *ps, t_lst **stack)
{
	int	i;
	int	num;
	int	size;

	calculate_chunk(ps, &num, &i);
	while (i >= 0)
	{
		size = ps->a.size;
		while (size--)
		{
			if (!(*stack)->f_lis && ((*stack)->index < (num - i + 1) * ps->chunk
					&& (*stack)->index >= (num - i) * ps->chunk))
				push(ps, B);
			else if (!(*stack)->f_lis && ((*stack)->index < (i + 1) * ps->chunk
					&& (*stack)->index >= i * ps->chunk))
			{
				push(ps, B);
				rotate(ps, &ps->b, B);
			}
			else
				rotate(ps, &ps->a, A);
		}
		i--;
	}
}
