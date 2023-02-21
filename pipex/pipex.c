#include "pipex.h"

int main (int argc, char **argv, char **env)
{
	int i_fd;
	int o_fd;
	char **path;

	char **comands;
	char *cheked_path;


	int *pip;
	int pip_i;
	int comands_pes;
	pid_t pid;
	int c_i = 0;

	int n = 0;
	i_fd =0;
	o_fd = 0;
	pip_i = 0;	
	path_chek_i = 0;
	comands_pes = argc - 4;

	if ( argc >=  4)
	{
		chekin_file(argv,argc,&i_fd, &o_fd);
		path = faund_path(env);		
	



	
		comands_path = chekin_comands(argc,argv,env,&path_chek_i);

		while ( n < path_chek_i- 1)
			printf("%s\n",comands_path[n++]);
		
		pip = (int*)malloc(sizeof(int)*comands_pes*2);
		if(!pip)
			exit(0);
		while(pip_i < (comands_pes *2))
		{
			pipe(&pip[pip_i*2]);
			pip_i++;
		}
		pip_i = 0;
//		while(comands_pes-- )
			//{
			pid = fork();
			printf("#%d##\n",pid);
				if (pid == 0)
				{

					printf("ferst\n");
					printf("secend\n");
					printf("@@@%s@@@\n",comands_path[0]);
					printf("@@@%s@@@\n",comands_path[1]);
					dup2(i_fd,0);
					dup2(pip[++pip_i],1);
					close(i_fd);
					close(o_fd);
					while(pip_i < comands_pes*2)
						close(pip[pip_i++]);

				//	comans_path[0]= "bin/ls";
			//		comands_path [3] = NULL;
				//	comands_path[1] = "-la";
					execve(comands_path[0],&comands_path[1], env);
					exit(0);
				}
					printf("heto\n");		
				pid = fork();
  		if (pid == 0)
			{
				printf("secend\n");
				printf("@@@%s@@@\n",comands_path[4]);
				printf("@@@%s@@@\n",comands_path[5]);
				dup2(pip[pip_i],0);
				dup2(o_fd,1);
				pip_i = 0;
				close(i_fd);
				close(o_fd);
				while(pip_i < argc*2)
					close(pip[pip_i++]);
				execve(comands_path[4],&comands_path[5],env);
				exit(0);
			}
			wait(NULL);
	}
	else 
		write(1,"pipex invalid it`s litel argument",33);
  while(1);
	return(0);
   
}

char  **chekin_comands ( int argc,char **argv, char **env,int *path_chek_i)
{
	t_chek_comands var;
	
	var.path_i = 0;
	var.comands_n = 0;
	var.path = faund_path(env);

	var.comands_path = (char **) malloc(sizeof(char**)*(argc - 3)*4 + 1);
	if(!var.comands_path)
		exit(0);
	while(var.comands_n < argc - 3)
 	{	
		var.comands = ft_split(argv[var.comands_n + 2],' ');
	while(var.path[var.path_i] && (access(( var.path_chek = 
							ft_strjoin(var.path[var.path_i],(var.comand_slesh = ft_strjoin("/",var.comands[0])))),F_OK)))
				{
					free(var.path_chek);	
					free(var.comand_slesh);
					var.path_i++;
				}
		if(var.path[var.path_i] && !access(var.path_chek,F_OK ))
			{
				var.comands_path[(*path_chek_i)++] = var.path_chek;
				free(var.comand_slesh);
			   	var.comands_path[(*path_chek_i)++] = var.comands[0];
				var.comands_path[(*path_chek_i)++] = var.comands[1];
				var.comands_path[(*path_chek_i)++] = NULL;
				var.path_i = 0;	
			}
    	else
		{
			if(var.path_chek)
				free(var.path_chek);
			if(var.comand_slesh)
				free(var.comand_slesh);
			write(1,"not found comand",20);
			exit(0);
		}
		var.comands_n++;
		free(var.comands);
	}
		var.comands_path[(*path_chek_i)++] = NULL;
	frik(var.path);
	return(var.comands_path);
}
