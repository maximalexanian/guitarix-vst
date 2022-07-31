v 20130925 2
C 40000 40000 0 0 0 title-B.sym
C 41700 44700 1 270 0 resistor-2.sym
{
T 42050 44300 5 10 0 0 270 0 1
device=RESISTOR
T 42000 44300 5 10 1 1 0 0 1
refdes=R1
T 42000 44000 5 10 1 1 0 0 1
value=1M
}
C 42700 45700 1 180 0 resistor-2.sym
{
T 42300 45350 5 10 0 0 180 0 1
device=RESISTOR
T 42216 45434 5 10 1 1 180 0 1
refdes=R2
T 42300 45300 5 10 1 1 0 0 1
value=68k
}
C 43700 44700 1 270 0 resistor-2.sym
{
T 44050 44300 5 10 0 0 270 0 1
device=RESISTOR
T 44000 44400 5 10 1 1 0 0 1
refdes=R3
T 44000 44200 5 10 1 1 0 0 1
value=1k5
}
C 43500 48200 1 270 0 resistor-2.sym
{
T 43850 47800 5 10 0 0 270 0 1
device=RESISTOR
T 43800 47800 5 10 1 1 0 0 1
refdes=R4
T 43800 47600 5 10 1 1 0 0 1
value=100k
}
C 51500 48300 1 270 0 resistor-2.sym
{
T 51850 47900 5 10 0 0 270 0 1
device=RESISTOR
T 51800 47900 5 10 1 1 0 0 1
refdes=R8
T 51800 47700 5 10 1 1 0 0 1
value=100k
}
C 51700 44800 1 270 0 resistor-2.sym
{
T 52050 44400 5 10 0 0 270 0 1
device=RESISTOR
T 51300 44400 5 10 1 1 0 0 1
refdes=R7
T 51300 44200 5 10 1 1 0 0 1
value=1k5
}
C 45900 46700 1 0 0 capacitor-1.sym
{
T 46100 47400 5 10 0 0 0 0 1
device=CAPACITOR
T 46200 47200 5 10 1 1 0 0 1
refdes=C3
T 46100 47600 5 10 0 0 0 0 1
symversion=0.1
T 46200 46500 5 10 1 1 0 0 1
value=22n
}
C 53400 46800 1 0 0 capacitor-1.sym
{
T 53600 47500 5 10 0 0 0 0 1
device=CAPACITOR
T 53700 47300 5 10 1 1 0 0 1
refdes=C6
T 53600 47700 5 10 0 0 0 0 1
symversion=0.1
T 53700 46600 5 10 1 1 0 0 1
value=22n
}
C 41700 43100 1 0 0 gnd-1.sym
C 50200 43200 1 0 0 gnd-1.sym
C 51700 43200 1 0 0 gnd-1.sym
C 41200 43600 1 0 0 triode.sym
{
T 44000 46400 5 10 1 1 0 0 1
refdes=U1
T 43900 46100 5 10 1 1 0 0 1
value=12ax7
T 43600 45700 5 10 0 1 0 0 1
device=TRIODE
}
C 41000 45500 1 0 0 input-1.sym
{
T 41000 45800 5 10 0 0 0 0 1
device=INPUT
T 41127 45534 5 10 1 1 0 0 1
refdes=Vin
}
N 42700 45600 42800 45600 4
N 41800 44700 41800 45600 4
{
T 41800 45300 5 10 1 1 0 0 1
netname=1
}
C 43700 43100 1 0 0 gnd-1.sym
C 45000 46700 1 0 0 ccurrent.sym
{
T 45200 47200 5 10 1 1 0 0 1
refdes=CC1
T 45400 47000 5 10 0 1 0 0 1
device=CONNECTION_CURRENT
}
N 45000 46900 43600 46900 4
{
T 44700 47000 5 10 1 1 0 0 1
netname=4
}
C 43400 48400 1 0 0 generic-power-1.sym
{
T 43600 48600 5 10 0 1 0 0 1
device=POWER
T 43932 48649 5 10 1 1 0 0 1
value=250V
T 43409 48652 5 10 1 1 0 0 1
refdes=Vcc1
}
C 49200 43700 1 0 0 triode.sym
{
T 52100 46200 5 10 1 1 0 0 1
refdes=U2
T 52100 45900 5 10 1 1 0 0 1
value=12ax7
}
C 51400 48500 1 0 0 generic-power-1.sym
{
T 49600 48600 5 10 0 1 0 0 1
device=POWER
T 51934 48752 5 10 1 1 0 0 1
value=250V
T 51395 48748 5 10 1 1 0 0 1
refdes=Vcc2
}
C 52400 46800 1 0 0 ccurrent.sym
{
T 52600 47300 5 10 1 1 0 0 1
refdes=CC2
T 52800 47100 5 10 0 1 0 0 1
device=CONNECTION_CURRENT
}
N 51600 46500 51600 47400 4
N 51600 47000 52400 47000 4
{
T 51900 47100 5 10 1 1 0 0 1
netname=11
}
T 54700 47000 8 10 1 1 0 0 1
netname=14
C 56100 46100 1 0 0 output-1.sym
{
T 56200 46400 5 10 0 0 0 0 1
device=OUTPUT
T 56389 46137 5 10 1 1 0 0 1
refdes=Vout
}
N 53400 47000 53200 47000 4
{
T 53200 47100 5 10 1 1 0 0 1
netname=13
}
N 41800 43400 41800 43800 4
N 43800 43400 43800 43800 4
N 50300 43500 50300 45300 4
N 51800 43500 51800 43900 4
N 43800 44700 43800 44900 4
N 51800 44800 51800 45000 4
{
T 51500 44900 5 10 1 1 0 0 1
netname=10
}
N 43600 48400 43600 48200 4
{
T 43400 48300 5 10 1 1 0 0 1
netname=5
}
N 51600 48500 51600 48300 4
{
T 51300 48400 5 10 1 1 0 0 1
netname=12
}
N 43600 46400 43600 47300 4
N 45900 46900 45800 46900 4
{
T 45800 47000 5 10 1 1 0 0 1
netname=6
}
C 50200 46200 1 270 0 resistor-variable-2.sym
{
T 50510 45802 5 10 1 1 0 0 1
refdes=P3
T 51100 45400 5 10 0 1 270 0 1
device=VARIABLE_RESISTOR
T 50300 45400 5 10 1 1 0 0 1
value=value=1M,var=Drive,inv=1,a=1
}
N 55600 47000 54300 47000 4
C 55500 45300 1 0 0 gnd-1.sym
C 55500 45700 1 270 1 resistor-variable-2.sym
{
T 55900 46250 5 10 1 1 90 2 1
refdes=P6
T 56400 46500 5 10 0 1 90 2 1
device=VARIABLE_RESISTOR
T 55500 45700 5 10 1 1 0 0 1
value=value=1M,var=Level,a=1
}
N 46800 46900 50300 46900 4
C 54700 44900 1 90 0 diode-1.sym
{
T 54100 45300 5 10 0 0 90 0 1
device=DIODE2
T 54600 45200 5 10 1 1 90 0 1
refdes=D1
T 54700 44900 5 10 0 0 0 0 1
value=Is=10e-12,mUt=30e-3
}
C 54400 46100 1 270 1 resistor-variable-2.sym
{
T 54800 46650 5 10 1 1 90 2 1
refdes=P7
T 55300 46900 5 10 0 1 90 2 1
device=VARIABLE_RESISTOR
T 54400 46100 5 10 0 1 0 0 1
value=value=100k,var=Saturation,inv=1
}
N 54500 46100 54500 45800 4
N 50300 46900 50300 46200 4
N 55600 46600 55600 47000 4
N 55600 45600 55600 45700 4
N 55000 46600 55000 46000 4
N 55000 46000 54500 46000 4
N 54500 44900 54500 44800 4
N 54500 44800 51800 44800 4
