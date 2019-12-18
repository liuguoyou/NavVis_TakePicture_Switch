/*
#include <msp430.h>
//unsigned int cnt=0;
#define CPU_F ((double)1000000)//��ʱ�ӵ�Ƶ��1MHz
#define delay_ms(x) __delay_cycles((long)(CPU_F*(double)x/1000.0))
unsigned char n;
unsigned int count;
unsigned char s[8];
int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  Init_UART();                             //initial uart:P1.1ΪRXD,P1.2ΪTXD
  P1DIR |= 0x01;                            // P1.0 output
  P2DIR |= 0x01;                            // P2.0 output
  P1OUT &= ~0x01;
  P1OUT &= ~0x01;
//P1DIR |= 0x01;                            // P1.0 output
//  CCTL0 = CCIE;                             // CCR0 interrupt enabled
//  CCR0 = 50000;
//  TACTL = TASSEL_2 + MC_1;                  // SMCLK, upmode
  __bis_SR_register(GIE);       // Enter  interrupt
	while(1)
	{
		//if(s[0] == '0' && s[1] == '0' && s[2] == '0' && s[3] == '0' && s[4] == '0' && s[5] == '0' && s[6] == '0' && s[7] == '0'){//�յ��ź�������
                  if(s[7] == '0'){
			s[0] = '1';
                        s[1] = '1';
                        s[2] = '1';
                        s[3] = '1';
                        s[4] = '1';
                        s[5] = '1';
                        s[6] = '1';
                        s[7] = '7';
			P2OUT |= 0x01;
			delay_ms(100);  //10ms�ĸߵ�ƽ��p1.0
			P2OUT &= ~0x01;
                        //count=count+1;
                        //UartPutNum(count);
			}
		//if(s[0] == '0' && s[1] == '0' && s[2] == '0' && s[3] == '0' && s[4] == '0' && s[5] == '0' && s[6] == '0' && s[7] == '1'){//�յ��ź���ͨ��
                  if(s[7] == '1'){
			s[0] = '1';
                        s[1] = '1';
                        s[2] = '1';
                        s[3] = '1';
                        s[4] = '1';
                        s[5] = '1';
                        s[6] = '1';
                        s[7] = '8';
                        P1DIR |= 0x01;                            // P1.0 output
			P1OUT |= 0x01;
			//delay_ms(100);  //10ms�ĸߵ�ƽ��p1.0
			//P1OUT &= ~0x01;
                        //count=count+1;
                        //UartPutNum(count);
			}
		//if(s[0] == '0' && s[1] == '0' && s[2] == '0' && s[3] == '0' && s[4] == '0' && s[5] == '0' && s[6] == '0' && s[7] == '2'){//�յ�star�ź���ϵ�
                  if(s[7] == '2'){
			s[0] = '1';
                        s[1] = '1';
                        s[2] = '1';
                        s[3] = '1';
                        s[4] = '1';
                        s[5] = '1';
                        s[6] = '1';
                        s[7] = '9';
			//POUT |= 0x01;
			//delay_ms(100);  //10ms�ĸߵ�ƽ��p1.0
			//P1OUT &= ~0x01;
                        P1DIR &= ~(BIT0);
                        //count=count+1;
                        //UartPutNum(count);
			}

	}
}


/******************************************************************************************************
 * ��       �ƣ����ڽ����жϺ���
 * ��       �ܣ����մ��ڷ��������ź�
 ******************************************************************************************************/
/* 
#pragma vector=USCIAB0RX_VECTOR
__interrupt void USCI0RX_ISR()
{
    s[n++]=UCA0RXBUF;
    if(n>=8)
    	n=0;
    UCA0TXBUF=UCA0RXBUF;
}
//// Timer A0 interrupt service routine ��ʱ���жϿ��Բ�Ҫ��
//#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
//#pragma vector=TIMER0_A0_VECTOR
//__interrupt void Timer_A (void)
//#elif defined(__GNUC__)
//void __attribute__ ((interrupt(TIMER0_A0_VECTOR))) Timer_A (void)
//#else
//#error Compiler not supported!
//#endif
//{
//  if(cnt<9)
//	  cnt++;
//  else{
//	  cnt=0;
//	  P1OUT ^= 0x01;                            // Toggle P1.0
//  }
//}


*/


