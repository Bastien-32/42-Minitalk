/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:34:28 by badal-la          #+#    #+#             */
/*   Updated: 2025/01/30 17:38:45 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

char	*malloc_buffer(char **buffer, int *i);
void	print_buffer(char **buffer, int *i);
void	fill_buffer(char c, char *buffer, int *i);

#endif