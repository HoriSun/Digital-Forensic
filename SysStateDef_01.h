/******************************ERROR_CODE*******************************/


/******History Of Changes*****
* ���µ��޸ģ�������������Ϸ�,ע���޸��ˣ����ڣ��͸Ķ�
* 3/10/2014  �  ��ͬ����֮��Ĵ����������壬����matlab�޷�����Ĵ���
* 3/10/2014  ���  ����
*****************************/


#ifndef _SYSSTATEDEF_01
#define _SYSSTATEDEF_01

/*ͳһ*/
#define FUCTION_OK           00   //����״̬
#define DLL_INITI_ERRO      -01   //����matlab���ɵ�DLL��ʼ��ʧ��
#define PARAMERROR          -02   //���������쳣
#define UNKNOWNERROR        -03   //δ֪�쳣
#define MATLAB_COUNT_ERRO   -04   //��������ݣ�matlab�޷���ɼ���

/*��Ƶ�궨��*/
#define AUDIO_OPEN_ERRO     -10   //��Ƶ�ļ��򿪴���
#define AUDIO_FORMATE_ERRO  -11   //��Ƶ��ʽ��֧��

/*ͼ��궨��*/
#define IMAGE_OPEN_ERRO     -20   //ͼ���ļ��򿪴���
#define IMAGE_FROMATE_ERRO  -21   //ͼ���ʽ��֧��

/*��Ƶ�궨��*/
#define VIDEO_OPEN_ERRO     -30   //��Ƶ�ļ��򿪴���
#define VIDEO_FORMATE_ERRO  -31   //��Ƶ��ʽ��֧��

/*����*/
#define PSRN_ERRO           -40   //psnr���ó������  VideoCodecDetector����

#endif

/*********************************END**********************************/
