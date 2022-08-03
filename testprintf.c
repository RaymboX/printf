#include "ft_printf.h"

#define VAR str1

int	main(void)
{
	char	*group1 = "+-#0 ";
	char	*group2 = "10";
	char	*group3 = ".4";
	char	*group4 = "csdiuxXP";
	char	group1_dest[6] = "\0\0\0\0\0\0";
	char	group4_dest[2] = "\0\0";

	int		i1 = 20193;
	int		i2 = -543454;
	int		i3 = 0;
	unsigned int	u1 = 39043;
	char	c1 = 'a';
	char	*str1 = "bonjour";
	void	*ptr;

	ptr = calloc(sizeof(char), 10);

	printf("%10.s", VAR);
	//ft_printf("%   ", VAR);
	free(ptr);
}
