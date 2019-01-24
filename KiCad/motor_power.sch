EESchema Schematic File Version 4
LIBS:Snack Machine-cache
EELAYER 26 0
EELAYER END
$Descr B 17000 11000
encoding utf-8
Sheet 2 3
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	1900 5000 2300 5000
Text HLabel 1500 5200 0    50   Input ~ 0
col_1_ctrl
Text Label 6300 8350 0    50   ~ 0
motor_common_gnd
$Comp
L Device:R R?
U 1 1 5BB1C4B9
P 7050 8850
F 0 "R?" H 7120 8896 50  0000 L CNN
F 1 "0.1R 1%" H 7120 8805 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 6980 8850 50  0001 C CNN
F 3 "~" H 7050 8850 50  0001 C CNN
	1    7050 8850
	1    0    0    -1  
$EndComp
Wire Wire Line
	7050 9000 6950 9000
Wire Wire Line
	6950 9000 6950 8900
Wire Wire Line
	6950 8900 6700 8900
Wire Wire Line
	6700 8800 6950 8800
Wire Wire Line
	6950 8800 6950 8700
Wire Wire Line
	6950 8700 7050 8700
Connection ~ 7050 8700
$Comp
L power:GND #PWR?
U 1 1 5BB27603
P 7050 9100
F 0 "#PWR?" H 7050 8850 50  0001 C CNN
F 1 "GND" H 7055 8927 50  0000 C CNN
F 2 "" H 7050 9100 50  0001 C CNN
F 3 "" H 7050 9100 50  0001 C CNN
	1    7050 9100
	1    0    0    -1  
$EndComp
Wire Wire Line
	7050 9100 7050 9000
Connection ~ 7050 9000
Wire Wire Line
	6950 9000 6700 9000
Connection ~ 6950 9000
Text HLabel 5550 9100 0    50   Input ~ 0
SCL
Wire Wire Line
	5550 9100 5700 9100
Text HLabel 5550 9000 0    50   Input ~ 0
SDA
Wire Wire Line
	5550 9000 5700 9000
$Comp
L power:+24V #PWR?
U 1 1 5BCCBC60
P 1750 1250
AR Path="/5BCCBC60" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BCCBC60" Ref="#PWR067"  Part="1" 
F 0 "#PWR067" H 1750 1100 50  0001 C CNN
F 1 "+24V" H 1765 1423 50  0000 C CNN
F 2 "" H 1750 1250 50  0001 C CNN
F 3 "" H 1750 1250 50  0001 C CNN
	1    1750 1250
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5BCD1BC4
P 2050 1600
AR Path="/5BCD1BC4" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BCD1BC4" Ref="R26"  Part="1" 
F 0 "R26" V 1950 1500 50  0000 L CNN
F 1 "1K" V 2150 1550 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 1980 1600 50  0001 C CNN
F 3 "~" H 2050 1600 50  0001 C CNN
	1    2050 1600
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5BCEAFCA
P 1750 2200
AR Path="/5BCEAFCA" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BCEAFCA" Ref="R19"  Part="1" 
F 0 "R19" V 1850 2200 50  0000 C CNN
F 1 "1k" V 1950 2200 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 1680 2200 50  0001 C CNN
F 3 "~" H 1750 2200 50  0001 C CNN
	1    1750 2200
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BCEAFDC
P 2300 2500
AR Path="/5BCEAFDC" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BCEAFDC" Ref="#PWR069"  Part="1" 
F 0 "#PWR069" H 2300 2250 50  0001 C CNN
F 1 "GND" H 2305 2327 50  0000 C CNN
F 2 "" H 2300 2500 50  0001 C CNN
F 3 "" H 2300 2500 50  0001 C CNN
	1    2300 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	1600 2200 1500 2200
Text HLabel 1500 2200 0    50   Input ~ 0
row_a_ctrl
$Comp
L Snack_Machine:INA219 U?
U 1 1 5BC6BBF3
P 6200 8950
F 0 "U?" H 6200 9365 50  0000 C CNN
F 1 "INA219" H 6200 9274 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:TSOT-23-8_HandSoldering" H 6200 8950 50  0001 C CNN
F 3 "" H 6200 8950 50  0001 C CNN
	1    6200 8950
	1    0    0    -1  
$EndComp
Text HLabel 3250 1250 2    50   Input ~ 0
row_a_motor
Wire Wire Line
	3250 1250 3100 1250
Text HLabel 4300 2200 0    50   Input ~ 0
row_b_ctrl
Text HLabel 6050 1250 2    50   Input ~ 0
row_b_motor
Text HLabel 7100 2200 0    50   Input ~ 0
row_c_ctrl
Text HLabel 8850 1250 2    50   Input ~ 0
row_c_motor
Text HLabel 9900 2200 0    50   Input ~ 0
row_d_ctrl
Text HLabel 11650 1250 2    50   Input ~ 0
row_d_motor
Text HLabel 1500 4150 0    50   Input ~ 0
row_e_ctrl
Text HLabel 3250 3200 2    50   Input ~ 0
row_e_motor
Text HLabel 4300 4150 0    50   Input ~ 0
row_f_ctrl
Text HLabel 6050 3200 2    50   Input ~ 0
row_f_motor
Text HLabel 7100 4150 0    50   Input ~ 0
row_g_ctrl
Text HLabel 8850 3200 2    50   Input ~ 0
row_g_motor
Text HLabel 9900 4150 0    50   Input ~ 0
row_h_ctrl
Text HLabel 11650 3200 2    50   Input ~ 0
row_h_motor
Text HLabel 1900 5000 0    50   Input ~ 0
col_1_motor
Text HLabel 4300 5200 0    50   Input ~ 0
col_2_ctrl
Text HLabel 4700 5000 0    50   Input ~ 0
col_2_motor
Text HLabel 7100 5200 0    50   Input ~ 0
col_3_ctrl
Text HLabel 7500 5000 0    50   Input ~ 0
col_3_motor
Text HLabel 9900 5200 0    50   Input ~ 0
col_4_ctrl
Text HLabel 10300 5000 0    50   Input ~ 0
col_4_motor
Text HLabel 1500 6300 0    50   Input ~ 0
col_5_ctrl
Text HLabel 1900 6100 0    50   Input ~ 0
col_5_motor
Text HLabel 4300 6300 0    50   Input ~ 0
col_6_ctrl
Text HLabel 4700 6100 0    50   Input ~ 0
col_6_motor
Text HLabel 7100 6300 0    50   Input ~ 0
col_7_ctrl
Text HLabel 7500 6100 0    50   Input ~ 0
col_7_motor
Text HLabel 9900 6300 0    50   Input ~ 0
col_8_ctrl
Text HLabel 10300 6100 0    50   Input ~ 0
col_8_motor
Wire Notes Line
	900  4800 12400 4800
Wire Notes Line
	900  850  900  7000
Wire Notes Line
	12600 4800 12750 4800
Wire Notes Line
	12750 850  12600 850 
Text Notes 13150 3350 1    118  ~ 0
High Side\nMotor Driving
Wire Notes Line
	12750 7000 12600 7000
Wire Notes Line
	12750 850  12750 7000
Text Notes 13150 6350 1    118  ~ 0
Low Side\nMotor Driving
$Comp
L Device:R R?
U 1 1 5BCBF666
P 5100 9100
F 0 "R?" H 5170 9146 50  0000 L CNN
F 1 "10k" H 5170 9055 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 5030 9100 50  0001 C CNN
F 3 "~" H 5100 9100 50  0001 C CNN
	1    5100 9100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BCD27ED
P 5100 9300
F 0 "#PWR?" H 5100 9050 50  0001 C CNN
F 1 "GND" H 5105 9127 50  0000 C CNN
F 2 "" H 5100 9300 50  0001 C CNN
F 3 "" H 5100 9300 50  0001 C CNN
	1    5100 9300
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5BCD303F
P 6850 9500
F 0 "C?" H 6965 9546 50  0000 L CNN
F 1 "0.1uF" H 6965 9455 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 6888 9350 50  0001 C CNN
F 3 "~" H 6850 9500 50  0001 C CNN
	1    6850 9500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BCEEBDE
P 6850 9650
F 0 "#PWR?" H 6850 9400 50  0001 C CNN
F 1 "GND" H 6855 9477 50  0000 C CNN
F 2 "" H 6850 9650 50  0001 C CNN
F 3 "" H 6850 9650 50  0001 C CNN
	1    6850 9650
	1    0    0    -1  
$EndComp
$Comp
L Snack_Machine:INA180B3 U?
U 1 1 5C27E419
P 3100 9050
F 0 "U?" H 3075 9375 50  0000 C CNN
F 1 "INA180B3" H 3075 9284 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-5_HandSoldering" H 2850 8950 50  0001 C CNN
F 3 "" H 2850 8950 50  0001 C CNN
	1    3100 9050
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5C27F4F5
P 2150 8250
F 0 "#PWR?" H 2150 8100 50  0001 C CNN
F 1 "+5V" H 2165 8423 50  0000 C CNN
F 2 "" H 2150 8250 50  0001 C CNN
F 3 "" H 2150 8250 50  0001 C CNN
	1    2150 8250
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5C27F640
P 2150 8450
F 0 "C?" H 2265 8496 50  0000 L CNN
F 1 "0.1uF" H 2265 8405 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 2188 8300 50  0001 C CNN
F 3 "~" H 2150 8450 50  0001 C CNN
	1    2150 8450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C291CA1
P 2150 8650
F 0 "#PWR?" H 2150 8400 50  0001 C CNN
F 1 "GND" H 2155 8477 50  0000 C CNN
F 2 "" H 2150 8650 50  0001 C CNN
F 3 "" H 2150 8650 50  0001 C CNN
	1    2150 8650
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5C291D2E
P 3600 8850
F 0 "#PWR?" H 3600 8700 50  0001 C CNN
F 1 "+5V" H 3615 9023 50  0000 C CNN
F 2 "" H 3600 8850 50  0001 C CNN
F 3 "" H 3600 8850 50  0001 C CNN
	1    3600 8850
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 8950 3600 8950
Wire Wire Line
	3600 8950 3600 8850
