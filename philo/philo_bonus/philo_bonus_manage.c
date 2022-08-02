/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus_manage.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yghari <yghari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 03:13:49 by yghari            #+#    #+#             */
/*   Updated: 2022/05/27 03:16:17 by yghari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	ft_kill_process(t_datab *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philosophers)
	{
		kill(data->philo.pid[i], SIGTERM);
		i++;
	}
}

void	ft_exit(t_datab *data)
{
	int	status;

	while (1)
	{
		waitpid(-1, &status, 0);
		if (WEXITSTATUS(status) == 1)
		{
			ft_kill_process(data);
			break ;
		}
		else if (WEXITSTATUS(status) == 2)
		{
			data->all_philos_eat++;
			if (data->all_philos_eat == data->nbr_philosophers)
			{
				ft_kill_process(data);
				break ;
			}
		}
	}
	ft_unlink(data);
}

void	ft_init_process(t_datab *data)
{
	int	i;

	i = 0;
	data->philo.nmbroftm_philo_eat = 0;
	while (i < data->nbr_philosophers)
	{
		data->philo.pid[i] = fork();
		if (data->philo.pid[i] == 0)
		{
			data->philo.id = i;
			data->philo.last_time_eat = ft_timestamp();
			ft_routine(data);
		}
		i++;
	}
}

void	ft_semaphore_open(t_datab *data)
{
	sem_unlink("fork_semaphore");
	sem_unlink("print_semaphore");
	data->fork_semaphore = sem_open("fork_semaphore",
			O_CREAT, 0600, data->nbr_philosophers);
	if (data->fork_semaphore == SEM_FAILED)
		ft_handle_error("SEMAPHORE FAILURE\n");
	data->print_semaphore = sem_open("print_semaphore", O_CREAT, 0600, 1);
	if (data->print_semaphore == SEM_FAILED)
		ft_handle_error("SEMAPHORE FAILURE\n");
}
