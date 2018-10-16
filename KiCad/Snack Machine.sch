EESchema Schematic File Version 4
LIBS:Snack Machine-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 2
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L power:+24V #PWR0101
U 1 1 5B457CBC
P 1050 700
F 0 "#PWR0101" H 1050 550 50  0001 C CNN
F 1 "+24V" H 1050 840 50  0000 C CNN
F 2 "" H 1050 700 50  0001 C CNN
F 3 "" H 1050 700 50  0001 C CNN
	1    1050 700 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 5B457CD0
P 1350 1150
F 0 "#PWR0102" H 1350 900 50  0001 C CNN
F 1 "GND" H 1350 1000 50  0000 C CNN
F 2 "" H 1350 1150 50  0001 C CNN
F 3 "" H 1350 1150 50  0001 C CNN
	1    1350 1150
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:uA7805 U1
U 1 1 5B8644FD
P 1350 800
F 0 "U1" H 1350 1042 50  0000 C CNN
F 1 "uA7805" H 1350 951 50  0000 C CNN
F 2 "" H 1375 650 50  0001 L CIN
F 3 "http://www.ti.com/lit/ds/symlink/ua78.pdf" H 1350 750 50  0001 C CNN
	1    1350 800 
	1    0    0    -1  
$EndComp
Wire Wire Line
	1050 800  1050 750 
Wire Wire Line
	1700 700  1700 800 
Wire Wire Line
	1700 800  1650 800 
Wire Wire Line
	1350 1150 1350 1100
$Comp
L Device:Crystal Y1
U 1 1 5B864B05
P 1600 4400
F 0 "Y1" V 1646 4269 50  0000 R CNN
F 1 "16Mhz" V 1555 4269 50  0000 R CNN
F 2 "" H 1600 4400 50  0001 C CNN
F 3 "~" H 1600 4400 50  0001 C CNN
	1    1600 4400
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1600 4550 2150 4550
$Comp
L Device:C C4
U 1 1 5B864CC9
P 1300 4250
F 0 "C4" V 1048 4250 50  0000 C CNN
F 1 "22p" V 1139 4250 50  0000 C CNN
F 2 "" H 1338 4100 50  0001 C CNN
F 3 "~" H 1300 4250 50  0001 C CNN
	1    1300 4250
	0    1    1    0   
$EndComp
$Comp
L Device:C C5
U 1 1 5B864D1C
P 1300 4550
F 0 "C5" V 1050 4550 50  0000 C CNN
F 1 "22p" V 1150 4550 50  0000 C CNN
F 2 "" H 1338 4400 50  0001 C CNN
F 3 "~" H 1300 4550 50  0001 C CNN
	1    1300 4550
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1450 4550 1600 4550
Connection ~ 1600 4550
Wire Wire Line
	1450 4250 1600 4250
$Comp
L power:GND #PWR0106
U 1 1 5B864EE9
P 1000 4300
F 0 "#PWR0106" H 1000 4050 50  0001 C CNN
F 1 "GND" H 1005 4127 50  0000 C CNN
F 2 "" H 1000 4300 50  0001 C CNN
F 3 "" H 1000 4300 50  0001 C CNN
	1    1000 4300
	1    0    0    -1  
$EndComp
$Comp
L Connector:AVR-ISP-6 J1
U 1 1 5B8692D8
P 2500 3250
F 0 "J1" H 2220 3346 50  0000 R CNN
F 1 "AVR-ISP-6" H 2220 3255 50  0000 R CNN
F 2 "" V 2250 3300 50  0001 C CNN
F 3 " ~" H 1225 2700 50  0001 C CNN
	1    2500 3250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0108
U 1 1 5B869528
P 2400 3650
F 0 "#PWR0108" H 2400 3400 50  0001 C CNN
F 1 "GND" V 2405 3522 50  0000 R CNN
F 2 "" H 2400 3650 50  0001 C CNN
F 3 "" H 2400 3650 50  0001 C CNN
	1    2400 3650
	0    -1   -1   0   
