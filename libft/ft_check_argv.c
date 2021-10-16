/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 15:14:44 by antton-t          #+#    #+#             */
/*   Updated: 2021/02/10 10:47:16 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_check_argv(char *str, char *end)
{
  while (*str && *end && *str == *end)
  {
    str++;
    end++;
    if ( *str == '\0' && *end == '\0')
      return (1);
  }
  while (*str != '.' && *str)
    str++;
   while (*str && *end && *str == *end)
  {
    str++;
    end++;
    if ( *str == '\0' && *end == '\0')
      return (1);
  }
  return (0);
}
