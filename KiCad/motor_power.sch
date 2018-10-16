EESchema Schematic File Version 4
LIBS:Snack Machine-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 2
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
L Device:Q_PMOS_SGD Q?
U 1 1 5BA8E115
P 1350 4450
AR Path="/5BA8E115" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5BA8E115" Ref="Q?"  Part="1" 
F 0 "Q?" H 1556 4496 50  0000 L CNN
F 1 "Q_PMOS_SGD" H 1556 4405 50  0000 L CNN
F 2 "" H 1550 4550 50  0001 C CNN
F 3 "~" H 1350 4450 50  0001 C CNN
	1    1350 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	1050 4450 1150 4450
$Comp
L Device:R R?
U 1 1 5BA8E124
P 1300 4950
AR Path="/5BA8E124" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BA8E124" Ref="R?"  Part="1" 
F 0 "R?" V 1093 4950 50  0000 C CNN
F 1 "1K" V 1184 4950 50  0000 C CNN
F 2 "" V 1230 4950 50  0001 C CNN
F 3 "~" H 1300 4950 50  0001 C CNN
	1    1300 4950
	0    1    1    0   
$EndComp
Wire Wire Line
	1450 4950 1450 4800
Wire Wire Line
	1650 4800 1450 4800
Connection ~ 1450 4800
Wire Wire Line
	1450 4800 1450 4650
Wire Wire Line
	1150 4950 1150 4450
Connection ~ 1150 4450
Wire Wire Line
	1050 4250 1450 4250
Text HLabel 1050 4450 0    50   Input ~ 0
col_1_ctrl
Text Label 1650 4800 0    50   ~ 0
motor_common_gnd
Text Label 2600 7050 0    50   ~ 0
motor_common_gnd
$Comp
L Device:R R?
U 1 1 5BB1C4B9
P 2400 7200
F 0 "R?" H 2470 7246 50  0000 L CNN
F 1 ".1" H 2470 7155 50  0000 L CNN
F 2 "" V 2330 7200 50  0001 C CNN
F 3 "~" H 2400 7200 50  0001 C CNN
	1    2400 7200
	1    0    0    -1  
$EndComp
Wire Wire Line
	2400 7350 2300 7350
Wire Wire Line
	2300 7350 2300 7250
Wire Wire Line
	2300 7250 2050 7250
Wire Wire Line
	2050 7150 2300 7150
Wire Wire Line
	2300 7150 2300 7050
Wire Wire Line
	2300 7050 2400 7050
Wire Wire Line
	2600 7050 2400 7050
Connection ~ 2400 7050
$Comp
L power:GND #PWR0121
U 1 1 5BB27603
P 2600 7350
F 0 "#PWR0121" H 2600 7100 50  0001 C CNN
F 1 "GND" H 2605 7177 50  0000 C CNN
F 2 "" H 2600 7350 50  0001 C CNN
F 3 "" H 2600 7350 50  0001 C CNN
	1    2600 7350
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 7350 2400 7350
Connection ~ 2400 7350
Wire Wire Line
	2300 7350 2050 7350
Connection ~ 2300 7350
Wire Wire Line
	2200 7450 2050 7450
Text HLabel 900  7450 0    50   Input ~ 0
SCL
Wire Wire Line
	900  7450 1050 7450
Text HLabel 900  7350 0    50   Input ~ 0
SDA
Wire Wire Line
	900  7350 1050 7350
$Comp
L Device:Q_PMOS_DGS Q?
U 1 1 5BCCBAF4
P 1950 900
AR Path="/5BCCBAF4" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5BCCBAF4" Ref="Q?"  Part="1" 
F 0 "Q?" V 2300 850 50  0000 L CNN
F 1 "Q_PMOS_DGS" V 2200 850 50  0000 L CNN
F 2 "" H 2150 1000 50  0001 C CNN
F 3 "~" H 1950 900 50  0001 C CNN
	1    1950 900 
	0    1    -1   0   
$EndComp
$Comp
L power:+24V #PWR?
U 1 1 5BCCBC60
P 1550 800
AR Path="/5BCCBC60" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BCCBC60" Ref="#PWR0123"  Part="1" 
F 0 "#PWR0123" H 1550 650 50  0001 C CNN
F 1 "+24V" H 1565 973 50  0000 C CNN
F 2 "" H 1550 800 50  0001 C CNN
F 3 "" H 1550 800 50  0001 C CNN
	1    1550 800 
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 800  1650 800 
$Comp
L Device:R R?
U 1 1 5BCD1BC4
P 1650 1000
AR Path="/5BCD1BC4" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BCD1BC4" Ref="R?"  Part="1" 
F 0 "R?" H 1720 1046 50  0000 L CNN
F 1 "1K" H 1720 955 50  0000 L CNN
F 2 "" V 1580 1000 50  0001 C CNN
F 3 "~" H 1650 1000 50  0001 C CNN
	1    1650 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	1650 850  1650 800 
Connection ~ 1650 800 
Wire Wire Line
	1650 800  1550 800 
Wire Wire Line
	1650 1150 1650 1250
Wire Wire Line
	1650 1250 1950 1250
Wire Wire Line
	1950 1250 1950 1100
$Comp
L Device:Q_NMOS_DGS Q?
U 1 1 5BCEAFC3
P 1850 1450
AR Path="/5BCEAFC3" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5BCEAFC3" Ref="Q?"  Part="1" 
F 0 "Q?" H 2055 1496 50  0000 L CNN
F 1 "Q_NMOS_DGS" H 2055 1405 50  0000 L CNN
F 2 "" H 2050 1550 50  0001 C CNN
F 3 "~" H 1850 1450 50  0001 C CNN
	1    1850 1450
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5BCEAFCA
P 1250 1450
AR Path="/5BCEAFCA" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BCEAFCA" Ref="R?"  Part="1" 
F 0 "R?" V 1350 1450 50  0000 C CNN
F 1 "R" V 1450 1450 50  0000 C CNN
F 2 "" V 1180 1450 50  0001 C CNN
F 3 "~" H 1250 1450 50  0001 C CNN
	1    1250 1450
	0    1    1    0   
$EndComp
Wire Wire Line
	1400 1450 1550 1450
