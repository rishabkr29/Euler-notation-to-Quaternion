
## Euler Angles and Quaternion Conversion

### **Euler Angles to Quaternion**
Euler angles are typically defined by **roll**, **pitch**, and **yaw** (rotation about the X, Y, and Z axes respectively). These angles are converted to a **Quaternion**, which is often preferred for its ability to avoid gimbal lock and provide smooth interpolations.

- **Roll (X)**: Rotation about the X-axis.
- **Pitch (Y)**: Rotation about the Y-axis.
- **Yaw (Z)**: Rotation about the Z-axis.

In the code, these Euler angles are converted to a quaternion using the following sequence: 
Quaternion = yawAngle * pitchAngle * rollAngle


The `Eigen::AngleAxisd` class is used to represent the individual axis rotations, and the resulting quaternion is normalized for stability.

### **Quaternion to Euler Angles**
The inverse conversion is also possible. A quaternion can be converted back to Euler angles by first converting it to a **rotation matrix**, then extracting the Euler angles using the `eulerAngles` function. The resulting Euler angles are in the order of **roll (X)**, **pitch (Y)**, and **yaw (Z)**.
