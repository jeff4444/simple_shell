#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int _strcmp(char *s1, char *s2);
extern char **environ;
int _setenv(const char *name, const char *value, int overwrite)
{
        char *init_value, *output, *init_name;
        int i = 0;

	if (name == NULL || value == NULL || name[0] == '\0')
		return (-1);
	init_value = getenv(name);
        init_name = malloc(sizeof(name));
        while (name[i] != '\0')
        {
                init_name[i] = name[i];
                i++;
        }
        init_name[i] = '\0';
	init_name = strcat(init_name, "=");
	i = 0;
	output = strcat(init_name, value);
        if (!init_value || overwrite)
		i = putenv(output);
	if (i == 0)
		return (0);
        return (-1);
}

int _strcmp(char *s1, char *s2)
{
        int i = 0;

        while (s1[i] != '\0')
        {
                if (s1[i] != s2[i])
                        return (0);
                i++;
        }
        if (s2[i] != '\0')
                return (0);
        return (1);
}

int main() {
    _setenv("OLDPWD", "/", 1);
	char *name = getenv("OLDPWD");
	printf("%s\n", name);
    return 0;
}
