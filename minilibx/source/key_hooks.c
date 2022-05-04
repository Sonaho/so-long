
#include "../includes/so_long.h"

int	key_hook(int keycode, t_data *data)
{
	ft_putstr_fd("\nKey press: ", 1);
	ft_putnbr_fd(keycode, 1);
	if (keycode == 53)
	{
		ft_putstr_fd("\nExit program\n", 1);
		clean_memory(data);
		return (0);
	}
	return (0);
}