$EndComp
Text Label 3050 3150 0    50   ~ 0
MOSI
Wire Wire Line
	3050 3150 2900 3150
Text Label 3050 3050 0    50   ~ 0
MISO
Wire Wire Line
	3050 3050 2900 3050
Text Label 3050 3250 0    50   ~ 0
SCK
Wire Wire Line
	3050 3250 2900 3250
Text Label 3050 3350 0    50   ~ 0
~RESET
Wire Wire Line
	4250 1200 4400 1200
$Comp
L Device:C C1
U 1 1 5B86B191
P 650 1900
F 0 "C1" H 765 1946 50  0000 L CNN
F 1 "100n" H 765 1855 50  0000 L CNN
F 2 "" H 688 1750 50  0001 C CNN
F 3 "~" H 650 1900 50  0001 C CNN
	1    650  1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	650  1750 650  1700
$Comp
L power:GND #PWR0110
U 1 1 5B86B550
P 650 2100
F 0 "#PWR0110" H 650 1850 50  0001 C CNN
F 1 "GND" H 655 1927 50  0000 C CNN
F 2 "" H 650 2100 50  0001 C CNN
F 3 "" H 650 2100 50  0001 C CNN
	1    650  2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	650  2100 650  2050
Text Label 2150 4550 0    50   ~ 0
XTAL2
Text Label 4250 1200 2    50   ~ 0
~RESET
Text Label 4250 1400 2    50   ~ 0
XTAL1
Wire Wire Line
	4250 1400 4400 1400
Text Label 4250 1600 2    50   ~ 0
XTAL2
Wire Wire Line
	4250 1600 4400 1600
$Sheet
S 8600 1700 1300 2000
U 5BA75957
F0 "MotorPower" 50
F1 "motor_power.sch" 50
F2 "row_a_ctrl" I L 8600 1750 50 
F3 "row_b_ctrl" I L 8600 1850 50 
F4 "row_c_ctrl" I L 8600 1950 50 
F5 "row_d_ctrl" I L 8600 2050 50 
F6 "row_e_ctrl" I L 8600 2150 50 
F7 "row_f_ctrl" I L 8600 2250 50 
F8 "row_g_ctrl" I L 8600 2350 50 
F9 "col_1_ctrl" I L 8600 2650 50 
F10 "col_2_ctrl" I L 8600 2750 50 
F11 "col_3_ctrl" I L 8600 2850 50 
F12 "col_4_ctrl" I L 8600 2950 50 
F13 "col_5_ctrl" I L 8600 3050 50 
F14 "col_6_ctrl" I L 8600 3150 50 
F15 "SCL" I L 8600 3650 50 
F16 "SDA" I L 8600 3550 50 
F17 "row_a_motor" I R 9900 1750 50 
F18 "row_b_motor" I R 9900 1850 50 
F19 "row_c_motor" I R 9900 1950 50 
F20 "row_d_motor" I R 9900 2050 50 
F21 "row_e_motor" I R 9900 2150 50 
F22 "row_f_motor" I R 9900 2250 50 
F23 "row_g_motor" I R 9900 2350 50 
F24 "row_h_ctrl" I L 8600 2450 50 
F25 "row_h_motor" I R 9900 2450 50 
F26 "col_1_motor" I R 9900 2650 50 
F27 "col_2_motor" I R 9900 2750 50 
F28 "col_3_motor" I R 9900 2850 50 
F29 "col_4_motor" I R 9900 2950 50 
F30 "col_5_motor" I R 9900 3050 50 
F31 "col_6_motor" I R 9900 3150 50 
F32 "col_7_ctrl" I L 8600 3250 50 
F33 "col_7_motor" I R 9900 3250 50 
F34 "col_8_ctrl" I L 8600 3350 50 
F35 "col_8_motor" I R 9900 3350 50 
$EndSheet
$Comp
L Device:C C3
U 1 1 5BB17217
P 1050 1900
F 0 "C3" H 1165 1946 50  0000 L CNN
F 1 "100n" H 1165 1855 50  0000 L CNN
F 2 "" H 1088 1750 50  0001 C CNN
F 3 "~" H 1050 1900 50  0001 C CNN
	1    1050 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	1050 1750 1050 1700
