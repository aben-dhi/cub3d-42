// #include <stdlib.h>
// #include <mlx.h>

#define WINDOW_columns 600
#define WINDOW_HEIGHT 300

// int main(void)
// {
//     void	*mlx_ptr;
//     void	*win_ptr;

//     mlx_ptr = mlx_init();
//     win_ptr = mlx_new_window(mlx_ptr, WINDOW_columns, WINDOW_HEIGHT, "My first window!");
// 	mlx_loop(mlx_ptr);
//     mlx_destroy_window(mlx_ptr, win_ptr);
//     // mlx_destroy_display(mlx_ptr);
//     free(mlx_ptr);
// }

#define MLX_ERROR 1

// int	main(void)
// {
// 	void	*mlx_ptr;
// 	void	*win_ptr;

// 	mlx_ptr = mlx_init();
// 	if (mlx_ptr == NULL)
// 		return (MLX_ERROR);
// 	win_ptr = mlx_new_window(mlx_ptr, WINDOW_columns, WINDOW_HEIGHT, "My first window!");
// 	if (win_ptr == NULL)
// 	{
// 		free(win_ptr);
// 		return (MLX_ERROR);
// 	}
// 	mlx_loop(mlx_ptr);
// 	// while (1);
// 	mlx_destroy_window(mlx_ptr, win_ptr);
// 	// mlx_destroy_display(mlx_ptr);
// 	free(mlx_ptr);
// }

#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("text.txt", O_RDONLY);
	line = get_next_line(fd);
	if (!line)
	{
		printf("shit");
		free(line);
		return (1);
	}
	while (1)
	{
		printf("%s\n", line);
		free(line);
		line = get_next_line(fd);
		if (!line)
		{
			printf("shit");
			return (1);
		}
	}
	return (0);
}
