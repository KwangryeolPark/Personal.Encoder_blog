/*
  �ۼ���: �ڱ���
  ���� �ۼ� ��¥: 2021-04-26
  ������ ���� ��¥: 2021-04-26
  ���� ����:
    tistory blog�� �ø� ���ڴ� ���� �ӵ� ����� �ڵ��Դϴ�.


  Copyright 2021. (�̸�) all rights reserved.
*/

#include "pid.c"
#include "gpio.h"
#include "exti.h"
#include "rcc.h"
#include "afio.h"
#include "tim.h"
#include "nvic.h"
#include "print.c"

//================================================================================================

extern void calculateErrors(void);
extern unsigned int pControlSystem(void);
extern unsigned int iControlSystem(void);
extern unsigned int dControlSystem(void);
extern unsigned int pidControlSystem(void);



volatile unsigned int encPulseRPMCnt = 0;
volatile unsigned int encRPM = 0;

//================================================================================================

void EXTI0_IRQHandler(void) {
/*
  �ڵ鷯 ��: EXTI0_IRQHandler

  ����: EXTI0 ���ͷ�Ʈ�� ó���ϴ� �ڵ鷯��, ���ڴ� RPM�� ����ϱ� ���� �޽� ���� ����մϴ�.

*/

  EXTI -> PR |= (1 << 0);       //      EXTI0�� clear�Ͽ� ���ͷ�Ʈ�� �ߺ����� �߻����� �ƴ��ϵ��� �մϴ�.
  encPulseRPMCnt++;             //      ����� �޽� ���� ������ŵ�ϴ�.
};

void EXTI1_IRQHandler(void) {
/*
  �ڵ鷯 ��: EXTI0_IRQHandler

  ����: EXTI1 ���ͷ�Ʈ�� ó���ϴ� �ڵ鷯��, ���ڴ� RPM�� ����ϱ� ���� �޽� ���� ����մϴ�.

*/

  EXTI -> PR |= (1 << 1);       //      EXTI1�� clear�Ͽ� ���ͷ�Ʈ�� �ߺ����� �߻����� �ƴ��ϵ��� �մϴ�.
  encPulseRPMCnt++;             //      ����� �޽� ���� ������ŵ�ϴ�.
};

void TIM2_IRQHandler(void) {
/*
  �ڵ鷯 ��: TIM2_IRQHandler

  ����: ���ڴ� �ӵ��� ����ϱ� ���� Timer�� M����� ���� ���˴ϴ�.

*/
  TIM2 -> SR = 0;               // TIM2�� �߻��Ǿ��ٴ� ���� �˷� �ߺ� �������� �ƴ��ϵ��� �մϴ�.
  encRPM = 10 * encPulseRPMCnt / 22;    // �ӵ� ���� ����մϴ�.
  encPulseRPMCnt = 0;           // �ӵ� ���� ����߱⿡ �޽� ���� �ʱ����մϴ�.
};










//================================================================================================











int main(void) {


}
















