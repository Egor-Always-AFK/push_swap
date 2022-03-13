/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <ocapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:21:37 by ocapers           #+#    #+#             */
/*   Updated: 2022/03/10 20:40:28 by ocapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

t_stack	*add_value(char *data, t_stack *head)
{
	t_stack	*tmp;
	t_stack	*dst;

	if (atoi_for_check_range(data) > INT_MAX 
		|| atoi_for_check_range(data) < INT_MIN
		|| (data[0] >= 'a' && data[0] <= 'z')
		|| (data[0] >= 'A' && data[0] <= 'Z')
		|| check_number_availability(data) == 1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	tmp = (t_stack *)malloc(sizeof(t_stack));
	tmp -> value = ft_atoi(data);
	dst = head;
	while (dst -> next != NULL)
		dst = dst -> next;
	dst -> next = tmp;
	tmp->next = NULL;
	return (head);
}

t_stack	*init_stack(char *data, t_stack *a)
{
	if (atoi_for_check_range(data) > INT_MAX 
		|| atoi_for_check_range(data) < INT_MIN
		|| (data[0] >= 'a' && data[0] <= 'z')
		|| (data[0] >= 'A' && data[0] <= 'Z')
		|| check_number_availability(data) == 1)
	{
		//ft_putstr_fd("Error\n", 2);
		write(2, "Error\n", 6);
		exit(1);
	}
	a = (t_stack *)malloc(sizeof(t_stack));
	a -> value = ft_atoi(data);
	a -> next = NULL;
	return (a);
}

void	free_stack(t_stack *a)
{
	t_stack	*tmp;

	while (a != NULL)
	{
		tmp = a;
		a = a->next;
		free(tmp);
		tmp = NULL;
	}
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	int			i;

	i = 1;
	if (argc < 3)
		exit(1);
	if (argv[1] == 34)
		i++;
	a = NULL;
	a = init_stack(argv[i], a);
	b = NULL;
	while (i++ < argc - 1)
		a = add_value(argv[i], a);
	parsing_arguments(&a);
	sort(&a, &b, argc);
	free_stack(a);
	return (0);
}
