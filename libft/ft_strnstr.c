/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwong <bwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:58:16 by bwong             #+#    #+#             */
/*   Updated: 2022/07/14 14:58:18 by bwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *substr, size_t len)
{
	unsigned int	str_size;
	unsigned int	substr_size;

	str_size = 0;
	substr_size = 0;
	if (!substr[substr_size])
		return ((char *)str);
	while (str[str_size] && str_size < len)
	{
		substr_size = 0;
		while (substr[substr_size] == str[str_size + substr_size]
			&& str_size + substr_size < len)
		{
			substr_size++;
			if (!substr[substr_size])
				return ((char *)(str + str_size));
		}
		str_size++;
	}
	return (NULL);
}