Wire Wire Line
	2150 8250 2150 8300
Wire Wire Line
	2150 8600 2150 8650
Wire Wire Line
	7050 8700 7050 8350
Wire Wire Line
	7050 8350 6250 8350
Wire Wire Line
	3500 9150 3600 9150
Text Label 1600 9150 0    50   ~ 0
motor_common_gnd
$Comp
L power:GND #PWR?
U 1 1 5C340246
P 2550 9750
F 0 "#PWR?" H 2550 9500 50  0001 C CNN
F 1 "GND" H 2555 9577 50  0000 C CNN
F 2 "" H 2550 9750 50  0001 C CNN
F 3 "" H 2550 9750 50  0001 C CNN
	1    2550 9750
	1    0    0    -1  
$EndComp
Wire Wire Line
	2550 9050 2550 9750
Text HLabel 2350 8950 0    50   Input ~ 0
MOTOR_CURRENT
Wire Wire Line
	2650 8950 2350 8950
Wire Wire Line
	2650 9050 2550 9050
$Comp
L power:GND #PWR?
U 1 1 5C3C541B
P 2400 9750
F 0 "#PWR?" H 2400 9500 50  0001 C CNN
F 1 "GND" H 2405 9577 50  0000 C CNN
F 2 "" H 2400 9750 50  0001 C CNN
F 3 "" H 2400 9750 50  0001 C CNN
	1    2400 9750
	1    0    0    -1  
$EndComp
Wire Wire Line
	3600 9150 3600 9550
$Comp
L power:+5V #PWR?
U 1 1 5C4150EA
P 6850 9300
F 0 "#PWR?" H 6850 9150 50  0001 C CNN
F 1 "+5V" H 6865 9473 50  0000 C CNN
F 2 "" H 6850 9300 50  0001 C CNN
F 3 "" H 6850 9300 50  0001 C CNN
	1    6850 9300
	1    0    0    -1  
$EndComp
Wire Wire Line
	6850 9350 6850 9300
Wire Wire Line
	6700 9100 6750 9100
Wire Wire Line
	6750 9100 6750 9350
Wire Wire Line
	6750 9350 6850 9350
Connection ~ 6850 9350
$Comp
L power:+5V #PWR?
U 1 1 5C4433AA
P 5100 8350
F 0 "#PWR?" H 5100 8200 50  0001 C CNN
F 1 "+5V" H 5050 8500 50  0000 L CNN
F 2 "" H 5100 8350 50  0001 C CNN
F 3 "" H 5100 8350 50  0001 C CNN
	1    5100 8350
	1    0    0    -1  
$EndComp
$Comp
L Jumper:SolderJumper_2_Open JP?
U 1 1 5C4436DC
P 5100 8550
F 0 "JP?" V 5050 8700 50  0000 C CNN
F 1 "SolderJumper_2_Open" V 5150 9050 50  0000 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_TrianglePad1.0x1.5mm" H 5100 8550 50  0001 C CNN
F 3 "~" H 5100 8550 50  0001 C CNN
	1    5100 8550
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5C443BBD
P 4800 8350
F 0 "#PWR?" H 4800 8200 50  0001 C CNN
F 1 "+5V" H 4750 8500 50  0000 L CNN
F 2 "" H 4800 8350 50  0001 C CNN
F 3 "" H 4800 8350 50  0001 C CNN
	1    4800 8350
	1    0    0    -1  
$EndComp
$Comp
L Jumper:SolderJumper_2_Open JP?
U 1 1 5C443BC3
P 4800 8550
F 0 "JP?" V 4700 8400 50  0000 C CNN
F 1 "SolderJumper_2_Open" V 4800 8100 50  0000 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_TrianglePad1.0x1.5mm" H 4800 8550 50  0001 C CNN
F 3 "~" H 4800 8550 50  0001 C CNN
	1    4800 8550
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5C466872
P 4800 9100
F 0 "R?" H 4870 9146 50  0000 L CNN
F 1 "10k" H 4870 9055 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 4730 9100 50  0001 C CNN
F 3 "~" H 4800 9100 50  0001 C CNN
	1    4800 9100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C46696D
P 4800 9300
F 0 "#PWR?" H 4800 9050 50  0001 C CNN
F 1 "GND" H 4805 9127 50  0000 C CNN
F 2 "" H 4800 9300 50  0001 C CNN
F 3 "" H 4800 9300 50  0001 C CNN
	1    4800 9300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 8900 5700 8900
Wire Wire Line
	5100 8900 5100 8950
Wire Wire Line
	4800 8800 4800 8950
Wire Wire Line
	4800 8800 5700 8800
Wire Wire Line
	5100 8900 5100 8700
Connection ~ 5100 8900
Wire Wire Line
	4800 8700 4800 8800
Connection ~ 4800 8800
Wire Wire Line
	4800 9250 4800 9300
Wire Wire Line
	5100 9250 5100 9300
Wire Wire Line
	4800 8350 4800 8400
Wire Wire Line
	5100 8350 5100 8400
$Comp
L Device:Q_PMOS_GSD Q?
U 1 1 5C02569C
P 2300 1350
AR Path="/5C02569C" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5C02569C" Ref="Q6"  Part="1" 
F 0 "Q6" V 2650 1300 50  0000 L CNN
F 1 "P-CH 30V 3.8A" V 2550 1300 50  0000 L CNN
F 2 "Snack Machine:TSOT-23_HandSoldering_Lite" H 2500 1450 50  0001 C CNN
F 3 "~" H 2300 1350 50  0001 C CNN
F 4 "Diodes Incorporated" V 2300 1350 50  0001 C CNN "Manufacturer"
F 5 "DMP3099L-7" V 2300 1350 50  0001 C CNN "Part Number"
	1    2300 1350
	0    1    -1   0   
$EndComp
Wire Wire Line
	2400 9150 2650 9150
Wire Wire Line
	1600 9150 2400 9150
Connection ~ 2400 9150
Wire Wire Line
	2400 9150 2400 9200
Wire Wire Line
	2400 9550 2400 9750
Wire Wire Line
	2400 9550 3600 9550
Connection ~ 2400 9550
Wire Wire Line
	2400 9500 2400 9550
$Comp
L Device:R R?
U 1 1 5C2D7083
P 2400 9350
F 0 "R?" H 2500 9300 50  0000 L CNN
F 1 "0.1R 1%" H 2500 9400 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 2330 9350 50  0001 C CNN
F 3 "~" H 2400 9350 50  0001 C CNN
	1    2400 9350
	-1   0    0    1   
$EndComp
$Comp
L Transistor_BJT:MMBT3904 Q?
U 1 1 5C3E46E6
P 2200 2200
F 0 "Q?" H 2391 2246 50  0000 L CNN
F 1 "MMBT3904" H 2391 2155 50  0000 L CNN
F 2 "Snack Machine:SOT-23_Handsoldering_Lite" H 2400 2125 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N3904.pdf" H 2200 2200 50  0001 L CNN
	1    2200 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	1900 2200 2000 2200
Wire Wire Line
	2300 2400 2300 2500
$Comp
L Device:R R?
U 1 1 5C41FA49
P 2300 1800
AR Path="/5C41FA49" Ref="R?"  Part="1" 
AR Path="/5BA75957/5C41FA49" Ref="R25"  Part="1" 
F 0 "R25" H 2370 1846 50  0000 L CNN
F 1 "1K" H 2370 1755 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 2230 1800 50  0001 C CNN
F 3 "~" H 2300 1800 50  0001 C CNN
	1    2300 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2300 1950 2300 2000
Wire Wire Line
	1750 1250 1850 1250
Wire Wire Line
	1900 1600 1850 1600
Wire Wire Line
	1850 1600 1850 1250
Connection ~ 1850 1250
Wire Wire Line
	1850 1250 2100 1250
Wire Wire Line
	2200 1600 2300 1600
Wire Wire Line
	2300 1600 2300 1550
Wire Wire Line
	2300 1650 2300 1600
Connection ~ 2300 1600
Wire Wire Line
	1500 5200 1600 5200
Text Label 2350 5550 0    50   ~ 0
motor_common_gnd
Wire Wire Line
	3150 5550 2300 5550
Wire Wire Line
	1900 5200 2000 5200
Wire Wire Line
	2000 5550 2000 5200
Wire Wire Line
	2300 5550 2300 5400
Connection ~ 2300 5550
$Comp
L Device:R R?
U 1 1 5BA8E124
P 2150 5550
AR Path="/5BA8E124" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BA8E124" Ref="R21"  Part="1" 
F 0 "R21" V 2050 5550 50  0000 C CNN
F 1 "10k" V 2250 5550 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 2080 5550 50  0001 C CNN
F 3 "~" H 2150 5550 50  0001 C CNN
	1    2150 5550
	0    1    1    0   
$EndComp
Connection ~ 2000 5200
$Comp
L Device:Q_NMOS_GSD Q?
U 1 1 5C0128D5
P 2200 5200
F 0 "Q?" H 2405 5246 50  0000 L CNN
F 1 "Q_NMOS_SGD" H 2405 5155 50  0000 L CNN
F 2 "Snack Machine:TSOT-23_HandSoldering_Lite" H 2400 5300 50  0001 C CNN
F 3 "~" H 2200 5200 50  0001 C CNN
F 4 "ON Semiconductor" H 2200 5200 50  0001 C CNN "Manufacturer"
F 5 "NTR4003NT1G" H 2200 5200 50  0001 C CNN "Part Number"
	1    2200 5200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5C4F5CE0
P 1750 5200
AR Path="/5C4F5CE0" Ref="R?"  Part="1" 
AR Path="/5BA75957/5C4F5CE0" Ref="R48"  Part="1" 
F 0 "R48" V 1650 5200 50  0000 C CNN
F 1 "1k" V 1850 5200 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 1680 5200 50  0001 C CNN
F 3 "~" H 1750 5200 50  0001 C CNN
	1    1750 5200
	0    1    1    0   
