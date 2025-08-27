#include "push_swap.h"

static int	is_number(char *str)
{
	int i;

	i = 0;
	if (!str[i])
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	has_duplicate(int *arr, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*parse_input(int ac, char **av)
{
	int	*arr;
	long	tmp;
	int		i;

	arr = malloc(sizeof(int) * (ac - 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < ac - 1)
	{
		if (!is_number(av[i + 1]))
			write(2, "Error\n", 6), free(arr), exit(1);
		tmp = ft_atoi(av[i + 1]);
		if (tmp > 2147483647 || tmp < -2147483648)
			write(2, "Error\n", 6), free(arr), exit(1);
		arr[i] = (int)tmp;
		i++;
	}
	if (has_duplicate(arr, ac - 1))
		write(2, "Error\n", 6), free(arr), exit(1);
	return (arr);
}
