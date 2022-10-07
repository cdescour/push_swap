/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 21:44:35 by cdescour          #+#    #+#             */
/*   Updated: 2022/10/07 21:50:08 by cdescour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef enum move
{
	srotate,
	rrotate
}			t_move;

typedef struct s_master
{
	int				nb_value;
	struct s_node	*top;
	struct s_node	*bottom;
	int				*arr_sort;
	struct s_eff	*effi;
	int				push_med;
	int				max;
	int				min;
	int				mr;
}				t_master;

typedef struct s_node
{
	int				value;
	int				rank;
	int				position;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

typedef struct s_eff
{
	int		rank;
	int		effi;
	t_move	type;
	int		nb_coup;
}				t_eff;

// push_swap.c
void		ft_pushswap(int *tab, int size);
void		ft_check_double_false(int *tab);
int			main(int argc, char **argv);

// memory.c
t_master	*ft_new_master(void);
t_master	*ft_tab_to_stack(t_master *m, int *tab, int *rank, int i);
char		**ft_mem_two_args(char **argv);
char		**ft_mem_many_args(int argc, char **argv);
int			*ft_mem_tab_int(char **tabstr);

// check_args.c
int			ft_check_is_nbr(char **tabstr);
int			ft_is_int(char *str);
int			ft_check_is_int(char **tabstr);
int			ft_check_argv(char **tabstr);
int			ft_check_double(int *tab, int size);

// get_rank.c
int			ft_rank_max(int *temptab, int size);
int			ft_rank_min(int *temptab, int size);
int			*ft_rank(int *temptab, int *rank, int size);
int			*ft_get_rank(int *tab, int size);

// set_value.c
void		ft_set_sort(int *arr, int nb_value);
void		ft_set_value(t_master *m);
void		ft_set_apex(t_master *m1);
void		ft_set_position(t_node *stack1, t_node *stack2);

// check.c
bool		ft_is_empty_master(t_master *m);

// sort.c
bool		ft_is_valid_stack(t_master *a);
void		ft_sort_back(t_master *m1, t_master *m2);
void		ft_sort_low(t_master *m1, t_master *m2);
void		ft_sort(t_master *m1, t_master *m2);

// sort_tall.c
void		ft_set_effi2(int eff[3], t_master *m, t_node *stack, int nb_v);
void		ft_set_effi(int n, t_master *m, t_node *stack, int nb_v);
void		ft_sort_algo(t_master *m1, t_master *m2);
void		ft_stack_split(t_master *m1, t_master *m2, int med);

// instructions.c
void		ft_swap(t_master *m, char a);
void		ft_rotate(t_master *m, char a);
void		ft_reverse_rotate(t_master *m, char a);
void		ft_push(t_master *m1, t_master *m2, char a);
void		ft_drotate(void (*f)(t_master *, char), t_master *m1, t_master *m2);

// free.c
int			ft_free_tabstr(char **tabstr);
void		ft_free_list(t_master *m);

// error.c
void		ft_error(void);
void		ft_error_tabstr(char **tabstr, int i);
#endif
