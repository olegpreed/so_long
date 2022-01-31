#include "so_long.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*a;

	if (!*lst)
	{
		*lst = new;
		new->next = 0;
		return ;
	}
	if (new == 0 || !lst)
		return ;
	a = ft_lstlast(*lst);
	a->next = new;
}

t_list	*ft_lstnew(void *content)
{
	t_list	*a;

	a = (t_list *)malloc(sizeof(t_list));
	if (!a)
		return (0);
	a->content = content;
	a->next = 0;
	return (a);
}