$EndComp
$Comp
L power:+24V #PWR?
U 1 1 5C58D71B
P 4550 1250
AR Path="/5C58D71B" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5C58D71B" Ref="#PWR077"  Part="1" 
F 0 "#PWR077" H 4550 1100 50  0001 C CNN
F 1 "+24V" H 4565 1423 50  0000 C CNN
F 2 "" H 4550 1250 50  0001 C CNN
F 3 "" H 4550 1250 50  0001 C CNN
	1    4550 1250
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5C58D721
P 4850 1600
AR Path="/5C58D721" Ref="R?"  Part="1" 
AR Path="/5BA75957/5C58D721" Ref="R20"  Part="1" 
F 0 "R20" V 4750 1500 50  0000 L CNN
F 1 "1K" V 4950 1550 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 4780 1600 50  0001 C CNN
F 3 "~" H 4850 1600 50  0001 C CNN
	1    4850 1600
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5C58D728
P 4550 2200
AR Path="/5C58D728" Ref="R?"  Part="1" 
AR Path="/5BA75957/5C58D728" Ref="R31"  Part="1" 
F 0 "R31" V 4650 2200 50  0000 C CNN
F 1 "1k" V 4750 2200 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 4480 2200 50  0001 C CNN
F 3 "~" H 4550 2200 50  0001 C CNN
	1    4550 2200
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C58D72F
P 5100 2500
AR Path="/5C58D72F" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5C58D72F" Ref="#PWR087"  Part="1" 
F 0 "#PWR087" H 5100 2250 50  0001 C CNN
F 1 "GND" H 5105 2327 50  0000 C CNN
F 2 "" H 5100 2500 50  0001 C CNN
F 3 "" H 5100 2500 50  0001 C CNN
	1    5100 2500
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_PMOS_GSD Q?
U 1 1 5C58D737
P 5100 1350
AR Path="/5C58D737" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5C58D737" Ref="Q3"  Part="1" 
F 0 "Q3" V 5450 1300 50  0000 L CNN
F 1 "P-CH 30V 3.8A" V 5350 1300 50  0000 L CNN
F 2 "Snack Machine:TSOT-23_HandSoldering_Lite" H 5300 1450 50  0001 C CNN
F 3 "~" H 5100 1350 50  0001 C CNN
F 4 "Diodes Incorporated" V 5100 1350 50  0001 C CNN "Manufacturer"
F 5 "DMP3099L-7" V 5100 1350 50  0001 C CNN "Part Number"
	1    5100 1350
	0    1    -1   0   
$EndComp
$Comp
L Transistor_BJT:MMBT3904 Q?
U 1 1 5C58D73E
P 5000 2200
F 0 "Q?" H 5191 2246 50  0000 L CNN
F 1 "MMBT3904" H 5191 2155 50  0000 L CNN
F 2 "Snack Machine:SOT-23_Handsoldering_Lite" H 5200 2125 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N3904.pdf" H 5000 2200 50  0001 L CNN
	1    5000 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 2200 4800 2200
Wire Wire Line
	5100 2400 5100 2500
$Comp
L Device:R R?
U 1 1 5C58D747
P 5100 1800
AR Path="/5C58D747" Ref="R?"  Part="1" 
AR Path="/5BA75957/5C58D747" Ref="R27"  Part="1" 
F 0 "R27" H 5170 1846 50  0000 L CNN
F 1 "1K" H 5170 1755 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 5030 1800 50  0001 C CNN
F 3 "~" H 5100 1800 50  0001 C CNN
	1    5100 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 1950 5100 2000
Wire Wire Line
	4550 1250 4650 1250
Wire Wire Line
	4700 1600 4650 1600
Wire Wire Line
	4650 1600 4650 1250
Connection ~ 4650 1250
Wire Wire Line
	4650 1250 4900 1250
Wire Wire Line
	5000 1600 5100 1600
Wire Wire Line
	5100 1600 5100 1550
Wire Wire Line
	5100 1650 5100 1600
Connection ~ 5100 1600
$Comp
L Device:D D?
U 1 1 5C594901
P 3100 1500
F 0 "D?" V 3050 1600 50  0000 L CNN
F 1 "50V 2A" V 3150 1600 50  0000 L CNN
F 2 "Snack Machine:D_SMB_Handsoldering_Lite" H 3100 1500 50  0001 C CNN
F 3 "~" H 3100 1500 50  0001 C CNN
F 4 "ON Semiconductor" H 3100 1500 50  0001 C CNN "Manufacturer"
F 5 "ES2A" H 3100 1500 50  0001 C CNN "Part Number"
	1    3100 1500
	0    1    1    0   
$EndComp
$Comp
L Device:C C?
U 1 1 5C59615D
P 2900 1500
F 0 "C?" H 2650 1550 50  0000 L CNN
F 1 "1uF 50V" H 2450 1450 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 2938 1350 50  0001 C CNN
F 3 "~" H 2900 1500 50  0001 C CNN
F 4 "Samsung" H 2900 1500 50  0001 C CNN "Manufacturer"
F 5 "CL10A105KB8NNNC" H 2900 1500 50  0001 C CNN "Part Number"
	1    2900 1500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C599703
P 2900 1750
AR Path="/5C599703" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5C599703" Ref="#PWR083"  Part="1" 
F 0 "#PWR083" H 2900 1500 50  0001 C CNN
F 1 "GND" H 2905 1577 50  0000 C CNN
F 2 "" H 2900 1750 50  0001 C CNN
F 3 "" H 2900 1750 50  0001 C CNN
	1    2900 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	3100 1650 3100 1700
Wire Wire Line
	3100 1700 2900 1700
Wire Wire Line
	2900 1700 2900 1750
Wire Wire Line
	2900 1650 2900 1700
Connection ~ 2900 1700
Wire Wire Line
	2900 1350 2900 1250
Connection ~ 2900 1250
Wire Wire Line
	2900 1250 2500 1250
Wire Wire Line
	3100 1350 3100 1250
Connection ~ 3100 1250
Wire Wire Line
	3100 1250 2900 1250
Wire Wire Line
	4400 2200 4300 2200
Wire Wire Line
	6050 1250 5900 1250
$Comp
L Device:D D?
U 1 1 5C5A3C30
P 5900 1500
F 0 "D?" V 5850 1600 50  0000 L CNN
F 1 "50V 2A" V 5950 1600 50  0000 L CNN
F 2 "Snack Machine:D_SMB_Handsoldering_Lite" H 5900 1500 50  0001 C CNN
F 3 "~" H 5900 1500 50  0001 C CNN
F 4 "ON Semiconductor" H 5900 1500 50  0001 C CNN "Manufacturer"
F 5 "ES2A" H 5900 1500 50  0001 C CNN "Part Number"
	1    5900 1500
	0    1    1    0   
$EndComp
$Comp
L Device:C C?
U 1 1 5C5A3C37
P 5700 1500
F 0 "C?" H 5450 1550 50  0000 L CNN
F 1 "1uF 50V" H 5250 1450 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 5738 1350 50  0001 C CNN
F 3 "~" H 5700 1500 50  0001 C CNN
F 4 "Samsung" H 5700 1500 50  0001 C CNN "Manufacturer"
F 5 "CL10A105KB8NNNC" H 5700 1500 50  0001 C CNN "Part Number"
	1    5700 1500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C5A3C3E
P 5700 1750
AR Path="/5C5A3C3E" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5C5A3C3E" Ref="#PWR084"  Part="1" 
F 0 "#PWR084" H 5700 1500 50  0001 C CNN
F 1 "GND" H 5705 1577 50  0000 C CNN
F 2 "" H 5700 1750 50  0001 C CNN
F 3 "" H 5700 1750 50  0001 C CNN
	1    5700 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	5900 1650 5900 1700
Wire Wire Line
	5900 1700 5700 1700
Wire Wire Line
	5700 1700 5700 1750
Wire Wire Line
	5700 1650 5700 1700
Connection ~ 5700 1700
Wire Wire Line
	5700 1350 5700 1250
Connection ~ 5700 1250
Wire Wire Line
	5700 1250 5300 1250
Wire Wire Line
	5900 1350 5900 1250
Connection ~ 5900 1250
Wire Wire Line
	5900 1250 5700 1250
$Comp
L power:+24V #PWR?
U 1 1 5C5AE602
P 7350 1250
AR Path="/5C5AE602" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5C5AE602" Ref="#PWR078"  Part="1" 
F 0 "#PWR078" H 7350 1100 50  0001 C CNN
F 1 "+24V" H 7365 1423 50  0000 C CNN
F 2 "" H 7350 1250 50  0001 C CNN
F 3 "" H 7350 1250 50  0001 C CNN
	1    7350 1250
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5C5AE608
P 7650 1600
AR Path="/5C5AE608" Ref="R?"  Part="1" 
AR Path="/5BA75957/5C5AE608" Ref="R22"  Part="1" 
F 0 "R22" V 7550 1500 50  0000 L CNN
F 1 "1K" V 7750 1550 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 7580 1600 50  0001 C CNN
F 3 "~" H 7650 1600 50  0001 C CNN
	1    7650 1600
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5C5AE60F
P 7350 2200
AR Path="/5C5AE60F" Ref="R?"  Part="1" 
AR Path="/5BA75957/5C5AE60F" Ref="R32"  Part="1" 
F 0 "R32" V 7450 2200 50  0000 C CNN
F 1 "1k" V 7550 2200 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 7280 2200 50  0001 C CNN
F 3 "~" H 7350 2200 50  0001 C CNN
	1    7350 2200
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C5AE616
P 7900 2500
AR Path="/5C5AE616" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5C5AE616" Ref="#PWR088"  Part="1" 
F 0 "#PWR088" H 7900 2250 50  0001 C CNN
F 1 "GND" H 7905 2327 50  0000 C CNN
F 2 "" H 7900 2500 50  0001 C CNN
F 3 "" H 7900 2500 50  0001 C CNN
	1    7900 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	7200 2200 7100 2200
Wire Wire Line
	8850 1250 8700 1250
