from sense_hat import SenseHat
from datetime import datetime
import smtplib
from email.mime.text import MIMEText
import time

sense = SenseHat()
sense.clear()

LOG_FILE = "weather.txt"

# --- Email configuration ---
SMTP_SERVER = "smtp.gmail.com"
SMTP_PORT = 587
SENDER_EMAIL = "your_email@gmail.com"
SENDER_PASSWORD = "your_app_password"
RECEIVER_EMAIL = "receiver_email@gmail.com"

EMAIL_INTERVAL_SECONDS = 300  # send an email every 5 minutes
last_email_time = 0


def read_sensors():
    temperature = round(sense.get_temperature(), 1)
    humidity = round(sense.get_humidity(), 1)
    pressure = round(sense.get_pressure(), 1)
    return temperature, humidity, pressure


def log_to_file(temperature, humidity, pressure):
    timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    line = f"{timestamp} | Temp: {temperature}C | Humidity: {humidity}% | Pressure: {pressure}hPa\n"
    with open(LOG_FILE, "a") as f:
        f.write(line)


def send_email(temperature, humidity, pressure):
    body = (
        f"Weather Station Reading\n"
        f"Temperature: {temperature} C\n"
        f"Humidity: {humidity} %\n"
        f"Pressure: {pressure} hPa\n"
    )
    msg = MIMEText(body)
    msg["Subject"] = "Weather Station Update"
    msg["From"] = SENDER_EMAIL
    msg["To"] = RECEIVER_EMAIL

    with smtplib.SMTP(SMTP_SERVER, SMTP_PORT) as server:
        server.starttls()
        server.login(SENDER_EMAIL, SENDER_PASSWORD)
        server.sendmail(SENDER_EMAIL, RECEIVER_EMAIL, msg.as_string())


def main():
    global last_email_time
    while True:
        temperature, humidity, pressure = read_sensors()
        message = f"T:{temperature}C H:{humidity}% P:{pressure}hPa"

        sense.show_message(message, scroll_speed=0.05)
        log_to_file(temperature, humidity, pressure)

        now = time.time()
        if now - last_email_time >= EMAIL_INTERVAL_SECONDS:
            try:
                send_email(temperature, humidity, pressure)
                last_email_time = now
            except Exception as e:
                print(f"Email failed: {e}")

        time.sleep(2)


if __name__ == "__main__":
    main()
