/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 21:42:43 by dghazary          #+#    #+#             */
/*   Updated: 2022/10/12 21:42:45 by dghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*ptr;
	char	*ptrstart;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr = malloc(sizeof (char) * len);
	ptrstart = ptr;
	if (!s1 || !s2)
		return (NULL);
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	return (ptrstart);
}
