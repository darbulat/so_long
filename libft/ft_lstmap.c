#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*last;
	t_list	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	last = ft_lstnew(f(temp->content));
	if (!last)
		return (NULL);
	temp = temp->next;
	while (temp)
	{
		new = ft_lstnew(f(temp->content));
		if (!new)
		{
			ft_lstclear(&last, del);
			return (NULL);
		}
		ft_lstadd_back(&last, new);
		temp = temp->next;
	}
	return (last);
}
