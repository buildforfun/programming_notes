import serial
import csv
import time

# Configure the serial port
# Run ls /dev/cu.* on terminal to find out all ports
ser = serial.Serial('/dev/cu.usbmodem141101', 9600)

with open('arduino/humid_sensor/humidity_data.csv', 'a', newline='') as csvfile:
    csvwriter = csv.writer(csvfile)
    
    while True:
        # Read a line from the serial port
        line = ser.readline().decode('utf-8').strip()
        
        # Split the line into values
        values = line.split(',')
        
        # Write the data to the CSV file
        csvwriter.writerow(values)
        
        # Flush the file to ensure data is written immediately
        csvfile.flush()
        
        print(f"Recorded: {line}")

# Close the serial port
ser.close()