#pragma once
#ifndef _MYFA_
#define _MYFA_

#include<vector>
#include<opencv2/core.hpp>
#include<baseFunc.h>

using cv::Mat;
using std::vector;

namespace myfa {
	//structLinesInfo
	//typedef struct _SCANLINES_INFO {
	//	double k;		//斜率
	//	double b;		//截距
	//	double dx;		//直线夹角（夹角范围为0~180度）的余弦
	//	double dy;		//直线夹角的正弦
	//	double x1;
	//	double y1;
	//	double x2;
	//	double y2;
	//	double len;		//直线长度
	//} SCANLINES_INFO;

	//typedef struct _LINES_INFO {
	//	double k;
	//	double b;
	//	double dx;
	//	double dy;
	//	double x1;
	//	double y1;
	//	double x2;
	//	double y2;
	//	double len;
	//	int orient;
	//} LINES_INFO;

	//typedef struct _MAP_PARAM {
	//	unsigned int mapHeight;	//地图的高度
	//	unsigned int mapWidth;	//地图的宽度
	//	double mapResol;		//地图的分辨率
	//	double mapOrigin[2];	//坐标系原点的位置	[mapOriX, mapOriY]
	//} MAP_PARAM;

	double NormalizedLineDirection(double x1, double y1, double x2, double y2);

	void FeatureAssociation(
		const Mat& ScanlineIm,
		const vector<structLinesInfo>& ScanlinesInfo,
		const vector<structLinesInfo>& MaplinesInfo,
		const structMapParam& MapParam,
		const int* LidarPos,
		const Mat& MaplineIm,
		const Mat& MapCache,
		const Mat& MapValue,
		const vector<double>& ScanRanges,
		const vector<double>& ScanAngles,
		double* estimatePose_realworld,
		double* estimatePose,
		Mat& poseAll
	);

	Mat ScanToMapMatch(
		double Scan_x1,
		double Scan_y1,
		double Scan_x2,
		double Scan_y2,
		double map_x1,
		double map_y1,
		double map_x2,
		double map_y2,
		const Mat& Scan_Im,
		const Mat& Map_Im,
		const Mat& MapCache,
		const int* LidarPos,
		const vector<double>& ScanRanges,
		const vector<double>& ScanAngles,
		const structMapParam& MapParam,
		unsigned scan_num_i,
		unsigned mapline_numi
	);

	double ScanToMapMatchScore(
		const Mat& Map_Im,
		const Mat& MapCache,
		const double* ScanPose_Global,
		const vector<double>& ScanRanges,
		const vector<double>& ScanAngles,
		const structMapParam& MapParam
	);

	void RotateScanIm(
		const double* Scanline,
		const double* Mapline,
		const Mat& Scan_Im,
		const Mat& Map_Im,
		const int* ScanPosition,
		double* ScanPoseNew
	);

	void samplePos(
		const Mat& realPos,
		const Mat& recored_Odom,
		Mat& sampleRealPos
	);
}


#endif // !_MYFA_

