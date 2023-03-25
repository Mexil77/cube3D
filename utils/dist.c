/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguttenb <vguttenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:25:25 by vguttenb          #+#    #+#             */
/*   Updated: 2023/03/25 19:01:06 by vguttenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

double	dist(double x_a, double y_a, double x_b, double y_b)
{
	double	x_side;
	double	y_side;
	double	result;

	x_side = x_a - x_b;
	y_side = y_a - y_b;
	result = sqrt(pow(x_side, 2) + pow(y_side, 2));
	return (result);
}
