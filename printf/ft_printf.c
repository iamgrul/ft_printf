#include "ft_printf.h"
#include "libft.h"
char    *ft_itoa_base(long long int value, char base);

char    ft_find_endofexp_dollarhelper(char *str, int max)
{
    int i;

    i = max;
    if (*(str--) == '$' && ft_isdigit(*str) && (--i >= 0))
    {
        while(ft_isdigit(*(--str)) && i > 0)
            i--;
        while (i < 0)
        {
            i++;
            str++;
        }
        if (*str != '.' && ft_atoi(str) != 0)
            return (1);
    } 
    return (0);
}
int     ft_find_endofexp(char *str)
{
    int         pos;

    pos = 0;
    while (*str)
    {
        if (!(ft_isdigit(*str) || *str == ':' || *str == '*' || *str == '.' || *str == ','
        || *str == '\'' || *str == ' ' || *str == '#' || *str == '-' || *str == '+' || *str == '$'))
        // || (*str == '$' && ft_find_endofexp_dollarhelper(str, pos)))) /// $$$$$$$$$$$$$
        {
            return (pos);
        }
        pos++;
        str++;
    }
    return (0);
}

int    ft_mod_accuracy(const char *str)
{
    char *tmp;
    int res;
    

    tmp = (char*)str;
    res = (int)str;
    while ((tmp = (ft_strchr(tmp, '.'))))
        str = ++tmp;
    if(str)
    {
        if ((ft_isdigit(*str) || *str == '*') && (int)str != res)
            res = (int)str - res;
        else
            res = -1;
            
    }
    else
        res = -1;
         
    return (res);
}

int     ft_mod_width(char *str)
{
    int i;
    char flag;
    int res;
    int pos;

    res = -1;
    i = 0;
    pos = -1;
    flag = 1;
    while (str[i])
    {
        if (str[i] == '.' && (ft_isdigit(str[i + 1]) || str[i + 1] == '*'))
            flag = 0;
        if ((ft_isdigit(str[i]) && ft_atoi(str + i) != 0) || str[i] == '*')
        {
            if (flag)
            {
                flag = 0;
                pos = i;
            }
            if(str[i + 1] == '*')
                flag = 1;
        }
        else
        {
            if (str[i] != '.')
                flag = 1;
        }
        i++;
    }
  //  res = ft_atoi(str + pos);
    return (pos);
}

char    *ft_mod_flag_zero(char *str)
{
    int i;
    int flag;
    
    i = 0;
    flag = 1;
    while (str[i])
    {
        if (str[i] == '.' && ft_isdigit(str[i + 1]))
            flag = 0;
        if (ft_isdigit(str[i]))
        {
            if (flag)
            {
                flag = 0;
                if (ft_atoi(str + i) == 0)
                    return ("0");
            }
        }
        else
        {
            if (str[i] != '.')
                flag = 1;
        }

        i++;
    }
    return "";
}


char    *ft_mod_flags(char *str)//-+ #0
{
    char *res;
    char *tmp;

    res = ft_strnew(0);
    if (ft_strchr(str, ' '))
    {
        tmp = ft_strjoin(res, " ");
        free(res);
        res = tmp;
    }
    if (ft_strchr(str, '-'))
    {
        tmp = ft_strjoin(res, "-");
        free(res);
        res = tmp;
    }
    if (ft_strchr(str, '+'))
    {
        tmp = ft_strjoin(res, "+");
        free(res);
        res = tmp;
    }
    if (ft_strchr(str, '#'))
    {
        tmp = ft_strjoin(res, "#");
        free(res);
        res = tmp;
    }
    tmp = ft_strjoin(res, ft_mod_flag_zero(str));
    free(res);
    res = tmp;

    return (res);
}

t_list  *ft_stars_push(char *str, va_list lst)
{
       int     buf[1]; //хотел записывать инты, а не строчки, но увы я рак
    char    *tmp;
    t_list *res;

    res = NULL;
    tmp = str;
    while ((tmp = ft_strchr(tmp, '*')))
    {
        buf[0] = va_arg(lst,    int);
        char *itoa  = ft_itoa_base(buf[0], 10);
        ft_lstadd(&res, ft_lstnew(itoa, ft_strlen(itoa)));
        res->content_size = tmp - str;
        free(itoa);
        tmp++;
    }
    return (res);
}

char     *ft_stars_pop(t_list *lst, int pos)
{
    while (lst)
    {
        if (lst->content_size == pos)
            return ((char*)(lst->content));
        lst = lst->next;
    }
    return (0);
}

// char    ft_spec_size(char *str)
// {
//     if (ft_strchr(str, l) || )


// }


void    ft_del(void *c, size_t s)
{
    free(c);
}

char	*ft_strnzero(int n)
{
	char *res;

	res = NULL;
	if (n > 0)
	{
		res = ft_strnew(n);
		res = (char*)ft_memset(res, '0', n);
	}
	return (res);
}
char	*ft_strnspace(int n)
{
	char *res;

	res = NULL;
	if (n > 0)
	{
		res = ft_strnew(n);
		res = (char*)ft_memset(res, ' ', n);
	}
	return (res);
}

void    ft_putnstr()//s
{

}



