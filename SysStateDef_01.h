#ifndef _SYSSTATEDEF_01
#define _SYSSTATEDEF_01

#include <iostream>
#include <string>
#include <map>

using namespace std; 

/***********************************STATE_CTR_DEF*******************************/

/******History Of Changes*****
* 最新的修改，请添加在在最上方,注明修改人，日期，和改动
* 6/10/2014  黎杰  修改:19行用 __VA_ARGS__
* 5/10/2014  杨帆  创建:用来定义底层算法统一的状态控制宏,新建调试状态开关宏；
*****************************/
#ifndef      _DEBUG_ON        //                                           
#define      _DEBUG_ON        //通过是它来开关调试信息，我们只用动这里就好了    关闭调试信息： 注释掉这三行   显示调试信息： 不注释      
#endif                        //


#ifdef       _DEBUG_ON
#define      DEBUG_PRINT(...)      printf(__VA_ARGS__)  //
#define      DEBUG_LEVEL      1        //debug级别，保留 (现在用不到)
#else
#define      DEBUG_PRINT(...)
#endif

/********************************STATE_CTR_DEF END*********************************/



/******************************ERROR_CODE*******************************/


/******History Of Changes*****
* 最新的修改，请添加在在最上方,注明修改人，日期，和改动
* 20/10/2014  许国斌 错误代码整理，增加一大波错误处理
* 15/10/2014  黄嘉斌 增加 VIDEO_PARSE_ERRO ：视频格式检测，解析错误
*  4/10/2014  黄镇杰 增加 DLL_NOT_FOUND ：动态加载的DLL未找到
*  4/10/2014  黄镇杰 修改-01错误为 MATLAB_INIT_ERROR
*  3/10/2014  黄镇杰 FUNCTION_OK 单词修正
*  3/10/2014  张清柏 IM_DEV_MATCH 图像设备匹配：两张图片大小格式不同
*  3/10/2014  黄镇杰 VIDEO_RECAP_FAIL 翻录检测：抖动过大，无法检测
*  3/10/2014  杨帆  不同类型之间的错误不连续定义，增加matlab无法计算的错误
*  3/10/2014  黎杰  创建
*****************************/

/*
 错误代码整理：
 错误代码定义为5位，首位表示错误码算法来源，0是统一错误代码，1是音频，2是图像，3是视频,其他保留
 即 < 10000的为统一错误码 ，10000-19999为音频错误码，20000-29999为图像错误码，30000-39999为音频错误码
 第二，三位表示算法接口，如篡改检测，编码检测，拼接检测，copymove等，算法公有错误类型将其定义为00
 后两位表示错误类型，如读取视频文件错误，加载资源文件错误等
 */

/*统一*/
#define FUNCTION_OK          00   //正常状态
#define MATLAB_INIT_ERROR   -01   //调用matlab生成的DLL初始化失败
#define PARAMERROR          -02   //参数输入异常
#define UNKNOWNERROR        -03   //未知异常
#define MATLAB_COUNT_ERRO   -04   //输入的数据，matlab无法完成计算
#define DLL_NOT_FOUND       -05   //动态加载的DLL未找到

/*音频宏定义*/
#define AUDIO_OPEN_ERRO     -10000   //音频文件打开错误
#define AUDIO_FORMATE_ERRO  -10001   //音频格式不支持

/*图像宏定义*/
#define IMAGE_OPEN_ERRO     -20000   //图像文件打开错误
#define IMAGE_FROMATE_ERRO  -20001   //图像格式不支持

//设备匹配
#define IMAGE_SIZE_NOTEQUAL     -20100   //IM_DEV_MATCH图像设备匹配：图像尺寸格式不匹配，设备匹配两张图片需大小格式相同
#define IMAGE_ONLY_THREE_CHANNEL -20101	 //只处理彩色三通道图像

//全局重压缩
#define IMAGE_CREATE_BIN_HIST_ERROR -20200	//直方图binHist生成错误
#define IMAGE_CALCULATE_IPDFT_ERROR -20201 //计算IPDFT复数矩阵错误
#define IMAGE_FUNCTION_ONLY_JPEG	-20202	//该算法只支持jpeg格式文件
#define IMAGE_TOOBIG				-20203 //图像过大

//CopyMove
#define IMAGE_CANOT_DETEC  -20300  //新增，图片打开成功，但得到的图片无法进行进一步测试 （可能不会遇到）
#define ERROR_MIDDLE_DATA  -20301  //新增，异常的中间数据，无法继续计算，请再次尝试或更改不同的阈值（运算过程中，为了保证程序正常进行而增加的判断，可能不会遇到）


/*视频宏定义*/
#define VIDEO_OPEN_ERRO     -30000   //视频文件打开错误
#define VIDEO_FORMATE_ERRO  -30001   //视频格式不支持


//翻录检测
#define VIDEO_RECAP_FAIL    -30100   //VI_RECAPTURE翻录检测：视频抖动太大无法检测

//结构检测
#define VIDEO_PARSE_ERRO	-30200	  //视频格式检测，解析错误

