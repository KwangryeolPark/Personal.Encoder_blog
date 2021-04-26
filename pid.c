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
  realError = target - current; // �ǽð� ������ �ܼ��� ��ǥ�� - ���簪�� �ǹ��մϴ�.
  accError += realError; /* ���� ������ �ǽð� ������ ����ؼ� ���� ���Դϴ�. I ��� ���� ���˴ϴ�. */ 
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