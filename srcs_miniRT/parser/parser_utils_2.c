/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:13:27 by gnaida            #+#    #+#             */
/*   Updated: 2022/03/11 18:56:21 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	ft_split_line_len(char **split_line)
{
	int	i;

	i = 0;
	while (split_line && split_line[i])
		i++;
	return (i);
}

void	ft_free_split_line(char **split_line)
{
	int	i;

	if (!split_line)
		return ;
	i = 0;
	while (split_line[i] != NULL)
	{
		free(split_line[i]);
		i++;
	}
	free(split_line);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while ((ss1[i] != '\0') && (ss2[i] != '\0') \
			&& (ss1[i] == ss2[i]) && (n > 0))
	{
		n--;
		if (n == 0)
			return (ss1[i] - ss2[i]);
		i++;
	}
	return (ss1[i] - ss2[i]);
}
