/*
 * Simulation@Home Competition.
 * File: Nature.h
 * Author: WenBin Fan
 * E-mail:0zheyu@sogou.com
 * Affiliation: Innovation Lab.
 *              HeFei Normal University.
 */


#ifndef __home_NATURE_H__
#define __home_NATURE_H__
#include <string>
#include <iostream>
using namespace std;
#define NATURE_DEBUG 0


string toLowerCase(string str);

string FindObject(string str);

string FindColor(string str);

string FindOther(string str);

string AnalysisObject(string str);

string Translate(string strTs);

string dealwithfinish(string str);

string dealwithobject(string str,int num);

#endif