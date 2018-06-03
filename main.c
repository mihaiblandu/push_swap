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

int get_lenght(char c);

typedef  struct node {
  int data;
 struct node *next;
} node;


typedef  struct nodes {
int data;
struct nodes *next;
struct nodes * back;

} nodes;



struct node *list_a = NULL;
struct node *list_b= NULL;



struct nodes *LIST_A = NULL;
struct nodes *LIST_B = NULL;





void print(int i);


node* create(int data,node* next)
{
    node* new_node = (node*)malloc(sizeof(node));
    if(new_node == NULL)
    {
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

void traverse(node** head)
{
    node* cursor = *head;
    while(cursor != NULL)
    {
    	printf("%d\n",cursor->data);
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


void sa()
{
	if(list_a->next->next != NULL)
	{
		struct node* temp;
		temp = list_a->next;

		list_a->next = list_a->next->next;
		temp->next = list_a;
		list_a =temp;

	}
	

}


void sb()
{

	if(list_b->next->next != NULL)
	{
		struct node* temp;
		temp = list_b->next;

		list_b->next = list_b->next->next;
		temp->next = list_b;
		list_b =temp;

	}

}
void ss()
{
	sa();
	sb();

}
void pa()
{
	struct node* temp;
	if (get_lenght('A') == 1)
	{
		/* code */

	temp = list_a;
	temp->next = list_b;
	list_b = temp;
	list_a = NULL;  
		return;
	}
	temp = list_a;
	list_a = list_a->next;
	temp->next = list_b;
	list_b = temp;
}
void pb()
{
	struct node* temp;
	temp = list_b;
	list_b = list_b->next;
	temp->next = list_a;
	list_a = temp;
}

void ra()
{
	struct node* temp;
	struct node* cap;

	temp = list_a;

	list_a = list_a->next;
	cap = list_a;
	temp->next = NULL;
	while(list_a->next != NULL)
	{
		list_a = list_a->next;
	}
	list_a->next = temp;
	list_a = cap;
}

void rb()
{
	struct node* temp;
	struct node* cap;

	temp = list_b;

	list_b = list_b->next;
	cap = list_b;
	temp->next = NULL;
	while(list_b->next != NULL)
	{
		list_b = list_b->next;
	}
	list_b->next = temp;
	list_b = cap;


}

void rr()
{

ra();
rb();

}


void  rra()
{
	if(get_lenght('A') <= 1)
		return ;

	if (get_lenght('A') == 2)
	{
		ra();
	}
	else{
		struct node* temp;
		struct node* cap;
		struct node* last;

		temp = list_a;
		cap = list_a;
		while(temp->next->next != NULL)
		{
			temp = temp->next;
		}
		last = temp->next;
		temp->next = NULL;

		last->next = cap; 
		list_a = last;



	}
}
void  rrb()
{
	if(get_lenght('B') <= 1)
		return ;

	if (get_lenght('B') == 2)
	{
		rb();
	}
	else{
		struct node* temp;
		struct node* cap;
		struct node* last;

		temp = list_b;
		cap = list_b;
		while(temp->next->next != NULL)
		{
			temp = temp->next;
		}
		last = temp->next;
		temp->next = NULL;

		last->next = cap; 
		list_b = last;

	}

}
void rrr()
{
	rra();
	rrb();
}

int get_lenght(char c)
{
	struct node* temp;
	int i;

	i = 0;

	if (c == 'A')
	{
		if(!list_a)
			return 0;

		temp = list_a;
		while(temp->next != NULL )
		{
			temp = temp->next;
			i++;
		}
	}
	
	if (c == 'B')
	{
		if(!list_b)
			return 0;
		temp = list_b;
		while(temp->next != NULL )
		{
			temp = temp->next;
			i++;
		}	
	
	}
	if (temp)
	{
		i++;
	}

	return i;
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
	while(str[i])
	{
		ft_putchar(str[i]);
		i++;
	}

}

int  count_words(char *s)
{

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


int count_char(char *s, int init)
{
	int i;

i = 0;
	while(s[init] != ' ' && s[init] != '\0')
	{
		i++;
		init++;
	}
	return i;
}

void print(int i)
{
	printf("$$$$$$$$$$$$$$$$$$$$$$$%d!\n",i);
}




void shufle()
{
			

	struct node*  first;
	struct node*  second;
	struct node*  last;

	first = list_a;
	second = first->next;
	last = first->next;
while(last->next != NULL)
{
	last = last->next;
}
if( first->data <= second->data && first->data <= last->data)
{

		list_a = list_a->next;

		if (get_lenght('A'))
		{			

			list_b = first;
			list_b->next = NULL;

  		}
  		else
  		{

  			first->next=list_b;
  			list_b = first; 
  		}

  		pa();
  		pa();pa();pa();pa();pa();pa();pa();pa();pa();pa();
  		pb();  		pb();
  		pb();
  		pb();
  		pb();
  		pb();
  		ra();ra();ra();ra();
  		rb();rb();rb();

  		rrr();rrr();rrr();


  		
		printf("Primul%d\n",list_a->data);
		printf("Primul%d\n",list_b->data);

			struct node* temp;

		temp = list_a;
		while(temp->next != NULL)
			{
				printf("TempA%d\n", temp->data);
				temp = temp->next;
			}
			printf("TempA%d\n", temp->data);
				temp = list_b;
		while(temp->next != NULL)
			{
				printf("TempB%d\n", temp->data);
				temp = temp->next;
			}
			printf("TempB%d\n", temp->data);
		

		printf("%d\n",list_a->data );
		printf("%d\n",list_b->data );

		printf("@@@@@,,,,,,,%d\n", get_lenght('A'));
		printf("!!!!!!,,,,,,%d\n", get_lenght('B'));
		printf("%s\n", "PB");


		return;
}


if( second->data <= first->data && second->data <= last->data)
	{
		list_a = list_a->next;

		if (get_lenght('A'))
		{			

			list_b = first;
			list_b->next = NULL;

  		}
  		else
  		{

  			first->next=list_b;
  			list_b = first; 
  		}

		printf("%d\n",list_a->data );

		printf("@@@@@,,,,,,,%d\n", get_lenght('A'));
		printf("!!!!!!,,,,,,%d\n", get_lenght('B'));

		return;
}
if( last->data <= second->data && last->data <= first->data)
	{
	append(&list_b, last->data);
		return;
}
}

void test()
{
	printf("Run test\n");
	if(get_lenght('A') == 0){
		printf("Primul%d\n",list_b->data);

			struct node* temp;

		temp = list_b;
		while(temp->next != NULL)
			{
				printf("TempB  %d\n", temp->data);
				temp = temp->next;
			}
			printf("TempB  %d\n", temp->data);
				temp = list_b;
		

	
		printf("%d\n",list_b->data );

	
		printf("!!!!!!,,,,,,%d\n", get_lenght('B'));
		printf("%s\n", "PB");
		return;

		}
			if(get_lenght('B') == 0){
		printf("Primul%d\n",list_a->data);

			struct node* temp;

		temp = list_a;
		while(temp->next != NULL)
			{
				printf("TempA  %d\n", temp->data);
				temp = temp->next;
			}
			printf("TempA  %d\n", temp->data);
				temp = list_a;
		

	
		printf("%d\n",list_a->data );

	
		printf("!!!!!!,,,,,,%d\n", get_lenght('A'));
		printf("%s\n", "PA");
		return;
	}



		printf("Primul%d\n",list_a->data);
		printf("Primul%d\n",list_b->data);

			struct node* temp;

		temp = list_a;
		while(temp->next != NULL)
			{
				printf("TempA  %d\n", temp->data);
				temp = temp->next;
			}
			printf("TempA  %d\n", temp->data);
				temp = list_b;
		while(temp->next != NULL)
			{
				printf("TempB  %d\n", temp->data);
				temp = temp->next;
			}
			printf("TempB  %d\n", temp->data);
		

		printf("%d\n",list_a->data );
		printf("%d\n",list_b->data );

		printf("@@@@@,,,,,,,%d\n", get_lenght('A'));
		printf("!!!!!!,,,,,,%d\n", get_lenght('B'));
		printf("%s\n", "PB");
}

void shufleLocalA()
{
	if(get_lenght('A') <= 2)
		{
	
			return;
		}


	struct node*  first;
	struct node*  second;
	struct node*  last;

	first = list_a;
	second = first->next;
	last = first->next;

	while(last->next != NULL)
	{
		last = last->next;
	}

	if( first->data >= second->data && first->data <= last->data)
		{
			sa();
			test();
		return;
		}


		if( second->data <= first->data && second->data <= last->data)
		{
		sa();
		test();
		return;
		}
		if( last->data <= second->data && last->data <= first->data)
		{
		rra();
		test();
		return;
		}

}

void shufleLocalB()
{
	if(get_lenght('B') <= 2)
		{
	
			return;
		}


	struct node*  first;
	struct node*  second;
	struct node*  last;

	first = list_b;
	second = first->next;
	last = first->next;
	while(last->next != NULL)
	{
		last = last->next;
	}
printf("LOCALs\n");

	if( first->data <= second->data && first->data >= last->data)
		{
			sb();
			test();
		return;
		}


		if( second->data <= first->data && second->data <= last->data)
		{
		sb();
		test();
		return;
		}
		if( last->data <= second->data && last->data <= first->data)
		{
		rrb();
		test();
		return;
		}

}

void shufleRealA()
{
			
	if(get_lenght('A') == 1)
		{
			pa();
			test();
			return;
		}


	struct node*  first;
	struct node*  second;
	struct node*  last;

	first = list_a;
	second = first->next;
	last = first->next;

	while(last->next != NULL)
	{
		last = last->next;
	}

	if( first->data <= second->data && first->data <= last->data)
		{
			pa();
			test();
		return;
		}


		if( second->data <= first->data && second->data <= last->data)
		{
		sa();
		pa();
		test();
		return;
		}
		if( last->data <= second->data && last->data <= first->data)
		{
		ra();
		pa();
		test();
		return;
		}

}

void shufleRealB()
{
	printf("Shuffle B\n");	
	//printf("@@@@@@@@@\n");
	//test();
	printf("@@@@@@@@@\n");


			
	if(get_lenght('B') == 1)
		{
			pb();
			//test();
			return;
		}


	struct node*  first;
	struct node*  second;
	struct node*  last;

	first = list_b;
	second = first->next;
	last = first->next;

	while(last->next != NULL)
	{
		last = last->next;
	}

printf("Print data %d | %d | %d |\n", first->data, second->data, last->data);
	if( first->data >= second->data && first->data >= last->data)
		{
			printf("U");
			pb();


			test();
		return;
		}


		if( second->data >= first->data && second->data >= last->data)
		{
			printf("D");
		sb();
		pb();
		test();

		return;
		}

		if( last->data >= second->data && last->data >= first->data)
		{
			printf("T");
		rb();
		pb();
		test();

		return;
		}

}
void algoritm(char **str, int size)
{
	int i;
	int value;


	i = 0;

	while(i < size)
	{
		value = atoi(str[i]);
		append(&list_a, value);
		i++;

	}
	i = 0;
while(i < size)
	{	
		shufleRealA();
		shufleLocalB();
		i++;
	
	}
	i = 0;
while(i < size)
	{	
		shufleRealB();
		shufleLocalA();
		i++;
	
	}

	test();
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
		strcat(str, b[k]);

		strcat(str, " ");
		k++;
	}


	
	int arglen;
	char **list = msh_get_args(str, " ", &arglen);


	algoritm(list, arglen);

return 0;
}