$Comp
L Device:R R?
U 1 1 5BCEAFD2
P 1550 1700
AR Path="/5BCEAFD2" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BCEAFD2" Ref="R?"  Part="1" 
F 0 "R?" H 1650 1750 50  0000 C CNN
F 1 "1K" H 1650 1650 50  0000 C CNN
F 2 "" V 1480 1700 50  0001 C CNN
F 3 "~" H 1550 1700 50  0001 C CNN
	1    1550 1700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BCEAFDC
P 1950 2050
AR Path="/5BCEAFDC" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BCEAFDC" Ref="#PWR0124"  Part="1" 
F 0 "#PWR0124" H 1950 1800 50  0001 C CNN
F 1 "GND" H 1955 1877 50  0000 C CNN
F 2 "" H 1950 2050 50  0001 C CNN
F 3 "" H 1950 2050 50  0001 C CNN
	1    1950 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	1100 1450 950  1450
Text HLabel 950  1450 0    50   Input ~ 0
row_a_ctrl
Connection ~ 1950 1250
Wire Wire Line
	1950 1650 1950 1950
Wire Wire Line
	1550 1450 1550 1550
Connection ~ 1550 1450
Wire Wire Line
	1550 1450 1650 1450
Wire Wire Line
	1550 1850 1550 1950
Wire Wire Line
	1550 1950 1950 1950
Connection ~ 1950 1950
Wire Wire Line
	1950 1950 1950 2050
$Comp
L Snack_Machine:INA219 U?
U 1 1 5BC6BBF3
P 1550 7300
F 0 "U?" H 1550 7715 50  0000 C CNN
F 1 "INA219" H 1550 7624 50  0000 C CNN
F 2 "" H 1550 7300 50  0001 C CNN
F 3 "" H 1550 7300 50  0001 C CNN
	1    1550 7300
	1    0    0    -1  
$EndComp
Text HLabel 2250 800  2    50   Input ~ 0
row_a_motor
Wire Wire Line
	2250 800  2150 800 
$Comp
L Device:Q_PMOS_DGS Q?
U 1 1 5BC7E4F3
P 4300 900
AR Path="/5BC7E4F3" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5BC7E4F3" Ref="Q?"  Part="1" 
F 0 "Q?" V 4650 850 50  0000 L CNN
F 1 "Q_PMOS_DGS" V 4550 850 50  0000 L CNN
F 2 "" H 4500 1000 50  0001 C CNN
F 3 "~" H 4300 900 50  0001 C CNN
	1    4300 900 
	0    1    -1   0   
$EndComp
$Comp
L power:+24V #PWR?
U 1 1 5BC7E4FA
P 3900 800
AR Path="/5BC7E4FA" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BC7E4FA" Ref="#PWR0125"  Part="1" 
F 0 "#PWR0125" H 3900 650 50  0001 C CNN
F 1 "+24V" H 3915 973 50  0000 C CNN
F 2 "" H 3900 800 50  0001 C CNN
F 3 "" H 3900 800 50  0001 C CNN
	1    3900 800 
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 800  4000 800 
$Comp
L Device:R R?
U 1 1 5BC7E501
P 4000 1000
AR Path="/5BC7E501" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BC7E501" Ref="R?"  Part="1" 
F 0 "R?" H 4070 1046 50  0000 L CNN
F 1 "1K" H 4070 955 50  0000 L CNN
F 2 "" V 3930 1000 50  0001 C CNN
F 3 "~" H 4000 1000 50  0001 C CNN
	1    4000 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 850  4000 800 
Connection ~ 4000 800 
Wire Wire Line
	4000 800  3900 800 
Wire Wire Line
	4000 1150 4000 1250
Wire Wire Line
	4000 1250 4300 1250
Wire Wire Line
	4300 1250 4300 1100
$Comp
L Device:Q_NMOS_DGS Q?
U 1 1 5BC7E50E
P 4200 1450
AR Path="/5BC7E50E" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5BC7E50E" Ref="Q?"  Part="1" 
F 0 "Q?" H 4405 1496 50  0000 L CNN
F 1 "Q_NMOS_DGS" H 4405 1405 50  0000 L CNN
F 2 "" H 4400 1550 50  0001 C CNN
F 3 "~" H 4200 1450 50  0001 C CNN
	1    4200 1450
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5BC7E515
P 3600 1450
AR Path="/5BC7E515" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BC7E515" Ref="R?"  Part="1" 
F 0 "R?" V 3700 1450 50  0000 C CNN
F 1 "R" V 3800 1450 50  0000 C CNN
F 2 "" V 3530 1450 50  0001 C CNN
F 3 "~" H 3600 1450 50  0001 C CNN
	1    3600 1450
	0    1    1    0   
$EndComp
Wire Wire Line
	3750 1450 3900 1450
$Comp
L Device:R R?
U 1 1 5BC7E51D
P 3900 1700
AR Path="/5BC7E51D" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BC7E51D" Ref="R?"  Part="1" 
F 0 "R?" H 4000 1750 50  0000 C CNN
F 1 "1K" H 4000 1650 50  0000 C CNN
F 2 "" V 3830 1700 50  0001 C CNN
F 3 "~" H 3900 1700 50  0001 C CNN
	1    3900 1700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BC7E524
P 4300 2050
AR Path="/5BC7E524" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BC7E524" Ref="#PWR0126"  Part="1" 
F 0 "#PWR0126" H 4300 1800 50  0001 C CNN
F 1 "GND" H 4305 1877 50  0000 C CNN
F 2 "" H 4300 2050 50  0001 C CNN
F 3 "" H 4300 2050 50  0001 C CNN
	1    4300 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	3450 1450 3300 1450
Text HLabel 3300 1450 0    50   Input ~ 0
row_b_ctrl
Connection ~ 4300 1250
Wire Wire Line
	4300 1650 4300 1950
Wire Wire Line
	3900 1450 3900 1550
Connection ~ 3900 1450
Wire Wire Line
	3900 1450 4000 1450
Wire Wire Line
	3900 1850 3900 1950
Wire Wire Line
	3900 1950 4300 1950
Connection ~ 4300 1950
Wire Wire Line
	4300 1950 4300 2050
Text HLabel 4600 800  2    50   Input ~ 0
row_b_motor
Wire Wire Line
	4600 800  4500 800 
