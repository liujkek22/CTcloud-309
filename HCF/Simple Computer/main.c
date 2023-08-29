/*
���̰���˵����
--------------------------------------------------
            |  1  |  2  |  3  |  +  |  
            - - - - - - - - - - - - -
            |  4  |  5  |  6  |  -  |
            - - - - - - - - - - - - -
            |  7  |  8  |  9  |  *  |
            - - - - - - - - - - - - -
			      | 0   |  CE |  =  |  /  | 
--------------------------------------------------*/
//�������
// ����һ�������ٰ�'+-*/',�ٰ�'='��ʾ�������Ȼ��C����
// �����9999+9999=19998
// �����9999-0   =9999
// �����9999*9999=99980001
// �� 1/9=0.1111 ����С�����4λ
#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char
	
//--------LCD1602-------------------
//P00-07==== D0-7
sbit rs=P0^0;
sbit rw=P0^1;
sbit lcden=P0^2;
//--------LCD1602-------------------
//--------KEY-----------------------
//P1��
//--------KEY-----------------------
uchar code table[]="                ";

long int data_a,data_b;//��һ�����͵ڶ�����
long int data_c;//������

uchar display[10];//  ��ʾ����



void delay_ms(uint x)
{
	uint i,j;
	for(i=x;i>0;i--)//ִ��x��ѭ��
	{
		for(j=110;j>0;j--);//ִ��110��ѭ��
	}
}

void delay_us(uint t)
{
    while(t--);     //t=0 ���˳�
}


//************************************************************************/
// ������1602Һ��дָ��
//************************************************************************/
void write_com(uchar com)  //1602Һ��дָ��
{
    rs=0;                    //дָ��
	lcden=0;                 //��ʹ��
	P2=com;                  //д��ָ��com
	delay_ms(1);             //��ʱ1ms
	lcden=1;                 //ʹ��1602
	delay_ms(2);             //��ʱ2ms
	lcden=0;                 //��ʹ��
}

//************************************************************************/
//������1602Һ��д����
//************************************************************************/
void write_date(uchar date)//1602Һ��д����
{
    rs=1;                    //д����
	lcden=0;                 //��ʹ�� 
	P2=date;                 //д������date
	delay_ms(1);             //��ʱ1ms
	lcden=1;                 //ʹ��1602
	delay_ms(2);             //��ʱ2ms
	lcden=0;                 //��ʹ��
}

//************************************************************************/
// ������ָ��x,yд���ַ�����
//************************************************************************/
void W_lcd(unsigned char x,unsigned char y,unsigned char Data)
{
   if(y==0){write_com(0x80+x);} //��һ��
   else{write_com(0xc0+x);}     //�ڶ���
   write_date(Data);            //д������ 
}	
//ָ��x,yд���ַ�������
void LCD_Write_String(unsigned char x,unsigned char y,unsigned char *s)
{
  if(y==0){write_com(0x80+x);} //��һ��
   else{write_com(0xc0+x);}    //�ڶ���
	while(*s)
	{write_date(*s);s++;}        //д������

}	

//************************************************************************/
// ��������ʼ��Һ�����������ʼ��
//************************************************************************/
void init_lcd(void)             //��ʼ��Һ�����������ʼ��
{
    rw=0;                        //дҺ��
	lcden=0;                      //ʹ��1602	
	write_com(0x38);              //8λ���ߣ�˫����ʾ��5��7�ĵ����ַ�  
	delay_us(100);                //��ʱ100us
	write_com(0x0c);              //����ʾ���޹�꣬��겻��˸
	write_com(0x06);              //������ƶ�
	write_com(0x01);              //����
	write_com(0x80);              //DD RAM ��ַ��0

}

//************************************************************************/
//��������ת������ɨ��
//************************************************************************/
short keycheckdown()            //��ת������ɨ��
{
  short temp1,temp2,temp,a=0xff;
	P1=0xf0;
	delay_ms(20);
	temp1=P1; //����ֵ
	P1=0xff;
	delay_ms(20);
	P1=0x0f;
	delay_ms(20);
	temp2=P1; //����ֵ
	P1=0xff;
	temp=(temp1&0xf0)|(temp2&0xff);//�����ζ����������
  switch(temp)	                  //ͨ��������������жϰ���λ��
{

        case 0x77 :a=0xd;break;//  ����/   
		case 0xb7 :a=0xe;break;// ����=	
		case 0xd7 :a=0xf;break;// ����CE 
		case 0xe7 :a=0;break;// ����0

		case 0x7b :a=0xc;break;// 	����*
		case 0xbb :a=9;break; //  ����9
		case 0xdb :a=8;break; //  ����8 
		case 0xeb :a=7;break; // 	����7

		case 0x7d :a=0xb;break;//  ����-
		case 0xbd :a=6;break; // 	����6
		case 0xdd :a=5;break; // 	����5
		case 0xed :a=4;break; // 	����4

		case 0x7e :a=0xa; break;// ����+
		case 0xbe :a=3;break;	   // ����3
		case 0xde :a=2;break;	   // ����2
		case 0xee :a=1;break;	   // ����1

		default :a=0xff;
}
    return a;                //���ذ���ֵ

}	

void display_a() //��ʾ����a
{
  display[3]=data_a%10000/1000;    //ǧ  
  display[2]=data_a%1000/100;      //��
	display[1]=data_a%100/10;        //ʮ
	display[0]=data_a%10;            //��

  write_com(0x80+0);
	if(data_a>999){ write_date('0'+display[3]);}   //��ʾǧλ
	if(data_a>99){ write_date('0'+display[2]);}    //��ʾ��λ
	if(data_a>9){ write_date('0'+display[1]);}     //��ʾʮλ
                write_date('0'+display[0]);      //��ʾ��λ
}

