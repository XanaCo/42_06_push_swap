/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:38:57 by ancolmen          #+#    #+#             */
/*   Updated: 2023/03/16 20:20:07 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
All linked list ps versions of libft functions, some a bit changed 
for better performances. This function will return the current stack size.
*/
int	ft_lstsize_ps(t_lst *lst)
{
	int		size;
	t_lst	*tmp;

	size = 0;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}

/*
Adds a node to the front of the list
*/
void	ft_lstadd_front_ps(t_lst **lst, t_lst *new)
{
	if (!*lst)
		*lst = new;
	else
	{
		new->next = *lst;
		*lst = new;
	}
}

/*
Adds a node to the back of the list
*/
void	ft_lstadd_back_ps(t_lst **lst, t_lst *new)
{
	t_lst	*tmp;

	if (!*lst)
		*lst = new;
	else
	{
		tmp = ft_lstlast_ps(*lst);
		tmp->next = new;
	}
}

/*
Finds and returns the last node of the list
*/
t_lst	*ft_lstlast_ps(t_lst *lst)
{
	t_lst	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
	return (tmp);
}
