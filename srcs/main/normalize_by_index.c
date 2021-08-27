/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_by_index.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 11:16:13 by lcouto            #+#    #+#             */
/*   Updated: 2021/08/27 16:52:14 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	setup_array_from_argv(char **argv, int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		array[i] = ft_atoi(argv[i + 1]);
		i++;
	}
}

int	*normalize_by_index(char **argv, int size)
{
	int		i;
	int		*original;
	int		*sorted;
	int		*normalized;
	int		j;

	original = (int *)ft_calloc(sizeof(int), size);
	sorted = (int *)ft_calloc(sizeof(int), size);
	normalized = (int *)ft_calloc(sizeof(int), size);
	setup_array_from_argv(argv, original, size);
	setup_array_from_argv(argv, sorted, size);
	quick_sort(sorted, 0, size - 1);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (original[i] != sorted[j])
			j++;
		normalized[i] = j;
		i++;
	}
	free(original);
	free(sorted);
	return (normalized);
}
