#define P_GAIN 1 
#define I_GAIN 1 
#define D_GAIN 1 
#define TIME 4 
unsigned int target = 0; 
unsigned int current = 0; 
unsigned int pControl = 0; 
unsigned int iControl = 0; 
unsigned int dControl = 0; 
unsigned int pidControl = 0; 
unsigned int realError = 0; 
unsigned int accError = 0; 
unsigned int errorGap = 0;



void calculateErrors(void) {
  errorGap = target - current - realError;
  realError = target - current; // 실시간 에러는 단순히 목표값 - 현재값을 의미합니다.
  accError += realError; /* 누적 에러는 실시간 에러를 계속해서 더한 값입니다. I 제어를 위해 사용됩니다. */ 
}
unsigned int pControlSystem(void) {
  pControl = P_GAIN * realError;
  return pControl; 
}
unsigned int iControlSystem(void) {
  iControl = I_GAIN * (accError * TIME);
  return iControl; 
}
unsigned int dControlSystem(void) {
  dControl = D_GAIN * (errorGap / TIME);
  return dControl; 
}
unsigned int pidControlSystem(void) {
  pidControl = pControl + iControl + dControl;
  return pidControl; 
}