$Comp
L power:GND #PWR0105
U 1 1 5BB1721F
P 1050 2100
F 0 "#PWR0105" H 1050 1850 50  0001 C CNN
F 1 "GND" H 1055 1927 50  0000 C CNN
F 2 "" H 1050 2100 50  0001 C CNN
F 3 "" H 1050 2100 50  0001 C CNN
	1    1050 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	1050 2100 1050 2050
$Comp
L MCU_Microchip_ATmega:ATmega2560-16AU U2
U 1 1 5BB84FB8
P 5200 3800
F 0 "U2" H 5200 814 50  0000 C CNN
F 1 "ATmega2560-16AU" H 5200 723 50  0000 C CNN
F 2 "Package_QFP:TQFP-100_14x14mm_P0.5mm" H 5200 3800 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-2549-8-bit-AVR-Microcontroller-ATmega640-1280-1281-2560-2561_datasheet.pdf" H 5200 3800 50  0001 C CNN
	1    5200 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5200 700  5200 900 
Wire Wire Line
	5300 900  5300 700 
Wire Wire Line
	5300 700  5200 700 
$Comp
L Device:C C6
U 1 1 5BB86B6A
P 1450 1900
F 0 "C6" H 1565 1946 50  0000 L CNN
F 1 "100n" H 1565 1855 50  0000 L CNN
F 2 "" H 1488 1750 50  0001 C CNN
F 3 "~" H 1450 1900 50  0001 C CNN
	1    1450 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	1450 1750 1450 1700
$Comp
L power:GND #PWR0112
U 1 1 5BB86B72
P 1450 2100
F 0 "#PWR0112" H 1450 1850 50  0001 C CNN
F 1 "GND" H 1455 1927 50  0000 C CNN
F 2 "" H 1450 2100 50  0001 C CNN
F 3 "" H 1450 2100 50  0001 C CNN
	1    1450 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	1450 2100 1450 2050
$Comp
L Device:C C7
U 1 1 5BB86B7F
P 1850 1900
F 0 "C7" H 1965 1946 50  0000 L CNN
F 1 "100n" H 1965 1855 50  0000 L CNN
F 2 "" H 1888 1750 50  0001 C CNN
F 3 "~" H 1850 1900 50  0001 C CNN
	1    1850 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	1850 1750 1850 1700
$Comp
L power:GND #PWR0114
U 1 1 5BB86B87
P 1850 2100
F 0 "#PWR0114" H 1850 1850 50  0001 C CNN
F 1 "GND" H 1855 1927 50  0000 C CNN
F 2 "" H 1850 2100 50  0001 C CNN
F 3 "" H 1850 2100 50  0001 C CNN
	1    1850 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	1850 2100 1850 2050
Text Label 6200 4800 0    50   ~ 0
RX_USB
Wire Wire Line
	6200 4800 6000 4800
Text Label 6200 4900 0    50   ~ 0
TX_USB
Wire Wire Line
	6200 4900 6000 4900
Text Label 6200 4100 0    50   ~ 0
RX_DISPLAY
Wire Wire Line
	6200 4100 6000 4100
Text Label 6200 4200 0    50   ~ 0
TX_DISPLAY
Wire Wire Line
	6200 4200 6000 4200
Text Label 4200 4800 2    50   ~ 0
RX_MDB1
Wire Wire Line
	4200 4800 4400 4800
Text Label 4200 4900 2    50   ~ 0
TX_MDB1
Wire Wire Line
	4200 4900 4400 4900
Text Label 4200 3900 2    50   ~ 0
RX_MDB2
Text Label 4200 4000 2    50   ~ 0
TX_MDB2
Wire Wire Line
	4200 4000 4400 4000
