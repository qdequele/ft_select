/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 11:03:23 by qdequele          #+#    #+#             */
/*   Updated: 2015/12/01 13:24:23 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		nbword;
	int		i;

	if (s == NULL)
		return (NULL);
	nbword = ft_wordcount((char const *)s, c);
	tab = (char **)malloc(sizeof(*tab) * nbword + 1);
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (nbword--)
	{
		while (*s == c && *s != '\0')
			s++;
		tab[i] = ft_strsub((const char *)s, 0, ft_wordlen((const char *)s, c));
		if (tab[i] == NULL)
			return (NULL);
		s = s + ft_wordlen((const char *)s, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
