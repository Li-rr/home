//
//                       _oo0oo_
//                      o8888888o
//                      88" . "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .' \\|     |// '.
//                 / \\|||  :  |||// \
//                / _||||| -:- |||||- \
//               |   | \\\  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//                       `=---='
//
//
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//               佛祖保佑         永无BUG
//
//
//
#include "devil.hpp"
using namespace _home;
//cons_not_info:表示在环境的任何状态下，info所描述的任何情况都禁止出现
void Devil::planwithcons_not_info(InfoCons cons_not[],Task task[],Sort sort[],Robot &robot,int consnotNum, int taskNum,Graph G )
{
    int i,j;
    int obj1,obj2;
    for(i=0 ; i <= consnotNum; i++)
    {
        if(cons_not[i].getState()=="on")
        {

        }
        if(cons_not[i].getState()=="near")
        {

        }
        if(cons_not[i].getState()=="plate")
        {

        }
        if(cons_not[i].getState()=="inside")
        {
                obj1 = cons_not[i].getState1();
                obj2 = cons_not[i].getState2();
                if(sort[obj1-1].getsInside() == obj2)   //确认出现这种情况的话
                {
                  move(obj2,sort,robot);
                 takeout(obj1,sort,robot,G);
                }
        }
        if(cons_not[i].getState()=="opened")
        {

        }
        if(cons_not[i].getState()=="closed")
        {

        }
    }
}