Wire Wire Line
	4400 3900 4200 3900
$Comp
L Device:R R1
U 1 1 5BB902AA
P 700 4400
F 0 "R1" H 770 4446 50  0000 L CNN
F 1 "1M" H 770 4355 50  0000 L CNN
F 2 "" V 630 4400 50  0001 C CNN
F 3 "~" H 700 4400 50  0001 C CNN
	1    700  4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	1150 4250 1150 4300
Wire Wire Line
	1000 4300 1150 4300
Connection ~ 1150 4300
Wire Wire Line
	1150 4300 1150 4550
Connection ~ 1150 4250
Wire Wire Line
	700  4250 1150 4250
Wire Wire Line
	700  4550 1150 4550
Connection ~ 1150 4550
$Comp
L Device:R R5
U 1 1 5BB94500
P 2000 4250
F 0 "R5" V 1793 4250 50  0000 C CNN
F 1 "27" V 1884 4250 50  0000 C CNN
F 2 "" V 1930 4250 50  0001 C CNN
F 3 "~" H 2000 4250 50  0001 C CNN
	1    2000 4250
	0    1    1    0   
$EndComp
Wire Wire Line
	1850 4250 1600 4250
Connection ~ 1600 4250
Text Label 2150 4250 0    50   ~ 0
XTAL1
Wire Wire Line
	2900 3350 3050 3350
Text Label 800  2700 2    50   ~ 0
~RESET
$Comp
L Device:R R4
U 1 1 5BB95C06
P 1350 2700
F 0 "R4" V 1143 2700 50  0000 C CNN
F 1 "10K" V 1234 2700 50  0000 C CNN
F 2 "" V 1280 2700 50  0001 C CNN
F 3 "~" H 1350 2700 50  0001 C CNN
	1    1350 2700
	0    1    1    0   
$EndComp
Wire Wire Line
	1500 2700 1600 2700
Wire Wire Line
	1200 2700 1000 2700
$Comp
L Device:C C2
U 1 1 5BB97ED7
P 1000 2850
F 0 "C2" H 1115 2896 50  0000 L CNN
F 1 "22p" H 1115 2805 50  0000 L CNN
F 2 "" H 1038 2700 50  0001 C CNN
F 3 "~" H 1000 2850 50  0001 C CNN
	1    1000 2850
	1    0    0    -1  
$EndComp
Connection ~ 1000 2700
Wire Wire Line
	1000 2700 800  2700
$Comp
L power:GND #PWR0117
U 1 1 5BB97F77
P 1000 3000
F 0 "#PWR0117" H 1000 2750 50  0001 C CNN
F 1 "GND" H 1005 2827 50  0000 C CNN
F 2 "" H 1000 3000 50  0001 C CNN
F 3 "" H 1000 3000 50  0001 C CNN
	1    1000 3000
	1    0    0    -1  
$EndComp
Text Label 6200 2300 0    50   ~ 0
MOSI
Text Label 6200 2400 0    50   ~ 0
MISO
Text Label 6200 2200 0    50   ~ 0
SCK
Wire Wire Line
	6200 2200 6000 2200
Wire Wire Line
	6000 2300 6200 2300
Wire Wire Line
	6200 2400 6000 2400
Text Label 700  5100 2    50   ~ 0
SDA
Text Label 700  5200 2    50   ~ 0
SCL
$Comp
L Device:R R2
U 1 1 5BB9C3CE
P 1050 5000
F 0 "R2" V 1257 5000 50  0000 C CNN
F 1 "10K" V 1166 5000 50  0000 C CNN
F 2 "" V 980 5000 50  0001 C CNN
F 3 "~" H 1050 5000 50  0001 C CNN
	1    1050 5000
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R3
U 1 1 5BB9C491
P 1050 5300
F 0 "R3" V 843 5300 50  0000 C CNN
F 1 "10K" V 934 5300 50  0000 C CNN
F 2 "" V 980 5300 50  0001 C CNN
F 3 "~" H 1050 5300 50  0001 C CNN
	1    1050 5300
	0    1    1    0   