$Comp
L Device:Q_PMOS_GSD Q?
U 1 1 5C5AE624
P 7900 1350
AR Path="/5C5AE624" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5C5AE624" Ref="Q4"  Part="1" 
F 0 "Q4" V 8250 1300 50  0000 L CNN
F 1 "P-CH 30V 3.8A" V 8150 1300 50  0000 L CNN
F 2 "Snack Machine:TSOT-23_HandSoldering_Lite" H 8100 1450 50  0001 C CNN
F 3 "~" H 7900 1350 50  0001 C CNN
F 4 "Diodes Incorporated" V 7900 1350 50  0001 C CNN "Manufacturer"
F 5 "DMP3099L-7" V 7900 1350 50  0001 C CNN "Part Number"
	1    7900 1350
	0    1    -1   0   
$EndComp
$Comp
L Transistor_BJT:MMBT3904 Q?
U 1 1 5C5AE62B
P 7800 2200
F 0 "Q?" H 7991 2246 50  0000 L CNN
F 1 "MMBT3904" H 7991 2155 50  0000 L CNN
F 2 "Snack Machine:SOT-23_Handsoldering_Lite" H 8000 2125 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N3904.pdf" H 7800 2200 50  0001 L CNN
	1    7800 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	7500 2200 7600 2200
Wire Wire Line
	7900 2400 7900 2500
$Comp
L Device:R R?
U 1 1 5C5AE634
P 7900 1800
AR Path="/5C5AE634" Ref="R?"  Part="1" 
AR Path="/5BA75957/5C5AE634" Ref="R29"  Part="1" 
F 0 "R29" H 7970 1846 50  0000 L CNN
F 1 "1K" H 7970 1755 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 7830 1800 50  0001 C CNN
F 3 "~" H 7900 1800 50  0001 C CNN
	1    7900 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	7900 1950 7900 2000
Wire Wire Line
	7350 1250 7450 1250
Wire Wire Line
	7500 1600 7450 1600
Wire Wire Line
	7450 1600 7450 1250
Connection ~ 7450 1250
Wire Wire Line
	7450 1250 7700 1250
Wire Wire Line
	7800 1600 7900 1600
Wire Wire Line
	7900 1600 7900 1550
Wire Wire Line
	7900 1650 7900 1600
Connection ~ 7900 1600
$Comp
L power:+24V #PWR?
U 1 1 5C5AE645
P 10150 1250
AR Path="/5C5AE645" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5C5AE645" Ref="#PWR079"  Part="1" 
F 0 "#PWR079" H 10150 1100 50  0001 C CNN
F 1 "+24V" H 10165 1423 50  0000 C CNN
F 2 "" H 10150 1250 50  0001 C CNN
F 3 "" H 10150 1250 50  0001 C CNN
	1    10150 1250
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5C5AE64B
P 10450 1600
AR Path="/5C5AE64B" Ref="R?"  Part="1" 
AR Path="/5BA75957/5C5AE64B" Ref="R24"  Part="1" 
F 0 "R24" V 10350 1500 50  0000 L CNN
F 1 "1K" V 10550 1550 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 10380 1600 50  0001 C CNN
F 3 "~" H 10450 1600 50  0001 C CNN
	1    10450 1600
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5C5AE652
P 10150 2200
AR Path="/5C5AE652" Ref="R?"  Part="1" 
AR Path="/5BA75957/5C5AE652" Ref="R34"  Part="1" 
F 0 "R34" V 10250 2200 50  0000 C CNN
F 1 "1k" V 10350 2200 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 10080 2200 50  0001 C CNN
F 3 "~" H 10150 2200 50  0001 C CNN
	1    10150 2200
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C5AE659
P 10700 2500
AR Path="/5C5AE659" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5C5AE659" Ref="#PWR089"  Part="1" 
F 0 "#PWR089" H 10700 2250 50  0001 C CNN
F 1 "GND" H 10705 2327 50  0000 C CNN
F 2 "" H 10700 2500 50  0001 C CNN
F 3 "" H 10700 2500 50  0001 C CNN
	1    10700 2500
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_PMOS_GSD Q?
U 1 1 5C5AE661
P 10700 1350
AR Path="/5C5AE661" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5C5AE661" Ref="Q5"  Part="1" 
F 0 "Q5" V 11050 1300 50  0000 L CNN
F 1 "P-CH 30V 3.8A" V 10950 1300 50  0000 L CNN
F 2 "Snack Machine:TSOT-23_HandSoldering_Lite" H 10900 1450 50  0001 C CNN
F 3 "~" H 10700 1350 50  0001 C CNN
F 4 "Diodes Incorporated" V 10700 1350 50  0001 C CNN "Manufacturer"
F 5 "DMP3099L-7" V 10700 1350 50  0001 C CNN "Part Number"
	1    10700 1350
	0    1    -1   0   
$EndComp
$Comp
L Transistor_BJT:MMBT3904 Q?
U 1 1 5C5AE668
P 10600 2200
F 0 "Q?" H 10791 2246 50  0000 L CNN
F 1 "MMBT3904" H 10791 2155 50  0000 L CNN
F 2 "Snack Machine:SOT-23_Handsoldering_Lite" H 10800 2125 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N3904.pdf" H 10600 2200 50  0001 L CNN
	1    10600 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	10300 2200 10400 2200
Wire Wire Line
	10700 2400 10700 2500
$Comp
L Device:R R?
U 1 1 5C5AE671
P 10700 1800
AR Path="/5C5AE671" Ref="R?"  Part="1" 
AR Path="/5BA75957/5C5AE671" Ref="R30"  Part="1" 
F 0 "R30" H 10770 1846 50  0000 L CNN
F 1 "1K" H 10770 1755 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 10630 1800 50  0001 C CNN
F 3 "~" H 10700 1800 50  0001 C CNN
	1    10700 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	10700 1950 10700 2000
Wire Wire Line
	10150 1250 10250 1250
Wire Wire Line
	10300 1600 10250 1600
Wire Wire Line
	10250 1600 10250 1250
Connection ~ 10250 1250
Wire Wire Line
	10250 1250 10500 1250
Wire Wire Line
	10600 1600 10700 1600
Wire Wire Line
	10700 1600 10700 1550
Wire Wire Line
	10700 1650 10700 1600
Connection ~ 10700 1600
$Comp
L Device:D D?
U 1 1 5C5AE684
P 8700 1500
F 0 "D?" V 8650 1600 50  0000 L CNN
F 1 "50V 2A" V 8750 1600 50  0000 L CNN
F 2 "Snack Machine:D_SMB_Handsoldering_Lite" H 8700 1500 50  0001 C CNN
F 3 "~" H 8700 1500 50  0001 C CNN
F 4 "ON Semiconductor" H 8700 1500 50  0001 C CNN "Manufacturer"
F 5 "ES2A" H 8700 1500 50  0001 C CNN "Part Number"
	1    8700 1500
	0    1    1    0   
$EndComp
$Comp
L Device:C C?
U 1 1 5C5AE68B
P 8500 1500
F 0 "C?" H 8250 1550 50  0000 L CNN
F 1 "1uF 50V" H 8050 1450 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 8538 1350 50  0001 C CNN
F 3 "~" H 8500 1500 50  0001 C CNN
F 4 "Samsung" H 8500 1500 50  0001 C CNN "Manufacturer"
F 5 "CL10A105KB8NNNC" H 8500 1500 50  0001 C CNN "Part Number"
	1    8500 1500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C5AE692
P 8500 1750
AR Path="/5C5AE692" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5C5AE692" Ref="#PWR085"  Part="1" 
F 0 "#PWR085" H 8500 1500 50  0001 C CNN
F 1 "GND" H 8505 1577 50  0000 C CNN
F 2 "" H 8500 1750 50  0001 C CNN
F 3 "" H 8500 1750 50  0001 C CNN
	1    8500 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	8700 1650 8700 1700
Wire Wire Line
	8700 1700 8500 1700
Wire Wire Line
	8500 1700 8500 1750
Wire Wire Line
	8500 1650 8500 1700
Connection ~ 8500 1700
Wire Wire Line
	8500 1350 8500 1250
Connection ~ 8500 1250
Wire Wire Line
	8500 1250 8100 1250
Wire Wire Line
	8700 1350 8700 1250
Connection ~ 8700 1250
Wire Wire Line
	8700 1250 8500 1250
Wire Wire Line
	10000 2200 9900 2200
Wire Wire Line
	11650 1250 11500 1250
$Comp
L Device:D D?
U 1 1 5C5AE6A7
P 11500 1500
F 0 "D?" V 11450 1600 50  0000 L CNN
F 1 "50V 2A" V 11550 1600 50  0000 L CNN
F 2 "Snack Machine:D_SMB_Handsoldering_Lite" H 11500 1500 50  0001 C CNN
F 3 "~" H 11500 1500 50  0001 C CNN
F 4 "ON Semiconductor" H 11500 1500 50  0001 C CNN "Manufacturer"
F 5 "ES2A" H 11500 1500 50  0001 C CNN "Part Number"
	1    11500 1500
	0    1    1    0   
$EndComp
$Comp
L Device:C C?
U 1 1 5C5AE6AE
P 11300 1500
F 0 "C?" H 11050 1550 50  0000 L CNN
F 1 "1uF 50V" H 10850 1450 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 11338 1350 50  0001 C CNN
F 3 "~" H 11300 1500 50  0001 C CNN
F 4 "Samsung" H 11300 1500 50  0001 C CNN "Manufacturer"
F 5 "CL10A105KB8NNNC" H 11300 1500 50  0001 C CNN "Part Number"
	1    11300 1500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C5AE6B5
P 11300 1750
AR Path="/5C5AE6B5" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5C5AE6B5" Ref="#PWR086"  Part="1" 
F 0 "#PWR086" H 11300 1500 50  0001 C CNN
F 1 "GND" H 11305 1577 50  0000 C CNN
F 2 "" H 11300 1750 50  0001 C CNN
F 3 "" H 11300 1750 50  0001 C CNN
	1    11300 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	11500 1650 11500 1700
Wire Wire Line
	11500 1700 11300 1700
Wire Wire Line
	11300 1700 11300 1750
Wire Wire Line
	11300 1650 11300 1700
Connection ~ 11300 1700
Wire Wire Line
	11300 1350 11300 1250
