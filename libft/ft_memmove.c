/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 21:40:37 by                   #+#    #+#             */
/*   Updated: 2021/09/17 21:40:37 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*udest;
	unsigned char	*usrc;
	size_t			i;

	if (dest == NULL && src == NULL)
		return (NULL);
	udest = (unsigned char *)dest;
	usrc = (unsigned char *)src;
	i = 0;
	if (udest > usrc)
		while (n--)
			udest[n] = usrc[n];
	else
	{
		while (i < n)
		{
			udest[i] = usrc[i];
			i++;
		}
	}
	return (dest);
}
