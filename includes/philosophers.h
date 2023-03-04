/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:06:54 by tmichel-          #+#    #+#             */
/*   Updated: 2023/03/04 17:18:55 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>

# define NUMB_ARG "Error: wrong number of arguments."
# define DIGITS "Error: arguments should only be composed by digits."
# define ONE_PHILO "Error: a philosopher should never eat alone."
# define T_ACTION "Error: time only goes one way in this dimension..."
# define T_MEALS "Error: philosophers must eat at least once."
# define MLC "Malloc error."

typedef struct s_info	t_info;
typedef struct s_philo	t_philo;

typedef struct s_philo {
	int			id;
	int			r_fork_id;
	int			l_fork_id;
	int			eating_lock;
	t_info		*info;
}		t_philo;

typedef struct s_info {
	int				n_philo;
	int				n_meals;
	pthread_mutex_t	fork;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				t_think;
	int				meals_eaten;
	t_philo			*philo;
}			t_info;

//LIBFT.C
int			ft_isdigit(int c);
void		ft_putstr_fd(char *s, int fd);
int			ft_atoi(const char *nptr);
//PARSING.C
int			ft_error(char *err);
void		ft_number(int ac, char **av);
int			parse_args(int ac, char **av);
//INIT.C
void		ft_init_args(int ac, char **av, t_info *info);
//DISPLAY.C
void		display_timestamp(size_t ts);
void		display_global(t_philo *philo, char *act);
//TIME.C
size_t		gettimeofday_ms(void);
size_t		timestamp_ms(void);
size_t		size_of_timestamp(size_t ts);

#endif
