/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 12:39:42 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/27 15:03:03 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 100

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);

int		gnl_strlen(char *str);
char	*gnl_strjoin(char *str, char *append);
char	*gnl_strdup(char *str);
char	*gnl_strchr(char *str, int c);
void	gnl_free_memory(char **str);

#endif
