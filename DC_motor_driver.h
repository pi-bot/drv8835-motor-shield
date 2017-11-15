#ifndef DC_motor_driver_h
#define DC_motor_driver_h

#if defined(__AVR_ATmega168__) || defined(__AVR_ATmega328P__) || defined (__AVR_ATmega32U4__)
  #define DC_motor_driver_USE_20KHZ_PWM
#endif

#include <Arduino.h>

class DC_motor_driver
{
  public:
    static void setM1Speed(int speed);
    static void setM2Speed(int speed);
    static void setSpeeds(int m1Speed, int m2Speed);
    static void flipM1(boolean flip);
    static void flipM2(boolean flip);
  
  private:
    static void initPinsAndMaybeTimer();
    static const unsigned char _M1DIR;
    static const unsigned char _M2DIR;
    static const unsigned char _M1PWM;
    static const unsigned char _M2PWM;
    static boolean _flipM1;
    static boolean _flipM2;
    
    static inline void init()
    {
      static boolean initialized = false;

      if (!initialized)
      {
        initialized = true;
        initPinsAndMaybeTimer();
      }
    }
};
#endif