int		ft_putnnbr(int nbr, int width, int acc, char *flags)//diouxX
{
	char *res;
	char *temp;
	char *temp2;
    if(nbr < 0)
        res = ft_itoa(-nbr);
    else
        res = ft_itoa(nbr);
    
	temp = ft_strnzero(acc - (int)ft_strlen(res));
	temp2 = res;
	if (temp)
    {
        res = ft_strjoin(temp, res);
	    free(temp2);
    }
		
	// 	if (temp)
    // free(temp);
	
	if (ft_strchr(flags, '+'))
	{
		temp2 = res;
		if (nbr < 0)
			res = ft_strjoin("-", res);
		else
			res = ft_strjoin("+\0", res);

		free(temp2);
	}
	else if (ft_strchr(flags, ' '))
	{
		temp2 = res;
		res = ft_strjoin(" ", res);
		free(temp2);		
	}
	// ft_putstr("213");
  
	if (width > (int)ft_strlen(res))
	{  
		temp = ft_strnspace(width - ft_strlen(res));
		temp2 = res;
		if (ft_strchr(flags, '-'))
			res = ft_strjoin(res, temp);
		else 
			res = ft_strjoin(temp, res);
		free(temp2);
		free(temp);
	}

	ft_putstr(res);
	return (ft_strlen(res));
}


void    ft_putnfloat()//aAeEfF
{

}


void    ft_putndec()
{

}


int		ft_type_mngr(char *str, va_list lst, int width, int acc, char *flag)
{
	int ret;
	int pos = ft_strlen(str);
	char *res;

	ret = 0;
	if (str[pos - 1] == 'd')
	{
		ret = ft_putnnbr(va_arg(lst, int), width, acc, flag);
		
	}	


	return (ret);
}


int     ft_exp_mngr(char *str, int len, va_list lst)
{
    int ret;
    char *flags;
    int acc_pos;
    int width_pos;
    char size;
    t_list *stars;

    stars = ft_stars_push(str, lst);

    acc_pos = ft_mod_accuracy(str);
    width_pos = ft_mod_width(str);//diouxX n - l,hh,h,ll,j,z,t,L; aAeEfFgG -L; cs -l
    flags = ft_mod_flags(str);
    // size = ft_spec_size(str);
    // ft_putnbr(swidth);



	int acc = -1, width = -1;

    // ft_putstr("a : ");
    if (str[acc_pos] == '*')
        acc = ft_atoi(ft_stars_pop(stars, acc_pos));
    else
    {
        if (acc_pos != -1)
            acc = ft_atoi(str + acc_pos);
	}
	// ft_putnbr(acc);
    // ft_putstr(";  ");
    
    // ft_putstr("w : ");
    if (str[width_pos] == '*')
        width = ft_atoi(ft_stars_pop(stars, width_pos));
    else
        if (width_pos != -1)
            width = ft_atoi(str + width_pos);
    // ft_putnbr(width);
	// ft_putstr(";  ");
    
    // ft_putstr("f : \'");
    // ft_putstr(flags);
    // ft_putstr("\';  ");

	// ft_putchar('\"');
	ret = ft_type_mngr(str, lst, width, acc, flags);
	// ft_putchar('\"');

	free(flags);
    ft_lstdel(&stars, &ft_del);
    free(stars);
    return (ret);
}

int     ft_printf_mngr(char *str, va_list lst)
{
    int     ret;
    int     endpos;
    char    *exp;

    ret = 0;
    while (*str)
    {
        if (*str == '%')
        {
            // ft_putchar('|');
            str++;
            endpos = ft_find_endofexp(str);

            // ft_putstr("Endpos: ");
            // ft_putnbr(pos);
            // ft_putchar(*str);
            // ft_putchar('\n');

            //ft_putnbr(endpos);
            //ft_putchar(str[endpos]);
            exp = ft_strsub(str, 0, endpos + 1);
            ret += ft_exp_mngr(exp, endpos, lst);
            str += endpos;
            // ft_putchar('|');
        }
        else
        {
            ret++;
            ft_putchar(*str);
        }
        str++;
    }
    return (ret);
}
void    ft_stack_normalize() //fF...
{

}






void    ft_mod_type()
{

}

void    ft_spec_size()
{

}
char    *ft_itoa_base_main(long long int value, char base, char flag, int size)
{
    char            *res;

    res = ft_strnew(size + flag);
    res[0] = '-';
    size = size - 1 + flag;
    while (value)
    {
        res[size] = value % base;
        res[size] += (res[size] > 10) ? 'A' - 10: '0';
        value /= base;
        size--;
    }
    return (res);
}
char    *ft_itoa_base(long long int value, char base)
{
    long long int   temp;
    char            flag;
    int             size;

    if (value == 0 || base < 2 || base > 36)
        return ("0");
    size = 0;
    flag = 0;
    temp = value;
    while (temp)
    {
        temp /= base;
        size++;
    }
    temp = value;
    if (value < 0)
    {
        if (base == 10)
            flag = 1;
        temp = -temp;
    }

    return (ft_itoa_base_main(temp, base, flag, size));
}

int     ft_printf(const char * restrict format, ...)
{    
    va_list ap;
    int ret = 0;
    
    va_start(ap, format);
    ret = ft_printf_mngr((char*)format, ap);
    va_end(ap);
    return (ret);
}
