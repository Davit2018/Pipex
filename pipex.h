/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 21:46:13 by dghazary          #+#    #+#             */
/*   Updated: 2022/10/12 21:47:08 by dghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include <stddef.h>

int		main(int argc, char **argv, char **envp);
char	*get_path(char *cmd, char **envp);
void	go_out(void);
char	**ft_split(char const *s, char c);
size_t	ft_start(char const *s, char c);
size_t	word_len(const char *s, char c);
int		ft_counter(const char *s, char c);
char	**ft_free(char	**ptr, size_t count);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *s1, const char *s2, size_t len);
size_t	ft_strlen(const char *s);
void	split_free(char **str);

#endif
