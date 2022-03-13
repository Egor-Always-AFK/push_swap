/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_into_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <ocapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:41:13 by ocapers           #+#    #+#             */
/*   Updated: 2022/03/10 18:20:23 by ocapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../push_swap.h"

int	*stack_into_array(t_stack **a, int argc)
{
	int		*arr;
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = (*a);
	arr = malloc(sizeof(int *) * (argc - 1));
	while (tmp->next != NULL)
	{
		arr[i] = tmp -> value;
		tmp = tmp -> next;
		i++;
	}
	arr[i] = tmp -> value;
	return (arr);
}

int	*sort_array_by_bubble(int *arr, int argc)
{
	int	i;
	int	j;
	int	tmp;
	int	min;

	i = -1;
	while (++i < argc - 1)
	{
		j = i;
		min = i;
		while (++j < argc - 1)
			if (arr[min] > arr[j])
				min = j;
		tmp = arr[i];
		arr[i] = arr[min];
		arr[min] = tmp;
	}
	return (arr);
}

int	find_min(t_stack **a, int argc)
{
	int	*arr;
	int	min;

	arr = sort_array_by_bubble(stack_into_array(a, argc), argc);
	min = arr[0];
	free(arr);
	return (min);
}

int	find_max(t_stack **a, int argc)
{
	int	*arr;
	int	max;

	arr = sort_array_by_bubble(stack_into_array(a, argc), argc);
	max = arr[argc - 2];
	free(arr);
	return (max);
}

int	find_mid(t_stack **a, int argc)
{
	int	*arr;
	int	mid;

	arr = sort_array_by_bubble(stack_into_array(a, argc), argc);
	mid = arr[(argc - 1) / 2];
	free(arr);
	return (mid);
}
