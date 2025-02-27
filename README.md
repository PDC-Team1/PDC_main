# PDC-Team1

## Introduction

The goal of this project is to enhance the Piracer by integrating a Park Distance Control (PDC) system, running on a Raspberry Pi (RPi) inside the head unit. The PDC system will utilize ultrasonic sensors to detect the distance between the vehicle and any obstacles, and provide an audible response to the driver. In addition, the full stack feature development will be integrated into the existing Yocto image, creating a comprehensive and fully functional system.

## Result Video

https://github.com/user-attachments/assets/a5470c65-6a3e-4704-9840-7bf12381203f

## Utilize various sensors on Arduino

Arduino can't run 3 sensors(encoder, ultrasonic, and buzzer) at the same time. The buzzer should be operated at different intervals depending on the distance. This process confuses the system and prevents it from operating as intended.

To solve this problem, we divide the buzzer's tasks into Tone and noTone and used a time stamp to ensure that the buzzer only performs one task at one period. This simple scheduling process allowed our system to operate well.
