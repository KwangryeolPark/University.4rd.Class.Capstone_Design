# About this project
This is my Capstone Design project.   
This is about balancing robot, which uses __PID control for balancing__.   
This robot uses pitch angle for sensing position and __its position should be stable__.   
The robot uses weight which locates on __top of the robot__ for mechanical stability.   
The robot's body is made of 3D printed things.   

# Used devices and pinout
<table style="width:100%">
    <tr>
        <th> device </th>
        <th> info </th>
    </tr>
    <tr>
        <td> Arduino </td>
        <td> Arduino Pro mini 3.3v </td>
    </tr>
    <tr>
        <td> MPU6050 </td>
        <td> Sensing position </td>
    </tr>
    <tr>
        <td> DRV8833 </td>
        <td> Motor driver </td>
    </tr>
    <tr>
        <th> Pin </th>
        <th> info </th>
    </tr>
    <tr>
        <td> D3 </td>
        <td> Right motor A (PWM) </td>
    </tr>
    <tr>
        <td> D5 </td>
        <td> Right motor B (PWM) </td>
    </tr>
    <tr>
        <td> D6 </td>
        <td> Left motor A (PWM) </td>
    </tr>
    <tr>
        <td> D9 </td>
        <td> Left motor B (PWM) </td>
    </tr>
    <tr>
        <td> A4 </td>
        <td> MPU6050 (I2C SDA) </td>
    </tr>
    <tr>
        <td> A5 </td>
        <td> MPU6050 (I2C SCL) </td>
    </tr>
</table>
   
# PID gains
You can adjust PID gains which locate in <a href = "https://github.com/KwangryeolPark/University.4rd.Class.Capstone_Design/blob/master/Arduino/src/Balanencing_robot/PID.h"> Arduino -> src -> Balanencing_robot -> PID.h </a>   
There are __const PID_TYPE__ data type variables (P_gain, I_gain, D_gain)   
```
const PID_TYPE P_gain = 75;
const PID_TYPE I_gain = 260;//0.9;
const PID_TYPE D_gain = 0.7;//43;
``` 
   
# How to tuning the PID gains?
If the robot react to much to immediate input or immediate variation in angle, then __you should reduce D gain___.   
If the robot does not respond to the minimal error, then __you have to increase I gain__.   
If the robot does not respond to more bigger error, then __you have to increase P gain__.   

# References
MPU6050 & Kalman filter libraries: <a href="http://www.tkjelectronics.com"> Here </a> 

# Image
<img src="https://github.com/KwangryeolPark/University.4rd.Class.Capstone_Design/blob/master/PNG/Assemble.png"></img>

# Video
<a href="https://tv.kakao.com/v/429553046"> Here Kakao TV </a>
<video src="https://github.com/KwangryeolPark/University.4rd.Class.Capstone_Design/blob/master/KakaoTalk_20220613_143041636.mp4" controls>
    <source src="https://github.com/KwangryeolPark/University.4rd.Class.Capstone_Design/blob/master/KakaoTalk_20220613_143041636.mp4" type="video/mp4">
</video>