//篡改检测
#define VIDEO_LOAD_MODEL_ERRO		-30300		//加载视频篡改model失败
#define VIDEO_COMBINE_VOTE_FAILED	-30301		//视频篡改合并投票失败
#define VIDEO_TOO_SHORT_ERROR		-30302		//视频长度太短，至少需要15帧
#define VIDEO_CCPEV_FEATURE_EXTRACT_ERROR -30303 //提取连续帧的CCPEV特征失败

//编码检测
#define VIDEO_TRANSFER_FORMAT_RAW_ERROR	-30400	//将视频转换为raw格式发生错误
#define VIDEO_CODEC_CREATE_PROCESS_FAILED -30401	//创建转换视频格式进程出错
#define VIDEO_COMPUTE_PSRN_OPEN_FILE_ERROR -30402	//计算PSNR时无法打开视频文件
#define VIDEO_COMPUTE_PSRN_ZERO_FRAME_ERROR -30403	//计算PSNR时，打开的视频文件不够1帧的大小
#define VIDEO_COMPUTE_PSRN_ERRO           -30404   //计算psnr出错，黎杰  VideoCodecDetector函数
#define VIDEO_DELETE_TMP_VIDEO_ERROR	-30405		//删除临时生成数据出错

/*其它*/

struct ErrorCodeMessage
{
	map<int, string> errorMessage; 
	ErrorCodeMessage()
	{
		errorMessage[FUNCTION_OK] = "正常状态";
		errorMessage[MATLAB_INIT_ERROR] = "调用matlab生成的DLL初始化失败";
		errorMessage[PARAMERROR] = "参数输入异常";
		errorMessage[UNKNOWNERROR] = "未知异常";
		errorMessage[MATLAB_COUNT_ERRO] = "输入的数据，matlab无法完成计算";
		errorMessage[DLL_NOT_FOUND] = "动态加载的DLL未找到";

		/*音频宏定义*/
		errorMessage[AUDIO_OPEN_ERRO] = "音频文件打开错误";
		errorMessage[AUDIO_FORMATE_ERRO] = "不支持该音频格式";

		/*图像宏定义*/
		errorMessage[IMAGE_OPEN_ERRO] = "图像文件打开错误";
		errorMessage[IMAGE_FROMATE_ERRO] = "CFA检测：仅支持tiff图像格式";

		//设备匹配
		errorMessage[IMAGE_SIZE_NOTEQUAL] = "图像设备匹配：尺寸不匹配，需提供与源图同尺寸图片";
		errorMessage[IMAGE_ONLY_THREE_CHANNEL] = "图像设备匹配：仅支持彩色三通道图像";

		//全局重压缩
		errorMessage[IMAGE_CREATE_BIN_HIST_ERROR] = "全局重压缩检测：直方图生成错误";
		errorMessage[IMAGE_CALCULATE_IPDFT_ERROR] = "全局重压缩检测：计算出错";
		errorMessage[IMAGE_FUNCTION_ONLY_JPEG] = "该算法只支持jpeg格式文件";
		errorMessage[IMAGE_TOOBIG] = "图片分辨率过大，无法检测";

		//CopyMove
		errorMessage[IMAGE_CANOT_DETEC] = "图像复制检测：图像打开成功，但得到的图片无法进行进一步测试";
		errorMessage[ERROR_MIDDLE_DATA] = "图像复制检测：出现异常，请尝试不同阈值";

		/*视频宏定义*/
		errorMessage[VIDEO_OPEN_ERRO] = "视频文件打开错误";
		errorMessage[VIDEO_FORMATE_ERRO] = "不支持该视频格式";

		//翻录检测
		errorMessage[VIDEO_RECAP_FAIL] = "视频翻录检测：视频抖动太大无法检测";

		//结构检测
		errorMessage[VIDEO_PARSE_ERRO] = "视频格式检测：文件结构解析错误";

		//篡改检测
		errorMessage[VIDEO_LOAD_MODEL_ERRO] = "篡改检测：加载视频篡改model失败";
		errorMessage[VIDEO_COMBINE_VOTE_FAILED] = "篡改检测：视频篡改合并投票失败";
		errorMessage[VIDEO_TOO_SHORT_ERROR] = "篡改检测：视频长度太短，至少需要15帧";
		errorMessage[VIDEO_CCPEV_FEATURE_EXTRACT_ERROR] = "篡改检测：提取视频特征失败";

		//编码检测
		errorMessage[VIDEO_TRANSFER_FORMAT_RAW_ERROR] = "编码检测：将视频转换为raw格式发生错误";
		errorMessage[VIDEO_CODEC_CREATE_PROCESS_FAILED] = "编码检测：创建转换视频格式进程出错";
		errorMessage[VIDEO_COMPUTE_PSRN_OPEN_FILE_ERROR] = "编码检测：计算PSNR时无法打开视频文件";
		errorMessage[VIDEO_COMPUTE_PSRN_ZERO_FRAME_ERROR] = "编码检测：计算PSNR时视频文件不够1帧";
		errorMessage[VIDEO_COMPUTE_PSRN_ERRO] = "编码检测：计算PSNR出错";
		errorMessage[VIDEO_DELETE_TMP_VIDEO_ERROR] = "编码检测：删除临时生成数据出错";
	}
	~ErrorCodeMessage(){}
};

/*********************************END**********************************/



#endif
