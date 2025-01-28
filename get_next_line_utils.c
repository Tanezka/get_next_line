/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaraaga <tkaraaga@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:00:12 by tkaraaga          #+#    #+#             */
/*   Updated: 2023/06/20 12:06:38 by tkaraaga         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str);

int	copy_func(void *ptr, char *str, char *temp)
{
	int	i;
	int	k;
	int	j;

	k = 0;
	j = 0;
	i = 0;
	while (str[i] != 0)
		i++;
	while (((char *)ptr)[k])
	{
		str[i] = ((char *)(ptr))[k++];
		if (str[i++] == '\n')
		{
			str[i] = '\0';
			while (((char *)ptr)[k])
			{
				temp[j++] = ((char *)ptr)[k++];
			}
			temp[j] = '\0';
			return (1);
		}
	}
	str[i] = '\0';
	return (0);
}

void	expander(char **str)
{
	char		*pholder;
	int			i;
	int			len;

	i = 0;
	len = ft_strlen(*str) + BUFFER_SIZE + 2;
	pholder = malloc(len);
	while ((*str)[i])
	{
		pholder[i] = (*str)[i];
		(*str)[i] = 0;
		i++;
	}
	pholder[i] = 0;
	free (*str);
	*str = malloc(len);
	i = 0;
	while (pholder[i])
	{
		(*str)[i] = pholder[i];
		pholder[i] = 0;
		i++;
	}
	(*str)[i] = 0;
	free (pholder);
}

void	temp_to_str(char *str, char *temp)
{
	int (i) = 0;
	int (k) = 0;
	while (temp[k] && temp[k] != '\n')
	{
		str[i++] = temp[k];
		temp[k++] = '\0';
	}
	str[i] = '\0';
	if (temp[k++] == '\n')
	{
		str[i++] = '\n';
		temp[k - 1] = 0;
		str[i] = '\0';
		if (k == 1 && temp[k] == '\0')
		{
			temp[0] = '\0';
			return ;
		}
		i = 0;
		while (temp[k])
		{
			temp[i++] = temp[k];
			temp[k++] = '\0';
		}
	}
}

int	nl_checker(char *str)
{
	int	i;
	int	len;

	i = 0;
	if (str == NULL)
		return (0);
	len = ft_strlen(str);
	while (i <= len)
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