$Comp
L Device:Q_PMOS_DGS Q?
U 1 1 5BC81D00
P 6650 900
AR Path="/5BC81D00" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5BC81D00" Ref="Q?"  Part="1" 
F 0 "Q?" V 7000 850 50  0000 L CNN
F 1 "Q_PMOS_DGS" V 6900 850 50  0000 L CNN
F 2 "" H 6850 1000 50  0001 C CNN
F 3 "~" H 6650 900 50  0001 C CNN
	1    6650 900 
	0    1    -1   0   
$EndComp
$Comp
L power:+24V #PWR?
U 1 1 5BC81D07
P 6250 800
AR Path="/5BC81D07" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BC81D07" Ref="#PWR0127"  Part="1" 
F 0 "#PWR0127" H 6250 650 50  0001 C CNN
F 1 "+24V" H 6265 973 50  0000 C CNN
F 2 "" H 6250 800 50  0001 C CNN
F 3 "" H 6250 800 50  0001 C CNN
	1    6250 800 
	1    0    0    -1  
$EndComp
Wire Wire Line
	6450 800  6350 800 
$Comp
L Device:R R?
U 1 1 5BC81D0E
P 6350 1000
AR Path="/5BC81D0E" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BC81D0E" Ref="R?"  Part="1" 
F 0 "R?" H 6420 1046 50  0000 L CNN
F 1 "1K" H 6420 955 50  0000 L CNN
F 2 "" V 6280 1000 50  0001 C CNN
F 3 "~" H 6350 1000 50  0001 C CNN
	1    6350 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	6350 850  6350 800 
Connection ~ 6350 800 
Wire Wire Line
	6350 800  6250 800 
Wire Wire Line
	6350 1150 6350 1250
Wire Wire Line
	6350 1250 6650 1250
Wire Wire Line
	6650 1250 6650 1100
$Comp
L Device:Q_NMOS_DGS Q?
U 1 1 5BC81D1B
P 6550 1450
AR Path="/5BC81D1B" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5BC81D1B" Ref="Q?"  Part="1" 
F 0 "Q?" H 6755 1496 50  0000 L CNN
F 1 "Q_NMOS_DGS" H 6755 1405 50  0000 L CNN
F 2 "" H 6750 1550 50  0001 C CNN
F 3 "~" H 6550 1450 50  0001 C CNN
	1    6550 1450
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5BC81D22
P 5950 1450
AR Path="/5BC81D22" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BC81D22" Ref="R?"  Part="1" 
F 0 "R?" V 6050 1450 50  0000 C CNN
F 1 "R" V 6150 1450 50  0000 C CNN
F 2 "" V 5880 1450 50  0001 C CNN
F 3 "~" H 5950 1450 50  0001 C CNN
	1    5950 1450
	0    1    1    0   
$EndComp
Wire Wire Line
	6100 1450 6250 1450
$Comp
L Device:R R?
U 1 1 5BC81D2A
P 6250 1700
AR Path="/5BC81D2A" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BC81D2A" Ref="R?"  Part="1" 
F 0 "R?" H 6350 1750 50  0000 C CNN
F 1 "1K" H 6350 1650 50  0000 C CNN
F 2 "" V 6180 1700 50  0001 C CNN
F 3 "~" H 6250 1700 50  0001 C CNN
	1    6250 1700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BC81D31
P 6650 2050
AR Path="/5BC81D31" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BC81D31" Ref="#PWR0128"  Part="1" 
F 0 "#PWR0128" H 6650 1800 50  0001 C CNN
F 1 "GND" H 6655 1877 50  0000 C CNN
F 2 "" H 6650 2050 50  0001 C CNN
F 3 "" H 6650 2050 50  0001 C CNN
	1    6650 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 1450 5650 1450
Text HLabel 5650 1450 0    50   Input ~ 0
row_c_ctrl
Connection ~ 6650 1250
Wire Wire Line
	6650 1650 6650 1950
Wire Wire Line
	6250 1450 6250 1550
Connection ~ 6250 1450
Wire Wire Line
	6250 1450 6350 1450
Wire Wire Line
	6250 1850 6250 1950
Wire Wire Line
	6250 1950 6650 1950
Connection ~ 6650 1950
Wire Wire Line
	6650 1950 6650 2050
Text HLabel 6950 800  2    50   Input ~ 0
row_c_motor
Wire Wire Line
	6950 800  6850 800 
$Comp
L Device:Q_PMOS_DGS Q?
U 1 1 5BC86906
P 9000 900
AR Path="/5BC86906" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5BC86906" Ref="Q?"  Part="1" 
F 0 "Q?" V 9350 850 50  0000 L CNN
F 1 "Q_PMOS_DGS" V 9250 850 50  0000 L CNN
F 2 "" H 9200 1000 50  0001 C CNN
F 3 "~" H 9000 900 50  0001 C CNN
	1    9000 900 
	0    1    -1   0   
$EndComp
$Comp
L power:+24V #PWR?
U 1 1 5BC8690D
P 8600 800
AR Path="/5BC8690D" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BC8690D" Ref="#PWR0129"  Part="1" 
F 0 "#PWR0129" H 8600 650 50  0001 C CNN
F 1 "+24V" H 8615 973 50  0000 C CNN
F 2 "" H 8600 800 50  0001 C CNN
F 3 "" H 8600 800 50  0001 C CNN
	1    8600 800 
	1    0    0    -1  
$EndComp
Wire Wire Line
	8800 800  8700 800 
$Comp
L Device:R R?
U 1 1 5BC86914
P 8700 1000
AR Path="/5BC86914" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BC86914" Ref="R?"  Part="1" 
F 0 "R?" H 8770 1046 50  0000 L CNN
F 1 "1K" H 8770 955 50  0000 L CNN
F 2 "" V 8630 1000 50  0001 C CNN
F 3 "~" H 8700 1000 50  0001 C CNN
	1    8700 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	8700 850  8700 800 
Connection ~ 8700 800 
Wire Wire Line
	8700 800  8600 800 
Wire Wire Line
	8700 1150 8700 1250
Wire Wire Line
	8700 1250 9000 1250
Wire Wire Line
	9000 1250 9000 1100
