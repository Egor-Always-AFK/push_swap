/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <ocapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:20:53 by ocapers           #+#    #+#             */
/*   Updated: 2022/03/10 20:34:38 by ocapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

# define INT_MAX 2147483647

# define INT_MIN -2147483648

typedef struct s_node
{
	int				value;
	int				step;
	int				rotate;
	struct s_node	*next;
}	t_stack;

typedef struct s_steps
{
	int	count_a;
	int	count_b;
	int	a_step;
	int	b_step;
}	t_steps;

int		main(int argc, char **argv);

void	swap_a(t_stack **a, int output_choise);

t_stack	*add_value(char *data, t_stack *head);

t_stack	*init_stack(char *data, t_stack *a);

void	swap_b(t_stack **b, int output_choise);

void	swap_all(t_stack **a, t_stack **b);

void	push_a(t_stack **a, t_stack **b);

void	push_b(t_stack **a, t_stack **b);

void	rotate_a(t_stack **a, int output_choise);

void	rotate_b(t_stack **b, int output_choise);

void	rotate_all(t_stack **a, t_stack **b);

void	reverse_rotate_a(t_stack **a, int output_choise);

void	reverse_rotate_b(t_stack **a, int output_choise);

void	reverse_rotate_all(t_stack **a, t_stack **b);

void	sort_three_and_less_elements(t_stack **a, int argc);

void	check_sort(t_stack **a);

void	check_individuality(t_stack **a);

void	second_check_individuality(t_stack *head, t_stack *tmp, t_stack **a);

void	sort_three_elements(t_stack **a, int path);

void	parsing_arguments(t_stack **a);

int	check_min_and_max(const char *data);

void	sort(t_stack **a, t_stack **b, int argc);

int		*stack_into_array(t_stack **a, int argc);

int		*sort_array_by_bubble(int *arr, int argc);

int		find_end(t_stack **a);

void	sort_five_elements(t_stack **a, t_stack **b, int argc);

int		find_max(t_stack **a, int argc);

int		find_min(t_stack **a, int argc);

int		count_of_elements(t_stack **stack);

void	free_stack(t_stack *a);

int		find_error(char *data);

int		find_mid(t_stack **a, int argc);

void	big_sort(t_stack **a, t_stack **b, int argc);

void	first_part_of_sort(t_stack **a, t_stack **b, int argc, int min);

void	mark_steps_all_elements(t_stack **stack, int count);

void	min_action(t_stack **a, t_stack **b, t_steps *steps);

void	action_manager(t_stack **a, t_stack **b, t_steps *steps);

int		steps_to_min(t_stack **a, int min);

int		find_good_place(t_stack **a, t_stack **b, t_steps *step, int min);

void	subfinder(t_stack **a, t_stack **b, int *action, int *buff);

int		smaller_element_finder(t_stack **a, int a_head_value, int b_head_value);

void	subfinder_part_two(t_stack **a, t_stack **b, int *buff, int *action);

long long	atoi_for_check_range(char *str);

int	check_space(char c);

int	check_number_availability(char *argv);

#endif