#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>



typedef  struct node {
  int data;
 struct node *next;
} node;


void print(int i);


node* create(int data,node* next)
{
    node* new_node = (node*)malloc(sizeof(node));
    if(new_node == NULL)
    {
        //printf("Error creating a new node.\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = next;

    return new_node;
}

/*
    insert a new node after the prev node
*/
node* insert_after(node *head, int data, node* prev)
{
    /* find the prev node, starting from the first node*/
    node *cursor = head;
    while(cursor != prev)
        cursor = cursor->next;

    if(cursor != NULL)
    {
        node* new_node = create(data,cursor->next);
        cursor->next = new_node;
        return head;
    }
    else
    {
        return NULL;
    }
}

void prepend(node** head,int data)
{
    node* new_node = create(data,*head);
    *head = new_node;
}

void append(node** head, int data)
{

	if (!*head)
	{
		*head = create(data, NULL);
		return;
	}
    /* go to the last node */
    node *cursor = *head;
    while(cursor->next != NULL)
        cursor = cursor->next;

    /* create a new node */
    node* new_node =  create(data,NULL);
    cursor->next = new_node;
}

node* search(node* head,int data)
{

    node *cursor = head;
    while(cursor!=NULL)
    {
        if(cursor->data == data)
            return cursor;
        cursor = cursor->next;
    }
    return NULL;
}

void traverse(node* head)
{
    node* cursor = head;
    while(cursor != NULL)
    {
        printf("%d\n", cursor->data);
        cursor = cursor->next;
    }
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(const char *s)
{
	int		i;

	i = -1;
	while (*(s + ++i))
		;
	return (i);
}

char	*ft_strcat(char *s1, const char *s2)
{
	int			i;
	int			j;

	i = -1;
	j = (int)ft_strlen(s1);
	while (*(s2 + ++i))
		*(s1 + j++) = *(s2 + i);
	*(s1 + j) = '\0';
	return (s1);
}

int		ft_atoi(const char *str)
{
	int		i;
	int		num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	while (*(str + i) == '\n' ||
		*(str + i) == '\t' ||
		*(str + i) == '\r' ||
		*(str + i) == '\v' ||
		*(str + i) == '\f' ||
		*(str + i) == ' ')
		i++;
	if (*(str + i) == '-')
		sign = -1;
	if (*(str + i) == '-' || *(str + i) == '+')
		i++;
	while (*(str + i) && *(str + i) >= '0' && *(str + i) <= '9')
		num = num * 10 + (*(str + i++) - '0');
	return (num * sign);
}


void printstr(char *str)
{
	int i;

	i = 0;
	////printf("--------------printstr-------------------------------\n");
	while(str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	//ft_putchar('!');
	////printf("\n--------------printstr-------------------------------\n");
}

int  count_words(char *s)
{
	////printf("ft count_words :%s\n",s);

	int i;
	int valve;
	int count;

	i = 0;
	count = 0;
	while(s[i] != '\0'){
	while(s[i] == ' ')
	{
		i++;
	}

	valve = 1;
	while((s[i] != ' ') && ( s[i] != '\0'))
	{
		i++;
		if(valve == 1)
		{
			valve = 0;
			count++;
		}
	}
	}
	return count;
}


char* make_a_cut(char *s, int a, int b)
{
	int i;
	int k = b - a;

	i = 0;

	if(a == b)
	{
		//printf("make_a_cut  has fail \n");
		return NULL;
	}

	char *str = (char*)malloc(sizeof(char)* k + 1);

	while(a < b)
	{
		str[i] = s[a];
		i++;
		a++;
	}
	str[a] = '\0';

	return (str);

}

int count_char(char *s, int init)
{
	int i;
	//printf("__Enter__\n");


	while(s[init] != ' ' && s[init] != '\0')
	{
		i++;
		init++;
		//printf("---?>%s\n", s);
	}
	//printf("%d\n", i);
	return i;
}

char **f_strsplit(char *s)
{
 	printf( "Enter a value :%s\n", s);

	int i;
	int k;
	int count = count_words(s);
	int compare;
	printf("%d\n", count);
	int l;

	char **segs = (char**)malloc(sizeof(char*)*count);

	i = 0;
	compare = 0;


	while(compare < count)
	{
		while(s[i] == ' ')
			i++;
		l = count_char(s,i);
		segs[compare] = (char*)malloc(sizeof(char)*l);
		// printf("SEGS  Start%s\n", segs[compare]);
		k = 0;
		while(k < l)
		{
			segs[compare][k] = s[i];
			k++;
			i++;
		}
		//printf("SEGS  End%s\n", segs[compare]);
			compare++;
	}

	return (segs);
}

void print(int i)
{
	//printf("$$$$$$$$$$$$$$$$$$$$$$$%d!\n",i);
}


void algoritm(char **str, int size)
{
	int i;
	int value;
	struct node *list_a = NULL;
	//struct node *start;


	i = 0;

	while(i < size)
	{
		//printf("-----SIZE-----\n");
		value = atoi(str[i]);
		printf("--| %s\n", str[i]);
		//printf("EEEEEEEEEEE\n%d\n",value );
		append(&list_a, value);
		//printf("WWWWWWWWWWWWWWWW\n");
		i++;

	}
	// traverse(list_a);

	//printf("WWWWWWWWWWWWWWWW\n");
	/*
	while(start->next != NULL )
	{
		//printf("----Try to print--------\n");
		//printf("%d\n", list_a->data);
		if(list_a->data == 99)
			exit(0);
	}

    traverse(list_a);
    */

}

static int msh_word_is_delimiter(char c, char *delimiters, int dlen)
{
	for (int i = 0; i < dlen; i++)
		if (c == delimiters[i])
			return (1);
	return (0);
}

static int msh_word_count(char *str, char *delimiters)
{
	int		count;
	char	*index;
	int		prev_is_delimiter;
	int		dlen;
	int		flag;

	count = 0;
	index = (char *)str;
	prev_is_delimiter = 1;
	dlen = strlen(delimiters);
	while (*index)
	{
		flag = msh_word_is_delimiter(*index, (char *)delimiters, dlen);
		if (prev_is_delimiter && !flag)
			count++;
		prev_is_delimiter = flag;
		index++;
	}
	return (count);
}

static char *msh_word_extract(char **str, char *delimiters)
{
	char	*word;
	char	*temp;
	int		dlen;

	dlen = strlen(delimiters);
	while (**str && msh_word_is_delimiter(**str, delimiters, dlen))
		(*str)++;
	temp = *str;
	while (*temp && !msh_word_is_delimiter(*temp, delimiters, dlen))
		temp++;
	word = (char *)malloc(temp - *str);
	dlen = 0;
	while (*str < temp)
	{
		word[dlen++] = **str;
		(*str)++;
	}
	word[dlen] = '\0';
	return (word);
}

char **msh_get_args(char *str, char *delimiters, int *args_len)
{
	char **arr;
	char *strindex;

	strindex = str;
	*args_len = msh_word_count(strindex, delimiters);
	if (*args_len == 0)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (*args_len + 1));
	for (int i = 0; i < *args_len; i++)
		arr[i] = msh_word_extract(&strindex, delimiters);
	arr[*args_len] = NULL;
	return (arr);
}


int main(int a, char **b)
{
	int len;
	int k;

	k = 1;
	len = 0;
	if (a > 1)
	{
		/* code */
		while(a > k)
		{
			len++;
			len = len + strlen(b[k]);
			k++;

		}

	}

	char *str;

	str = (char*)malloc(sizeof(char)*len );

	k = 1;
	while( a > k)
	{
		//printf(">>>>>>>>%s!\n", b[k]);
		strcat(str, b[k]);
		//printf(">>>>>>>>%s!\n", str);

		strcat(str, " ");
		//printf(">>>>>>>>%s!\n", str);
		k++;
	}

	// printstr(str);

	//printf("MAIN*-%s\n", str );


// char **list = f_strsplit(str);

	int arglen;
	char **list = msh_get_args(str, " ", &arglen);
	// for (int i = 0; i < arglen; i++)
	// 	printf("-- %s\n", list[i]);

	algoritm(list, arglen);

return 0;
}