$Comp
L Device:Q_NMOS_DGS Q?
U 1 1 5BC86921
P 8900 1450
AR Path="/5BC86921" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5BC86921" Ref="Q?"  Part="1" 
F 0 "Q?" H 9105 1496 50  0000 L CNN
F 1 "Q_NMOS_DGS" H 9105 1405 50  0000 L CNN
F 2 "" H 9100 1550 50  0001 C CNN
F 3 "~" H 8900 1450 50  0001 C CNN
	1    8900 1450
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5BC86928
P 8300 1450
AR Path="/5BC86928" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BC86928" Ref="R?"  Part="1" 
F 0 "R?" V 8400 1450 50  0000 C CNN
F 1 "R" V 8500 1450 50  0000 C CNN
F 2 "" V 8230 1450 50  0001 C CNN
F 3 "~" H 8300 1450 50  0001 C CNN
	1    8300 1450
	0    1    1    0   
$EndComp
Wire Wire Line
	8450 1450 8600 1450
$Comp
L Device:R R?
U 1 1 5BC86930
P 8600 1700
AR Path="/5BC86930" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BC86930" Ref="R?"  Part="1" 
F 0 "R?" H 8700 1750 50  0000 C CNN
F 1 "1K" H 8700 1650 50  0000 C CNN
F 2 "" V 8530 1700 50  0001 C CNN
F 3 "~" H 8600 1700 50  0001 C CNN
	1    8600 1700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BC86937
P 9000 2050
AR Path="/5BC86937" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BC86937" Ref="#PWR0130"  Part="1" 
F 0 "#PWR0130" H 9000 1800 50  0001 C CNN
F 1 "GND" H 9005 1877 50  0000 C CNN
F 2 "" H 9000 2050 50  0001 C CNN
F 3 "" H 9000 2050 50  0001 C CNN
	1    9000 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	8150 1450 8000 1450
Text HLabel 8000 1450 0    50   Input ~ 0
row_d_ctrl
Connection ~ 9000 1250
Wire Wire Line
	9000 1650 9000 1950
Wire Wire Line
	8600 1450 8600 1550
Connection ~ 8600 1450
Wire Wire Line
	8600 1450 8700 1450
Wire Wire Line
	8600 1850 8600 1950
Wire Wire Line
	8600 1950 9000 1950
Connection ~ 9000 1950
Wire Wire Line
	9000 1950 9000 2050
Text HLabel 9300 800  2    50   Input ~ 0
row_d_motor
Wire Wire Line
	9300 800  9200 800 
Wire Notes Line
	450  2300 9850 2300
$Comp
L Device:Q_PMOS_DGS Q?
U 1 1 5BC92720
P 1950 2750
AR Path="/5BC92720" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5BC92720" Ref="Q?"  Part="1" 
F 0 "Q?" V 2300 2700 50  0000 L CNN
F 1 "Q_PMOS_DGS" V 2200 2700 50  0000 L CNN
F 2 "" H 2150 2850 50  0001 C CNN
F 3 "~" H 1950 2750 50  0001 C CNN
	1    1950 2750
	0    1    -1   0   
$EndComp
$Comp
L power:+24V #PWR?
U 1 1 5BC92727
P 1550 2650
AR Path="/5BC92727" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BC92727" Ref="#PWR0131"  Part="1" 
F 0 "#PWR0131" H 1550 2500 50  0001 C CNN
F 1 "+24V" H 1565 2823 50  0000 C CNN
F 2 "" H 1550 2650 50  0001 C CNN
F 3 "" H 1550 2650 50  0001 C CNN
	1    1550 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 2650 1650 2650
$Comp
L Device:R R?
U 1 1 5BC9272E
P 1650 2850
AR Path="/5BC9272E" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BC9272E" Ref="R?"  Part="1" 
F 0 "R?" H 1720 2896 50  0000 L CNN
F 1 "1K" H 1720 2805 50  0000 L CNN
F 2 "" V 1580 2850 50  0001 C CNN
F 3 "~" H 1650 2850 50  0001 C CNN
	1    1650 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	1650 2700 1650 2650
Connection ~ 1650 2650
Wire Wire Line
	1650 2650 1550 2650
Wire Wire Line
	1650 3000 1650 3100
Wire Wire Line
	1650 3100 1950 3100
Wire Wire Line
	1950 3100 1950 2950
$Comp
L Device:Q_NMOS_DGS Q?
U 1 1 5BC9273B
P 1850 3300
AR Path="/5BC9273B" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5BC9273B" Ref="Q?"  Part="1" 
F 0 "Q?" H 2055 3346 50  0000 L CNN
F 1 "Q_NMOS_DGS" H 2055 3255 50  0000 L CNN
F 2 "" H 2050 3400 50  0001 C CNN
F 3 "~" H 1850 3300 50  0001 C CNN
	1    1850 3300
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5BC92742
P 1250 3300
AR Path="/5BC92742" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BC92742" Ref="R?"  Part="1" 
F 0 "R?" V 1350 3300 50  0000 C CNN
F 1 "R" V 1450 3300 50  0000 C CNN
F 2 "" V 1180 3300 50  0001 C CNN
F 3 "~" H 1250 3300 50  0001 C CNN
	1    1250 3300
	0    1    1    0   
$EndComp
Wire Wire Line
	1400 3300 1550 3300
$Comp
L Device:R R?
U 1 1 5BC9274A
P 1550 3550
AR Path="/5BC9274A" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BC9274A" Ref="R?"  Part="1" 
F 0 "R?" H 1650 3600 50  0000 C CNN
F 1 "1K" H 1650 3500 50  0000 C CNN
F 2 "" V 1480 3550 50  0001 C CNN
F 3 "~" H 1550 3550 50  0001 C CNN
	1    1550 3550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BC92751
P 1950 3900
AR Path="/5BC92751" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BC92751" Ref="#PWR0132"  Part="1" 
F 0 "#PWR0132" H 1950 3650 50  0001 C CNN
F 1 "GND" H 1955 3727 50  0000 C CNN
F 2 "" H 1950 3900 50  0001 C CNN
F 3 "" H 1950 3900 50  0001 C CNN
	1    1950 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	1100 3300 950  3300
Text HLabel 950  3300 0    50   Input ~ 0
row_e_ctrl
Connection ~ 1950 3100
Wire Wire Line
	1950 3500 1950 3800
Wire Wire Line
	1550 3300 1550 3400
Connection ~ 1550 3300
Wire Wire Line
	1550 3300 1650 3300
Wire Wire Line
	1550 3700 1550 3800
Wire Wire Line
	1550 3800 1950 3800
Connection ~ 1950 3800
Wire Wire Line
	1950 3800 1950 3900
Text HLabel 2250 2650 2    50   Input ~ 0
row_e_motor
Wire Wire Line
	2250 2650 2150 2650
