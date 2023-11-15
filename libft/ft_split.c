/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:05:35 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/14 09:34:54 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static	size_t	count_words(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || !*(s +1)))
			i++;
		s++;
	}
	return (i);
}

static	char	const	*find_next_sep(char const *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (s);
}

static	char	**free_split(char **split_s, size_t nbr_of_alloc)
{
	size_t	i;

	i = 0;
	while (i < nbr_of_alloc)
		free(split_s[i++]);
	free(split_s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		cw;
	char const	*next;
	char		**split_s;

	if (!s)
		return (NULL);
	i = -1;
	cw = count_words(s, c);
	split_s = ft_calloc(cw + 1, sizeof(char *));
	if (!split_s)
		return (NULL);
	while (++i < cw)
	{
		while (*s == c)
			s++;
		next = find_next_sep(s, c);
		split_s[i] = ft_substr(s, 0, (next - s));
		if (!split_s[i])
			return (free_split(split_s, i));
		s = next + 1;
	}
	split_s[i] = NULL;
	return (split_s);
}
