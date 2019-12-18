#include <msp430G2553.h>
#include "UART.h"

/***********************************************
�������ƣ�Init_UART
��    �ܣ���BLE���г�ʼ�����ò����ʼ��շ����ڣ�ʹ�ܽ����ж�
��    ������
����ֵ  ����
***********************************************/
void Init_UART()
{
   	P1SEL  |= BIT1+BIT2;    //P1.1ΪRXD,P1.2ΪTXD
	P1SEL2  |= BIT1+BIT2;  //P1.1ΪRXD,P1.2ΪTXD
	UCA0CTL1 |= UCSSEL_2; //ѡ��ʱ��BRCLK
	UCA0BR0 = 106;   //1Mhz 9600
	UCA0BR1 = 0;     //1Mhz 9600
	UCA0MCTL = UCBRS2 + UCBRS0;  //������=BRCLK/(UBR+(M7+...0)/8)
 	UCA0CTL1 &=~ UCSWRST;   //��ʼ��˳��SWRST=1���ô��� Ȼ������SWRST=0 ���������Ӧ�ж�
 	IE2 |= UCA0RXIE;    //ʹ�ܽ����ж�
}

/***********************************************
�������ƣ�UartPutchar
��    �ܣ���һ���ַ�д�봮�ڷ��ͻ�����
��    �����ȴ����ڷ��͵�����
����ֵ  ����
***********************************************/
void UartPutchar(unsigned char c)
{
	while(!(IFG2&UCA0TXIFG)); //(������Ϊ��)
	UCA0TXBUF = c;
	IFG2 &= ~UCA0TXIFG;
}
/***********************************************
�������ƣ�UartPutNum
��    �ܣ�ͨ�����ڷ���һ������
��    �����ȴ����ڷ��͵�����
����ֵ  ����
***********************************************/
void UartPutNum(unsigned long int n)
{
	unsigned char number[8];
	unsigned int i;
	number[0] = n / 10000000; //���λ
	number[1] = n % 10000000 / 1000000;
	number[2] = n % 1000000 / 100000;
	number[3] = n % 100000 / 10000;
	number[4] = n % 10000 / 1000;
    number[5] = n % 1000 / 100;
    number[6] = n % 100 / 10;
    number[7] = n % 10;
    for(i = 0;i<8;i++)
    	UartPutchar(number[i]+'0');
}
/***********************************************
�������ƣ�UartPutStr
��    �ܣ�ͨ�����ڷ���һ���ַ���
��    �����ȴ����ڷ��͵��ַ���
����ֵ  ����
***********************************************/
void UartPutStr(unsigned char *s)
{
  while(*s!='\0')
  {
	  UartPutchar(*s++);
  }
}
/***********************************************
�������ƣ�UartGetchar
��    �ܣ��Ӵ��ڽ��ܻ�������ȡһ���ַ�
��    ������
����ֵ  ����ȡ�����ַ�
***********************************************/
unsigned char UartGetChar()
{
	unsigned char c;
	while(!(IFG2&UCA0RXIFG)); //(�ȴ��������)
	c = UCA0RXBUF;
	IFG2 &= ~UCA0RXIFG;
	//UCA0RXBUF=0;
	return c;
}
/***********************************************
�������ƣ�UartGetStr
��    �ܣ��Ӵ��ڽ��ܻ�������ȡһ���ַ���
��    �����ַ���ָ����ַ�������
����ֵ  ����
***********************************************/
void UartGetStr(unsigned char *s,unsigned int cnt)
{
	unsigned int i;
	for(i = 0;i < cnt;i++)
	{
		s[i] = UartGetChar();
	}
}
