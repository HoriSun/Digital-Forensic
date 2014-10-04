/******************************ERROR_CODE*******************************/


/******History Of Changes*****
* 最新的修改，请添加在在最上方,注明修改人，日期，和改动
* 4/10/2014  黄镇杰 增加 DLL_NOT_FOUND ：动态加载的DLL未找到
* 4/10/2014  黄镇杰 修改-01错误为 MATLAB_INIT_ERROR
* 3/10/2014  黄镇杰 FUNCTION_OK 单词修正
* 3/10/2014  张清柏 IM_DEV_MATCH 图像设备匹配：两张图片大小格式不同
* 3/10/2014  黄镇杰 VIDEO_RECAP_FAIL 翻录检测：抖动过大，无法检测
* 3/10/2014  杨帆  不同类型之间的错误不连续定义，增加matlab无法计算的错误
* 3/10/2014  黎杰  创建
*****************************/


#ifndef _SYSSTATEDEF_01
#define _SYSSTATEDEF_01

/*统一*/
#define FUNCTION_OK          00   //正常状态
#define MATLAB_INIT_ERROR   -01   //调用matlab生成的DLL初始化失败
#define PARAMERROR          -02   //参数输入异常
#define UNKNOWNERROR        -03   //未知异常
#define MATLAB_COUNT_ERRO   -04   //输入的数据，matlab无法完成计算
#define DLL_NOT_FOUND       -05   //动态加载的DLL未找到

/*音频宏定义*/
#define AUDIO_OPEN_ERRO     -10   //音频文件打开错误
#define AUDIO_FORMATE_ERRO  -11   //音频格式不支持

/*图像宏定义*/
#define IMAGE_OPEN_ERRO     -20   //图像文件打开错误
#define IMAGE_FROMATE_ERRO  -21   //图像格式不支持
#define IMGSIZENOTEQUAL     -22   //IM_DEV_MATCH图像设备匹配：图像尺寸格式不匹配，设备匹配两张图片需大小格式相同

/*视频宏定义*/
#define VIDEO_OPEN_ERRO     -30   //视频文件打开错误
#define VIDEO_FORMATE_ERRO  -31   //视频格式不支持
#define VIDEO_RECAP_FAIL    -32   //VI_RECAPTURE翻录检测：视频抖动太大无法检测

/*其它*/
#define PSRN_ERRO           -40   //psnr调用出错，黎杰  VideoCodecDetector函数


#endif

/*********************************END**********************************/
