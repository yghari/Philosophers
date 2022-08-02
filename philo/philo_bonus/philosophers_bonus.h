/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yghari <yghari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 03:15:37 by yghari            #+#    #+#             */
/*   Updated: 2022/05/27 03:15:53 by yghari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/types.h>
# include <signal.h>
# include <time.h>
# include <sys/time.h>

# define DIE	0

typedef struct s_philob
{
	int				id;
	long int		last_time_eat;
	int				nmbroftm_philo_eat;
	pid_t			*pid;
}	t_philob;

typedef struct s_datab
{
	int				nbr_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nmbroftm_each_philo_eat;
	int				philo_state;
	long int		start_time;
	int				all_philos_eat;
	pthread_t		thread;
	sem_t			*fork_semaphore;
	sem_t			*print_semaphore;
	t_philob		philo;
}	t_datab;

int			ft_isdigit(int c);
size_t		ft_strlen(const char *s);
void		ft_putstr_fd(char *s, int fd);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strtrim(char const *s1, char const *set);
int			ft_atoi(const char *str);
void		ft_handle_error(char *str);
void		ft_empty_arg(int ac, char **av);
void		ft_check_integers(char **argv, int argc);
void		ft_semaphore_open(t_datab *data);
void		ft_init_process(t_datab *data);
void		ft_exit(t_datab *data);
void		ft_kill_process(t_datab *data);
void		ft_init_data(t_datab *data, int ac, char **av);
void		*ft_chk_deth(void *arg);
void		ft_print_state(t_datab *data, int philo_id, char *str);
void		ft_eat(t_datab *data);
long int	ft_timestamp(void);
void		ft_precis_usleep(long int sleep_time);
void		*ft_routine(t_datab *data);
void		ft_unlink(t_datab *data);

#endif
