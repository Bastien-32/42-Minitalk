/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:20:54 by badal-la          #+#    #+#             */
/*   Updated: 2025/01/31 17:05:15 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_realloc(char *old_str, int new_size)
{
	char	*new_str;
	int		i;

	new_str = malloc(sizeof(char) * new_size);
	if (!new_str)
	{
		free(old_str);
		return (NULL);
	}
	ft_memset(new_str, 0, new_size);
	i = 0;
	if (old_str)
	{
		while (i < (int)ft_strlen(old_str) && i < new_size - 1)
		{
			new_str[i] = old_str[i];
			i++;
		}
		free(old_str);
	}
	return (new_str);
}

char	*malloc_buffer(char **buffer, int *i)
{
	static int	buffer_size = 10000;
	char		*new_buffer;

	if (!*buffer)
	{
		*buffer = malloc(buffer_size * sizeof(char));
		if (!*buffer)
			exit (1);
		ft_memset(*buffer, 0, buffer_size);
		*i = 0;
	}
	if (*i >= buffer_size - 1)
	{
		buffer_size *= 2;
		new_buffer = ft_realloc(*buffer, buffer_size * sizeof(char));
		if (!new_buffer)
		{
			free(*buffer);
			exit(1);
		}
		*buffer = new_buffer;
	}
	return (*buffer);
}

void	fill_buffer(char c, char *buffer, int *i)
{
	buffer[*i] = c;
	(*i)++;
	buffer[*i] = '\0';
}

void	print_buffer(char **buffer, int *i)
{
	ft_printf("Received message : %s\n", *buffer);
	*i = 0;
	free(*buffer);
	*buffer = NULL;
}
