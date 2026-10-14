/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcouto-b <gcouto-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 19:01:34 by gcouto-b          #+#    #+#             */
/*   Updated: 2026/10/14 06:53:59 by gcouto-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	words_count(char const *s, char c)
{
	size_t	words;
	size_t	i;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (words);
}

static void	free_array(char **array, size_t filled)
{
	while (filled > 0)
	{
		filled--;
		free(array[filled]);
	}
}

static char	*split_word(char const *s, char c)
{
	size_t	i;
	char	*str;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s, i);
	str[i] = '\0';
	return (str);
}

static int	fill_array(char **array, char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			array[j] = split_word(s + i, c);
			if (!array[j])
			{
				free_array(array, j);
				return (0);
			}
			i += ft_strlen(array[j]);
			j++;
		}
	}
	array[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (!s)
		return (NULL);
	array = malloc(sizeof(char *) * (words_count(s, c) + 1));
	if (!array)
		return (NULL);
	if (!fill_array(array, s, c))
	{
		free(array);
		return (NULL);
	}
	return (array);
}
