#include"REG52.H"
#include"intrins.h"

#define uchar unsigned char
#define uint unsigned int

uchar Tab[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
uchar nt=60,wt=60,sz=0,t,DJS=60,seg=60,tx=10;
bit ms=0;//???

sbit k = P3^4;	   
sbit g = P3^5;	   
sbit a = P3^7;    
sbit j = P3^6;     

sbit we1=P2^0;
sbit we2=P2^1;

sbit NSG=P1^2;
sbit NSY=P1^1;
sbit NSR=P1^0;
sbit WEG=P1^5;
sbit WEY=P1^4;
sbit WER=P1^3;



void delay(uint t);
void display();
void Init_Timer0(void);
void NST();
void WET();
void jstx();
void keycan();


void main()
{
	Init_Timer0();
	while(1)
	{
		if(sz==3)    
		{
		
			seg=tx;    
			jstx();	   
		}
		if(sz==1)   
		{seg=nt;}   
		if(sz==2)   
		{seg=wt;}   
		if(sz==0)   
		{
			if(ms==0) 
			{NST();}  
			if(ms==1) 
			{WET();}  
		}
		keycan();
		display();
	}
	
}

void delay(uint t)	          
{
	uchar x,y;
	for(x=0;x<t;x++)    
		for(y=0;y<200;y++);
}

void display()
{
		we1=0;
	  we2=1;  
		P0=Tab[seg%10]; 
		delay(5);  
		P0=0x00;   
		we1=1;     
	  we2=0;     
		P0=Tab[seg/10]; 
		delay(5);   
		P0=0x00;	  
}

void Init_Timer0(void)
{
 	TMOD &= 0XF0;
 	TMOD |= 0x01;	      
	TH0=0x3c;       
	TL0=0xb0;
   IP=0x02;     
	TR0=1;  
	ET0=1;  
   EA=1;	
}

void timer0 (void) interrupt 1 //using 0
{
	TH0=0x3c; 
	TL0=0xb0;
	t++;        
	if(t==20) 
	{
		DJS--;   
		t=0;
		if(DJS<=5)
		{
			if(ms==1)    
			{NSY=~NSY;}  
			if(ms==0)    
			{WEY=~WEY;}  
			else(NSY||WEY==1);
		}
		if(DJS==0)      
		{
			ms=~ms;      
			NSY=1;       
			WEY=1;       
			if(ms==0)    
			{DJS=nt;}    
			if(ms==1)     
			{DJS=wt;}    
		}
		if(sz==3)  
		{
			tx--;  
			if(tx==0)
			{sz=0;}
		}
	}	
}

void WET()
{
	seg=DJS;
	NSG=1;
	NSR=0;
	NSY=1;
	WER=1;
	WEG=0;
	WEY=1;
}

void NST()
{
	seg=DJS;
	NSG=0;
	NSR=1;
	NSY=1;
				
	WER=0;
	WEG=1;
	WEY=1;
}


void jstx()
{
	
	NSG=1;
	NSR=0;
	NSY=1;
	WEG=1;
	WER=0;
	WEY=1;

}

void keycan()
{
	if(k==0)
	{
		delay(10);
		if(k==0)  
		{
			sz++; 
			if(sz==4) 
			{sz=0;}  
			if(sz==3) 
			{tx=10;} 
		}
		while(!k);
	}
	if(a==0&&sz==1)	
	{
		delay(10);
		if(a==0&&sz==1)
		{
			nt++;       
			if(nt==61) 
			{nt=1;}    
		}
		while(!a);  
	}
	if(a==0&&sz==2)	
	{
		delay(10);
		if(a==0&&sz==2)
		{
			wt++;
			if(wt==61)
			{wt=1;}
		}
		while(!a);
	}
	if(j==0&&sz==1)
	{
		delay(10);
		if(j==0&&sz==1)
		{
			nt--;
			if(nt==0)
			{nt=60;}
		}
		while(!j);
	}
	if(j==0&&sz==2)
	{
		delay(10);
		if(j==0&&sz==2)
		{
			wt--;
			if(wt==0)
			{wt=60;}
		}
		while(!j);
	}
	if(g==0)
	{
		delay(10);
		if(g==0)
		{sz=0;}    
		while(!g); 
	}
}


