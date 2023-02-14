/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:06:54 by tmichel-          #+#    #+#             */
/*   Updated: 2023/02/14 18:03:48 by tmichel-         ###   ########.fr       */
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

typedef struct s_philo {
	int	id;
	int	right_fork_id;
	int	left_fork_id;
}		t_philo;

//LIBFT.C
int		ft_isdigit(int c);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *nptr);
//UTILS.C
int		ft_error(char *err);
int		ft_number(int ac, char **av);
int		parse_args(int ac, char **av);
#endif
