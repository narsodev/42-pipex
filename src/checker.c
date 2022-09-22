/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narso </var/spool/mail/narso>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:19:14 by narso             #+#    #+#             */
/*   Updated: 2022/09/19 21:11:54 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_check_args(int argc)
{
	if (argc != 5)
	{
		ft_printf("Error: four args required\n");
		exit(EXIT_FAILURE);
	}
}