$EndComp
Wire Wire Line
	700  5100 900  5100
Wire Wire Line
	900  5100 900  5000
Wire Wire Line
	900  5200 700  5200
Wire Wire Line
	900  5200 900  5300
Text Label 6200 3900 0    50   ~ 0
SCL
Text Label 6200 4000 0    50   ~ 0
SDA
Wire Wire Line
	6200 4000 6000 4000
Wire Wire Line
	6000 3900 6200 3900
Text Label 6200 5400 0    50   ~ 0
RFID_DATA_0
Text Label 6200 5500 0    50   ~ 0
RFID_DATA_1
Text Label 6200 5300 0    50   ~ 0
RFID_GREEN_LED
Text Label 6200 5200 0    50   ~ 0
RFID_RED_LED
Text Label 6200 5100 0    50   ~ 0
RFID_BEEP
$Comp
L Connector_Generic:Conn_02x05_Counter_Clockwise J5
U 1 1 5BB8533B
P 10400 1000
F 0 "J5" H 10450 1417 50  0000 C CNN
F 1 "Display Serial Header" H 10450 1326 50  0000 C CNN
F 2 "" H 10400 1000 50  0001 C CNN
F 3 "~" H 10400 1000 50  0001 C CNN
	1    10400 1000
	1    0    0    -1  
$EndComp
NoConn ~ 10700 800 
NoConn ~ 10700 900 
NoConn ~ 10700 1000
NoConn ~ 10700 1100
NoConn ~ 10700 1200
Wire Wire Line
	10000 800  10200 800 
Text Label 10000 900  2    50   ~ 0
TX_DISPLAY
Text Label 10000 1000 2    50   ~ 0
RX_DISPLAY
Wire Wire Line
	10000 1000 10200 1000
Wire Wire Line
	10200 900  10000 900 
$Comp
L power:GND #PWR0120
U 1 1 5BBA6C9C
P 10000 1050
F 0 "#PWR0120" H 10000 800 50  0001 C CNN
F 1 "GND" V 10005 922 50  0000 R CNN
F 2 "" H 10000 1050 50  0001 C CNN
F 3 "" H 10000 1050 50  0001 C CNN
	1    10000 1050
	0    1    1    0   
$EndComp
Wire Wire Line
	10000 1100 10200 1100
Text Label 9950 1200 2    50   ~ 0
~RESET
Wire Wire Line
	10000 1100 10000 1050
$Comp
L Connector:Conn_01x05_Male J2
U 1 1 5BBFAD05
P 7200 5300
F 0 "J2" H 7173 5230 50  0000 R CNN
F 1 "RFID_CONNECTOR" H 7173 5321 50  0000 R CNN
F 2 "" H 7200 5300 50  0001 C CNN
F 3 "~" H 7200 5300 50  0001 C CNN
	1    7200 5300
	-1   0    0    1   
$EndComp
Wire Wire Line
	6000 5100 7000 5100
Wire Wire Line
	6000 5200 7000 5200
Wire Wire Line
	6000 5300 7000 5300
Wire Wire Line
	6000 5400 7000 5400
Wire Wire Line
	6000 5500 7000 5500
Wire Wire Line
	8600 1750 8400 1750
Text Label 8400 1750 0    50   ~ 0
r1
Text Label 8400 1850 0    50   ~ 0
r2
Text Label 8400 1950 0    50   ~ 0
r3
Text Label 8400 2050 0    50   ~ 0
r4
Text Label 8400 2150 0    50   ~ 0
r5
Text Label 8400 2250 0    50   ~ 0
r6
Text Label 8400 2350 0    50   ~ 0
r7
Text Label 8400 2450 0    50   ~ 0
r8
Wire Wire Line
	8600 1850 8400 1850
