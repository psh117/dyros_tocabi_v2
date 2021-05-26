#ifndef TOCABI_CONTROLLER_H
#define TOCABI_CONTROLLER_H

#include "tocabi_controller/state_manager.h"
#include "tocabi_controller/wholebody_functions.h"
#include "tocabi_cc/cc.h"

class TocabiController
{
public:
    TocabiController(StateManager &stm_global);

    ~TocabiController();
    void *Thread1();
    void *Thread2();
    void *Thread3();

    DataContainer &dc_;
    StateManager &stm_;
    RobotData &rd_;

    static void *Thread1Starter(void *context) { return ((TocabiController *)context)->Thread1(); }
    static void *Thread2Starter(void *context) { return ((TocabiController *)context)->Thread2(); }
    static void *Thread3Starter(void *context) { return ((TocabiController *)context)->Thread3(); }

    void SendCommand(Eigen::VectorQd torque_command);
    void GetTaskCommand(tocabi_msgs::TaskCommand &msg);

    void MeasureTime(int currentCount, int nanoseconds1, int nanoseconds2 = 0);
    int64_t total1 = 0, total2 = 0, total_dev1 = 0, total_dev2 = 0;
    float lmax = 0.0, lmin = 10000.00, ldev = 0.0, lavg = 0.0, lat = 0.0;
    float smax = 0.0, smin = 10000.00, sdev = 0.0, savg = 0.0, sat = 0.0;

};

#endif