Connection ~ 11300 1250
Wire Wire Line
	11300 1250 10900 1250
Wire Wire Line
	11500 1350 11500 1250
Connection ~ 11500 1250
Wire Wire Line
	11500 1250 11300 1250
$Comp
L power:+24V #PWR?
U 1 1 5C5C35E7
P 1750 3200
AR Path="/5C5C35E7" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5C5C35E7" Ref="#PWR090"  Part="1" 
F 0 "#PWR090" H 1750 3050 50  0001 C CNN
F 1 "+24V" H 1765 3373 50  0000 C CNN
F 2 "" H 1750 3200 50  0001 C CNN
F 3 "" H 1750 3200 50  0001 C CNN
	1    1750 3200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5C5C35ED
P 2050 3550
AR Path="/5C5C35ED" Ref="R?"  Part="1" 
AR Path="/5BA75957/5C5C35ED" Ref="R35"  Part="1" 
F 0 "R35" V 1950 3450 50  0000 L CNN
F 1 "1K" V 2150 3500 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 1980 3550 50  0001 C CNN
F 3 "~" H 2050 3550 50  0001 C CNN
	1    2050 3550
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5C5C35F4
P 1750 4150
AR Path="/5C5C35F4" Ref="R?"  Part="1" 
AR Path="/5BA75957/5C5C35F4" Ref="R44"  Part="1" 
F 0 "R44" V 1850 4150 50  0000 C CNN
F 1 "1k" V 1950 4150 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 1680 4150 50  0001 C CNN
F 3 "~" H 1750 4150 50  0001 C CNN
	1    1750 4150
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C5C35FB
P 2300 4450
AR Path="/5C5C35FB" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5C5C35FB" Ref="#PWR0134"  Part="1" 
F 0 "#PWR0134" H 2300 4200 50  0001 C CNN
F 1 "GND" H 2305 4277 50  0000 C CNN
F 2 "" H 2300 4450 50  0001 C CNN
F 3 "" H 2300 4450 50  0001 C CNN
	1    2300 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	1600 4150 1500 4150
Wire Wire Line
	3250 3200 3100 3200
$Comp
L Device:Q_PMOS_GSD Q?
U 1 1 5C5C360D
P 2300 3300
AR Path="/5C5C360D" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5C5C360D" Ref="Q11"  Part="1" 
F 0 "Q11" V 2650 3250 50  0000 L CNN
F 1 "P-CH 30V 3.8A" V 2550 3250 50  0000 L CNN
F 2 "Snack Machine:TSOT-23_HandSoldering_Lite" H 2500 3400 50  0001 C CNN
F 3 "~" H 2300 3300 50  0001 C CNN
F 4 "Diodes Incorporated" V 2300 3300 50  0001 C CNN "Manufacturer"
F 5 "DMP3099L-7" V 2300 3300 50  0001 C CNN "Part Number"
	1    2300 3300
	0    1    -1   0   
$EndComp
$Comp
L Transistor_BJT:MMBT3904 Q?
U 1 1 5C5C3614
P 2200 4150
F 0 "Q?" H 2391 4196 50  0000 L CNN
F 1 "MMBT3904" H 2391 4105 50  0000 L CNN
F 2 "Snack Machine:SOT-23_Handsoldering_Lite" H 2400 4075 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N3904.pdf" H 2200 4150 50  0001 L CNN
	1    2200 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	1900 4150 2000 4150
Wire Wire Line
	2300 4350 2300 4450
$Comp
L Device:R R?
U 1 1 5C5C361D
P 2300 3750
AR Path="/5C5C361D" Ref="R?"  Part="1" 
AR Path="/5BA75957/5C5C361D" Ref="R40"  Part="1" 
F 0 "R40" H 2370 3796 50  0000 L CNN
F 1 "1K" H 2370 3705 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 2230 3750 50  0001 C CNN
F 3 "~" H 2300 3750 50  0001 C CNN
	1    2300 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	2300 3900 2300 3950
Wire Wire Line
	1750 3200 1850 3200
Wire Wire Line
	1900 3550 1850 3550
Wire Wire Line
	1850 3550 1850 3200
Connection ~ 1850 3200
Wire Wire Line
	1850 3200 2100 3200
Wire Wire Line
	2200 3550 2300 3550
Wire Wire Line
	2300 3550 2300 3500
Wire Wire Line
	2300 3600 2300 3550
Connection ~ 2300 3550
$Comp
L power:+24V #PWR?
U 1 1 5C5C362E
P 4550 3200
AR Path="/5C5C362E" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5C5C362E" Ref="#PWR0120"  Part="1" 
F 0 "#PWR0120" H 4550 3050 50  0001 C CNN
F 1 "+24V" H 4565 3373 50  0000 C CNN
F 2 "" H 4550 3200 50  0001 C CNN
F 3 "" H 4550 3200 50  0001 C CNN
	1    4550 3200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5C5C3634
P 4850 3550
AR Path="/5C5C3634" Ref="R?"  Part="1" 
AR Path="/5BA75957/5C5C3634" Ref="R36"  Part="1" 
F 0 "R36" V 4750 3450 50  0000 L CNN
F 1 "1K" V 4950 3500 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 4780 3550 50  0001 C CNN
F 3 "~" H 4850 3550 50  0001 C CNN
	1    4850 3550
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5C5C363B
P 4550 4150
AR Path="/5C5C363B" Ref="R?"  Part="1" 
AR Path="/5BA75957/5C5C363B" Ref="R45"  Part="1" 
F 0 "R45" V 4650 4150 50  0000 C CNN
F 1 "1k" V 4750 4150 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 4480 4150 50  0001 C CNN
F 3 "~" H 4550 4150 50  0001 C CNN
	1    4550 4150
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C5C3642
P 5100 4450
AR Path="/5C5C3642" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5C5C3642" Ref="#PWR0135"  Part="1" 
F 0 "#PWR0135" H 5100 4200 50  0001 C CNN
F 1 "GND" H 5105 4277 50  0000 C CNN
F 2 "" H 5100 4450 50  0001 C CNN
F 3 "" H 5100 4450 50  0001 C CNN
	1    5100 4450
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_PMOS_GSD Q?
U 1 1 5C5C364A
P 5100 3300
AR Path="/5C5C364A" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5C5C364A" Ref="Q12"  Part="1" 
F 0 "Q12" V 5450 3250 50  0000 L CNN
F 1 "P-CH 30V 3.8A" V 5350 3250 50  0000 L CNN
F 2 "Snack Machine:TSOT-23_HandSoldering_Lite" H 5300 3400 50  0001 C CNN
F 3 "~" H 5100 3300 50  0001 C CNN
F 4 "Diodes Incorporated" V 5100 3300 50  0001 C CNN "Manufacturer"
F 5 "DMP3099L-7" V 5100 3300 50  0001 C CNN "Part Number"
	1    5100 3300
	0    1    -1   0   
$EndComp
$Comp
L Transistor_BJT:MMBT3904 Q?
U 1 1 5C5C3651
P 5000 4150
F 0 "Q?" H 5191 4196 50  0000 L CNN
F 1 "MMBT3904" H 5191 4105 50  0000 L CNN
F 2 "Snack Machine:SOT-23_Handsoldering_Lite" H 5200 4075 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N3904.pdf" H 5000 4150 50  0001 L CNN
	1    5000 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 4150 4800 4150
Wire Wire Line
	5100 4350 5100 4450
$Comp
L Device:R R?
U 1 1 5C5C365A
P 5100 3750
AR Path="/5C5C365A" Ref="R?"  Part="1" 
AR Path="/5BA75957/5C5C365A" Ref="R41"  Part="1" 
F 0 "R41" H 5170 3796 50  0000 L CNN
F 1 "1K" H 5170 3705 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 5030 3750 50  0001 C CNN
F 3 "~" H 5100 3750 50  0001 C CNN
	1    5100 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 3900 5100 3950
Wire Wire Line
	4550 3200 4650 3200
Wire Wire Line
	4700 3550 4650 3550
Wire Wire Line
	4650 3550 4650 3200
Connection ~ 4650 3200
Wire Wire Line
	4650 3200 4900 3200
Wire Wire Line
	5000 3550 5100 3550
Wire Wire Line
	5100 3550 5100 3500
Wire Wire Line
	5100 3600 5100 3550
Connection ~ 5100 3550
$Comp
L Device:D D?
U 1 1 5C5C366D
P 3100 3450
F 0 "D?" V 3050 3550 50  0000 L CNN
F 1 "50V 2A" V 3150 3550 50  0000 L CNN
F 2 "Snack Machine:D_SMB_Handsoldering_Lite" H 3100 3450 50  0001 C CNN
F 3 "~" H 3100 3450 50  0001 C CNN
F 4 "ON Semiconductor" H 3100 3450 50  0001 C CNN "Manufacturer"
F 5 "ES2A" H 3100 3450 50  0001 C CNN "Part Number"
	1    3100 3450
	0    1    1    0   
$EndComp
$Comp
L Device:C C?
U 1 1 5C5C3674
P 2900 3450
F 0 "C?" H 2650 3500 50  0000 L CNN
F 1 "1uF 50V" H 2450 3400 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 2938 3300 50  0001 C CNN
F 3 "~" H 2900 3450 50  0001 C CNN
F 4 "Samsung" H 2900 3450 50  0001 C CNN "Manufacturer"
F 5 "CL10A105KB8NNNC" H 2900 3450 50  0001 C CNN "Part Number"
	1    2900 3450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C5C367B
P 2900 3700
AR Path="/5C5C367B" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5C5C367B" Ref="#PWR0130"  Part="1" 
F 0 "#PWR0130" H 2900 3450 50  0001 C CNN
F 1 "GND" H 2905 3527 50  0000 C CNN
F 2 "" H 2900 3700 50  0001 C CNN
F 3 "" H 2900 3700 50  0001 C CNN
	1    2900 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	3100 3600 3100 3650
Wire Wire Line
	3100 3650 2900 3650
Wire Wire Line
	2900 3650 2900 3700
Wire Wire Line
	2900 3600 2900 3650
