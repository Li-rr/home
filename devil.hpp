/*
 * Simulation@Home Competition
 * File: devil.hpp
 * Author: Jiongkun Xie
 * Affiliation: Multi-Agent Systems Lab.
 *              University of Science and Technology of China
 */

#ifndef __home_devil_HPP__
#define __home_devil_HPP__

#include "cserver/plug.hpp"
#include "class.h"
namespace _home
{

    class Devil : public Plug
    {
    public:
        Devil();
        void planWithtask(Task task[],Sort sort[],int taskNum,int sortNum,Robot &robot);
		int move(int sot,Sort sort[],Robot &robot);
		int open(int sot,Sort sort[],Robot &robot,Graph G);
		int takeout(int sot,Sort sort[],Robot &robot,Graph G);
    protected:
		int close(int sot,Sort sort[],Robot &robot,Graph G);
		int getSort(int sot,Sort sort[],Robot &robot,Graph G);
		int putin(int sot,Sort sort[],Robot &robot,Graph G);
		int putdown(int sort,Robot &robot,Graph G);
		int pickup(int sot,Sort sort[],Robot &robot,Graph G);
        void Plan();

        void Fini();
    };//Plug

}//_home

#endif//__home_devil_HPP__
//end of file
