/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 21:41:23 by                   #+#    #+#             */
/*   Updated: 2021/09/17 21:41:23 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*us1;
	unsigned char	*us2;
	size_t			count;

	count = -1;
	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	while (++count < n)
	{
		if (!us1[count] && !us2[count])
			return (0);
		if (us1[count] != us2[count])
			return (us1[count] - us2[count]);
	}
	return (0);
}
