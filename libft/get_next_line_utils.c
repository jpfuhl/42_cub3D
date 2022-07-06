/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 12:50:11 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/10/15 12:36:57 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		index++;
	}
	return (index);
}

char	*gnl_strjoin(char *str, char *append)
{
	char	*join;
	int		len;
	int		i;
	int		j;

	len = gnl_strlen(str) + gnl_strlen(append);
	join = malloc((len + 1) * sizeof(char));
	if (!join)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		join[i] = str[i];
		i++;
	}
	while (append[j] != '\0')
	{
		join[i + j] = append[j];
		j++;
	}
	join[i + j] = '\0';
	gnl_free_memory(&str);
	return (join);
}

char	*gnl_strdup(char *str)
{
	char	*dup;
	int		len;
	int		index;

	len = gnl_strlen(str);
	dup = malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	index = 0;
	while (str[index] != '\0')
	{
		dup[index] = str[index];
		index++;
	}
	dup[index] = '\0';
	return (dup);
}

char	*gnl_strchr(char *str, int c)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == c)
			break ;
		index++;
	}
	if (str[index] == c)
		return (&str[index]);
	return (NULL);
}

void	gnl_free_memory(char **str)
{
	free(*str);
	*str = NULL;
}
