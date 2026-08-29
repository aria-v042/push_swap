/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nd-abreu <nd-abreu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 12:42:26 by frodrig2          #+#    #+#             */
/*   Updated: 2026/08/28 21:31:30 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

typedef enum e_strat
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
}	t_strat;

typedef enum e_ops
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
}	t_ops;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
	t_strat	strat;
	int		bench_mode;
	float	disorder;
	int		ops_count[11];
}	t_data;

/* ==== MAIN (srcs/main/) ==== */

/* ==== UTILS (srcs/utils/) ==== */

int		stack_check_dup(t_stack *node, int num);
t_stack	*stack_new_node(int value);
void	stack_add_bottom(t_stack **stack_p, t_stack *new_node);

/* ==== PARSING (srcs/parse/) ==== */

int		parser(t_data *data, int argc, char **argv);
int		parse_flag(t_data *data, char *arg);
int		parse_numbers(t_data *data, char *arg);

/* ==== OPERATIONS (srcs/ops/) ==== */

/* ==== SORTING STRATEGIES (srcs/sort/) ==== */

/* tiny */
/* simple - O(n^2) */
/* medium - O(n sqrt(n)) */
/* complex - O(n log n) */

/* ==== BENCHMARKS (srcs/bench/) ==== */

#endif
