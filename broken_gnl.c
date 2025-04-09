#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include <fcntl.h>



int ft_strlen(char *c)
{
	int i;

	if(c == NULL)
		return(0);
	i = 0;
	while(c[i])
	{
		i++;
	}
	return(i);
}

char *ft_strchr(char *s, int c)
{
	int i;

	i = 0;
	while(s[i])
	{
		if(s[i] == (char)c)
			return(&s[i]);
		i++;
	}
	if( c == '\0')
		return(&s[i]);
	return(NULL);
}

char *ft_memmove(char *dest, char *src, int n)
{
	int i;

	if(!dest && !src)
		return(NULL);
	if(dest < src)
	{
		i = 0;
		while(i < n)
		{
			dest[i] = src[i];
			i++;
		}
	}
	else
	{
		i = n - 1;
		while(i >= 0)
		{
			dest[i] = src[i];
			i--;
		}
	}
	return(dest);
}

int ft_join(char *s1, char *s2, int n)
{

	printf("s1 = %s\n", s1);
	printf("s2 = %s\n", s2);

	char *retj = NULL;
	int size1 = ft_strlen(s1);
	printf("size1 = %d\n", size1);
	int size2 = ft_strlen(s2);
	printf("size2 = %d\n", size2);

	retj = malloc (sizeof(char) * (size1 + size2 + 1));
	if(!retj)
	{
		return (-1);
	}
	ft_memmove(retj, s1, size1);
	ft_memmove(retj + size1, s2, size2);
	retj[size1 + size2 + 1] = 0;

	printf("retj = %s\n", retj);


	return(0);
}

char *buffer(fd)
{
	static char buf[BUFFER_SIZE + 1];
	char *ret = NULL;
	char *tmp = NULL;
	int nb_read = 0;

	nb_read = read(fd , buf, BUFFER_SIZE);
	if(nb_read < 0)
		return(NULL);
	buf[nb_read] = '\0';
	if(nb_read == 0)
	{
		printf("nb_read = 0");
	}
	else
	{
		tmp = ft_strchr(buf, '\n');
		tmp = buf;
		printf("tmp = %s\n", tmp);
		printf("buffer = %s\n", buf);
		ft_join(buf, tmp, 0);

	}
	return(ret);
}

int main(void)
{
	int fd = 0;

	fd = open("text1.txt", O_RDONLY);
	if(fd < 0)
		perror("open");
	buffer(fd);


	return(0);
}
