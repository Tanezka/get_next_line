/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaraaga <tkaraaga@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:41:39 by tkaraaga          #+#    #+#             */
/*   Updated: 2023/06/20 12:07:01 by tkaraaga         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <stdlib.h>
# include <unistd.h>

void	temp_to_str(char *str, char *temp);

int		copy_func(void *ptr, char *str, char *temp);

void	expander(char **str);

int		nl_checker(char *str);

char	*get_next_line(int fd);

#endif
