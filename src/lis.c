/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:53:48 by ancolmen          #+#    #+#             */
/*   Updated: 2023/03/24 17:27:02 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
Longest Increasing Subsequence (LIS). 
These group of functions will count, check and mark the longest increasing 
subsequence of numbers in the A pile. 
lis function will stock the correct lenght it in each number calling the 
function lis_check, and preparing the linked list for the flag function.
*/
void	lis(t_ps *ps, t_lst *stack)
{
	t_lst	*iter;
	int		max_lis;

	iter = stack->next;
	while (iter)
	{
		max_lis = lis_check(ps, stack, iter);
		stack->f_lis = max_lis;
		iter->f_lis = stack->f_lis;
		stack = iter;
		iter = iter->next;
	}
}

/*
lis_check will send the LIS lenght or zero, depending on the previous lenght 
stored : if the new number is bigger, this means a bigger LIS was found and 
it should be the one we keep.
*/
int	lis_check(t_ps *ps, t_lst *actual, t_lst *iter)
{
	int	lis;

	lis = 1;
	while (iter)
	{
		if (actual->index == iter->index - 1)
		{
			lis++;
			actual = iter;
		}
		iter = iter->next;
	}
	if (lis > ps->a.lis_count)
	{
		ps->a.lis_count = lis;
		return (lis);
	}
	return (0);
}

/*
lis_flag will find the first number with the maximum LIS stored and starts 
flagging, cleaning the other numbers if necessary
*/
void	lis_flag(t_ps *ps, t_lst *stack)
{
	t_lst	*iter;

	iter = stack->next;
	while (stack)
	{
		if (stack->f_lis == ps->a.lis_count)
		{
			while (iter)
			{
				if (stack->index == iter->index - 1)
				{
					stack->f_lis = ps->a.lis_count;
					iter->f_lis = stack->f_lis;
					stack = iter;
				}
				iter = iter->next;
			}
		}
		else
			stack->f_lis = 0;
		stack = stack->next;
	}
}
