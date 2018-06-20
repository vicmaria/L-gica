//Trabalho de Anaísa Forti e Victoria Rodrigues

#include <stdio.h>

void ImprimeRelacoes(int n, FILE *arq)
{
	fprintf(arq,"{");
		
			if((n & 32768) == 32768)
			 fprintf(arq,"(1,1)");
			 
			if((n & 16384) == 16384)
			 fprintf(arq,"(1,2)");
			
			if((n & 8192) == 8192)
			 fprintf(arq,"(1,3)");
			 
			if((n & 4096) == 4096)
			 fprintf(arq,"(1,4)");
			
			if((n & 2048) == 2048)
			 fprintf(arq,"(2,1)");
		
			if((n & 1024) == 1024)
			 fprintf(arq,"(2,2)");
			
			if((n & 512) == 512)
			 fprintf(arq,"(2,3)");
			
			if((n & 256) == 256)
			 fprintf(arq,"(2,4)");
			
			if((n & 128) == 128)
			 fprintf(arq,"(3,1)");
			
			if((n & 64) == 64)
			 fprintf(arq,"(3,2)");
		
			if((n & 32) == 32)
			 fprintf(arq,"(3,3)");
			
			if((n & 16) == 16)
			 fprintf(arq,"(3,4)");
			 
			if((n & 8) == 8)
			 fprintf(arq,"(4,1)");
			
			if((n & 4) == 4)
			 fprintf(arq,"(4,2)");
			
			if((n & 2) == 2)
			 fprintf(arq,"(4,3)");
			 
			if((n & 1) == 1)
			 fprintf(arq,"(4,4)");
			
			fprintf(arq,"}");
}

int Transitiva(int n, FILE *arq)
{
	int t = 1;
	
     if( 0 < (n & 61440) < 61440)
   {
		if(((n & 16384) == 16384) && ((n & 3840) != 0))  //verifica (1,2) e (2,z)
	{
		  if(((n & 2048) == 2048) && (n & 32768) != 32768)  //(2,1) (1,1)
		   t = 0;
		  if(((n & 512) == 512) && (n & 8192) != 8192)    //(2,3)  (1,3)
		   t = 0; 
		  if(((n & 256) == 256) && (n & 4096) != 4096)    //(2,4)  (1,4)
		   t = 0; 
	}
	
	if(t == 1)
	{
		if(((n & 8192) == 8192) && ((n & 240) != 0))  //verifica (1,3) e (3,z)
	   {
		  if(((n & 128) == 128) && (n & 32768) != 32768)  //(3,1) (1,1)
		   t = 0;
		  if(((n & 64) == 64) && (n & 16384) != 16384)    //(3,2)  (1,2)
		   t = 0; 
		  if(((n & 16) == 16) && (n & 4096) != 4096)    //(3,4)  (1,4)
		   t = 0; 
	   }
	
	}
	if(t == 1)
	{
		if(((n & 4096) == 4096) && ((n & 15) != 0))  //verifica (1,4) e (4,z)
	   {
		  if(((n & 8) == 8) && (n & 32768) != 32768)  //(4,1) (1,1)
		   t = 0;
		  if(((n & 4) == 4) && (n & 16384) != 16384)    //(4,2)  (1,2)
		   t = 0; 
		  if(((n & 2) == 2) && (n & 8192) != 8192)    //(4,3)  (1,3)
		   t = 0; 
	   }
	
	}
   }
   
	 if(0 < (n & 3840) < 3840)
   {
   	 	if(t == 1)
	{
		if(((n & 2048) == 2048) && ((n & 61440) != 0))  //verifica (2,1) e (1,z)
	{
		  if(((n & 16384) == 16384) && (n & 1024) != 1024)  //(1,2) (2,2)
		   t = 0;
		  if(((n & 8192) == 8192) && (n & 512) != 512)    //(1,3)  (2,3)
		   t = 0; 
		  if(((n & 4096) == 4096) && (n & 256) != 256)    //(1,4)  (2,4)
		   t = 0; 
	}
   }
	
	if(t == 1)
	{
		if(((n & 512) == 512) && ((n & 240) != 0))  //verifica (2,3) e (3,z)
	   {
		  if(((n & 128) == 128) && (n & 2048) != 2048)  //(3,1) (2,1)
		   t = 0;
		  if(((n & 64) == 64) && (n & 1024) != 1024)    //(3,2)  (2,2)
		   t = 0; 
		  if(((n & 16) == 16) && (n & 256) != 256)    //(3,4)  (2,4)
		   t = 0; 
	   }
	
	}
	if(t == 1)
	{
		if(((n & 256) == 256) && ((n & 15) != 0))  //verifica (2,4) e (4,z)
	   {
		  if(((n & 8) == 8) && (n & 2048) != 2048)  //(4,1) (2,1)
		   t = 0;
		  if(((n & 4) == 4) && (n & 1024) != 1024)    //(4,2)  (2,2)
		   t = 0; 
		  if(((n & 2) == 2) && (n & 512) != 512)    //(4,3)  (2,3)
		   t = 0; 
	   }
	
	}
   }
  
  if(0 < (n & 240) < 240)
  {
  	  if(t == 1)
   	{
		if(((n & 128) == 128) && ((n & 61440) != 0))  //verifica (3,1) e (1,z)
	{
		  if(((n & 16384) == 16384) && (n & 64) != 64)  //(1,2) (3,2)
		   t = 0;
		  if(((n & 8192) == 8192) && (n & 32) != 32)    //(1,3)  (3,3)
		   t = 0; 
		  if(((n & 4096) == 4096) && (n & 16) != 16)    //(1,4)  (3,4)
		   t = 0; 
	}
    }
	
	if(t == 1)
	{
		if(((n & 64) == 64) && ((n & 3840) != 0))  //verifica (3,2) e (2,z)
	   {
		  if(((n & 2048) == 2048) && (n & 128) != 128)  //(2,1) (3,1)
		   t = 0;
		  if(((n & 512) == 512) && (n & 32) != 32)    //(2,3)  (3,3)
		   t = 0; 
		  if(((n & 256) == 256) && (n & 16) != 16)    //(2,4)  (3,4)
		   t = 0; 
	   }
	
	}
	if(t == 1)
	{
		if(((n & 16) == 16) && ((n & 15) != 0))  //verifica (3,4) e (4,z)
	   {
		  if(((n & 8) == 8) && (n & 128) != 128)  //(4,1) (3,1)
		   t = 0;
		  if(((n & 4) == 4) && (n & 64) != 64)    //(4,2)  (3,2)
		   t = 0; 
		  if(((n & 2) == 2) && (n & 32) != 32)    //(4,3)  (3,3)
		   t = 0; 
	   }
	
	}
   }
   
   if(0 < (n & 15) < 15)  
  {
  	 if(t == 1)
	{
		if(((n & 8) == 8) && ((n & 61440) != 0))  //verifica (4,1) e (1,z)
	{
		  if(((n & 16384) == 16384) && (n & 4) != 4)  //(1,2) (4,2)
		   t = 0;
		  if(((n & 8192) == 8192) && (n & 2) != 2)    //(1,3)  (4,3)
		   t = 0; 
		  if(((n & 4096) == 4096) && (n & 1) != 1)    //(1,4)  (4,4)
		   t = 0; 
	}
   }
	
	if(t == 1)
	{
		if(((n & 4) == 4) && ((n & 3840) != 0))  //verifica (4,2) e (2,z)
	   {
		  if(((n & 2048) == 2048) && (n & 8) != 8)  //(2,1) (4,1)
		   t = 0;
		  if(((n & 512) == 512) && (n & 2) != 2)    //(2,3)  (4,3)
		   t = 0; 
		  if(((n & 256) == 256) && (n & 1) != 1)    //(2,4)  (4,4)
		   t = 0; 
	   }
	
	}
	if(t == 1)
	{
		if(((n & 2) == 2) && ((n & 240) != 0))  //verifica (4,3) e (3,z)
	   {
		  if(((n & 128) == 128) && (n & 8) != 8)  //(3,1) (4,1)
		   t = 0;
		  if(((n & 64) == 64) && (n & 4) != 4)    //(3,2)  (4,2)
		   t = 0; 
		  if(((n & 32) == 32) && (n & 2) != 2)    //(3,4)  (4,3)
		   t = 0; 
	   }
	
	}
   }
	
	if(t == 1)
	fprintf(arq,"T");
	return t;
}

