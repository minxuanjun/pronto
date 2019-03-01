#pragma once
#include <ros/node_handle.h>
#include <pronto_core/pose_meas_module.hpp>
#include <geometry_msgs/PoseWithCovarianceStamped.h>

namespace MavStateEst {

class PoseHandlerROS : public SensingModule<geometry_msgs::PoseWithCovarianceStamped> {
public:
    PoseHandlerROS(ros::NodeHandle& nh);

    RBISUpdateInterface* processMessage(const geometry_msgs::PoseWithCovarianceStamped *msg,
                                        MavStateEstimator *est);

    bool processMessageInit(const geometry_msgs::PoseWithCovarianceStamped *msg,
                            const std::map<std::string, bool> &sensor_initialized,
                            const RBIS &default_state,
                            const RBIM &default_cov,
                            RBIS &init_state,
                            RBIM &init_cov);
private:
    ros::NodeHandle& nh_;
    std::shared_ptr<PoseMeasModule> pose_module_;
    PoseMeasurement pose_meas_;

    void poseMsgFromROS(const geometry_msgs::PoseWithCovarianceStamped& msg,
                        PoseMeasurement& pose_meas);

};

}