$Comp
L Device:Q_PMOS_DGS Q?
U 1 1 5BC92765
P 4300 2750
AR Path="/5BC92765" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5BC92765" Ref="Q?"  Part="1" 
F 0 "Q?" V 4650 2700 50  0000 L CNN
F 1 "Q_PMOS_DGS" V 4550 2700 50  0000 L CNN
F 2 "" H 4500 2850 50  0001 C CNN
F 3 "~" H 4300 2750 50  0001 C CNN
	1    4300 2750
	0    1    -1   0   
$EndComp
$Comp
L power:+24V #PWR?
U 1 1 5BC9276C
P 3900 2650
AR Path="/5BC9276C" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BC9276C" Ref="#PWR0133"  Part="1" 
F 0 "#PWR0133" H 3900 2500 50  0001 C CNN
F 1 "+24V" H 3915 2823 50  0000 C CNN
F 2 "" H 3900 2650 50  0001 C CNN
F 3 "" H 3900 2650 50  0001 C CNN
	1    3900 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 2650 4000 2650
$Comp
L Device:R R?
U 1 1 5BC92773
P 4000 2850
AR Path="/5BC92773" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BC92773" Ref="R?"  Part="1" 
F 0 "R?" H 4070 2896 50  0000 L CNN
F 1 "1K" H 4070 2805 50  0000 L CNN
F 2 "" V 3930 2850 50  0001 C CNN
F 3 "~" H 4000 2850 50  0001 C CNN
	1    4000 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 2700 4000 2650
Connection ~ 4000 2650
Wire Wire Line
	4000 2650 3900 2650
Wire Wire Line
	4000 3000 4000 3100
Wire Wire Line
	4000 3100 4300 3100
Wire Wire Line
	4300 3100 4300 2950
$Comp
L Device:Q_NMOS_DGS Q?
U 1 1 5BC92780
P 4200 3300
AR Path="/5BC92780" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5BC92780" Ref="Q?"  Part="1" 
F 0 "Q?" H 4405 3346 50  0000 L CNN
F 1 "Q_NMOS_DGS" H 4405 3255 50  0000 L CNN
F 2 "" H 4400 3400 50  0001 C CNN
F 3 "~" H 4200 3300 50  0001 C CNN
	1    4200 3300
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5BC92787
P 3600 3300
AR Path="/5BC92787" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BC92787" Ref="R?"  Part="1" 
F 0 "R?" V 3700 3300 50  0000 C CNN
F 1 "R" V 3800 3300 50  0000 C CNN
F 2 "" V 3530 3300 50  0001 C CNN
F 3 "~" H 3600 3300 50  0001 C CNN
	1    3600 3300
	0    1    1    0   
$EndComp
Wire Wire Line
	3750 3300 3900 3300
$Comp
L Device:R R?
U 1 1 5BC9278F
P 3900 3550
AR Path="/5BC9278F" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BC9278F" Ref="R?"  Part="1" 
F 0 "R?" H 4000 3600 50  0000 C CNN
F 1 "1K" H 4000 3500 50  0000 C CNN
F 2 "" V 3830 3550 50  0001 C CNN
F 3 "~" H 3900 3550 50  0001 C CNN
	1    3900 3550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BC92796
P 4300 3900
AR Path="/5BC92796" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BC92796" Ref="#PWR0134"  Part="1" 
F 0 "#PWR0134" H 4300 3650 50  0001 C CNN
F 1 "GND" H 4305 3727 50  0000 C CNN
F 2 "" H 4300 3900 50  0001 C CNN
F 3 "" H 4300 3900 50  0001 C CNN
	1    4300 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	3450 3300 3300 3300
Text HLabel 3300 3300 0    50   Input ~ 0
row_f_ctrl
Connection ~ 4300 3100
Wire Wire Line
	4300 3500 4300 3800
Wire Wire Line
	3900 3300 3900 3400
Connection ~ 3900 3300
Wire Wire Line
	3900 3300 4000 3300
Wire Wire Line
	3900 3700 3900 3800
Wire Wire Line
	3900 3800 4300 3800
Connection ~ 4300 3800
Wire Wire Line
	4300 3800 4300 3900
Text HLabel 4600 2650 2    50   Input ~ 0
row_f_motor
Wire Wire Line
	4600 2650 4500 2650
$Comp
L Device:Q_PMOS_DGS Q?
U 1 1 5BC927AA
P 6650 2750
AR Path="/5BC927AA" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5BC927AA" Ref="Q?"  Part="1" 
F 0 "Q?" V 7000 2700 50  0000 L CNN
F 1 "Q_PMOS_DGS" V 6900 2700 50  0000 L CNN
F 2 "" H 6850 2850 50  0001 C CNN
F 3 "~" H 6650 2750 50  0001 C CNN
	1    6650 2750
	0    1    -1   0   
$EndComp
$Comp
L power:+24V #PWR?
U 1 1 5BC927B1
P 6250 2650
AR Path="/5BC927B1" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BC927B1" Ref="#PWR0135"  Part="1" 
F 0 "#PWR0135" H 6250 2500 50  0001 C CNN
F 1 "+24V" H 6265 2823 50  0000 C CNN
F 2 "" H 6250 2650 50  0001 C CNN
F 3 "" H 6250 2650 50  0001 C CNN
	1    6250 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	6450 2650 6350 2650
$Comp
L Device:R R?
U 1 1 5BC927B8
P 6350 2850
AR Path="/5BC927B8" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BC927B8" Ref="R?"  Part="1" 
F 0 "R?" H 6420 2896 50  0000 L CNN
F 1 "1K" H 6420 2805 50  0000 L CNN
F 2 "" V 6280 2850 50  0001 C CNN
F 3 "~" H 6350 2850 50  0001 C CNN
	1    6350 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	6350 2700 6350 2650
Connection ~ 6350 2650
Wire Wire Line
	6350 2650 6250 2650
Wire Wire Line
	6350 3000 6350 3100
Wire Wire Line
	6350 3100 6650 3100
Wire Wire Line
	6650 3100 6650 2950
