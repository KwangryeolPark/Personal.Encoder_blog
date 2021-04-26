#define P_GAIN 1        //      P ����� ����Դϴ�.
#define I_GAIN 1        //      I ����� ����Դϴ�.
#define D_GAIN 1        //      D ����� ����Դϴ�.
#define TIME 4          //      I, D ������� �ð� ��ȭ���Դϴ�.
unsigned int target = 0;        //      ��ǥ ���Դϴ�.
unsigned int current = 0;       //      ���� ���Դϴ�.
unsigned int pControl = 0;      //      P ����Դϴ�.
unsigned int iControl = 0;      //      I ����Դϴ�.
unsigned int dControl = 0;      //      D ����Դϴ�.
unsigned int pidControl = 0;    //      PID ����Դϴ�.
unsigned int realError = 0;     //      �ǽð� �����Դϴ�.     
unsigned int accError = 0;      //      ������ �����Դϴ�.
unsigned int errorGap = 0;      //      ������ ��ȭ���Դϴ�.

//================================================================================================

void calculateErrors(void) {
/*
  �Լ� ��: calculateErrors
  
  ����:
    ������ ���� ������ ����մϴ�.
  
*/
  errorGap = target - current - realError;      //      ���� ��ȭ���� ����մϴ�.
  realError = target - current;                 //      �ǽð� ������ ����մϴ�.
  accError += realError;                        //      ������ ������ ����մϴ�.
}
unsigned int pControlSystem(void) {
/*
  �Լ� ��: pControlSystem
  
  ���ϰ�:
    P ���
  
  ����:
    ���� ������ �������� P ����� ����Ͽ� ��ȯ�մϴ�.
  
*/
  pControl = P_GAIN * realError;        //      �ǽð� ������ �������� P ����� ����մϴ�.
  return pControl; 
}
unsigned int iControlSystem(void) {
/*
  �Լ� ��: iControlSystem
  
  ���ϰ�:
    I ���
  
  ����:
    ���� ������ �������� I ����� ����Ͽ� ��ȯ�մϴ�.
  
*/
  iControl = I_GAIN * (accError * TIME);        //      ������ �������� �������� I ����� ����մϴ�.
  return iControl; 
}
unsigned int dControlSystem(void) {
/*
  �Լ� ��: dControlSystem
  
  ���ϰ�:
    D ���
  
  ����:
    ���� ������ �������� D ����� ����Ͽ� ��ȯ�մϴ�.
  
*/
  dControl = D_GAIN * (errorGap / TIME);        //      ���� ��ȭ���� �������� D ����� ����մϴ�.
  return dControl; 
}
unsigned int pidControlSystem(void) {
/*
  �Լ� ��: pidControlSystem
  
  ���ϰ�:
    PID ���
  
  ����:
    ���� P, I, D ����� �ջ��Ͽ� ��ȯ�մϴ�.
  
*/
  pidControl = pControl + iControl + dControl;  //      P, I, D ����� �ջ��Ͽ� ��ȯ�մϴ�.
  return pidControl; 
}