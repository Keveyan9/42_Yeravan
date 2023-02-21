/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:52:05 by skeveyan          #+#    #+#             */
/*   Updated: 2022/02/12 15:52:30 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>


	
int	main(int  argc, char **argv)
{  

		int t;
	    int colup[4];
		int coldown[4];
		int rowleft[4] ;
		int rowright[4];
	if (argc > 1)
	{	int i;
		int b ;
		

		b = 0;
		i = 0;
		t = 0 ;

		int u ;
		int d;
		int l;
		int r;

		u = 0;
		d = 0;
		l = 0;
		r = 0;
		
		 while ( argv[1][i] != '\0') 
	    {
	    	if ('0'< argv[1][i] && argv[1][i] < '5')
	    	{
	    		// seperet chars ol char have 4 slot
	    		if(b < 4 && u < 4){
	    			colup[u] = argv[1][i] - 48  ;
	    			//printf("%d\n", colup[u] );
	    			u++;
	    		} 
	    		else if ((b > 3 && b < 8) && d < 4)
	    		{
	    			coldown[d] = argv[1][i] - 48 ;
	    			//printf("%d\n", coldown[d] );
	    			d++;
	    		}
	    		else if((b > 7 && b < 12) && l < 4)
	    		{
	    			rowleft[l] = argv[1][i] - 48 ;
	    			//printf("%d\n",rowleft[l] );
	    			l++;	
	    		}
	    		else if ((b > 11 && b < 16) && r < 4)
	    		{
	    			rowright[r] = argv[1][i] - 48 ; 
	    			//printf("%d\n", rowright[u] );
	    			r++;

	    		}
	    		else
	    		{

	    		}
	    		b++;
	    		i++;
	    		}
				else if (argv[1][i]==' '|| argv[1][i]==',')
				{
	     		i++;
			}
	     	else
	     	{
	    	write(1," 1 you Enter ancorect number", 30);
	     		goto verch;
	     	}


		}
		
	}
	else
	{
	write(1,"plise Enter corect number 1-4 and 16 pice \n",40);
	goto verch;
	}
// most add return going main funktion  if doing plise enter corect number 
  	//////SECEND CHEKIN //////  
  	int c;
	int r;
	int v ;
	v = 0;
	c = 0;
	r = 0;

 while(v < 4) 
 {
  	if(((colup[c] + coldown[c]) < 6) && ((colup[c] + coldown[c]) > 2 ))
  	{
  		//printf("%d\n",colup[c] );
  		c++;
  		v++;
 	 }
  	else
 	 {
 	 	write(1," 1 -plise Enter corect number 1-4 in colup and coldown 8 pice ",80);
  		goto verch;
 	 }

	if((rowleft[r] +rowright[r] ) < 6 && (rowleft[r] + rowright[r] > 2))
	{
		r++;
		v++;
	}
	else
	{
		write(1,"2 -plise Enter corect number 1-4in rowright  and rowleft pice ",80);
		goto verch;
	}	  
}

  // t = 0;
  //  while(t < 4)
  //     {
      	
	// printf("%d\n", colup[t] );
	// printf("%d\n", coldown[t] );
	// printf("%d\n", rowleft[t] );
	// printf("%d\n", rowright[t] );
	// t++;}
		// code algoritm 

	///manual 
	int matric[4][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0} };
	int calemb;
	int strong;
	strong = 0;
	calemb = 0;


//// air Funkshen ///
	
	int collum ;
	int row ;
	int douwn;
	row = 0;
	douwn = 3;
	collum  = 0;



	//int flagfor[4] ={0,0,0,0,};
	int x[4] ={0,0,0,0,};
	int y[4] ={0,0,0,0,};
	int p ;
	p  = 0; 

	while(row < 4)
	{ 

		switch(colup[row])
		{
			
			
			case 1:matric[0][row] = 4;y[p] = 0;x[p]=row;p++;
			break;
			case 4:matric[3][row] = 1;matric[2][row] = 2;matric[1][row] = 3;matric[0][row] = 4;y[p] = 0;x[p]=row;p++;
			break;
			// case 3:matric[2][row] = 4;
			// break;
		}


		
		switch(coldown[row])
		{
			
			
			case 1:matric[3][row] = 4;y[p] = 3;x[p]=row;p++;
			break;
			case 4:matric[3][row] = 1;matric[2][row] = 2;matric[1][row] = 3;matric[0][row] = 4; y[p] = 0;x[p]=row;p++;
			break;
			// case 3:matric[1][row] = 4;
			// break;
		}

			switch(rowleft[row])
		{
			
			case 1:matric[row ][0] = 4; y[p] = row ;x[p]=0;p++;
			break;
			 case 4:matric[row][0] = 1;matric[row][1] = 2;matric[row][2] = 3;matric[row][3] = 4; y[p] = row;x[p]=3;p++;
			break;
			// case 3:matric[row][2] = 4;
			// break;
		}
			switch(rowright[row])
		{
			
			case 1:matric[row ][3] = 4;  y[p] = row; x[p]=3;p++;
			break;
			 case 4:matric[row][3] = 1;matric[row][2] = 2;matric[row][1] = 3;matric[row][0] = 4; y[p] = row ;x[p]=0;p++;
			break;
			// case 3:matric[row][1] = 4;
			// break;
		}



row++;
}


		// if(colup[pic]==1)
		// {
		// 	matric[0][pic] = 4;
		// }
		// else if (pic)	
		
	







 //////manual ////////
    
while(strong<4){
	while(calemb < 4)
	{
      printf(" %d ",matric[strong][calemb]);
		printf(" ");
	//write(1, &matric[strong][strong], 4);
    calemb++;
     }
    printf(" \n");
   calemb = 0;
    strong++;
}
int test;
test = 0 ;
while(test < 5)
{    printf("%d ",x[test] );
		printf("%d ", y[test]);
	printf("\n " );
	test++;
}



    verch:
	return 0;
}


