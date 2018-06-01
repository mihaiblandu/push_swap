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
        printf("Error creating a new node.\n");
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

node* prepend(node* head,int data)
{
    node* new_node = create(data,head);
    head = new_node;
    return head;
}

node* append(node* head, int data)
{
    /* go to the last node */
    node *cursor = head;
    while(cursor->next != NULL)
        cursor = cursor->next;
 
    /* create a new node */
    node* new_node =  create(data,NULL);
    cursor->next = new_node;
 
    return head;
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
        print(cursor->data);
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
	//printf("--------------printstr-------------------------------\n");
	while(str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	//ft_putchar('!');
	//printf("\n--------------printstr-------------------------------\n");
}

int  count_words(char *s)
{
	//printf("ft count_words :%s\n",s);

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
		printf("make_a_cut  has fail \n");
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
	printf("__Enter__\n");


	while(s[init] != ' ' && s[init] != '\0')
	{
		i++;
		init++;
		printf("---?>%s\n", s);
	}
	printf("%d\n", i);
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
		printf("SEGS  Start%s\n", segs[compare]);
		k = 0;
		while(k < l)
		{
			segs[compare][k] = s[i];
			k++;
			i++;
		}
		printf("SEGS  End%s\n", segs[compare]);
			compare++;
	}

	return (segs);
}

void print(int i)
{
	printf("$$$$$$$$$$$$$$$$$$$$$$$%d!\n",i);
}


void algoritm(char **str, int size)
{
	int i;
	int value;
	struct node *list_a;
	struct node *start;


	i = 0;
	
	while(i < size)
	{
		printf("-----SIZE-----\n");
		value = ft_atoi(str[i]);
		printf("EEEEEEEEEEE\n%d\n",value );		
		list_a = prepend(list_a, value);
		if (/* condition */ i == 0)
		{
			start = list_a->next;
		}
		printf("WWWWWWWWWWWWWWWW\n");
		i++;

	} 
	printf("WWWWWWWWWWWWWWWW\n");
	
	while(start->next != NULL )
	{
		printf("----Try to print--------\n");
		printf("%d\n", list_a->data);
		if(list_a->data == 99)
			exit(0);
	}
	
    traverse(list_a);
    

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
			printf(">>>>>>>>%s!\n", b[k]);
		strcat(str, b[k]);
			printf(">>>>>>>>%s!\n", str);

		strcat(str, " ");
			printf(">>>>>>>>%s!\n", str);
		k++;
		}

	printstr(str);

	printf("MAIN*-%s\n", str );


char **list = f_strsplit(str);

int i = count_words(str);
while(i > 0)
{
	printf("/*Primul :%s\n", list[i - 1]);
	i--;
}
	printf("**************%s\n",str );
			printf("--------------\n");

	i = count_words(str);	
	algoritm(list, i);

return 0;
}