$Comp
L Device:Q_NMOS_DGS Q?
U 1 1 5BC927C5
P 6550 3300
AR Path="/5BC927C5" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5BC927C5" Ref="Q?"  Part="1" 
F 0 "Q?" H 6755 3346 50  0000 L CNN
F 1 "Q_NMOS_DGS" H 6755 3255 50  0000 L CNN
F 2 "" H 6750 3400 50  0001 C CNN
F 3 "~" H 6550 3300 50  0001 C CNN
	1    6550 3300
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5BC927CC
P 5950 3300
AR Path="/5BC927CC" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BC927CC" Ref="R?"  Part="1" 
F 0 "R?" V 6050 3300 50  0000 C CNN
F 1 "R" V 6150 3300 50  0000 C CNN
F 2 "" V 5880 3300 50  0001 C CNN
F 3 "~" H 5950 3300 50  0001 C CNN
	1    5950 3300
	0    1    1    0   
$EndComp
Wire Wire Line
	6100 3300 6250 3300
$Comp
L Device:R R?
U 1 1 5BC927D4
P 6250 3550
AR Path="/5BC927D4" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BC927D4" Ref="R?"  Part="1" 
F 0 "R?" H 6350 3600 50  0000 C CNN
F 1 "1K" H 6350 3500 50  0000 C CNN
F 2 "" V 6180 3550 50  0001 C CNN
F 3 "~" H 6250 3550 50  0001 C CNN
	1    6250 3550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BC927DB
P 6650 3900
AR Path="/5BC927DB" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BC927DB" Ref="#PWR0136"  Part="1" 
F 0 "#PWR0136" H 6650 3650 50  0001 C CNN
F 1 "GND" H 6655 3727 50  0000 C CNN
F 2 "" H 6650 3900 50  0001 C CNN
F 3 "" H 6650 3900 50  0001 C CNN
	1    6650 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 3300 5650 3300
Text HLabel 5650 3300 0    50   Input ~ 0
row_g_ctrl
Connection ~ 6650 3100
Wire Wire Line
	6650 3500 6650 3800
Wire Wire Line
	6250 3300 6250 3400
Connection ~ 6250 3300
Wire Wire Line
	6250 3300 6350 3300
Wire Wire Line
	6250 3700 6250 3800
Wire Wire Line
	6250 3800 6650 3800
Connection ~ 6650 3800
Wire Wire Line
	6650 3800 6650 3900
Text HLabel 6950 2650 2    50   Input ~ 0
row_g_motor
Wire Wire Line
	6950 2650 6850 2650
$Comp
L Device:Q_PMOS_DGS Q?
U 1 1 5BC927EF
P 9000 2750
AR Path="/5BC927EF" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5BC927EF" Ref="Q?"  Part="1" 
F 0 "Q?" V 9350 2700 50  0000 L CNN
F 1 "Q_PMOS_DGS" V 9250 2700 50  0000 L CNN
F 2 "" H 9200 2850 50  0001 C CNN
F 3 "~" H 9000 2750 50  0001 C CNN
	1    9000 2750
	0    1    -1   0   
$EndComp
$Comp
L power:+24V #PWR?
U 1 1 5BC927F6
P 8600 2650
AR Path="/5BC927F6" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BC927F6" Ref="#PWR0137"  Part="1" 
F 0 "#PWR0137" H 8600 2500 50  0001 C CNN
F 1 "+24V" H 8615 2823 50  0000 C CNN
F 2 "" H 8600 2650 50  0001 C CNN
F 3 "" H 8600 2650 50  0001 C CNN
	1    8600 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	8800 2650 8700 2650
$Comp
L Device:R R?
U 1 1 5BC927FD
P 8700 2850
AR Path="/5BC927FD" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BC927FD" Ref="R?"  Part="1" 
F 0 "R?" H 8770 2896 50  0000 L CNN
F 1 "1K" H 8770 2805 50  0000 L CNN
F 2 "" V 8630 2850 50  0001 C CNN
F 3 "~" H 8700 2850 50  0001 C CNN
	1    8700 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	8700 2700 8700 2650
Connection ~ 8700 2650
Wire Wire Line
	8700 2650 8600 2650
Wire Wire Line
	8700 3000 8700 3100
Wire Wire Line
	8700 3100 9000 3100
Wire Wire Line
	9000 3100 9000 2950
$Comp
L Device:Q_NMOS_DGS Q?
U 1 1 5BC9280A
P 8900 3300
AR Path="/5BC9280A" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5BC9280A" Ref="Q?"  Part="1" 
F 0 "Q?" H 9105 3346 50  0000 L CNN
F 1 "Q_NMOS_DGS" H 9105 3255 50  0000 L CNN
F 2 "" H 9100 3400 50  0001 C CNN
F 3 "~" H 8900 3300 50  0001 C CNN
	1    8900 3300
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5BC92811
P 8300 3300
AR Path="/5BC92811" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BC92811" Ref="R?"  Part="1" 
F 0 "R?" V 8400 3300 50  0000 C CNN
F 1 "R" V 8500 3300 50  0000 C CNN
F 2 "" V 8230 3300 50  0001 C CNN
F 3 "~" H 8300 3300 50  0001 C CNN
	1    8300 3300
	0    1    1    0   
$EndComp
Wire Wire Line
	8450 3300 8600 3300
$Comp
L Device:R R?
U 1 1 5BC92819
P 8600 3550
AR Path="/5BC92819" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BC92819" Ref="R?"  Part="1" 
F 0 "R?" H 8700 3600 50  0000 C CNN
F 1 "1K" H 8700 3500 50  0000 C CNN
F 2 "" V 8530 3550 50  0001 C CNN
F 3 "~" H 8600 3550 50  0001 C CNN
	1    8600 3550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BC92820
P 9000 3900
AR Path="/5BC92820" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BC92820" Ref="#PWR0138"  Part="1" 
F 0 "#PWR0138" H 9000 3650 50  0001 C CNN
F 1 "GND" H 9005 3727 50  0000 C CNN
F 2 "" H 9000 3900 50  0001 C CNN
F 3 "" H 9000 3900 50  0001 C CNN
	1    9000 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	8150 3300 8000 3300
Text HLabel 8000 3300 0    50   Input ~ 0
row_h_ctrl
Connection ~ 9000 3100
Wire Wire Line
	9000 3500 9000 3800
Wire Wire Line
	8600 3300 8600 3400
Connection ~ 8600 3300
Wire Wire Line
	8600 3300 8700 3300
Wire Wire Line
	8600 3700 8600 3800
Wire Wire Line
	8600 3800 9000 3800
