/*
  작성인: 박광렬
  최초 작성 날짜: 2021-04-26
  마지막 수정 날짜: 2021-04-26
  파일 설명:
    tistory blog에 올릴 엔코더 모터 속도 제어용 코드입니다.


  Copyright 2021. (이름) all rights reserved.
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
  핸들러 명: EXTI0_IRQHandler

  설명: EXTI0 인터럽트를 처리하는 핸들러로, 엔코더 RPM을 계산하기 위한 펄스 값을 계산합니다.

*/

  EXTI -> PR |= (1 << 0);       //      EXTI0을 clear하여 인터럽트가 중복으로 발생하지 아니하도록 합니다.
  encPulseRPMCnt++;             //      엔토더 펄스 값을 증가시킵니다.
};

void EXTI1_IRQHandler(void) {
/*
  핸들러 명: EXTI0_IRQHandler

  설명: EXTI1 인터럽트를 처리하는 핸들러로, 엔코더 RPM을 계산하기 위한 펄스 값을 계산합니다.

*/

  EXTI -> PR |= (1 << 1);       //      EXTI1을 clear하여 인터럽트가 중복으로 발생하지 아니하도록 합니다.
  encPulseRPMCnt++;             //      엔토더 펄스 값을 증가시킵니다.
};

void TIM2_IRQHandler(void) {
/*
  핸들러 명: TIM2_IRQHandler

  설명: 엔코더 속도를 계산하기 위한 Timer로 M방식을 위해 사용됩니다.

*/
  TIM2 -> SR = 0;               // TIM2가 발생되었다는 것을 알려 중복 실행하지 아니하도록 합니다.
  encRPM = 10 * encPulseRPMCnt / 22;    // 속도 값을 계산합니다.
  encPulseRPMCnt = 0;           // 속도 값을 계산했기에 펄스 값을 초기하합니다.
};










//================================================================================================











int main(void) {


}
















