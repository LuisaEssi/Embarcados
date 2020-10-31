#include<stdio.h>
#include<wiringPi.h>
#include"decod.h"
#include<sys/types.h>
#include <unistd.h>

#define SENSOR_ENTRADA 0
#define SENSOR_SAIDA 2
#define SENSOR_ALCOOL 3
#define LED 7
#define CATODO_D 28
#define CATODO_U 29

int qtd_pessoas = 0;  // entrada = 0, saida = 0; 


int main()
{
    wiringPiSetup();
    pinMode(SENSOR_ENTRADA,INPUT);
    pinMode(SENSOR_SAIDA,INPUT);
    pinMode(SENSOR_ALCOOL,INPUT);
    pinMode(LED,OUTPUT);
    pinMode(CATODO_U,OUTPUT);
    pinMode(CATODO_D,OUTPUT);
    pid_t pid1;
   
    pid1 = fork();

    //filho cuida do sensor e o pai cuida do alcool 
    if (pid1 == 0)  
    {
	while(1)
	{
	    if(digitalRead(SENSOR_ENTRADA) == 0)        // detecta se há presença 
	    {
		if (qtd_pessoas<100 && qtd_pessoas>=0)
		{
		    qtd_pessoas=qtd_pessoas+1;
		    printf("%d\n", qtd_pessoas);
		}
		
		while(digitalRead(SENSOR_ENTRADA) == 0)
		{	    
		    decode(qtd_pessoas%10);
		    digitalWrite(CATODO_U,HIGH);
		    digitalWrite(CATODO_D,LOW);
		    usleep(5000);
		    decode(qtd_pessoas/10);
		    digitalWrite(CATODO_U,LOW);
		    digitalWrite(CATODO_D,HIGH);
		    usleep(5000); 
			}
		// aguarda enquato o sensor ainda esta com presença         
	    }else if(digitalRead(SENSOR_SAIDA) == 0)        // detecta se há presença 
	     {
		if (qtd_pessoas>0)
		{
		  qtd_pessoas= qtd_pessoas-1;
		    printf("%d\n", qtd_pessoas);
		}
		
		while(digitalRead(SENSOR_SAIDA) == 0)
		{
		    decode(qtd_pessoas%10);
		    digitalWrite(CATODO_U,HIGH);
		    digitalWrite(CATODO_D,LOW);
		    usleep(5000);
		    decode(qtd_pessoas/10);
		    digitalWrite(CATODO_U,LOW);
		    digitalWrite(CATODO_D,HIGH);
		    usleep(5000); 
		    } // aguarda enquato o sensor ainda esta com presença         
	     }
	    
	   
	    decode(qtd_pessoas%10);
	    digitalWrite(CATODO_U,HIGH);
	    digitalWrite(CATODO_D,LOW);
	    usleep(5000);
	    decode(qtd_pessoas/10);
	    digitalWrite(CATODO_U,LOW);
	    digitalWrite(CATODO_D,HIGH);
	    usleep(5000); 
    
	}
	
    }else{

         while(1){  
	
          if(digitalRead(SENSOR_ALCOOL) == 0)        // detecta se há presença 
          {
            digitalWrite(LED,HIGH);
	    usleep(500000);
            while(digitalRead(SENSOR_ALCOOL) == 0); // aguarda enquato o sensor ainda esta com presença  
            digitalWrite(LED,LOW);  
	    }  
	}
    }

return 0; 
}
