#define P_GAIN 1        //      P 제어량의 계수입니다.
#define I_GAIN 1        //      I 제어량의 계수입니다.
#define D_GAIN 1        //      D 제어량의 계수입니다.
#define TIME 4          //      I, D 제어에서의 시간 변화량입니다.
unsigned int target = 0;        //      목표 값입니다.
unsigned int current = 0;       //      현재 값입니다.
unsigned int pControl = 0;      //      P 제어량입니다.
unsigned int iControl = 0;      //      I 제어량입니다.
unsigned int dControl = 0;      //      D 제어량입니다.
unsigned int pidControl = 0;    //      PID 제어량입니다.
unsigned int realError = 0;     //      실시간 에러입니다.     
unsigned int accError = 0;      //      누적된 에러입니다.
unsigned int errorGap = 0;      //      에러의 변화량입니다.

//================================================================================================

void calculateErrors(void) {
/*
  함수 명: calculateErrors
  
  설명:
    에러에 관한 값들을 계산합니다.
  
*/
  errorGap = target - current - realError;      //      에러 변화량을 계산합니다.
  realError = target - current;                 //      실시간 에러를 계산합니다.
  accError += realError;                        //      누적된 에러를 계산합니다.
}
unsigned int pControlSystem(void) {
/*
  함수 명: pControlSystem
  
  리턴값:
    P 제어량
  
  설명:
    계산된 에러를 기준으로 P 제어량을 계산하여 반환합니다.
  
*/
  pControl = P_GAIN * realError;        //      실시간 에러를 기준으로 P 제어량을 계산합니다.
  return pControl; 
}
unsigned int iControlSystem(void) {
/*
  함수 명: iControlSystem
  
  리턴값:
    I 제어량
  
  설명:
    계산된 에러를 기준으로 I 제어량을 계산하여 반환합니다.
  
*/
  iControl = I_GAIN * (accError * TIME);        //      누적된 에러량을 기준으로 I 제어량을 계산합니다.
  return iControl; 
}
unsigned int dControlSystem(void) {
/*
  함수 명: dControlSystem
  
  리턴값:
    D 제어량
  
  설명:
    계산된 에러를 기준으로 D 제어량을 계산하여 반환합니다.
  
*/
  dControl = D_GAIN * (errorGap / TIME);        //      에러 변화량을 기준으로 D 제어량을 계산합니다.
  return dControl; 
}
unsigned int pidControlSystem(void) {
/*
  함수 명: pidControlSystem
  
  리턴값:
    PID 제어량
  
  설명:
    계산된 P, I, D 제어량을 합산하여 반환합니다.
  
*/
  pidControl = pControl + iControl + dControl;  //      P, I, D 제어량을 합산하여 반환합니다.
  return pidControl; 
}