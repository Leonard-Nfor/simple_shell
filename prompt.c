#include"main.h"
/**
 * display_prompt - write $ to stdout
 * Return: Nothing
 */
void display_prompt(void)
{
	printf("$ ");
	fflush(stdout);
}
/**
 * execute_command- excute any command given
 * @command: The command to be past
 * Return: an integer
 */
int execute_command(char *command)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		char *args[] = {command, NULL};
		if (execve(command, args, environ) == -1)
		{
			perror("Execution failed");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
		{
			return (1);
		}
	}
	return (0);
}
