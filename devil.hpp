/*
 * Simulation@Home Competition
 * File: devil.hpp
 * Author: Ranran Li
 * E-mail: 921090271@qq.com.
 * Affiliation: Innovation Lab.
 *              HeFei Normal University.
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
        void planWithtask(Task task[],Sort sort[],int taskNum,int sortNum,Robot &robot,Graph &G);
		int move(int sot,Sort sort[],Robot &robot);
		int open(int sot,Sort sort[],Robot &robot,Graph G);
		int takeout(int sot,Sort sort[],Robot &robot,Graph G);
		int puton(int sotx,int soty,Sort sort[],Robot &robot,Graph &G);
		void planwithcons_not_info(InfoCons cons_not[],Task task[],Sort sort[],Robot &robot,int consnotNum, int taskNum,Graph G );
		void planwithcons_notnot_info(InfoCons cons_notnot[],Task task[],Sort sort[],Robot &robot,int consnotnotNum,int taskNum);
    protected:
		int close(int sot,Sort sort[],Robot &robot,Graph &G);
		int getSort(int sot,Sort sort[],Robot &robot,Graph G);
		int putin(int smallsot,int sot,Sort sort[],Robot &robot,Graph &G);
		int putdown(int sot,Sort sort[],Robot &robot,Graph &G);
		int pickup(int sot,Sort sort[],Robot &robot,Graph G);
		void dealwithputdown(Task task[],int taskNum,Sort sort[],Robot &robot);
		void dealwithgoto(Task task[],int taskNum,Sort sort[],Robot &robot);
		void dealwithpickup(Task task[],int taskNum,Sort sort[],Robot &robot);
		void checkHold(Robot &robot,Graph &G);
		void checkPlate(Robot &plate,Graph G);
        void Plan();
		void getLostLocFromTask(Task task[],int taskNum,Sort sort[]);
        void Fini();
    };//Plug

}//_home

#endif//__home_devil_HPP__
//end of file