Connection ~ 2900 3650
Wire Wire Line
	2900 3300 2900 3200
Connection ~ 2900 3200
Wire Wire Line
	2900 3200 2500 3200
Wire Wire Line
	3100 3300 3100 3200
Connection ~ 3100 3200
Wire Wire Line
	3100 3200 2900 3200
Wire Wire Line
	4400 4150 4300 4150
Wire Wire Line
	6050 3200 5900 3200
$Comp
L Device:D D?
U 1 1 5C5C3690
P 5900 3450
F 0 "D?" V 5850 3550 50  0000 L CNN
F 1 "50V 2A" V 5950 3550 50  0000 L CNN
F 2 "Snack Machine:D_SMB_Handsoldering_Lite" H 5900 3450 50  0001 C CNN
F 3 "~" H 5900 3450 50  0001 C CNN
F 4 "ON Semiconductor" H 5900 3450 50  0001 C CNN "Manufacturer"
F 5 "ES2A" H 5900 3450 50  0001 C CNN "Part Number"
	1    5900 3450
	0    1    1    0   
$EndComp
$Comp
L Device:C C?
U 1 1 5C5C3697
P 5700 3450
F 0 "C?" H 5450 3500 50  0000 L CNN
F 1 "1uF 50V" H 5250 3400 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 5738 3300 50  0001 C CNN
F 3 "~" H 5700 3450 50  0001 C CNN
F 4 "Samsung" H 5700 3450 50  0001 C CNN "Manufacturer"
F 5 "CL10A105KB8NNNC" H 5700 3450 50  0001 C CNN "Part Number"
	1    5700 3450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C5C369E
P 5700 3700
AR Path="/5C5C369E" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5C5C369E" Ref="#PWR0131"  Part="1" 
F 0 "#PWR0131" H 5700 3450 50  0001 C CNN
F 1 "GND" H 5705 3527 50  0000 C CNN
F 2 "" H 5700 3700 50  0001 C CNN
F 3 "" H 5700 3700 50  0001 C CNN
	1    5700 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5900 3600 5900 3650
Wire Wire Line
	5900 3650 5700 3650
Wire Wire Line
	5700 3650 5700 3700
Wire Wire Line
	5700 3600 5700 3650
Connection ~ 5700 3650
Wire Wire Line
	5700 3300 5700 3200
Connection ~ 5700 3200
Wire Wire Line
	5700 3200 5300 3200
Wire Wire Line
	5900 3300 5900 3200
Connection ~ 5900 3200
Wire Wire Line
	5900 3200 5700 3200
$Comp
L power:+24V #PWR?
U 1 1 5C5C36AF
P 7350 3200
AR Path="/5C5C36AF" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5C5C36AF" Ref="#PWR0122"  Part="1" 
F 0 "#PWR0122" H 7350 3050 50  0001 C CNN
F 1 "+24V" H 7365 3373 50  0000 C CNN
F 2 "" H 7350 3200 50  0001 C CNN
F 3 "" H 7350 3200 50  0001 C CNN
	1    7350 3200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5C5C36B5
P 7650 3550
AR Path="/5C5C36B5" Ref="R?"  Part="1" 
AR Path="/5BA75957/5C5C36B5" Ref="R37"  Part="1" 
F 0 "R37" V 7550 3450 50  0000 L CNN
F 1 "1K" V 7750 3500 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 7580 3550 50  0001 C CNN
F 3 "~" H 7650 3550 50  0001 C CNN
	1    7650 3550
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5C5C36BC
P 7350 4150
AR Path="/5C5C36BC" Ref="R?"  Part="1" 
AR Path="/5BA75957/5C5C36BC" Ref="R46"  Part="1" 
F 0 "R46" V 7450 4150 50  0000 C CNN
F 1 "1k" V 7550 4150 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 7280 4150 50  0001 C CNN
F 3 "~" H 7350 4150 50  0001 C CNN
	1    7350 4150
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C5C36C3
P 7900 4450
AR Path="/5C5C36C3" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5C5C36C3" Ref="#PWR0136"  Part="1" 
F 0 "#PWR0136" H 7900 4200 50  0001 C CNN
F 1 "GND" H 7905 4277 50  0000 C CNN
F 2 "" H 7900 4450 50  0001 C CNN
F 3 "" H 7900 4450 50  0001 C CNN
	1    7900 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	7200 4150 7100 4150
Wire Wire Line
	8850 3200 8700 3200
$Comp
L Device:Q_PMOS_GSD Q?
U 1 1 5C5C36CD
P 7900 3300
AR Path="/5C5C36CD" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5C5C36CD" Ref="Q13"  Part="1" 
F 0 "Q13" V 8250 3250 50  0000 L CNN
F 1 "P-CH 30V 3.8A" V 8150 3250 50  0000 L CNN
F 2 "Snack Machine:TSOT-23_HandSoldering_Lite" H 8100 3400 50  0001 C CNN
F 3 "~" H 7900 3300 50  0001 C CNN
F 4 "Diodes Incorporated" V 7900 3300 50  0001 C CNN "Manufacturer"
F 5 "DMP3099L-7" V 7900 3300 50  0001 C CNN "Part Number"
	1    7900 3300
	0    1    -1   0   
$EndComp
$Comp
L Transistor_BJT:MMBT3904 Q?
U 1 1 5C5C36D4
P 7800 4150
F 0 "Q?" H 7991 4196 50  0000 L CNN
F 1 "MMBT3904" H 7991 4105 50  0000 L CNN
F 2 "Snack Machine:SOT-23_Handsoldering_Lite" H 8000 4075 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N3904.pdf" H 7800 4150 50  0001 L CNN
	1    7800 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	7500 4150 7600 4150
Wire Wire Line
	7900 4350 7900 4450
$Comp
L Device:R R?
U 1 1 5C5C36DD
P 7900 3750
AR Path="/5C5C36DD" Ref="R?"  Part="1" 
AR Path="/5BA75957/5C5C36DD" Ref="R42"  Part="1" 
F 0 "R42" H 7970 3796 50  0000 L CNN
F 1 "1K" H 7970 3705 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 7830 3750 50  0001 C CNN
F 3 "~" H 7900 3750 50  0001 C CNN
	1    7900 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7900 3900 7900 3950
Wire Wire Line
	7350 3200 7450 3200
Wire Wire Line
	7500 3550 7450 3550
Wire Wire Line
	7450 3550 7450 3200
Connection ~ 7450 3200
Wire Wire Line
	7450 3200 7700 3200
Wire Wire Line
	7800 3550 7900 3550
Wire Wire Line
	7900 3550 7900 3500
Wire Wire Line
	7900 3600 7900 3550
Connection ~ 7900 3550
$Comp
L power:+24V #PWR?
U 1 1 5C5C36EE
P 10150 3200
AR Path="/5C5C36EE" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5C5C36EE" Ref="#PWR0124"  Part="1" 
F 0 "#PWR0124" H 10150 3050 50  0001 C CNN
F 1 "+24V" H 10165 3373 50  0000 C CNN
F 2 "" H 10150 3200 50  0001 C CNN
F 3 "" H 10150 3200 50  0001 C CNN
	1    10150 3200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5C5C36F4
P 10450 3550
AR Path="/5C5C36F4" Ref="R?"  Part="1" 
AR Path="/5BA75957/5C5C36F4" Ref="R39"  Part="1" 
F 0 "R39" V 10350 3450 50  0000 L CNN
F 1 "1K" V 10550 3500 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 10380 3550 50  0001 C CNN
F 3 "~" H 10450 3550 50  0001 C CNN
	1    10450 3550
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5C5C36FB
P 10150 4150
AR Path="/5C5C36FB" Ref="R?"  Part="1" 
AR Path="/5BA75957/5C5C36FB" Ref="R47"  Part="1" 
F 0 "R47" V 10250 4150 50  0000 C CNN
F 1 "1k" V 10350 4150 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 10080 4150 50  0001 C CNN
F 3 "~" H 10150 4150 50  0001 C CNN
	1    10150 4150
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C5C3702
P 10700 4450
AR Path="/5C5C3702" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5C5C3702" Ref="#PWR0137"  Part="1" 
F 0 "#PWR0137" H 10700 4200 50  0001 C CNN
F 1 "GND" H 10705 4277 50  0000 C CNN
F 2 "" H 10700 4450 50  0001 C CNN
F 3 "" H 10700 4450 50  0001 C CNN
	1    10700 4450
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_PMOS_GSD Q?
U 1 1 5C5C370A
P 10700 3300
AR Path="/5C5C370A" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5C5C370A" Ref="Q14"  Part="1" 
F 0 "Q14" V 11050 3250 50  0000 L CNN
F 1 "P-CH 30V 3.8A" V 10950 3250 50  0000 L CNN
F 2 "Snack Machine:TSOT-23_HandSoldering_Lite" H 10900 3400 50  0001 C CNN
F 3 "~" H 10700 3300 50  0001 C CNN
F 4 "Diodes Incorporated" V 10700 3300 50  0001 C CNN "Manufacturer"
F 5 "DMP3099L-7" V 10700 3300 50  0001 C CNN "Part Number"
	1    10700 3300
	0    1    -1   0   
$EndComp
$Comp
L Transistor_BJT:MMBT3904 Q?
U 1 1 5C5C3711
P 10600 4150
F 0 "Q?" H 10791 4196 50  0000 L CNN
F 1 "MMBT3904" H 10791 4105 50  0000 L CNN
F 2 "Snack Machine:SOT-23_Handsoldering_Lite" H 10800 4075 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N3904.pdf" H 10600 4150 50  0001 L CNN
	1    10600 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	10300 4150 10400 4150
Wire Wire Line
	10700 4350 10700 4450
$Comp
L Device:R R?
U 1 1 5C5C371A
P 10700 3750
AR Path="/5C5C371A" Ref="R?"  Part="1" 
AR Path="/5BA75957/5C5C371A" Ref="R43"  Part="1" 
F 0 "R43" H 10770 3796 50  0000 L CNN
F 1 "1K" H 10770 3705 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 10630 3750 50  0001 C CNN
F 3 "~" H 10700 3750 50  0001 C CNN
	1    10700 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	10700 3900 10700 3950
