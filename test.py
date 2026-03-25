import os
import time
import subprocess
import RPi.GPIO as GPIO

# НАСТРОЙКИ
TARGET_IP = "192.168.0.192"
RELAY_PIN = 17
CHECK_INTERVAL = 2
OFF_DELAY = 10

GPIO.setmode(GPIO.BCM)
GPIO.setup(RELAY_PIN, GPIO.OUT, initial=GPIO.HIGH)

def is_pc_online(ip):

    res = subprocess.call(['ping', '-c', '1', '-W', '1', ip],
                          stdout=subprocess.DEVNULL, stderr=subprocess.STDOUT)
    return res == 0

print("Система запущена. Мониторю IP:", TARGET_IP)

offline_counter = 0

try:
    while True:
        if is_pc_online(TARGET_IP):

            GPIO.output(RELAY_PIN, GPIO.LOW)
            offline_counter = 0
        else:

            offline_counter += CHECK_INTERVAL
            if offline_counter >= OFF_DELAY:
                GPIO.output(RELAY_PIN, GPIO.HIGH)

        time.sleep(CHECK_INTERVAL)

except KeyboardInterrupt:
    GPIO.cleanup()
