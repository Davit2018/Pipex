/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 21:42:20 by dghazary          #+#    #+#             */
/*   Updated: 2022/10/12 21:42:22 by dghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_start(char const *s, char c)
{
	size_t	index;

	index = 0;
	while (*s == c && *s)
	{
		++s;
		++index;
	}
	return (index);
}

size_t	word_len(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != c && *s)
	{
		++len;
		++s;
	}
	return (len);
}

int	ft_counter(const char *s, char c)
{
	int	count;
	int	word;

	count = 0;
	word = 0;
	while (*s)
	{
		if (*s != c && !word)
		{
			++count;
			word = 1;
		}
		else if (*s == c)
			word = 0;
		s++;
	}
	return (count);
}

char	**ft_free(char	**ptr, size_t count)
{
	while (count >= 0)
	{
		free(ptr[count]);
		count--;
	}
	free (ptr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**string;
	size_t	wordscount;
	size_t	curr_start;
	size_t	curr_len;
	size_t	i;

	i = 0;
	wordscount = ft_counter(s, c);
	string = (char **)malloc((wordscount + 1) * sizeof(char *));
	if (!string)
		return (NULL);
	while (i < wordscount)
	{
	curr_start = ft_start(s, c);
	curr_len = word_len(s + curr_start, c);
	string[i] = ft_substr(s, curr_start, curr_len);
		if (string[i] == NULL)
			return (ft_free(string, (i -1)));
	s = s + curr_len + curr_start;
	++i;
	}
	string[i] = (NULL);
	return (string);
}
