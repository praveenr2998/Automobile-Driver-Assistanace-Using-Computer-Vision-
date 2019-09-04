# Pedestrian-Detection---RaspberryPi


I have created a pedestrian safety framework for autonomous driving vehicles using Computer Vision (CV).

Components Used: 1.Raspberry pi 3B+ - installed with OpenCv and its associated libraries.
                 2.Arduino UNO (2 nos) 
                 3.MCP2515 CAN Controller
                 4.LoRa WAN module
                 5.WebCam 
                 
I have detected pedestrians using HOG descriptor fed into a pretrained Support Vector Machine algorithm in OpenCv.

In order to send a signal to the ECU of the automobile after pedetrian detection i used a CAN controller(MCP2515) which converts the oputput from the raspberrypi into a signal which could be transmitted through CAN BUS.

In order to indicate the vehicle which is having a blind spot i used LoRa WAN interfaced with an arduino at receiver end. 
