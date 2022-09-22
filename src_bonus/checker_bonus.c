/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narso </var/spool/mail/narso>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:19:14 by narso             #+#    #+#             */
/*   Updated: 2022/09/22 20:17:48 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_check_args(int argc)
{
	if (argc < 5)
	{
		ft_printf("Error: minimum four args required\n");
		exit(EXIT_FAILURE);
	}
}
