/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_and_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:53:48 by ancolmen          #+#    #+#             */
/*   Updated: 2023/04/06 21:13:51 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
This funtion will allocate and initialize a stack structure, 
and call the stack filling function, which will check also
if everything is correct and there are no problems
*/
void	fill_stack(t_ps *ps)
{
	int	i;
	int	val;
	int	size;

	i = 0;
	size = 0;
	val = 0;
	while (ps->args && ps->args[size])
		size++;
	i = size - 1;
	while (i >= 0)
	{
		if (!ft_atoi_ps(ps->args[i], &val))
			add_to_lst(ps, val);
		else
		{
			ft_exit(ps, ERROR);
			break ;
		}
		i--;
	}
	if (check_doubles(ps))
		ft_exit(ps, ERROR);
}

/*
This function will allocate and initialize a new element and it 
will add it to the front of the list to maintain the args order.
It will save a little time and movements without checking all 
the list at each element addition
*/
void	add_to_lst(t_ps *ps, int val)
{
	t_lst	*new;

	new = (t_lst *)malloc(sizeof(t_lst));
	if (!new)
		ft_exit(ps, ERROR);
	new->num = val;
	new->pos = 0;
	new->index = 0;
	new->next = NULL;
	if (!ps->a.lst)
		ps->a.lst = new;
	else
	{
		new->next = ps->a.lst;
		ps->a.lst = new;
	}
}

/*
This modified atoi will make sure the args follow the exercise rules
*/
int	ft_atoi_ps(const char *nptr, int *val)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (ft_iswspace(nptr[i]))
		i++;
	if (nptr[i] && (nptr[i] == '+' || nptr[i] == '-'))
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] && nptr[i] >= 48 && nptr[i] <= 57)
	{
		result = result * 10 + nptr[i] - 48;
		i++;
	}
	if (result * sign > INT_MAX || result * sign < INT_MIN || nptr[i])
		return (1);
	*val = (int)(result * sign);
	return (0);
}

/*
This funtion will return 1 if there are doubles in the function args
*/
int	check_doubles(t_ps *ps)
{
	t_lst	*tmp;
	t_lst	*iter;

	tmp = ps->a.lst;
	while (tmp)
	{
		iter = tmp->next;
		while (iter)
		{
			if (tmp->num == iter->num)
				return (1);
			iter = iter->next;
		}
		tmp = tmp->next;
	}
	return (0);
}
