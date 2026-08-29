/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nd-abreu <nd-abreu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 12:42:26 by frodrig2          #+#    #+#             */
/*   Updated: 2026/08/29 00:25:45 by nd-abreu         ###   ########.fr       */
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
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR
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
void	stack_free(t_stack **stack_p);
t_stack	*stack_get_bottom(t_stack *node);

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