int Simetria(int n, FILE *arq)
{
	int s = 1;
	
	if(((n & 2048) == 2048) ^ ((n & 16384) == 16384))
	  s = 0;
	
	if(s == 1)
	if(((n & 128) == 128) ^ ((n & 8192) == 8192))
	  s = 0;
	
	if(s == 1)
	if(((n & 8) == 8) ^ ((n & 4096) == 4096))
	  s = 0;
	
	if(s == 1)
	if(((n & 64) == 64) ^ ((n & 512) == 512))
	  s = 0;
	  
	if(s == 1)	
	if(((n & 4) == 4) ^ ((n & 256) == 256))
	  s = 0;

	if(s == 1)	
	if(((n & 2) == 2) ^ ((n & 16) == 16))
	  s = 0;
	  
	if(s == 1)
	{
		fprintf(arq, "S");
	}
	return s;
	
}

int Reflexiva(int n, FILE *arq)
{
	int r = 0;
	if((n & 33825) == 33825)  
	 {
	 	fprintf(arq,"R"); 
	 	r = 1;
	  } 
	return r;
}

void Irreflexiva(int n, FILE *arq)
{
	int i = 1;
	
	if(((n & 32768) == 32768) || ((n & 1024) == 1024) || ((n & 32) == 32) || ((n & 1) == 1)) 
	 i = 0;
	 
	if(i==1)
	fprintf(arq,"I");
}

