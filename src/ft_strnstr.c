/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 21:42:59 by dghazary          #+#    #+#             */
/*   Updated: 2022/10/12 21:43:02 by dghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n > 1 && ((unsigned char)*s1 == (unsigned char)*s2) && *s1)
	{
		n--;
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	int		length;
	char	*large;
	char	*small;

	if (*s2 == '\0')
		return ((char *)s1);
	large = (char *)s1;
	small = (char *)s2;
	i = 0;
	length = ft_strlen(small);
	while (large[i] != '\0' && (i + length) <= len)
	{
		if (ft_strncmp((large + i), small, length) == 0)
			return (large + i);
		i++;
	}
	return (NULL);
}