Connection ~ 9000 3800
Wire Wire Line
	9000 3800 9000 3900
Text HLabel 9300 2650 2    50   Input ~ 0
row_h_motor
Wire Wire Line
	9300 2650 9200 2650
Wire Notes Line
	450  4150 9850 4150
Text HLabel 1050 4250 0    50   Input ~ 0
col_1_motor
$Comp
L Device:Q_PMOS_SGD Q?
U 1 1 5BCA89F6
P 3700 4450
AR Path="/5BCA89F6" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5BCA89F6" Ref="Q?"  Part="1" 
F 0 "Q?" H 3906 4496 50  0000 L CNN
F 1 "Q_PMOS_SGD" H 3906 4405 50  0000 L CNN
F 2 "" H 3900 4550 50  0001 C CNN
F 3 "~" H 3700 4450 50  0001 C CNN
	1    3700 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 4450 3500 4450
$Comp
L Device:R R?
U 1 1 5BCA89FE
P 3650 4950
AR Path="/5BCA89FE" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BCA89FE" Ref="R?"  Part="1" 
F 0 "R?" V 3443 4950 50  0000 C CNN
F 1 "1K" V 3534 4950 50  0000 C CNN
F 2 "" V 3580 4950 50  0001 C CNN
F 3 "~" H 3650 4950 50  0001 C CNN
	1    3650 4950
	0    1    1    0   
$EndComp
Wire Wire Line
	3800 4950 3800 4800
Wire Wire Line
	4000 4800 3800 4800
Connection ~ 3800 4800
Wire Wire Line
	3800 4800 3800 4650
Wire Wire Line
	3500 4950 3500 4450
Connection ~ 3500 4450
Wire Wire Line
	3400 4250 3800 4250
Text HLabel 3400 4450 0    50   Input ~ 0
col_2_ctrl
Text Label 4000 4800 0    50   ~ 0
motor_common_gnd
Text HLabel 3400 4250 0    50   Input ~ 0
col_2_motor
$Comp
L Device:Q_PMOS_SGD Q?
U 1 1 5BCADB68
P 6050 4450
AR Path="/5BCADB68" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5BCADB68" Ref="Q?"  Part="1" 
F 0 "Q?" H 6256 4496 50  0000 L CNN
F 1 "Q_PMOS_SGD" H 6256 4405 50  0000 L CNN
F 2 "" H 6250 4550 50  0001 C CNN
F 3 "~" H 6050 4450 50  0001 C CNN
	1    6050 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 4450 5850 4450
$Comp
L Device:R R?
U 1 1 5BCADB70
P 6000 4950
AR Path="/5BCADB70" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BCADB70" Ref="R?"  Part="1" 
F 0 "R?" V 5793 4950 50  0000 C CNN
F 1 "1K" V 5884 4950 50  0000 C CNN
F 2 "" V 5930 4950 50  0001 C CNN
F 3 "~" H 6000 4950 50  0001 C CNN
	1    6000 4950
	0    1    1    0   
$EndComp
Wire Wire Line
	6150 4950 6150 4800
Wire Wire Line
	6350 4800 6150 4800
Connection ~ 6150 4800
Wire Wire Line
	6150 4800 6150 4650
Wire Wire Line
	5850 4950 5850 4450
Connection ~ 5850 4450
Wire Wire Line
	5750 4250 6150 4250
Text HLabel 5750 4450 0    50   Input ~ 0
col_3_ctrl
Text Label 6350 4800 0    50   ~ 0
motor_common_gnd
Text HLabel 5750 4250 0    50   Input ~ 0
col_3_motor
$Comp
L Device:Q_PMOS_SGD Q?
U 1 1 5BCADB82
P 8400 4450
AR Path="/5BCADB82" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5BCADB82" Ref="Q?"  Part="1" 
F 0 "Q?" H 8606 4496 50  0000 L CNN
F 1 "Q_PMOS_SGD" H 8606 4405 50  0000 L CNN
F 2 "" H 8600 4550 50  0001 C CNN
F 3 "~" H 8400 4450 50  0001 C CNN
	1    8400 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	8100 4450 8200 4450
$Comp
L Device:R R?
U 1 1 5BCADB8A
P 8350 4950
AR Path="/5BCADB8A" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BCADB8A" Ref="R?"  Part="1" 
F 0 "R?" V 8143 4950 50  0000 C CNN
F 1 "1K" V 8234 4950 50  0000 C CNN
F 2 "" V 8280 4950 50  0001 C CNN
F 3 "~" H 8350 4950 50  0001 C CNN
	1    8350 4950
	0    1    1    0   
$EndComp
Wire Wire Line
	8500 4950 8500 4800
Wire Wire Line
	8700 4800 8500 4800
Connection ~ 8500 4800
Wire Wire Line
	8500 4800 8500 4650
Wire Wire Line
	8200 4950 8200 4450
Connection ~ 8200 4450
Wire Wire Line
	8100 4250 8500 4250
Text HLabel 8100 4450 0    50   Input ~ 0
col_4_ctrl
Text Label 8700 4800 0    50   ~ 0
motor_common_gnd
Text HLabel 8100 4250 0    50   Input ~ 0
col_4_motor
Wire Notes Line
	450  5050 9850 5050
$Comp
L Device:Q_PMOS_SGD Q?
U 1 1 5BCB38D1
P 1350 5350
AR Path="/5BCB38D1" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5BCB38D1" Ref="Q?"  Part="1" 
F 0 "Q?" H 1556 5396 50  0000 L CNN
F 1 "Q_PMOS_SGD" H 1556 5305 50  0000 L CNN
F 2 "" H 1550 5450 50  0001 C CNN
F 3 "~" H 1350 5350 50  0001 C CNN
	1    1350 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	1050 5350 1150 5350
$Comp
L Device:R R?
U 1 1 5BCB38D9
P 1300 5850
AR Path="/5BCB38D9" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BCB38D9" Ref="R?"  Part="1" 
F 0 "R?" V 1093 5850 50  0000 C CNN
F 1 "1K" V 1184 5850 50  0000 C CNN
F 2 "" V 1230 5850 50  0001 C CNN
F 3 "~" H 1300 5850 50  0001 C CNN
	1    1300 5850
	0    1    1    0   
$EndComp
Wire Wire Line
	1450 5850 1450 5700
Wire Wire Line
	1650 5700 1450 5700