Wire Wire Line
	10150 3200 10250 3200
Wire Wire Line
	10300 3550 10250 3550
Wire Wire Line
	10250 3550 10250 3200
Connection ~ 10250 3200
Wire Wire Line
	10250 3200 10500 3200
Wire Wire Line
	10600 3550 10700 3550
Wire Wire Line
	10700 3550 10700 3500
Wire Wire Line
	10700 3600 10700 3550
Connection ~ 10700 3550
$Comp
L Device:D D?
U 1 1 5C5C372D
P 8700 3450
F 0 "D?" V 8650 3550 50  0000 L CNN
F 1 "50V 2A" V 8750 3550 50  0000 L CNN
F 2 "Snack Machine:D_SMB_Handsoldering_Lite" H 8700 3450 50  0001 C CNN
F 3 "~" H 8700 3450 50  0001 C CNN
F 4 "ON Semiconductor" H 8700 3450 50  0001 C CNN "Manufacturer"
F 5 "ES2A" H 8700 3450 50  0001 C CNN "Part Number"
	1    8700 3450
	0    1    1    0   
$EndComp
$Comp
L Device:C C?
U 1 1 5C5C3734
P 8500 3450
F 0 "C?" H 8250 3500 50  0000 L CNN
F 1 "1uF 50V" H 8050 3400 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 8538 3300 50  0001 C CNN
F 3 "~" H 8500 3450 50  0001 C CNN
F 4 "Samsung" H 8500 3450 50  0001 C CNN "Manufacturer"
F 5 "CL10A105KB8NNNC" H 8500 3450 50  0001 C CNN "Part Number"
	1    8500 3450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C5C373B
P 8500 3700
AR Path="/5C5C373B" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5C5C373B" Ref="#PWR0132"  Part="1" 
F 0 "#PWR0132" H 8500 3450 50  0001 C CNN
F 1 "GND" H 8505 3527 50  0000 C CNN
F 2 "" H 8500 3700 50  0001 C CNN
F 3 "" H 8500 3700 50  0001 C CNN
	1    8500 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	8700 3600 8700 3650
Wire Wire Line
	8700 3650 8500 3650
Wire Wire Line
	8500 3650 8500 3700
Wire Wire Line
	8500 3600 8500 3650
Connection ~ 8500 3650
Wire Wire Line
	8500 3300 8500 3200
Connection ~ 8500 3200
Wire Wire Line
	8500 3200 8100 3200
Wire Wire Line
	8700 3300 8700 3200
Connection ~ 8700 3200
Wire Wire Line
	8700 3200 8500 3200
Wire Wire Line
	10000 4150 9900 4150
Wire Wire Line
	11650 3200 11500 3200
$Comp
L Device:D D?
U 1 1 5C5C3750
P 11500 3450
F 0 "D?" V 11450 3550 50  0000 L CNN
F 1 "50V 2A" V 11550 3550 50  0000 L CNN
F 2 "Snack Machine:D_SMB_Handsoldering_Lite" H 11500 3450 50  0001 C CNN
F 3 "~" H 11500 3450 50  0001 C CNN
F 4 "ON Semiconductor" H 11500 3450 50  0001 C CNN "Manufacturer"
F 5 "ES2A" H 11500 3450 50  0001 C CNN "Part Number"
	1    11500 3450
	0    1    1    0   
$EndComp
$Comp
L Device:C C?
U 1 1 5C5C3757
P 11300 3450
F 0 "C?" H 11050 3500 50  0000 L CNN
F 1 "1uF 50V" H 10850 3400 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 11338 3300 50  0001 C CNN
F 3 "~" H 11300 3450 50  0001 C CNN
F 4 "Samsung" H 11300 3450 50  0001 C CNN "Manufacturer"
F 5 "CL10A105KB8NNNC" H 11300 3450 50  0001 C CNN "Part Number"
	1    11300 3450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5C5C375E
P 11300 3700
AR Path="/5C5C375E" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5C5C375E" Ref="#PWR0133"  Part="1" 
F 0 "#PWR0133" H 11300 3450 50  0001 C CNN
F 1 "GND" H 11305 3527 50  0000 C CNN
F 2 "" H 11300 3700 50  0001 C CNN
F 3 "" H 11300 3700 50  0001 C CNN
	1    11300 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	11500 3600 11500 3650
Wire Wire Line
	11500 3650 11300 3650
Wire Wire Line
	11300 3650 11300 3700
Wire Wire Line
	11300 3600 11300 3650
Connection ~ 11300 3650
Wire Wire Line
	11300 3300 11300 3200
Connection ~ 11300 3200
Wire Wire Line
	11300 3200 10900 3200
Wire Wire Line
	11500 3300 11500 3200
Connection ~ 11500 3200
Wire Wire Line
	11500 3200 11300 3200
Wire Wire Line
	4700 5000 5100 5000
Wire Wire Line
	4300 5200 4400 5200
Text Label 5150 5550 0    50   ~ 0
motor_common_gnd
Wire Wire Line
	5950 5550 5100 5550
Wire Wire Line
	4700 5200 4800 5200
Wire Wire Line
	4800 5550 4800 5200
Wire Wire Line
	5100 5550 5100 5400
Connection ~ 5100 5550
$Comp
L Device:R R?
U 1 1 5C5DBCEA
P 4950 5550
AR Path="/5C5DBCEA" Ref="R?"  Part="1" 
AR Path="/5BA75957/5C5DBCEA" Ref="R52"  Part="1" 
F 0 "R52" V 4850 5550 50  0000 C CNN
F 1 "10k" V 5050 5550 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 4880 5550 50  0001 C CNN
F 3 "~" H 4950 5550 50  0001 C CNN
	1    4950 5550
	0    1    1    0   
$EndComp
Connection ~ 4800 5200
$Comp
L Device:Q_NMOS_GSD Q?
U 1 1 5C5DBCF4
P 5000 5200
F 0 "Q?" H 5205 5246 50  0000 L CNN
F 1 "Q_NMOS_SGD" H 5205 5155 50  0000 L CNN
F 2 "Snack Machine:TSOT-23_HandSoldering_Lite" H 5200 5300 50  0001 C CNN
F 3 "~" H 5000 5200 50  0001 C CNN
F 4 "ON Semiconductor" H 5000 5200 50  0001 C CNN "Manufacturer"
F 5 "NTR4003NT1G" H 5000 5200 50  0001 C CNN "Part Number"
	1    5000 5200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5C5DBCFB
P 4550 5200
AR Path="/5C5DBCFB" Ref="R?"  Part="1" 
AR Path="/5BA75957/5C5DBCFB" Ref="R49"  Part="1" 
F 0 "R49" V 4450 5200 50  0000 C CNN
F 1 "1k" V 4650 5200 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 4480 5200 50  0001 C CNN
F 3 "~" H 4550 5200 50  0001 C CNN
	1    4550 5200
	0    1    1    0   
$EndComp
Wire Wire Line
	7500 5000 7900 5000
Wire Wire Line
	7100 5200 7200 5200
Text Label 7950 5550 0    50   ~ 0
motor_common_gnd
Wire Wire Line
	8750 5550 7900 5550
Wire Wire Line
	7500 5200 7600 5200
Wire Wire Line
	7600 5550 7600 5200
Wire Wire Line
	7900 5550 7900 5400
Connection ~ 7900 5550
$Comp
L Device:R R?
U 1 1 5C5F2C92
P 7750 5550
AR Path="/5C5F2C92" Ref="R?"  Part="1" 
AR Path="/5BA75957/5C5F2C92" Ref="R53"  Part="1" 
F 0 "R53" V 7650 5550 50  0000 C CNN
F 1 "10k" V 7850 5550 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 7680 5550 50  0001 C CNN
F 3 "~" H 7750 5550 50  0001 C CNN
	1    7750 5550
	0    1    1    0   
$EndComp
Connection ~ 7600 5200
$Comp
L Device:Q_NMOS_GSD Q?
U 1 1 5C5F2C9C
P 7800 5200
F 0 "Q?" H 8005 5246 50  0000 L CNN
F 1 "Q_NMOS_SGD" H 8005 5155 50  0000 L CNN
F 2 "Snack Machine:TSOT-23_HandSoldering_Lite" H 8000 5300 50  0001 C CNN
F 3 "~" H 7800 5200 50  0001 C CNN
F 4 "ON Semiconductor" H 7800 5200 50  0001 C CNN "Manufacturer"
F 5 "NTR4003NT1G" H 7800 5200 50  0001 C CNN "Part Number"
	1    7800 5200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5C5F2CA3
P 7350 5200
AR Path="/5C5F2CA3" Ref="R?"  Part="1" 
AR Path="/5BA75957/5C5F2CA3" Ref="R50"  Part="1" 
F 0 "R50" V 7250 5200 50  0000 C CNN
F 1 "1k" V 7450 5200 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 7280 5200 50  0001 C CNN
F 3 "~" H 7350 5200 50  0001 C CNN
	1    7350 5200
	0    1    1    0   
$EndComp
Wire Wire Line
	10300 5000 10700 5000
Wire Wire Line
	9900 5200 10000 5200
Text Label 10750 5550 0    50   ~ 0
motor_common_gnd
Wire Wire Line
	11550 5550 10700 5550
Wire Wire Line
	10300 5200 10400 5200
Wire Wire Line
	10400 5550 10400 5200
Wire Wire Line
	10700 5550 10700 5400
Connection ~ 10700 5550
$Comp
L Device:R R?
U 1 1 5C5F2CB2
P 10550 5550
AR Path="/5C5F2CB2" Ref="R?"  Part="1" 
AR Path="/5BA75957/5C5F2CB2" Ref="R54"  Part="1" 
F 0 "R54" V 10450 5550 50  0000 C CNN
F 1 "10k" V 10650 5550 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 10480 5550 50  0001 C CNN
F 3 "~" H 10550 5550 50  0001 C CNN
	1    10550 5550
	0    1    1    0   
