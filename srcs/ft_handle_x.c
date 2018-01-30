/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <nbrucker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 19:25:43 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/02 19:25:43 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_xlen(t_pf *ft, uintmax_t nbr)
{
	int x;

	x = ft_baselen_precision(ft, nbr, 16);
	if (nbr == 0 && ft->precision == 0 && ft->point == 1)
		return (0);
	if (nbr == 0 && ft->hash == 1)
		return (1);
	if (nbr != 0 && ft->hash == 1)
		return (x + 2);
	if (ft->hash == 0)
		return (ft_baselen_precision(ft, nbr, 16));
	if (ft->hash == 1)
		return (ft_baselen_precision(ft, nbr, 16) + 2);
	return (x);
}

void	ft_handle_ux(t_pf *ft, va_list *ag)
{
	uintmax_t nbr;

	nbr = ft_get_uint(ft, ag);
	ft_remove_zero(ft);
	ft_handle_width_left(ft, ft_get_xlen(ft, nbr));
	if (ft->hash == 1 && nbr != 0)
		ft_putstr_pf(ft, "0X", 2);
	ft_handle_zero(ft, ft_get_xlen(ft, nbr));
	ft_putbase(ft, nbr, "0123456789ABCDEF");
	ft_handle_width_right(ft, ft_get_xlen(ft, nbr));
	ft->ready = ft->index;
}

void	ft_handle_x(t_pf *ft, va_list *ag)
{
	uintmax_t nbr;

	nbr = ft_get_uint(ft, ag);
	ft_remove_zero(ft);
	ft_handle_width_left(ft, ft_get_xlen(ft, nbr));
	if (ft->hash == 1 && nbr != 0)
		ft_putstr_pf(ft, "0x", 2);
	ft_handle_zero(ft, ft_get_xlen(ft, nbr));
	ft_putbase(ft, nbr, "0123456789abcdef");
	ft_handle_width_right(ft, ft_get_xlen(ft, nbr));
	ft->ready = ft->index;
}
