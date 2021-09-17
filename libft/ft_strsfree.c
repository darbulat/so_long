#include "libft.h"

char	**ft_strsfree(char **strs, int i)
{
	while (--i >= 0)
		free(strs[i]);
	free (strs);
	return (NULL);
}
