/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <ocapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:21:49 by ocapers           #+#    #+#             */
/*   Updated: 2022/02/02 15:21:49 by ocapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parsing_arguments(t_stack **a)
{
	check_sort(a);
	check_individuality(a);
}

void	check_individuality(t_stack **a)
{
	t_stack	*head;
	t_stack	*tmp;

	head = (*a);
	while (head->next != NULL)
	{
		tmp = head->next;
		while (tmp->next != NULL)
		{
			if (head->value == tmp->value || head->value == tmp->next->value)
			{
				//ft_putstr_fd("Error\n", 2);
				write(2, "Error\n", 6);
				exit (1);
			}
			tmp = tmp->next;
		}
		head = head->next;
	}
	tmp = (*a);
	second_check_individuality(head, tmp, a);
}

void	second_check_individuality(t_stack *head, t_stack *tmp, t_stack **a)
{
	while (tmp->next != NULL)
	{
		if (tmp->value == head->value)
		{
			//ft_putstr_fd("Error\n", 2);
			write(2, "Error\n", 6);
			exit (1);
		}
		tmp = tmp->next;
	}
	if ((*a)->value == (*a)->next->value)
	{
		//ft_putstr_fd("Error\n", 2);
		write(2, "Error\n", 6);
		exit (1);
	}
}

void	check_sort(t_stack **a)
{
	t_stack	*head;
	int		i;

	i = 0;
	head = (*a);
	while (head->next != NULL)
	{
		if (head->value < head->next->value)
			head = head->next;
		else
		{
			i++;
			head = head->next;
		}
	}
	if (i == 0)
		exit (0);
}

int	check_number_availability(char *argv)
{
	int	i;
	int out;

	i = 0;
	out = 0;
	while (out == 0 && argv[i] != '\0')
	{
		if (argv[i] >= '0' && argv[i] <= '9')
			i++;
		else
			out = 1;
	}
	return (out);
}