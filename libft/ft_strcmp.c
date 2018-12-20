/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyczyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:59:59 by atyczyns          #+#    #+#             */
/*   Updated: 2018/11/15 19:20:06 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int		i;
	int		result;

	i = 0;
	while ((int)s1[i] != 0 && (int)s2[i] != 0 && (int)s1[i] == (int)s2[i])
		i++;
	result = ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i];
	return (result);
}
