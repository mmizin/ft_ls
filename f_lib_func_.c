/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_lib_func_.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 19:35:00 by nmizin            #+#    #+#             */
/*   Updated: 2018/05/25 19:35:00 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*f_sdup(const char *s1)
{
	char			*stwo;
	size_t			len;

	len = 0;
	if (!s1)
		return (0);
	while (s1[len])
	{
		len++;
	}
	stwo = (char *)malloc(sizeof(char) * (len + 1));
	if (stwo == NULL)
		return (NULL);
	len = 0;
	while (s1[len])
	{
		stwo[len] = s1[len];
		len++;
	}
	stwo[len] = '\0';
	return (stwo);
}

int		f_scmp(char *s1, char *s2)
{
	int				i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i])
	{
		if (s1[i] == s2[i])
		{
			i++;
		}
		if (s1[i] != s2[i])
		{
			return (0);
		}
	}
	return (1);
}

char	*f_jo_fr(char *s1, char *s2, int i)
{
	char			*new;
	size_t			sumconcat;
	int				j;
	int				k;

	j = -1;
	k = 0;
	if (!s1 || !s2)
		return (NULL);
	sumconcat = f_slen(s1) + f_slen(s2);
	new = (char *)malloc(sizeof(char) * (sumconcat + 1));
	if (!new)
		return (NULL);
	while (s1[++j])
		new[j] = s1[j];
	while (s2[k])
		new[j++] = s2[k++];
	new[j] = '\0';
	if (i == 1 || i == 3)
		free(s1);
	if (i == 2 || i == 3)
		free(s2);
	return (new);
}

void	f_bzero(void *s, size_t n)
{
	unsigned char	*sone;

	sone = (unsigned char *)s;
	while (n--)
		*sone++ = 0;
}

int		f_slen(const char *s)
{
	unsigned char	*string;
	int				len;

	string = (unsigned char *)s;
	len = 0;
	while (string && *string)
	{
		len++;
		string++;
	}
	return (len);
}