Wire Wire Line
	8600 1950 8400 1950
Wire Wire Line
	8600 2050 8400 2050
Wire Wire Line
	8600 2150 8400 2150
Wire Wire Line
	8600 2250 8400 2250
Wire Wire Line
	8600 2350 8400 2350
Wire Wire Line
	8600 2450 8400 2450
Entry Wire Line
	8300 1650 8400 1750
Entry Wire Line
	8300 1750 8400 1850
Entry Wire Line
	8300 1850 8400 1950
Entry Wire Line
	8300 1950 8400 2050
Entry Wire Line
	8300 2050 8400 2150
Entry Wire Line
	8300 2150 8400 2250
Entry Wire Line
	8300 2250 8400 2350
Entry Wire Line
	8300 2350 8400 2450
Wire Wire Line
	6000 1200 6200 1200
Wire Wire Line
	6000 1300 6200 1300
Wire Wire Line
	6000 1400 6200 1400
Wire Wire Line
	6000 1500 6200 1500
Wire Wire Line
	6000 1600 6200 1600
Wire Wire Line
	6000 1700 6200 1700
Wire Wire Line
	6000 1800 6200 1800
Wire Wire Line
	6000 1900 6200 1900
Text Label 6200 1200 2    50   ~ 0
r1
Text Label 6200 1300 2    50   ~ 0
r2
Text Label 6200 1400 2    50   ~ 0
r3
Text Label 6200 1500 2    50   ~ 0
r4
Text Label 6200 1600 2    50   ~ 0
r5
Text Label 6200 1700 2    50   ~ 0
r6
Text Label 6200 1800 2    50   ~ 0
r7
Text Label 6200 1900 2    50   ~ 0
r8
Entry Wire Line
	6200 1200 6300 1100
Entry Wire Line
	6200 1300 6300 1200
Entry Wire Line
	6200 1400 6300 1300
Entry Wire Line
	6200 1500 6300 1400
Entry Wire Line
	6200 1600 6300 1500
Entry Wire Line
	6200 1700 6300 1600
Entry Wire Line
	6200 1800 6300 1700
Entry Wire Line
	6200 1900 6300 1800
Wire Bus Line
	6300 1100 6400 1000
Wire Bus Line
	6400 1000 8200 1000
Wire Bus Line
	8200 1000 8300 1100
Wire Wire Line
	6000 3000 6200 3000
Wire Wire Line
	6000 3100 6200 3100
Wire Wire Line
	6000 3200 6200 3200
Wire Wire Line
	6000 3300 6200 3300
Wire Wire Line
	6000 3400 6200 3400
Wire Wire Line
	6000 3500 6200 3500
Wire Wire Line
	6000 3600 6200 3600
Wire Wire Line
	6000 3700 6200 3700
Entry Wire Line
	6200 3000 6300 2900
Entry Wire Line
	6200 3100 6300 3000
Entry Wire Line
	6200 3200 6300 3100
Entry Wire Line
	6200 3300 6300 3200
Entry Wire Line
	6200 3400 6300 3300
Entry Wire Line
	6200 3500 6300 3400
Entry Wire Line
	6200 3600 6300 3500
Entry Wire Line
	6200 3700 6300 3600
Text Label 6200 3000 2    50   ~ 0
c1
Text Label 6200 3100 2    50   ~ 0
c2
Text Label 6200 3200 2    50   ~ 0
c3
Text Label 6200 3300 2    50   ~ 0
c4
Text Label 6200 3400 2    50   ~ 0
c5
Text Label 6200 3500 2    50   ~ 0
c6
Text Label 6200 3600 2    50   ~ 0
c7
Text Label 6200 3700 2    50   ~ 0
c8
Entry Wire Line
	8300 2550 8400 2650
Wire Wire Line
	8600 2650 8400 2650
Wire Wire Line
	8600 2750 8400 2750
Wire Wire Line
	8600 2850 8400 2850
Wire Wire Line
	8600 2950 8400 2950
