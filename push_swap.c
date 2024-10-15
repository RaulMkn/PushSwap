/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:42:45 by rmakende          #+#    #+#             */
/*   Updated: 2024/10/15 20:53:07 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_list	*create_new_node(int *new_content, t_list **list, t_list **temp)
{
	t_list	*new_node;

	new_node = ft_lstnew(new_content);
	if (!new_node)
	{
		free_list(list);
		return (NULL);
	}
	if (*list == NULL)
	{
		*list = new_node;
	}
	else
	{
		(*temp)->next = new_node;
	}
	*temp = new_node;
	return (new_node);
}
/*
t_list	*string_push_swap(char const *argv[], t_list *lst, t_list *temp)
{
	char	**src;
	int		j;
	int		comparer;
	int		*ptr;

	j = 0;
	comparer = 0;
	src = ft_split(argv[1], ' ');
	if (!src)
		return (NULL);
	while (src[j] != NULL)
	{
		ptr = malloc(sizeof(int));
		if (!ptr)
			return (free(ptr), f_split(src, &lst, 1));
		*ptr = ft_atoi(src[j], &comparer);
		if (comparer)
			return (free(ptr), f_split(src, &lst, 1));
		if (*ptr == 0)
		{
			comparer = is_valid_num(src[j]);
			if (comparer == 1)
				return (free(ptr), f_split(src, &lst, 1));
		}
		temp = create_new_node(ptr, &lst, &temp);
		j++;
	}
	return (f_split(src, &lst, 0), lst);
}
*/

int	handle_new_content(const char *arg, int **new_content, t_list **list)
{
	int	comparer;

	comparer = 0;
	*new_content = malloc(sizeof(int));
	if (!(*new_content))
		return (0);
	**new_content = ft_atoi(arg, &comparer);
	if (comparer)
		return (free(*new_content), free_list(list), 0);
	if (**new_content == 0)
	{
		comparer = is_valid_num(arg);
		if (comparer == 1)
		{
			free(*new_content);
			free_list(list);
			return (0);
		}
	}
	return (1);
}

int	process_arguments(int argc, char const *argv[],
t_list **list, t_list **temp)
{
	int		i;
	int		*new_content;
	int		result;

	i = 1;
	while (i < argc)
	{
		if (argv[2] == NULL)
		{
			*list = string_push_swap(argv, *list, *temp);
			if (!*list)
				return (1);
			else
				return (0);
		}
		result = handle_new_content(argv[i], &new_content, list);
		if (result == 0)
			return (1);
		*temp = create_new_node(new_content, list, temp);
		i++;
	}
	return (0);
}

int	main(int argc, char const *argv[])
{
	t_list	*list;
	t_list	*temp;

	list = NULL;
	temp = NULL;
	if (argc > 1)
	{
		if (process_arguments(argc, argv, &list, &temp) == 1)
			return (ft_putstr_fd("Error\n", 2), 1);
	}
	else
		ft_putstr_fd("Error\n", 2);
	if (check_duplicates(list) == 1)
		return (ft_putstr_fd("Error\n", 2), ft_lstclear(&list, free), 1);
	print_list(list);
	//ft_putstr_fd("OK\n", 1);
	return (free_list(&list), 0);
}
