
#include "../includes/so_long.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		ft_putstr_fd("\nExit program\n", 1);
		clean_memory(data);
		return (0);
	} 
	else if (keycode == 13)
		move_up(data);
	else if (keycode == 0)
		move_left(data);
	else if (keycode == 1)
		move_down(data);
	else if (keycode == 2)
		move_right(data);
	return (0);
}
