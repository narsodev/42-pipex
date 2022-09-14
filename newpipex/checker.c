/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narso </var/spool/mail/narso>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:19:14 by narso             #+#    #+#             */
/*   Updated: 2022/08/30 14:37:16 by narso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_check_args(int argc)
{
	if (argc != 5) {
		ft_printf("Error: five args required\n");
		exit(EXIT_FAILURE);
	}
}
