/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_super_sort_.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 19:37:00 by nmizin            #+#    #+#             */
/*   Updated: 2018/05/24 19:37:00 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_ls.h"

static int	f_check_(int arr[], int size)
{
	int i;
	int *ptr1;
	int *ptr2;
	int res;
	int tmp;

	i = 0;
	res = 1;
	ptr1 = arr;
	ptr2 = arr + 1;
	while (i < size)
	{
		if (*ptr1 > *ptr2)
		{
			res = 0;
			tmp = *ptr1;
			*ptr1 = *ptr2;
			*ptr2 = tmp;
		}
		ptr1++;
		ptr2++;
		i++;
	}
	return (res);
}

void sort_(int arr[], int size)
{
	int mid;
	int *ptr1;
	int *ptr2;
	int i;
	int tmp;

	if (f_check_(arr, size))
		return ;
	else
	{
		i = 0;
		mid = size/ 2;
		ptr1 = arr + 0;
		ptr2 = arr + (size - 1);
		while (i <= mid)
		{
			if (*ptr1 > *ptr2)
			{
				tmp = *ptr1;
				*ptr1 = *ptr2;
				*ptr2 = tmp;
				if (*ptr1 > *(ptr1 + 1))
				{
					tmp = *ptr1;
					*ptr1 = *(ptr1 + 1);
					*(ptr1 + 1) = tmp;
				}
				if (*ptr2 < *(ptr2 - 1))
				{
					tmp = *(ptr2 - 1);
					*(ptr2 - 1) = *ptr2;
					*ptr2 = tmp;
				}
			}
			if (i == mid)
			{
				if (*ptr1 < *(ptr1 -1))
				{
					tmp = *(ptr1 - 1);
					*(ptr1 - 1) = *ptr1;
					*ptr1 = tmp;
				}
			}
			i++;
			ptr1++;
			ptr2--;
		}
		sort_(arr, size);
	}
}

