/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:04:53 by gduval            #+#    #+#             */
/*   Updated: 2016/11/14 16:32:33 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_isdigit(int c)
{
	if (!c)
		return (0);
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}
