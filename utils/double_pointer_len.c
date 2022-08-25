/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_pointer_len.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:32:05 by emgarcia          #+#    #+#             */
/*   Updated: 2022/08/25 16:36:09 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

size_t	double_pointer_len(char **double_pointer)
{
	size_t	len;

	if (!double_pointer)
		return (0);
	len = 0;
	while (double_pointer[len])
		len++;
	return (len);
}
