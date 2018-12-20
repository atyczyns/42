/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyczyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 10:27:34 by atyczyns          #+#    #+#             */
/*   Updated: 2018/12/20 10:45:37 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static char	*ft_rostring(char *str, int i, int j)
{
	while (str[i] == ' ' && str[i] && str[i] == '\t')
		++i;
	while (str[j])
		++j;
	str[j] = ' ';
	++j;
	str[j] = '\0';
	while (str[i] != ' ' && str[i] != '\t' && str[i])
	{
		str[j] = str[i];
		str[j + 1] = '\0';
		str[i] = ' ';
		++i;
		++j;
	}
	return (str);
}

static char	*ft_epurate(char *str, int i, int j, char *rep)
{
	while ((str[i] == ' ' || str[i] == '\t') && str[i])
		++i;
	while ((str[i] != ' ' || str[i] != '\t') && str[i])
	{
		rep[j] = str[i];
		++i;
		++j;
	}
	if (str[i] != '\0')
	{
		rep[j] = ' ';
		++j;
		ft_epurate(str + i, 0, j, rep);
	}
	else
		rep[j] = '\0';
	return (rep);
}

static int	ft_compt(char *str, int compt, int i)
{
	while (str[i] == ' ' && str[i] && str[i] == '\t')
		++i;
	if (str[i] != '\0')
		++compt;
	while ((str[i] != ' ' || str[i] != '\t') && str[i])
	{
		++compt;
		++i;
	}
	if (str[i] != '\0')
		ft_compt(str, compt, i);
	return (compt);
}

int			main(int argc, char **argv)
{
	char	*rep;
	int		i;

	i = -1;
	if (argc < 2)
	{
		ft_putchar('\n');
		return (0);
	}
	rep = (char *)malloc(sizeof(char) * ft_compt(argv[1], 0, 0) + 1);
	rep[ft_compt(argv[1], 0, 0) + 1] = '\0';
	rep = ft_epurate(ft_rostring(argv[1], 0, 0), 0, 0, rep);
	while (rep[++i])
		ft_putchar(rep[i]);
	ft_putchar('\n');
	return (0);
}
