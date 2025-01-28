/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaraaga <tkaraaga@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:40:47 by tkaraaga          #+#    #+#             */
/*   Updated: 2023/06/20 12:02:55 by tkaraaga         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	temp_checker(char *str, char *temp, void *ptr)
{
	if (temp && temp[0])
	{
		temp_to_str(str, temp);
		if (temp[0] != '\0')
		{
			free(ptr);
			return (1);
		}
		else
		{
			free(temp);
			return (0);
		}
	}
	return (0);
}

char	*reader(char **str, void *ptr, int fd, int *bytes)
{
	int				dmaker;
	char			*temp1;
	int				nl_check;

	*bytes = 1;
	dmaker = -1;
	nl_check = nl_checker(*str);
	temp1 = malloc(BUFFER_SIZE + 1);
	temp1[0] = 0;
	while (*bytes > 0 && dmaker != 1 && nl_check == 0)
	{
		*bytes = read(fd, ptr, BUFFER_SIZE);
		((char *)ptr)[*bytes] = '\0';
		dmaker = copy_func(ptr, *str, temp1);
		if (*bytes == BUFFER_SIZE)
			expander(str);
	}
	free(ptr);
	if (!temp1[0])
	{
		free(temp1);
		return (NULL);
	}
	return (temp1);
}

char	*get_next_line(int fd)
{
	char			*str;
	static char		*temp;
	void			*ptr;
	int				bytes;

	bytes = read(fd, NULL, 0);
	if (bytes == -1)
	{
		free (temp);
		return (temp = NULL);
	}
	ptr = (void *)malloc(BUFFER_SIZE + 1);
	str = (char *)malloc(BUFFER_SIZE + 10);
	str[0] = 0;
	if (temp_checker(str, temp, ptr) == 1)
		return (str);
	temp = reader(&str, ptr, fd, &bytes);
	if (bytes > 0 || str[0])
		return (str);
	free (str);
	return (NULL);
}
