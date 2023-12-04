#include"main.h"
/**
 * main- where the program will start
 * Return: An int
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		display_prompt();
		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			printf("\n");
			break;
		}
		command[strcspn(command, "\n")] = '\0';
		if (strlen(command) == 0)
		{
			continue;
		}

		if (!execute_command(command))
		{
			fprintf(stderr, "Command not found: %s\n", command);
		}
	}

	return (0);
}