Wire Wire Line
	8600 3050 8400 3050
Wire Wire Line
	8600 3150 8400 3150
Wire Wire Line
	8600 3250 8400 3250
Wire Wire Line
	8600 3350 8400 3350
Entry Wire Line
	8300 2650 8400 2750
Entry Wire Line
	8300 2750 8400 2850
Entry Wire Line
	8300 2850 8400 2950
Entry Wire Line
	8300 2950 8400 3050
Entry Wire Line
	8300 3050 8400 3150
Entry Wire Line
	8300 3150 8400 3250
Entry Wire Line
	8300 3250 8400 3350
Text Label 8400 2650 0    50   ~ 0
c1
Text Label 8400 2750 0    50   ~ 0
c2
Text Label 8400 2850 0    50   ~ 0
c3
Text Label 8400 2950 0    50   ~ 0
c4
Text Label 8400 3050 0    50   ~ 0
c5
Text Label 8400 3150 0    50   ~ 0
c6
Text Label 8400 3250 0    50   ~ 0
c7
Text Label 8400 3350 0    50   ~ 0
c8
Wire Bus Line
	8300 2550 8200 2450
Wire Bus Line
	8200 2450 6400 2450
Wire Bus Line
	6400 2450 6300 2550
$Comp
L Connector:Screw_Terminal_01x08 J3
U 1 1 5BC83E1D
P 10300 2050
F 0 "J3" H 10380 2042 50  0000 L CNN
F 1 "Screw_Terminal_01x08" H 10380 1951 50  0000 L CNN
F 2 "" H 10300 2050 50  0001 C CNN
F 3 "~" H 10300 2050 50  0001 C CNN
	1    10300 2050
	1    0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x08 J4
U 1 1 5BC83F41
P 10300 2950
F 0 "J4" H 10380 2942 50  0000 L CNN
F 1 "Screw_Terminal_01x08" H 10380 2851 50  0000 L CNN
F 2 "" H 10300 2950 50  0001 C CNN
F 3 "~" H 10300 2950 50  0001 C CNN
	1    10300 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	10100 1750 9900 1750
Wire Wire Line
	10100 1850 9900 1850
Wire Wire Line
	10100 1950 9900 1950
Wire Wire Line
	10100 2050 9900 2050
Wire Wire Line
	10100 2150 9900 2150
Wire Wire Line
	10100 2250 9900 2250
Wire Wire Line
	10100 2350 9900 2350
Wire Wire Line
	10100 2450 9900 2450
Wire Wire Line
	10100 2650 9900 2650
Wire Wire Line
	10100 2750 9900 2750
Wire Wire Line
	10100 2850 9900 2850
Wire Wire Line
	10100 2950 9900 2950
Wire Wire Line
	10100 3050 9900 3050
Wire Wire Line
	10100 3150 9900 3150
Wire Wire Line
	10100 3250 9900 3250
Wire Wire Line
	10100 3350 9900 3350
Text Label 8400 3550 2    50   ~ 0
SDA
Text Label 8400 3650 2    50   ~ 0
SCL
Wire Wire Line
	8400 3550 8600 3550
Wire Wire Line
	8400 3650 8600 3650
Text Notes 1850 600  0    50   ~ 0
TODO: make this a switching power supply
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5BC89BCF
P 700 750
F 0 "#FLG0101" H 700 825 50  0001 C CNN
F 1 "PWR_FLAG" H 700 924 50  0000 C CNN
F 2 "" H 700 750 50  0001 C CNN
F 3 "~" H 700 750 50  0001 C CNN
	1    700  750 
	1    0    0    -1  
$EndComp
Wire Wire Line
	700  750  1050 750 
Connection ~ 1050 750 
Wire Wire Line
	1050 750  1050 700 