void Bijetora(int n, FILE *arq)
{
	int b = 0;
	
	if((((n & 32768) == 32768) ^ ((n & 2048) == 2048)) ^ (((n & 128) == 128) ^ ((n & 8) == 8)))
	 b = 1;
	if((((n & 32768) == 32768) ^ ((n & 2048) == 2048)) && (((n & 128) == 128) ^ ((n & 8) == 8)))
	 b = 0;
	if((((n & 32768) == 32768) && ((n & 2048) == 2048)) ^ (((n & 128) == 128) && ((n & 8) == 8)))
	 b = 0;
	 
	if(b == 1) 
	{
		if((((n & 16384) == 16384) ^ ((n & 1024) == 1024)) ^ (((n & 64) == 64) ^ ((n & 4) == 4)))
	     b = 1; 
	    if((((n & 16384) == 16384) ^ ((n & 1024) == 1024)) && (((n & 64) == 64) ^ ((n & 4) == 4)))
	     b = 0; 
	    if((((n & 16384) == 16384) && ((n & 1024) == 1024)) ^ (((n & 64) == 64) && ((n & 4) == 4)))
	     b = 0; 
	}
	
	if(b == 1)
	{
		if((((n & 8192) == 8192) ^ ((n & 512) == 512)) ^ (((n & 32) == 32) ^ ((n & 2) == 2)))
	     b = 1;
	    if((((n & 8192) == 8192) ^ ((n & 512) == 512)) && (((n & 32) == 32) ^ ((n & 2) == 2)))
	     b = 0;
	    if((((n & 8192) == 8192) && ((n & 512) == 512)) ^ (((n & 32) == 32) && ((n & 2) == 2)))
	     b = 0;
	}
	 
	if(b == 1)
	{
		if((((n & 4096) == 4096) ^ ((n & 256) == 256)) ^ (((n & 16) == 16) ^ ((n & 1) == 1)))
	     b = 1;
	    if((((n & 4096) == 4096) && ((n & 256) == 256)) ^ (((n & 16) == 16) && ((n & 1) == 1)))
	     b = 0;
	    if((((n & 4096) == 4096) ^ ((n & 256) == 256)) && (((n & 16) == 16) ^ ((n & 1) == 1)))
	     b = 0;
	}
	
	if(b == 1)
	 fprintf(arq,"FiFbFs");
}

void Funcao(int n, FILE *arq)
{
	int f = 2;
	
	if(((n & 61440) != 0) && ((n & 3840) != 0) && ((n & 240) != 0) && ((n & 15) != 0))
	{
	  
	   	if(((n & 32768) == 32768) ^ ((n & 16384) == 16384))
		{
			f = 1;
		 if(((n & 8192) == 8192) || ((n & 4096) == 4096))
		    f = 0;
		}
		if(((n & 8192) == 8192) ^ ((n & 4096) == 4096))  //(1,3) (1,4)
		{
			f = 1;
			if(((n & 32768) == 32768) || ((n & 16384) == 16384))
			 f = 0;
		}
	  
	 if(f == 1)
	  {	
	    if((((n & 2048) == 2048) && ((n & 1024) == 1024)) && (((n & 512) == 512) && ((n & 256) == 256)))
	     f = 0;
	    if((((n & 2048) == 2048) && ((n & 1024) == 1024)) ^ (((n & 512) == 512) && ((n & 256) == 256)))
	     f = 0;
	    if((((n & 2048) == 2048) ^ ((n & 1024) == 1024)) && (((n & 512) == 512) ^ ((n & 256) == 256)))
	     f = 0;
	  }
	
	 if(f == 1)
	   {
		 if((((n & 128) == 128) && ((n & 64) == 64)) && (((n & 32) == 32) && ((n & 16) == 16)))
		  f = 0;
		 if((((n & 128) == 128) && ((n & 64) == 64)) ^ (((n & 32) == 32) && ((n & 16) == 16)))
		  f = 0;
		 if((((n & 128) == 128) ^ ((n & 64) == 64)) && (((n & 32) == 32) ^ ((n & 16) == 16)))
		  f = 0;			
	 }
	 
	 if(f == 1)
	   {	
		if((((n & 8) == 8) && ((n & 4) == 4)) && (((n & 2) == 2) && ((n & 1) == 1)))
		 f = 0;
		if((((n & 8) == 8) && ((n & 4) == 4)) ^ (((n & 2) == 2) && ((n & 1) == 1)))
		 f = 0;
		if((((n & 8) == 8) ^ ((n & 4) == 4)) && (((n & 2) == 2) ^ ((n & 1) == 1)))
		 f = 0;
     }
    }
	
	if(f == 1)
	{
		fprintf(arq,"F");
		Bijetora(n, arq);
	}
	
	
}

int main ()
{
	int n,s, t, r;
	FILE *arq;
	
	if((arq = fopen("tarefa3.txt", "w")) != NULL)
	{
		for(n = 65535; n > -1; n--)
		{
			ImprimeRelacoes(n, arq);
			r = Reflexiva(n, arq);
			s = Simetria(n, arq);
	        t = Transitiva(n, arq);
	
	        if((s == 1) && (t == 1) && (r == 1))
	        fprintf(arq,"E");
			
			Irreflexiva(n, arq);
			Funcao(n, arq);
			
			fprintf(arq,"\n");
		}
	   fclose(arq);
	}
	else
	  printf("ERRO");
	
	return 0;
}
