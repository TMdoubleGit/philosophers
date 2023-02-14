/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:19:22 by tmichel-          #+#    #+#             */
/*   Updated: 2023/02/14 18:03:57 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "philosophers.h"
// #include <pthread.h>
// #include <stdio.h>

// #define NC "\e[0m"
// #define YELLOW "\e[33m"
// #define BYELLOW "\e[1;33m"
// #define RED "\e[31m"
// #define GREEN "\e[32m"
// #define TIMES_TO_COUNT 21000

// void	parse_args (int ac, char **av)
// {
// 	int	i;

// 	i = 0;
// 	if (ac != 6)
// 		exit(EXIT_FAILURE);
// }

// void	*thread_routine(void *data)
// {
// 	pthread_t		tid;
// 	unsigned int	*count;
// 	unsigned int	i;

// 	tid = pthread_self();
// 	count = (unsigned int *)data;
// 	printf("%sThread [%ld]: Count at thread start = %d.%s\n",
// 			YELLOW,
// 			tid,
// 			*count,
// 			NC);
// 	i = 0;
// 	while (i < TIMES_TO_COUNT)
// 	{
// 		(*count)++;
// 		i++;
// 	}
// 	printf("%sThread [%ld]: Final count = %d.%s\n",
// 			YELLOW,
// 			tid,
// 			*count,
// 			NC);
// 	return (NULL);
// }

// int	main(void)
// {
// 	pthread_t tid1;
// 	pthread_t tid2;
// 	unsigned int count;

// 	printf("Main: Expected count is %s%u%s\n", GREEN, 2 * TIMES_TO_COUNT, NC);
// 	pthread_create(&tid1, NULL, thread_routine, &count);
// 	printf("Main: Created first thread [%ld]\n", tid1);
// 	pthread_create(&tid2, NULL, thread_routine, &count);
// 	printf("Main: Created second thread [%ld]\n", tid2);
// 	pthread_join(tid1, NULL);
// 	printf("Main: joining first thread [%ld]\n", tid1);
// 	pthread_join(tid2, NULL);
// 	printf("Main: joining second thread [%ld]\n", tid2);
// 	if (count != (2 * TIMES_TO_COUNT))
// 		printf("%sMain: ERROR ! Total count is %u%s\n", RED, count, NC);
// 	else
// 		 printf("%sMain: OK. Total count is %u%s\n", GREEN, count, NC);
// 	return (0);
// }