void display_b()  //��ʾ����b
{

  write_com(0x80+7);               //��һ��  
  display[3]=data_b%10000/1000;    //ǧ  
  display[2]=data_b%1000/100;      //��
	display[1]=data_b%100/10;        //ʮ
	display[0]=data_b%10;            //��

	if(data_b>999){ write_date('0'+display[3]);}   //��ʾǧλ
	if(data_b>99){ write_date('0'+display[2]);}    //��ʾ��λ
	if(data_b>9){ write_date('0'+display[1]);}     //��ʾʮλ
                write_date('0'+display[0]);      //��ʾ��λ

}

//������
void display_c(x)
{

   if(data_c<100000000&&data_c>-1)//���ʱ��ʾ����
	 {//display[8]=data_c%1000000000/100000000;    	//����
		display[7]=data_c%100000000/10000000;    	//ǧ��
		display[6]=data_c%10000000/1000000;    		//����
		display[5]=data_c%1000000/100000;    		//ʮ��
		display[4]=data_c%100000/10000;    			//��
		display[3]=data_c%10000/1000;    			//ǧ
		display[2]=data_c%1000/100;      			//��
		display[1]=data_c%100/10;        			//ʮ
		display[0]=data_c%10;            			//�� 

		 write_com(0x80+6+0x40);//��һ��  
		 if(x==4)
		 { 
			// if(data_c>99999999)	{	write_date('0'+display[8]);}    //��ʾ����
           if(data_c>9999999)	{	write_date('0'+display[7]);}      //ǧ��
		   if(data_c>999999)	{	write_date('0'+display[6]);}      //����
           if(data_c>99999)	    {write_date('0'+display[5]);}        //ʮ��
								write_date('0'+display[4]);    //��
								write_date('.');
								write_date('0'+display[3]);    //ǧ
								write_date('0'+display[2]);    //��
								write_date('0'+display[1]);    //ʮ
								write_date('0'+display[0]);    //�� 
		 }
    else{
		if(data_c>99999999)	{	write_date('0'+display[8]);}    //��ʾ����
		if(data_c>9999999)	{	write_date('0'+display[7]);}    //ǧ��
		if(data_c>999999)	{	write_date('0'+display[6]);}    //����
		if(data_c>99999)	{	write_date('0'+display[5]);}    //ʮ��
		if(data_c>9999)		{	write_date('0'+display[4]);}    //��
		if(data_c>999)		{	write_date('0'+display[3]);}    //ǧ
		if(data_c>99)		{	write_date('0'+display[2]);}    //��
		if(data_c>9)		{	write_date('0'+display[1]);}    //ʮ
								write_date('0'+display[0]);          //��
	    	}
	 }
     else  //���ʱ��ʾ����
	   {
		   write_com(0x80+11+0x40); //��һ��
		   write_date('E');         //��ʾ E 
	     write_date('r');         //��ʾ R
       write_date('r');		 //��ʾ R
		   write_date('o');		 //��ʾ O
		   write_date('r');		 //��ʾ E
	    }	 
	 
}

void eql(uchar x)//�Ӽ��˳�����
{
    switch(x)   //���ܼ�ѡ��
		{
		  case 1:data_c=data_a+data_b;break; 		  //�� /* + S=1 */ /* ��ֵת������*/									
      case 2:if(data_a>=data_b){data_c=data_a-data_b;} /* - S=2 *///��
           else{data_c=data_b-data_a;W_lcd(5,1,'-');} //��������
					   break;  	 
			case 3:data_c=(data_a*data_b);break;		  /* * S=3 *///��
			case 4:if(data_b==0){LCD_Write_String(0,1,"Error !");}else{data_c=(data_a*10000/data_b);}break;		  /* / S=4 *///3y//��//���ʱ��ʾ����
			case 0:break;			
		}
}

void main()
{
  uchar key=0xff;         //��ֵ��ʼ��
  uchar n=0;              //��1�������԰�1-4��
	uchar m=5;              //��2�������԰�1-4��
	uchar x=0;
	data_a=0;               //ǰһ����
	data_b=0;               //��һ����
	data_c=0;               //���
	init_lcd();             //1602Һ����ʼ�� 
	display_a();
	
    while(1)
 {
		  key=keycheckdown();
			if(key != 0xff)
		{
			if(key<10)
			{
		     if(n<4){data_a=data_a*10+key;m=5;display_a();}n++;
             if(m<4){data_b=data_b*10+key;n=5;display_b();}m++;
			}
			else
			{ switch(key)
			  {
				case 0xa:n=5;m=0;x=1;W_lcd(5,0,'+');break;
                case 0xb:n=5;m=0;x=2;W_lcd(5,0,'-');break;				
			    case 0xc:n=5;m=0;x=3;W_lcd(5,0,'*');break;
				case 0xd:n=5;m=0;x=4;W_lcd(5,0,'/');break;
				case 0xe:n=5;m=5;eql(x);W_lcd(12,0,'=');display_c(x);break;
				case 0xf:n=0;m=5;x=0;data_a=0;data_b=0;data_c=0;LCD_Write_String(0,0,table);LCD_Write_String(0,1,table);W_lcd(0,0,'0');break;
			  }
			}
			do{P1=0xf0;}while(P1!=0xf0);//�������ɿ�
		}//{0xff!=key}
   }//while
}//main

















