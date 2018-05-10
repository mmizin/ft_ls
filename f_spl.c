/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_split.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 19:34:00 by nmizin            #+#    #+#             */
/*   Updated: 2018/05/03 19:34:00 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int f_size(char *str) {
	int c;

	c = 0;
	while (*str)
	{
		while ((*str == ' ' || *str == '\t' || *str == '\n') && *str)
			str++;
		if ((*str != ' ' || *str != '\t' || *str != '\n') && *str)
		{
			while ((*str != ' ' && *str != '\t' && *str != '\n') && *str)
				str++;
			c++;
		}
	}
	return (c);
}

static int f_letter(char *str)
{
	int c;

	c = 0;
	while ((*str == ' ' || *str == '\t' || *str == '\n') && *str)
		str++;
	while ((*str != ' ' && *str != '\t' && *str != '\n') && *str)
	{
		c++;
		str++;
	}
	return (c);
}

char    **f_spl(char *str)
{
	int i;
	int j;
	int letter;
	int word;
	char **new;

	i = 0;
	word = f_size(str);
	new = (char **)malloc(sizeof(char *) * (word + 1));
	new[word] = NULL;
	while (word--)
	{
		while (*str && (*str == ' ' || *str == '\t' || *str == '\n'))
			str++;
		letter = f_letter(str);
		j = 0;
		new[i] = (char *)malloc(sizeof(char) * (letter + 1));
		new[i][letter] = '\0';
		while (letter--)
		{
			new[i][j++] = *str++;
		}
		i++;
	}
	return (new);
}