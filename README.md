# PDC-Team1

## Introduction

The goal of this project is to enhance the Piracer by integrating a Park Distance Control (PDC) system, running on a Raspberry Pi (RPi) inside the head unit. The PDC system will utilize ultrasonic sensors to detect the distance between the vehicle and any obstacles, and provide an audible response to the driver. In addition, the full stack feature development will be integrated into the existing Yocto image, creating a comprehensive and fully functional system.

[SEA:ME DES Project - PDC System](https://github.com/SEA-ME/DES_PDC-System)

This project is the third project of the DES module and follows the Head Unit Project. For fundamental information regarding basic architectures, custom OS, and communication methods, please refer to the Head Unit Project.


[Head Unit Project](https://github.com/Head-Unit-Team1/Head-Unit-Team1.git)

## Result Video

https://github.com/user-attachments/assets/a5470c65-6a3e-4704-9840-7bf12381203f

## Utilize various sensors on Arduino

Arduino can't run 3 sensors(encoder, ultrasonic, and buzzer) at the same time. The buzzer should be operated at different intervals depending on the distance. This process confuses the system and prevents it from operating as intended.

To solve this problem, we divide the buzzer's tasks into Tone and noTone and used a time stamp to ensure that the buzzer only performs one task at one period. This simple scheduling process allowed our system to operate well.

## Developers

<table align="center">

  <tr>
    <td align="center">
      <a href="https://github.com/YEOHANBIN">
        <img src="https://github.com/YEOHANBIN.png" width="150px;" alt="Hanbin Yeo"/>
        <br />
        <sub><b>Hanbin Yeo</b></sub>
      </a>
      <br />
      <a href="https://github.com/YEOHANBIN"><img src="https://img.shields.io/badge/GitHub-YEOHANBIN-blue?logo=github" alt="GitHub Badge" /></a>
      <br />
    </td>
    <td align="center">
      <a href="https://github.com/jwoon0906">
        <img src="https://github.com/jwoon0906.png" width="150px;" alt="Jangwoon Park"/>
        <br />
        <sub><b>Jangwoon Park</b></sub>
      </a>
      <br />
      <a href="https://github.com/jwoon0906"><img src="https://img.shields.io/badge/GitHub-jwoon0906-blue?logo=github" alt="GitHub Badge" /></a>
      <br />
    </td>
    <td align="center">
      <a href="https://github.com/KunhoPark-Jason">
        <img src="https://github.com/KunhoPark-Jason.png" width="150px;" alt="Kunho Park"/>
        <br />
        <sub><b>Kunho Park</b></sub>
      </a>
      <br />
      <a href="https://github.com/KunhoPark-Jason"><img src="https://img.shields.io/badge/GitHub-KunhoPark-Jason-blue?logo=github" alt="GitHub Badge" /></a>
      <br />
    </td>
    <td align="center">
      <a href="https://github.com/euiseok-shin">
        <img src="https://github.com/euiseok-shin.png" width="150px;" alt="Euiseok Shin"/>
        <br />
        <sub><b>Euiseok Shin</b></sub>
      </a>
      <br />
      <a href="https://github.com/euiseok-shin"><img src="https://img.shields.io/badge/GitHub-euiseok-shin-blue?logo=github" alt="GitHub Badge" /></a>
      <br />
    </td>
    
  </tr>
</table>
