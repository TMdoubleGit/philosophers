/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:06:54 by tmichel-          #+#    #+#             */
/*   Updated: 2023/03/15 15:36:32 by tmichel-         ###   ########.fr       */
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
# define T_ACTION "Error: time only goes one way in this dimension..."
# define T_MEALS "Error: philosophers must eat at least once."
# define MLC "Malloc error."

# define MSE "is eating\n"
# define MSF "has taken a fork\n"
# define MST "is thinking\n"
# define MSSL "is sleeping\n"
# define MSD "is dead\n"

# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0

typedef struct s_info	t_info;
typedef struct s_philo	t_philo;

typedef struct s_philo {
	int			id;
	int			r_fork_id;
	int			l_fork_id;
	size_t		last_meal;
	pthread_t	th;
	t_info		*info;
}		t_philo;

typedef struct s_info {
	int				n_philo;
	int				n_meals;
	int				t_eat;
	int				t_sleep;
	int				t_think;
	int				game_over;
	int				meals_eaten;
	size_t			t_die;
	pthread_mutex_t	*fork;
	pthread_mutex_t	lock;
	t_philo			*philo;
}			t_info;

//LIBFT.C
int			ft_isdigit(int c);
void		ft_putstr_fd(char *s, int fd);
int			ft_strlen(char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *nptr);
//PARSING.C
int			ft_error(char *err);
void		ft_number(int ac, char **av);
int			parse_args(int ac, char **av);
//INIT.C
void		inf_loop(t_info *info);
void		init_thread(t_info *info);
void		sub_init_struct(t_info *info);
void		init_struct(int ac, char **av, t_info *info);
//ACTIONS.C
void		philo_eat(t_philo *philo);
void		philo_slt(t_philo *philo);
void		*thread_routine(void *data);
void		routine_even(t_philo *philo);
void		routine_odd(t_philo *philo);
//DISPLAY.C
void		display_timestamp(size_t ts);
void		display_action(t_philo *philo, char *act);
void		display_global(t_philo *philo, char *act);
//TIME.C
size_t		gettimeofday_ms(void);
size_t		timestamp_ms(void);
size_t		size_of_timestamp(size_t ts);
//END.C
void		dead_loop(t_info *info, t_philo philo);
void		meal_loop(t_info *info);
int			check_end(t_info *info);
void		ft_exit(t_info *info);

#endif