$Comp
L power:+5V #PWR0103
U 1 1 5BC8E530
P 1700 700
F 0 "#PWR0103" H 1700 550 50  0001 C CNN
F 1 "+5V" H 1715 873 50  0000 C CNN
F 2 "" H 1700 700 50  0001 C CNN
F 3 "" H 1700 700 50  0001 C CNN
	1    1700 700 
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0104
U 1 1 5BC8E5E9
P 650 1700
F 0 "#PWR0104" H 650 1550 50  0001 C CNN
F 1 "+5V" H 665 1873 50  0000 C CNN
F 2 "" H 650 1700 50  0001 C CNN
F 3 "" H 650 1700 50  0001 C CNN
	1    650  1700
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0107
U 1 1 5BC8E64E
P 1050 1700
F 0 "#PWR0107" H 1050 1550 50  0001 C CNN
F 1 "+5V" H 1065 1873 50  0000 C CNN
F 2 "" H 1050 1700 50  0001 C CNN
F 3 "" H 1050 1700 50  0001 C CNN
	1    1050 1700
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0109
U 1 1 5BC8E6B3
P 1450 1700
F 0 "#PWR0109" H 1450 1550 50  0001 C CNN
F 1 "+5V" H 1465 1873 50  0000 C CNN
F 2 "" H 1450 1700 50  0001 C CNN
F 3 "" H 1450 1700 50  0001 C CNN
	1    1450 1700
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0111
U 1 1 5BC8E718
P 1850 1700
F 0 "#PWR0111" H 1850 1550 50  0001 C CNN
F 1 "+5V" H 1865 1873 50  0000 C CNN
F 2 "" H 1850 1700 50  0001 C CNN
F 3 "" H 1850 1700 50  0001 C CNN
	1    1850 1700
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0113
U 1 1 5BC8E792
P 1600 2700
F 0 "#PWR0113" H 1600 2550 50  0001 C CNN
F 1 "+5V" H 1615 2873 50  0000 C CNN
F 2 "" H 1600 2700 50  0001 C CNN
F 3 "" H 1600 2700 50  0001 C CNN
	1    1600 2700
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0115
U 1 1 5BC8E80C
P 2400 2750
F 0 "#PWR0115" H 2400 2600 50  0001 C CNN
F 1 "+5V" H 2415 2923 50  0000 C CNN
F 2 "" H 2400 2750 50  0001 C CNN
F 3 "" H 2400 2750 50  0001 C CNN
	1    2400 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	1200 5000 1200 5150
$Comp
L power:+5V #PWR0116
U 1 1 5BC8E8EE
P 1200 5150
F 0 "#PWR0116" H 1200 5000 50  0001 C CNN
F 1 "+5V" V 1215 5278 50  0000 L CNN
F 2 "" H 1200 5150 50  0001 C CNN
F 3 "" H 1200 5150 50  0001 C CNN
	1    1200 5150
	0    1    1    0   
$EndComp
Connection ~ 1200 5150
Wire Wire Line
	1200 5150 1200 5300
$Comp
L power:+5V #PWR0118
U 1 1 5BC8EAAF
P 5200 700
F 0 "#PWR0118" H 5200 550 50  0001 C CNN
F 1 "+5V" H 5215 873 50  0000 C CNN
F 2 "" H 5200 700 50  0001 C CNN
F 3 "" H 5200 700 50  0001 C CNN
	1    5200 700 
	1    0    0    -1  
$EndComp
Connection ~ 5200 700 
$Comp
L power:+5V #PWR0119
U 1 1 5BC8EBC9
P 10000 800
F 0 "#PWR0119" H 10000 650 50  0001 C CNN
F 1 "+5V" V 10015 928 50  0000 L CNN
F 2 "" H 10000 800 50  0001 C CNN
F 3 "" H 10000 800 50  0001 C CNN
	1    10000 800 
	0    -1   -1   0   
$EndComp
Wire Bus Line
	6300 1100 6300 1800
Wire Bus Line
	8300 2550 8300 3250
Wire Bus Line
	8300 1100 8300 2350
Wire Bus Line
	6300 2550 6300 3600
$EndSCHEMATC
