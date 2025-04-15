#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Geometry>

// Convert Euler angles (roll, pitch, yaw) to Quaternion
Eigen::Quaterniond eulerToQuaternion(double roll, double pitch, double yaw) {
    // Eigen uses ZYX order: yaw (Z), pitch (Y), roll (X)
    Eigen::AngleAxisd rollAngle(roll, Eigen::Vector3d::UnitX());
    Eigen::AngleAxisd pitchAngle(pitch, Eigen::Vector3d::UnitY());
    Eigen::AngleAxisd yawAngle(yaw, Eigen::Vector3d::UnitZ());

    Eigen::Quaterniond q = yawAngle * pitchAngle * rollAngle;
    return q.normalized();
}

// Convert Quaternion to Euler angles (roll, pitch, yaw)
Eigen::Vector3d quaternionToEuler(const Eigen::Quaterniond& q) {
    Eigen::Matrix3d rotationMatrix = q.toRotationMatrix();
    Eigen::Vector3d euler = rotationMatrix.eulerAngles(2, 1, 0); // ZYX order

    // Return in roll (X), pitch (Y), yaw (Z) order
    return Eigen::Vector3d(euler[2], euler[1], euler[0]);
}

int main() {
    // Example Euler angles (in radians)
    double roll = M_PI / 4;    // 45 degrees
    double pitch = M_PI / 6;   // 30 degrees
    double yaw = M_PI / 3;     // 60 degrees

    std::cout << "Original Euler angles (rad):\n";
    std::cout << "  Roll: " << roll << "\n  Pitch: " << pitch << "\n  Yaw: " << yaw << "\n\n";

    // Convert to Quaternion
    Eigen::Quaterniond q = eulerToQuaternion(roll, pitch, yaw);
    std::cout << "Quaternion:\n";
    std::cout << "  x: " << q.x() << "\n  y: " << q.y() << "\n  z: " << q.z() << "\n  w: " << q.w() << "\n\n";

    // Convert back to Euler
    Eigen::Vector3d euler = quaternionToEuler(q);
    std::cout << "Recovered Euler angles (rad):\n";
    std::cout << "  Roll: " << euler[0] << "\n  Pitch: " << euler[1] << "\n  Yaw: " << euler[2] << "\n";

    return 0;
}
