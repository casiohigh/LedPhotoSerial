from email import message
from tkinter import Y
import serial
import time

lenghs = {'s' : 3, 
          'y': 0,
          'n': 0}
lenghts = {'s':3, 'u':0,'d':0,'b':0}
values = []

def get_connection(port):
    ser = serial.Serial(port, timeout = 1)
    ser = serial.Serial(port,timeout=1)
    return ser

def send(ser, message, msg_len):
def send(ser,message, mesg_len):
    ser.write(message)
    time.sleep(0.1)
    if msg_len != 0:
        data = ser.read(msg_len)
    time.sleep(0.005)
    if mesg_len != 0:
        data = ser.readline()
        result = data.decode()
        result = result.strip()
        print(result)

def switch(result):
    if result >= 200:
        param = 'y'   
    else:
        param = 'n'
    return param
        return (result)

if __name__ == '__main__':
    ser = get_connection("COM9")
if name == 'main':
    ser = get_connection("COM12")
    while True:
        inp = input("Enter command: ")
        length = lenghs.get(inp,13)
#S        send(ser, inp.encode(), length)
        if length == 13:
            switch(send(ser, inp.encode(), length))
        print("Enter command: \nu - on, \nd - off, \nauto - on/off for resistor, \nrec - on data, \nb - more bright")      
        inp = input()
        if inp == "u" or inp == "d" :
            send(ser, inp.encode(), lenghts[inp])
        elif inp == "auto":
            while True:
                com = "s"
                val = send(ser, com.encode(), lenghts[com])
                if val:
                    val = int(val)
                    print(val)
                    if val > 900:
                        send(ser, 'd'.encode(), 0)
                    else:
                        send(ser, 'u'.encode(), 0)
        elif inp == "rec":
            while True: 
                com = "s"
                val = send(ser, com.encode(), lenghts[com])
                if val:
                    values.append(val)
                print (values)
        elif inp == "b":
            while True: 
                com = "s"
                val = send(ser, com.encode(), lenghts[com])
                if val:
                    val = int(val)
                    print(val)
                    if val > 900:
                        send(ser, 'b'.encode(), 0)
                        brightness = send(ser, '50'.encode(),1)
                    else:
                        send(ser, 'b'.encode(), 0)
                        brightness = send(ser, '255'.encode(),1)
        else:
            print("Error")
