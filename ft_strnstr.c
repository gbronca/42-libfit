/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcouto-b <gcouto-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 18:41:55 by gcouto-b          #+#    #+#             */
/*   Updated: 2026/10/13 19:24:18 by gcouto-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (!*needle)
		return ((char *)haystack);
	while (len && *haystack)
	{
		i = 0;
		while (i < len && haystack[i] && needle[i] && haystack[i] == needle[i])
			i++;
		if (!needle[i])
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
