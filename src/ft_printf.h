/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakatan </var/mail/hnakatan>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:20:22 by hnakatan          #+#    #+#             */
/*   Updated: 2022/08/04 17:32:48 by hnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stdarg.h>
# include<unistd.h>
# include<stdlib.h>
# include<stdint.h>
# include<limits.h>

int	print_char(int	c);
int	print_percent(void);
int	print_upper_hex(unsigned int	num);
int	print_lower_hex(unsigned int	num);
int	print_unsigned_int(unsigned int	num);
int	print_pointer(uintptr_t	num);
int	print_string(char	*s);
int	ft_printf(const char	*s, ...);

#endif