#include <msp430.h>
//unsigned int cnt=0;
#define CPU_F ((double)1000000)//��ʱ�ӵ�Ƶ��1MHz
#define delay_ms(x) __delay_cycles((long)(CPU_F*(double)x/1000.0))
unsigned char n;
unsigned int count;
unsigned char s[8];
int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  Init_UART();                             //initial uart:P1.1ΪRXD,P1.2ΪTXD
  P1DIR |= BIT0;                            // P1.0 output
  P1DIR |= BIT6;                            // P2.0 output
  P1OUT |= BIT6;
  P1OUT &= ~(BIT0);
//P1DIR |= 0x01;                            // P1.0 output
//  CCTL0 = CCIE;                             // CCR0 interrupt enabled
//  CCR0 = 50000;
//  TACTL = TASSEL_2 + MC_1;                  // SMCLK, upmode
  __bis_SR_register(GIE);       // Enter  interrupt
	while(1)
	{
                //if(s[0] == '0' && s[1] == '0' && s[2] == '0' && s[3] == '0' && s[4] == '0' && s[5] == '0' && s[6] == '0' && s[7] == '0'){//�յ��ź�������
                  if(s[7] == '0'){
			s[0] = '1';
                        s[1] = '1';
                        s[2] = '1';
                        s[3] = '1';
                        s[4] = '1';
                        s[5] = '1';
                        s[6] = '1';
                        s[7] = '7';
			P1OUT |= BIT0;
			delay_ms(100);  //10ms�ĸߵ�ƽ��p1.0
			P1OUT &= ~BIT0;
                        //count=count+1;
                        //UartPutNum(count);
			}
		//if(s[0] == '0' && s[1] == '0' && s[2] == '0' && s[3] == '0' && s[4] == '0' && s[5] == '0' && s[6] == '0' && s[7] == '0'){//�յ��ź�������
                  if(s[7] == '3'){
			s[0] = '1';
                        s[1] = '1';
                        s[2] = '1';
                        s[3] = '1';
                        s[4] = '1';
                        s[5] = '1';
                        s[6] = '1';
                        s[7] = '5';
                        delay_ms(100);
			P1OUT &= ~(BIT6);
                        
                        
			}
		//if(s[0] == '0' && s[1] == '0' && s[2] == '0' && s[3] == '0' && s[4] == '0' && s[5] == '0' && s[6] == '0' && s[7] == '1'){//�յ��ź���ͨ��
                  if(s[7] == '4'){
			s[0] = '1';
                        s[1] = '1';
                        s[2] = '1';
                        s[3] = '1';
                        s[4] = '1';
                        s[5] = '1';
                        s[6] = '1';
                        s[7] = '6';
                        //P1DIR |= 0x01;                            // P1.0 output
			//P1OUT |= 0x01;
			//delay_ms(100);  
                        //P1OUT |= 0X01;
                        P1OUT |=BIT6;

			}
		//if(s[0] == '0' && s[1] == '0' && s[2] == '0' && s[3] == '0' && s[4] == '0' && s[5] == '0' && s[6] == '0' && s[7] == '2'){//�յ�star�ź���ϵ�


	}
}


/******************************************************************************************************
 * ��       �ƣ����ڽ����жϺ���
 * ��       �ܣ����մ��ڷ��������ź�
 ******************************************************************************************************/
#pragma vector=USCIAB0RX_VECTOR
__interrupt void USCI0RX_ISR()
{
    s[n++]=UCA0RXBUF;
    if(n>=8)
    	n=0;
    UCA0TXBUF=UCA0RXBUF;
}
//// Timer A0 interrupt service routine ��ʱ���жϿ��Բ�Ҫ��
//#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
//#pragma vector=TIMER0_A0_VECTOR
//__interrupt void Timer_A (void)
//#elif defined(__GNUC__)
//void __attribute__ ((interrupt(TIMER0_A0_VECTOR))) Timer_A (void)
//#else
//#error Compiler not supported!
//#endif
//{
//  if(cnt<9)
//	  cnt++;
//  else{
//	  cnt=0;
//	  P1OUT ^= 0x01;                            // Toggle P1.0
//  }
//}
