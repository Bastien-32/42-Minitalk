/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_pf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:55:26 by badal-la          #+#    #+#             */
/*   Updated: 2025/01/30 14:07:41 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_pf(unsigned int nb, char *base)
{
	int		i;
	char	c;

	i = 0;
	if (nb >= (unsigned int)ft_strlen_pf(base))
		i += ft_putnbr_base_pf(nb / ft_strlen_pf(base), base);
	c = base[nb % ft_strlen_pf(base)];
	i += write(1, &c, 1);
	return (i);
}
