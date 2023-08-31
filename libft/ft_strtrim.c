/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:03:14 by ancolmen          #+#    #+#             */
/*   Updated: 2022/11/24 14:54:07 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	index_start(const char *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		if (ft_strchr(set, s1[i]) == 0)
			return (i);
		i++;
	}	
	return (0);
}

static size_t	index_end(const char *s1, char const *set)
{
	size_t	i;

	i = ft_strlen(s1) - 1;
	while (i > 0)
	{
		if (ft_strchr(set, s1[i]) == 0)
			return (i);
		i--;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s3;
	size_t	start;
	size_t	end;
	size_t	i;

	i = 0;
	if (!s1)
		return (NULL);
	start = index_start(s1, set);
	end = index_end(s1, set);
	if (end == 0 && start == 0)
		s3 = (char *)ft_calloc((end - start) + 1, sizeof(char));
	else
		s3 = (char *)ft_calloc((end - start) + 2, sizeof(char));
	if (!s3)
		return (NULL);
	while (i < (end - start + 1) && !(end == 0 && start == 0))
	{
		s3[i] = s1[start + i];
		i++;
	}
	return (s3);
}