$EndComp
Connection ~ 10400 5200
$Comp
L Device:Q_NMOS_GSD Q?
U 1 1 5C5F2CBC
P 10600 5200
F 0 "Q?" H 10805 5246 50  0000 L CNN
F 1 "Q_NMOS_SGD" H 10805 5155 50  0000 L CNN
F 2 "Snack Machine:TSOT-23_HandSoldering_Lite" H 10800 5300 50  0001 C CNN
F 3 "~" H 10600 5200 50  0001 C CNN
F 4 "ON Semiconductor" H 10600 5200 50  0001 C CNN "Manufacturer"
F 5 "NTR4003NT1G" H 10600 5200 50  0001 C CNN "Part Number"
	1    10600 5200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5C5F2CC3
P 10150 5200
AR Path="/5C5F2CC3" Ref="R?"  Part="1" 
AR Path="/5BA75957/5C5F2CC3" Ref="R51"  Part="1" 
F 0 "R51" V 10050 5200 50  0000 C CNN
F 1 "1k" V 10250 5200 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 10080 5200 50  0001 C CNN
F 3 "~" H 10150 5200 50  0001 C CNN
	1    10150 5200
	0    1    1    0   
$EndComp
Wire Wire Line
	1900 6100 2300 6100
Wire Wire Line
	1500 6300 1600 6300
Text Label 2350 6650 0    50   ~ 0
motor_common_gnd
Wire Wire Line
	3150 6650 2300 6650
Wire Wire Line
	1900 6300 2000 6300
Wire Wire Line
	2000 6650 2000 6300
Wire Wire Line
	2300 6650 2300 6500
Connection ~ 2300 6650
$Comp
L Device:R R?
U 1 1 5C5FF399
P 2150 6650
AR Path="/5C5FF399" Ref="R?"  Part="1" 
AR Path="/5BA75957/5C5FF399" Ref="R83"  Part="1" 
F 0 "R83" V 2050 6650 50  0000 C CNN
F 1 "10k" V 2250 6650 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 2080 6650 50  0001 C CNN
F 3 "~" H 2150 6650 50  0001 C CNN
	1    2150 6650
	0    1    1    0   
$EndComp
Connection ~ 2000 6300
$Comp
L Device:Q_NMOS_GSD Q?
U 1 1 5C5FF3A3
P 2200 6300
F 0 "Q?" H 2405 6346 50  0000 L CNN
F 1 "Q_NMOS_SGD" H 2405 6255 50  0000 L CNN
F 2 "Snack Machine:TSOT-23_HandSoldering_Lite" H 2400 6400 50  0001 C CNN
F 3 "~" H 2200 6300 50  0001 C CNN
F 4 "ON Semiconductor" H 2200 6300 50  0001 C CNN "Manufacturer"
F 5 "NTR4003NT1G" H 2200 6300 50  0001 C CNN "Part Number"
	1    2200 6300
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5C5FF3AA
P 1750 6300
AR Path="/5C5FF3AA" Ref="R?"  Part="1" 
AR Path="/5BA75957/5C5FF3AA" Ref="R79"  Part="1" 
F 0 "R79" V 1650 6300 50  0000 C CNN
F 1 "1k" V 1850 6300 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 1680 6300 50  0001 C CNN
F 3 "~" H 1750 6300 50  0001 C CNN
	1    1750 6300
	0    1    1    0   
$EndComp
Wire Wire Line
	4700 6100 5100 6100
Wire Wire Line
	4300 6300 4400 6300
Text Label 5150 6650 0    50   ~ 0
motor_common_gnd
Wire Wire Line
	5950 6650 5100 6650
Wire Wire Line
	4700 6300 4800 6300
Wire Wire Line
	4800 6650 4800 6300
Wire Wire Line
	5100 6650 5100 6500
Connection ~ 5100 6650
$Comp
L Device:R R?
U 1 1 5C5FF3B9
P 4950 6650
AR Path="/5C5FF3B9" Ref="R?"  Part="1" 
AR Path="/5BA75957/5C5FF3B9" Ref="R84"  Part="1" 
F 0 "R84" V 4850 6650 50  0000 C CNN
F 1 "10k" V 5050 6650 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 4880 6650 50  0001 C CNN
F 3 "~" H 4950 6650 50  0001 C CNN
	1    4950 6650
	0    1    1    0   
$EndComp
Connection ~ 4800 6300
$Comp
L Device:Q_NMOS_GSD Q?
U 1 1 5C5FF3C3
P 5000 6300
F 0 "Q?" H 5205 6346 50  0000 L CNN
F 1 "Q_NMOS_SGD" H 5205 6255 50  0000 L CNN
F 2 "Snack Machine:TSOT-23_HandSoldering_Lite" H 5200 6400 50  0001 C CNN
F 3 "~" H 5000 6300 50  0001 C CNN
F 4 "ON Semiconductor" H 5000 6300 50  0001 C CNN "Manufacturer"
F 5 "NTR4003NT1G" H 5000 6300 50  0001 C CNN "Part Number"
	1    5000 6300
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5C5FF3CA
P 4550 6300
AR Path="/5C5FF3CA" Ref="R?"  Part="1" 
AR Path="/5BA75957/5C5FF3CA" Ref="R80"  Part="1" 
F 0 "R80" V 4450 6300 50  0000 C CNN
F 1 "1k" V 4650 6300 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 4480 6300 50  0001 C CNN
F 3 "~" H 4550 6300 50  0001 C CNN
	1    4550 6300
	0    1    1    0   
$EndComp
Wire Wire Line
	7500 6100 7900 6100
Wire Wire Line
	7100 6300 7200 6300
Text Label 7950 6650 0    50   ~ 0
motor_common_gnd
Wire Wire Line
	8750 6650 7900 6650
Wire Wire Line
	7500 6300 7600 6300
Wire Wire Line
	7600 6650 7600 6300
Wire Wire Line
	7900 6650 7900 6500
Connection ~ 7900 6650
$Comp
L Device:R R?
U 1 1 5C5FF3D9
P 7750 6650
AR Path="/5C5FF3D9" Ref="R?"  Part="1" 
AR Path="/5BA75957/5C5FF3D9" Ref="R85"  Part="1" 
F 0 "R85" V 7650 6650 50  0000 C CNN
F 1 "10k" V 7850 6650 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 7680 6650 50  0001 C CNN
F 3 "~" H 7750 6650 50  0001 C CNN
	1    7750 6650
	0    1    1    0   
$EndComp
Connection ~ 7600 6300
$Comp
L Device:Q_NMOS_GSD Q?
U 1 1 5C5FF3E3
P 7800 6300
F 0 "Q?" H 8005 6346 50  0000 L CNN
F 1 "Q_NMOS_SGD" H 8005 6255 50  0000 L CNN
F 2 "Snack Machine:TSOT-23_HandSoldering_Lite" H 8000 6400 50  0001 C CNN
F 3 "~" H 7800 6300 50  0001 C CNN
F 4 "ON Semiconductor" H 7800 6300 50  0001 C CNN "Manufacturer"
F 5 "NTR4003NT1G" H 7800 6300 50  0001 C CNN "Part Number"
	1    7800 6300
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5C5FF3EA
P 7350 6300
AR Path="/5C5FF3EA" Ref="R?"  Part="1" 
AR Path="/5BA75957/5C5FF3EA" Ref="R81"  Part="1" 
F 0 "R81" V 7250 6300 50  0000 C CNN
F 1 "1k" V 7450 6300 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 7280 6300 50  0001 C CNN
F 3 "~" H 7350 6300 50  0001 C CNN
	1    7350 6300
	0    1    1    0   
$EndComp
Wire Wire Line
	10300 6100 10700 6100
Wire Wire Line
	9900 6300 10000 6300
Text Label 10750 6650 0    50   ~ 0
motor_common_gnd
Wire Wire Line
	11550 6650 10700 6650
Wire Wire Line
	10300 6300 10400 6300
Wire Wire Line
	10400 6650 10400 6300
Wire Wire Line
	10700 6650 10700 6500
Connection ~ 10700 6650
$Comp
L Device:R R?
U 1 1 5C5FF3F9
P 10550 6650
AR Path="/5C5FF3F9" Ref="R?"  Part="1" 
AR Path="/5BA75957/5C5FF3F9" Ref="R86"  Part="1" 
F 0 "R86" V 10450 6650 50  0000 C CNN
F 1 "10k" V 10650 6650 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 10480 6650 50  0001 C CNN
F 3 "~" H 10550 6650 50  0001 C CNN
	1    10550 6650
	0    1    1    0   
$EndComp
Connection ~ 10400 6300
$Comp
L Device:Q_NMOS_GSD Q?
U 1 1 5C5FF403
P 10600 6300
F 0 "Q?" H 10805 6346 50  0000 L CNN
F 1 "Q_NMOS_SGD" H 10805 6255 50  0000 L CNN
F 2 "Snack Machine:TSOT-23_HandSoldering_Lite" H 10800 6400 50  0001 C CNN
F 3 "~" H 10600 6300 50  0001 C CNN
F 4 "ON Semiconductor" H 10600 6300 50  0001 C CNN "Manufacturer"
F 5 "NTR4003NT1G" H 10600 6300 50  0001 C CNN "Part Number"
	1    10600 6300
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5C5FF40A
P 10150 6300
AR Path="/5C5FF40A" Ref="R?"  Part="1" 
AR Path="/5BA75957/5C5FF40A" Ref="R82"  Part="1" 
F 0 "R82" V 10050 6300 50  0000 C CNN
F 1 "1k" V 10250 6300 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 10080 6300 50  0001 C CNN
F 3 "~" H 10150 6300 50  0001 C CNN
	1    10150 6300
	0    1    1    0   
$EndComp
Wire Notes Line
	900  7000 12400 7000
Wire Notes Line
	900  5900 12400 5900
Wire Notes Line
	900  850  12400 850 
Wire Notes Line
	900  2800 12400 2800
Wire Notes Line
	3800 850  3800 7000
Wire Notes Line
	6600 850  6600 7000
Wire Notes Line
	9400 850  9400 7000
Wire Notes Line
	12400 850  12400 7000
$EndSCHEMATC
