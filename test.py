import os
import time
import subprocess
import RPi.GPIO as GPIO

# НАСТРОЙКИ
TARGET_IP = "192.168.0.192"  # Твой статический IP основного компа
RELAY_PIN = 17               # GPIO 17 (Pin 11)
CHECK_INTERVAL = 2           # Проверка каждые 2 секунды
OFF_DELAY = 10               # Выключение через 10 секунд тишины

GPIO.setmode(GPIO.BCM)

# Для Low Level при старте ставим HIGH, чтобы реле было ВЫКЛЮЧЕНО
GPIO.setup(RELAY_PIN, GPIO.OUT, initial=GPIO.HIGH)

def is_pc_online(ip):
    # Пингуем 1 раз, ждем ответ 1 сек
    res = subprocess.call(['ping', '-c', '1', '-W', '1', ip],
                          stdout=subprocess.DEVNULL, stderr=subprocess.STDOUT)
    return res == 0

print(f"Система запущена. Мониторю IP: {TARGET_IP}")

offline_counter = 0

try:
    while True:
        if is_pc_online(TARGET_IP):
            # --- ЛОГИКА LOW LEVEL ---
            # Подаем LOW (0), чтобы реле защелкнулось и колонки ВКЛЮЧИЛИСЬ
            GPIO.output(RELAY_PIN, GPIO.LOW)
            offline_counter = 0
        else:
            # Если комп не пингуется — считаем время
            offline_counter += CHECK_INTERVAL
            if offline_counter >= OFF_DELAY:
                # --- ЛОГИКА LOW LEVEL ---
                # Подаем HIGH (1), чтобы реле разомкнулось и колонки ВЫКЛЮЧИЛИСЬ
                GPIO.output(RELAY_PIN, GPIO.HIGH)

        time.sleep(CHECK_INTERVAL)

except KeyboardInterrupt:
    GPIO.cleanup()