Connection ~ 1450 5700
Wire Wire Line
	1450 5700 1450 5550
Wire Wire Line
	1150 5850 1150 5350
Connection ~ 1150 5350
Wire Wire Line
	1050 5150 1450 5150
Text HLabel 1050 5350 0    50   Input ~ 0
col_5_ctrl
Text Label 1650 5700 0    50   ~ 0
motor_common_gnd
Text HLabel 1050 5150 0    50   Input ~ 0
col_5_motor
$Comp
L Device:Q_PMOS_SGD Q?
U 1 1 5BCB38EB
P 3700 5350
AR Path="/5BCB38EB" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5BCB38EB" Ref="Q?"  Part="1" 
F 0 "Q?" H 3906 5396 50  0000 L CNN
F 1 "Q_PMOS_SGD" H 3906 5305 50  0000 L CNN
F 2 "" H 3900 5450 50  0001 C CNN
F 3 "~" H 3700 5350 50  0001 C CNN
	1    3700 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 5350 3500 5350
$Comp
L Device:R R?
U 1 1 5BCB38F3
P 3650 5850
AR Path="/5BCB38F3" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BCB38F3" Ref="R?"  Part="1" 
F 0 "R?" V 3443 5850 50  0000 C CNN
F 1 "1K" V 3534 5850 50  0000 C CNN
F 2 "" V 3580 5850 50  0001 C CNN
F 3 "~" H 3650 5850 50  0001 C CNN
	1    3650 5850
	0    1    1    0   
$EndComp
Wire Wire Line
	3800 5850 3800 5700
Wire Wire Line
	4000 5700 3800 5700
Connection ~ 3800 5700
Wire Wire Line
	3800 5700 3800 5550
Wire Wire Line
	3500 5850 3500 5350
Connection ~ 3500 5350
Wire Wire Line
	3400 5150 3800 5150
Text HLabel 3400 5350 0    50   Input ~ 0
col_6_ctrl
Text Label 4000 5700 0    50   ~ 0
motor_common_gnd
Text HLabel 3400 5150 0    50   Input ~ 0
col_6_motor
$Comp
L Device:Q_PMOS_SGD Q?
U 1 1 5BCB3905
P 6050 5350
AR Path="/5BCB3905" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5BCB3905" Ref="Q?"  Part="1" 
F 0 "Q?" H 6256 5396 50  0000 L CNN
F 1 "Q_PMOS_SGD" H 6256 5305 50  0000 L CNN
F 2 "" H 6250 5450 50  0001 C CNN
F 3 "~" H 6050 5350 50  0001 C CNN
	1    6050 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 5350 5850 5350
$Comp
L Device:R R?
U 1 1 5BCB390D
P 6000 5850
AR Path="/5BCB390D" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BCB390D" Ref="R?"  Part="1" 
F 0 "R?" V 5793 5850 50  0000 C CNN
F 1 "1K" V 5884 5850 50  0000 C CNN
F 2 "" V 5930 5850 50  0001 C CNN
F 3 "~" H 6000 5850 50  0001 C CNN
	1    6000 5850
	0    1    1    0   
$EndComp
Wire Wire Line
	6150 5850 6150 5700
Wire Wire Line
	6350 5700 6150 5700
Connection ~ 6150 5700
Wire Wire Line
	6150 5700 6150 5550
Wire Wire Line
	5850 5850 5850 5350
Connection ~ 5850 5350
Wire Wire Line
	5750 5150 6150 5150
Text HLabel 5750 5350 0    50   Input ~ 0
col_7_ctrl
Text Label 6350 5700 0    50   ~ 0
motor_common_gnd
Text HLabel 5750 5150 0    50   Input ~ 0
col_7_motor
$Comp
L Device:Q_PMOS_SGD Q?
U 1 1 5BCB391E
P 8400 5350
AR Path="/5BCB391E" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5BCB391E" Ref="Q?"  Part="1" 
F 0 "Q?" H 8606 5396 50  0000 L CNN
F 1 "Q_PMOS_SGD" H 8606 5305 50  0000 L CNN
F 2 "" H 8600 5450 50  0001 C CNN
F 3 "~" H 8400 5350 50  0001 C CNN
	1    8400 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	8100 5350 8200 5350
$Comp
L Device:R R?
U 1 1 5BCB3926
P 8350 5850
AR Path="/5BCB3926" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BCB3926" Ref="R?"  Part="1" 
F 0 "R?" V 8143 5850 50  0000 C CNN
F 1 "1K" V 8234 5850 50  0000 C CNN
F 2 "" V 8280 5850 50  0001 C CNN
F 3 "~" H 8350 5850 50  0001 C CNN
	1    8350 5850
	0    1    1    0   
$EndComp
Wire Wire Line
	8500 5850 8500 5700
Wire Wire Line
	8700 5700 8500 5700
Connection ~ 8500 5700
Wire Wire Line
	8500 5700 8500 5550
Wire Wire Line
	8200 5850 8200 5350
Connection ~ 8200 5350
Wire Wire Line
	8100 5150 8500 5150
Text HLabel 8100 5350 0    50   Input ~ 0
col_8_ctrl
Text Label 8700 5700 0    50   ~ 0
motor_common_gnd
Text HLabel 8100 5150 0    50   Input ~ 0
col_8_motor
Wire Notes Line
	450  5950 9850 5950
Wire Notes Line
	2800 450  2800 5950
Wire Notes Line
	5150 450  5150 5950
Wire Notes Line
	7500 450  7500 5950
Wire Notes Line
	9850 450  9850 5950
Wire Notes Line
	10000 4150 10150 4150
Wire Notes Line
	10150 450  10000 450 
Text Notes 10800 3950 1    197  ~ 0
High Side\nMotor Driving
Wire Notes Line
	10150 5950 10000 5950
Wire Notes Line
	10150 450  10150 5950
Text Notes 11100 5750 1    197  ~ 0
Low Side\nMotor\nDriving
$Comp
L power:+5V #PWR?
U 1 1 5BC96F7C
P 2200 7450
F 0 "#PWR?" H 2200 7300 50  0001 C CNN
F 1 "+5V" H 2215 7623 50  0000 C CNN
F 2 "" H 2200 7450 50  0001 C CNN
F 3 "" H 2200 7450 50  0001 C CNN
	1    2200 7450
	-1   0    0    1   
$EndComp
$EndSCHEMATC
