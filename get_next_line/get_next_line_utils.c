#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	i;

	i = 0;
	p = malloc((ft_strlen(s) + 1));
	if (p == NULL)
		return (p);
	while (i < ft_strlen(s) + 1)
	{
		*(p + i) = s[i];
		i++;
	}
	return (p);
}

static void	ft_len(char const *s1, char const *s2, size_t *lens1, size_t *lens2)
{
	*lens1 = ft_strlen(s1);
	*lens2 = ft_strlen(s2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	lens1;
	size_t	lens2;
	char	*p;

	if (!s1 || !s2)
		return (NULL);
	ft_len(s1, s2, &lens1, &lens2);
	p = malloc(lens1 + lens2 + 1);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < lens1)
	{
		p[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < lens2)
	{
		p[i + lens1] = s2[i];
		i++;
	}
	p[i + lens1] = '\0';
	return (p);
}