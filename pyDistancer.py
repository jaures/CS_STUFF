import serial   # Needed for serial Communication
import time     # Needed for sleep function
import smtplib  # Needed for emailing
import imaplib

usr = "cs101f17@gmail.com"      # Your Username
psw = "learning4lyfe"           # Your Password
rcp = "jauresade@gmail.com"     # The recipient
msg = "Someone is too close!"   # The Message to Send
msg_sent = 1

er = imaplib.IMAP4_SSL('imap.gmail.com',993)
er.login(usr, psw)
print("Starting Email Count: ")
msg_cnt = int(er.select('Inbox')[1][0])
print(msg_cnt)


ser = serial.Serial('COM3', 9600, timeout=1)
while 1:
    try:
        # Read the Distance from Serial as an int
        distance = int(ser.readline());
        tmp = int(er.select('Inbox')[1][0])
        if(tmp > msg_cnt):
            ser.write("1")
            msg_cnt = tmp
            print("New Count: ", msg_cnt)
        print(distance)
        if(distance < 10) and msg_sent is 0:
            server = smtplib.SMTP_SSL("smtp.gmail.com",465)
            server.login(usr, psw)
            server.sendmail(usr, rcp, msg)
            server.close()
            print("MSG SENT!")
            time.sleep(1)
        msg_sent = (msg_sent + 1) % 20 # Used to limit number of messages sent at once

    except :#ser.SerialTimeoutException:
        print('Data could not be read')
        time.sleep(1)
