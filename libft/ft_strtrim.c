/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:58:00 by bwong             #+#    #+#             */
/*   Updated: 2022/07/14 14:59:20 by bwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	beg;
	size_t	end;
	size_t	i;

	if (!s1)
		return (0);
	i = 0;
	beg = 0;
	end = ft_strlen(s1) - 1;
	while (s1[i] && ft_strchr(set, s1[i]))
		beg = (i++) + 1;
	if (beg >= ft_strlen(s1))
		return ((char *)ft_calloc(sizeof(char), 1));
	i = ft_strlen(s1) - 1;
	while (i && s1[i] && ft_strchr(set, s1[i]))
		end = (i--) - 1;
	return (ft_substr(s1, beg, (end - beg + 1)));
}
