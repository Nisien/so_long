/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_extension.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossa <nrossa@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 02:05:25 by nrossa            #+#    #+#             */
/*   Updated: 2023/10/27 05:57:05 by nrossa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_management.h"

char	*ft_end_of_string(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
		i++;
	return (str + i - 1);
}

int	ft_check_extension(char *str)
{
	char	*str_end;

	if (!str)
		return (KO);
	if (ft_strlen(str) < 4)
		return (KO);
	str_end = ft_end_of_string(str);
	if (*(str_end - 3) == '.' && *(str_end - 2) == 'b'
		&& *(str_end - 1) == 'e' && *str_end == 'r')
		return (OK);
	else
		return (KO);
}
