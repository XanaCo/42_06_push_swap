/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:53:48 by ancolmen          #+#    #+#             */
/*   Updated: 2023/04/05 14:39:01 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
This function will search the POS value of all numbers, transform it into COST 
and stock it in the ps structure. The cost is exactly the value of each number 
position (the number of shots needed to move the index to the top of the list), 
until we reach the middle of the stack, when it will decrease from here to the 
end, in negative value (to choose between rev_rotate or rotate later).
*/
void	get_move_cost(t_ps *ps, t_lst **stack, int id)
{
	t_lst	*tmp;
	int		size;

	tmp = *stack;
	lst_position(&tmp);
	if (id == A)
		size = ps->a.size;
	if (id == B)
		size = ps->b.size;
	while (tmp)
	{
		tmp->cost = tmp->pos;
		if (tmp->pos > size / 2)
			tmp->cost = (tmp->pos - size);
		tmp = tmp->next;
	}
}

/*
This function will take an index and compare it to the target to place it in 
the other stack
*/
int	get_index_cost(t_ps *ps, t_lst *stack, int index)
{
	int	target;

	target = find_target(stack, index);
	if (target >= 0)
	{
		while (stack)
		{
			if (stack->index == target)
				return (stack->cost);
			stack = stack->next;
		}
	}
	return (ps->a.size);
}

/*
This funtion calculates the current range of the stack A and compares the 
current and last index of A with the given B index. It will return the best 
position to place the B index in stack A or -1 to flag the end of the stack
*/
int	find_target(t_lst *stack, int index)
{
	int		min;
	int		max;
	t_lst	*last;
	t_lst	*iter;

	min = index_lowest(stack);
	max = index_highest(stack);
	iter = stack;
	while (iter->next)
		iter = iter->next;
	last = iter;
	if (index > last->index && index < stack->index)
		return (stack->index);
	while (stack && stack->next)
	{
		if (index > stack->index && index < stack->next->index)
			return (stack->next->index);
		else if (index > max || index < min)
			return (min);
		stack = stack->next;
	}
	return (-1);
}

/*
This function finds the cheapest push from B to stack A, in the right position.
It compares each number's cost and keeps the cheaper one
*/
void	cheapest_move(t_ps *ps, t_lst *stack_a, t_lst *stack_b)
{
	int	index_cost_a;
	int	cheapest;
	int	cost_a;
	int	cost_b;

	cheapest = INT_MAX;
	while (stack_b)
	{
		index_cost_a = get_index_cost(ps, stack_a, stack_b->index);
		if (index_cost_a != ps->a.size)
		{
			if ((ft_abs(stack_b->cost)
					+ ft_abs(index_cost_a)) < ft_abs(cheapest))
			{
				cheapest = ft_abs(stack_b->cost) + ft_abs(index_cost_a);
				cost_a = index_cost_a;
				cost_b = stack_b->cost;
			}
		}
		stack_b = stack_b->next;
	}
	move_cheapest(ps, cost_a, cost_b);
}

/*
This function will do the operations needed to push the right number into the 
stack A in its right position
*/
void	move_cheapest(t_ps *ps, int cost_a, int cost_b)
{
	while (cost_a != 0 || cost_b != 0)
	{
		if (cost_a < 0)
		{
			rev_rotate(ps, &ps->a, A);
			cost_a++;
		}
		else if (cost_a > 0)
		{
			rotate(ps, &ps->a, A);
			cost_a--;
		}
		if (cost_b < 0)
		{
			rev_rotate(ps, &ps->b, B);
			cost_b++;
		}
		else if (cost_b > 0)
		{
			rotate(ps, &ps->b, B);
			cost_b--;
		}
	}
	push(ps, A);
}
