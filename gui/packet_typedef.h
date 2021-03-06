#ifndef PACKET_TYPEDEF_H
#define PACKET_TYPEDEF_H
//#include <QtGlobal>

#define DestanationToUSART 26
#define DestanationToMotor 22
#define DestanationToLife  05
#define DestanationInESP   15
#define LeftMotorData      55
#define RightMotorData     75
#define UpMotor            125
#define DownMotor          126
#define StopMotor          120
#define CamLeftRight       100
#define CamUpDown          150
#define DistanceLeft       200
#define DistanceRight      210
#define DistanceWall       220
#define EMStop             35
#define AutoStart          10
#define InUsart            44
#define toUsart            45
#define autoWork           50

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef signed char int8_t;
typedef signed short int16_t;
typedef signed int int32_t;
typedef struct
{
    uint8_t start_1;
    uint8_t start_2;
    uint8_t  Distanation_usart;
    uint16_t Distance_Left;
    uint16_t Distance_Right;
    uint16_t Voltage_acc;
    uint16_t Voltage_5V;
    uint16_t Voltage_3V3;
    uint16_t Current;
    uint16_t DistanceToWall;
    uint8_t  autoData;
    uint16_t motor_cam_lr;
    uint16_t motor_cam_ud;

} my_tcp_uart_packet;

typedef struct
{
  uint8_t start_1;
  uint8_t start_2;
  uint8_t distanation; // Motors or uart to servos
  uint8_t Left_Right;
  uint8_t Up_Down;
  uint16_t Value;
  uint8_t EmStop;
  double acs;
  my_tcp_uart_packet usart;
  uint16_t crc;
  uint8_t end_1;
  uint8_t end_2;
}my_tcp_packet;

#endif // PACKET_TYPEDEF_H
