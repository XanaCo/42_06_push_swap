/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:13:28 by anana             #+#    #+#             */
/*   Updated: 2023/04/06 18:57:11 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
/* 
	OBJECTIVES
	
	3 numbers 					--> less than 3 moves
	5 numbers 					--> less than 12 moves
	100 numbers :
    	less than 700 moves		--> 5 points
    	less than 900 moves		--> 4 points
    	less than 1100 moves	--> 3 points
    	less than 1300 moves	--> 2 points
    	less than 1500 moves	--> 1 point
	500 numbers :
    	less than 5500 moves	--> 5 points
        less than 7000 moves	--> 4 points
        less than 8500 moves	--> 3 points
        less than 10000 moves	--> 2 points
        less than 11500 moves	--> 1 point
*/
int	main(int argc, char **argv)
{
	int		i;
	t_ps	ps;

	i = argc - 1;
	if (i < 1)
		return (0);
	ft_bzero(&ps, sizeof(ps));
	while (i > 0)
	{
		ps.args = ft_split(argv[i], ' ');
		if (!ps.args)
			ft_exit(&ps, ERROR);
		fill_stack(&ps);
		ft_free_matrix(ps.args);
		ps.args = NULL;
		i--;
	}
	if (ps.a.lst)
		start_program(&ps);
	print_cmd(&ps);
	ft_exit(&ps, NO_ERROR);
	return (0);
}
