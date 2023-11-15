#include "shell.h"

/**
 * main - a replica for shell
 * Return: exit value
*/
int main(int argc, char **argv, char **env)
{
  char *line = NULL, **a = NULL;
  size_t n;
  int status = 0, i = 0, proc = 1;

  (void)argc; (void)argv;
  while (1)
  {
    if (isatty(0))
      _print("$ ");
    if (getline(&line, &n, stdin) == -1)
      {
        isatty(0) ? _print("\n") : _print("");
        break; }
    if (count(line) == 0)
			continue;
		line[_strlen(line) - 1] = '\0';
    a = tokenize(line);
    _free(a, _strlen_(a));
    printf("first free\n");
    a = tokenize(line);
    i = 0;
    while (a[i])
    {
      printf("%s\n", a[i]);
      i++;
    }	
    status = execmd(a, env, proc);
    i = 0;
    while(a[i])
    {
      printf("free %s\n", a[i]);
      free(a[i]);
      i++; }
    free(a);
    proc++; }
  free(line);
  exit(status);
}