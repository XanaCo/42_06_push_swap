/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:53:48 by ancolmen          #+#    #+#             */
/*   Updated: 2023/04/06 16:25:17 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
This will push the first number of the stack into the other stack
*/
void	push(t_ps *ps, int id)
{
	t_lst	*move;

	if (id == A)
	{
		if (!ps->b.lst)
			return ;
		move = ps->b.lst;
		ps->b.lst = ps->b.lst->next;
		move->next = NULL;
		ft_lstadd_front_ps(&ps->a.lst, move);
		stock_cmd(ps, "pa");
	}
	if (id == B)
	{
		if (!ps->a.lst)
			return ;
		move = ps->a.lst;
		ps->a.lst = ps->a.lst->next;
		move->next = NULL;
		ft_lstadd_front_ps(&ps->b.lst, move);
		stock_cmd(ps, "pb");
	}
	stacks_size(ps);
}

/*
This will swap the first and second numbers of the stack
*/
void	swap(t_ps *ps, t_stack	*stack, int id)
{
	t_lst	*first;
	t_lst	*second;

	if (!stack->lst)
		return ;
	first = stack->lst;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->lst = second;
	if (id == A)
		stock_cmd(ps, "sa");
	if (id == B)
		stock_cmd(ps, "sb");
}

/*
This will move the first number of the stack to the last position
*/
void	rotate(t_ps *ps, t_stack *stack, int id)
{
	t_lst	*first;

	if (!stack->lst)
		return ;
	first = stack->lst;
	stack->lst = first->next;
	first->next = NULL;
	ft_lstadd_back_ps(&stack->lst, first);
	if (id == A)
		stock_cmd(ps, "ra");
	if (id == B)
		stock_cmd(ps, "rb");
}

/*
This will move the last number of the stack into the first position 
*/
void	rev_rotate(t_ps *ps, t_stack *stack, int id)
{
	t_lst	*last_block;
	t_lst	*tmp;
	int		lst_size;
	int		i;

	if (!stack->lst)
		return ;
	lst_size = ft_lstsize_ps(stack->lst) - 1;
	last_block = ft_lstlast_ps(stack->lst);
	last_block->next = stack->lst;
	stack->lst = last_block;
	tmp = stack->lst;
	i = 0;
	while (i++ < lst_size)
		tmp = tmp->next;
	tmp->next = NULL;
	if (id == A)
		stock_cmd(ps, "rra");
	if (id == B)
		stock_cmd(ps, "rrb");
}
