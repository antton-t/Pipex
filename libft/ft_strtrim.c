/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 19:59:56 by antton-t          #+#    #+#             */
/*   Updated: 2021/09/23 19:59:57 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		len;
	char	*trim;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	i = 0;
	while (ft_isinstr(s1[i], set))
		i++;
	j = 0;
	if (i != len)
		while (ft_isinstr(s1[len - 1 - j], set))
			j++;
	trim = (char *)malloc(sizeof(char) * (len - i - j + 1));
	if (trim == NULL)
		return (NULL);
	len = len - i - j;
	j = 0;
	while (j < len)
		trim[j++] = s1[i++];
	trim[j] = 0;
	return (trim);
}
