/*
** mylist.h for mylist in /home/bongol_b/rendu/Piscine_C_J11
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Oct 12 09:29:09 2015 berdrigue bongolo-beto
** Last update Sat Jun  4 22:36:32 2016 Berdrigue BONGOLO BETO
*/

#ifndef MYLIST_H_
# define MYLIST_H_

typedef struct s_list2	t_list2;
typedef struct s_list	t_list;

struct		s_list
{
  void		*data;
  t_list	*next;
};

struct		s_list2
{
  void		*data;
  t_list2	*next;
  t_list2	*prev;
};

/*
** Simple linked list
*/
t_list		*my_params_in_list(int ac, const char **av);
int		my_rev_list(t_list **begin);
void		*my_find_elm_eq_in_list(t_list *begin, void *dat, int (*cmp)());
t_list		*my_find_node_eq_in_list(t_list *begin, void *da, int (*cmp)());
int		my_add_elem_in_list_end(t_list **begin, void *data);
int		my_add_elem_in_list_begin(t_list **begin, void *data);
void		my_rm_elem_in_list_end(t_list **begin);
int		my_apply_on_list(t_list *begin, void (*f)());
void		*my_rm_el_from_list(t_list **begin, void *dat, int (*cmp)());
int		my_rm_all_eq_from_list(t_list **begin, void *dat, int (*cmp)());
char		**my_list_to_wordtab(t_list *begin);
int		my_list_size(t_list *begin);
void		my_free_list(t_list **begin, void (*f)(void *));
t_list		*my_list_rev_copy(t_list *begin);
t_list		*my_list_copy(t_list *begin);
void		my_apply_elm_eq_in_list(t_list *, int (*)(), void *, int (*)());
void		my_add_list_to_list(t_list **begin1, t_list *begin2);
int		my_sort_list(t_list **begin, int (*cmp)());

/*
** Double linked list
*/
int		my_rev_list2(t_list2 **begin);
t_list2		*my_params_in_list2(int ac, char **av);
int		my_add_elem_in_list2_begin(t_list2 **begin, void *data);
int		my_add_elem_in_list2_end(t_list2 **begin, void *data);
void		*my_find_elm_eq_in_list2(t_list2 *, void *dat, int (*cmp)());
void		my_rm_elem_in_list2_end(t_list2 **begin);
int		my_apply_on_list2(t_list2 *begin, void (*f)(void*));
void		*my_rm_el_from_list2(t_list2 **begin, void *dat, int (*cmp)());
int		my_rm_all_eq_from_list2(t_list2 **, void *dat, int (*cmp)());
int		my_list2_size(t_list2 *begin);
char		**my_list2_to_wordtab(t_list2 *begin);
void		my_free_list2(t_list2 **begin, void (*f)(void *));
t_list2		*my_list2_copy(t_list2 *begin);
t_list2		*my_list2_rev_copy(t_list2 *begin);
void		my_apply_elm_eq_in_list2(t_list2 *, int (*)(), void *,
					 int (*)());
void		my_add_list_to_list2(t_list2 **begin1, t_list2 *begin2);
int		my_apply_on_rev_list2(t_list2 *begin, void (*f)(void *));
void		my_rm_elem_in_list2_begin(t_list2 **begin);

#endif /* !MYLIST_H_ */
