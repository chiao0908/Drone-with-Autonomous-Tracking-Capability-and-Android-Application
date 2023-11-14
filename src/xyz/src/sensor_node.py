#!/usr/bin/env python
import Jetson.GPIO as GPIO
import time 

v = 343
trigger_pin = 23
echo_pin = 24
GPIO.setmode(GPIO.BCM)
GPIO.setup(trigger_pin, GPIO.OUT)
GPIO.setup(echo_pin, GPIO.IN)

try:

  while 1:
    def cm():
        GPIO.output(trigger_pin, True)
        time.sleep(0.00001)
        GPIO.output(trigger_pin, False)

        while GPIO.input(echo_pin) == False:
          pulse_start = time.time()
        while GPIO.input(echo_pin) == True:
          pulse_end = time.time()
        d=0
        t = (pulse_end - pulse_start)
        d = (t*v)
        d = (d*50)
        return (d)
   
  print ("%f" % cm())
  time.sleep(0.05)
finally:
  GPIO.cleanup()