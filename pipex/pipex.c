#include "pipex.h"

int main (int argc, char **argv, char **env)
{
	int i_fd;
	int o_fd;
	char **comands_path;
	int path_chek_i;
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

				
			//wait(NULL);
			wait(NULL);
//			}

//			char **comand;
//		comand = (char **)malloc(sizeof(char*) * 3);
//		if(!comand)
//			return(0);
//		coma	nd[0] = ft_strdup("ls");
//		comand[1] = ft_strdup("-ls");
//		comand[2] = NULL;			
//		pipe(fdp);
//
//		pid1 = fork();
//		if(pid1 == 0)
//		{
//			dup2(fdp[1],1);
//			close(fdp[1]);
//			close(fdp[0]);
//			printf("%d",execve("/bin/ls",comand,env));
//		}
//
//
//		wait(NULL);
//		wait(NULL);
//
	}
	else 
		write(1,"pipex invalid it`s litel argument",33);
	//while(1);
	return(0);
   
}


void  chekin_file(char **fp, int argc,int *i_fd,int *o_fd )
{
	if((*i_fd = open(fp[1],O_RDWR)) < 0)
		{
			perror("not  input file ");
			exit(0);
		}
	if ((*o_fd = open(fp[argc - 1],O_RDWR | O_CREAT | O_TRUNC ,0644 )) < 0)
	{
		perror("out file error");
		exit(0);
	}
}

char **faund_path(char **env)
{
	char *full_path;
	int i ;

	i = 0;
	while(env[i])
	{
		if(ft_strncmp(env[i],"PATH=",5) == 0 )
		{
		   return(ft_split(env[i]+5,':'));
		}
		i++;	
	}
	return(NULL);
}

char ** chekin_comands( int argc,char **argv, char **env,int *path_chek_i)
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

void frik(char **s1)
{	
	int i;
	i = 0;
if(s1)
{
	while( s1[i])
		free(s1[i++]);
	free(s1);
}
}
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 && --n && *s1 == *s2 && s2++)
		s1++;
	return ((unsigned char)*s1 - (unsigned char)*s2);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	 char 	*nowstring;
	size_t	n;
	size_t	t;

	n = 0;
	t = 0;
	nowstring = (char *) malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!nowstring)
		return (0);
	while (s1[n])
	{	
		nowstring[n] = s1[n];
		n++;
	}
	while (s2[t])
		nowstring[n++] = s2[t++];
	nowstring[n++] = '\0';
	return (nowstring);
}

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (s[n])
		n++;
	return (n);
}
size_t	need_row(const char *s, char c )
{
	size_t	row ;
	char	flag;

	flag = 0;
	row = 0;
	while (*s)
	{
		if (*s != c && flag++ == 0)
			row++;
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (row);
}

char	**ft_split( char const *s, char c)
{
	char	**back;
	size_t	s_index;
	size_t	row_maloc;
	size_t	row_index;

	s_index = 0;
	row_maloc = 0;
	row_index = 0;
	back = (char **)malloc ((need_row(s, c) + 1) * sizeof(char *));
	if (!s && !back)
		return (0);
	back[need_row(s, c)] = NULL;
	while (row_index < need_row(s, c))
	{
		while (s[s_index] && s[s_index] == c)
			s_index++;
		while (s[s_index] && s[s_index] != c && ++row_maloc)
			s_index++;
		back[row_index++] = ft_substr(s, (s_index - row_maloc), row_maloc);
		s_index++;
		row_maloc = 0;
	}
	return (back);
}


char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	n;

	n = 0;
	if (ft_strlen(s) < start)
	{	
		new_str = malloc (sizeof(char));
		new_str[n] = '\0';
		return (new_str);
	}
	while (s[n] && n < len)
		n++;
	new_str = (char *)malloc(n + 1);
	if (!s || !new_str)
		return (0);
		n = 0;
	while (s[start + n] && n < len)
	{
		new_str[n] = s[start + n];
		n++;
	}
	new_str[n++] = '\0';
	return (new_str);
}


char	*ft_strdup(const char *s)
{
	size_t	n;
	char	*str;

	n = 0;
	str = malloc(ft_strlen(s) * sizeof(char) + 1);
	if (!str)
		return (NULL);
	while (*s)
		str[n++] = *s++;
	str[n] = '\0';
	return (str);
}

