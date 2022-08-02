/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yghari <yghari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 02:55:05 by yghari            #+#    #+#             */
/*   Updated: 2022/05/27 02:55:58 by yghari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_print_state(t_data	*data, int philo_id, char	*str)
{
	pthread_mutex_lock(&data->print_mutex);
	if (data->philo_state != DIE)
		printf("%ldms  %d  %s",
			(ft_timestamp() - data->start_time), philo_id, str);
	pthread_mutex_unlock(&data->print_mutex);
}

void	ft_chk_deth(t_philo	*philo, t_data	*data)
{
	while (data->philo_state != DIE)
	{
		if (ft_timestamp() - philo->last_time_eat > data->time_to_die)
		{
			data->philo_state = DIE;
			pthread_mutex_lock(&data->print_mutex);
			printf("%ldms  %d  died\n",
				(ft_timestamp() - data->start_time), data->philo->id + 1);
		}
		else if (data->all_philos_eat == data->nbr_philosophers)
			data->philo_state = DIE;
		usleep(500);
	}
}

void	ft_eat(t_philo	*philo, t_data	*data)
{
	pthread_mutex_lock(&data->philo[philo->id].fork_mutex);
	ft_print_state(data, philo->id + 1, "has taken a fork\n");
	pthread_mutex_lock(&data->philo[(philo->id + 1)
		% data->nbr_philosophers].fork_mutex);
	ft_print_state(data, philo->id + 1, "has taken a fork\n");
	ft_print_state(data, philo->id + 1, "is eating\n");
	philo->last_time_eat = ft_timestamp();
	data->philo[philo->id].nmbroftm_philo_eat++;
	ft_precis_usleep(philo, data->time_to_eat);
	pthread_mutex_unlock(&data->philo[(philo->id + 1)
		% data->nbr_philosophers].fork_mutex);
	pthread_mutex_unlock(&data->philo[philo->id].fork_mutex);
}

void	ft_destroy(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philosophers)
	{
		pthread_mutex_destroy(&data->philo[i].fork_mutex);
		i++;
	}
	free(data->philo);
}
