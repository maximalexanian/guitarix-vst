v 20110115 2
C 40000 40000 0 0 0 title-B.sym
C 48500 45100 1 270 0 resistor-2.sym
{
T 48850 44700 5 10 0 0 270 0 1
device=RESISTOR
T 48800 44800 5 10 1 1 0 0 1
refdes=Rk
T 48800 44600 5 10 1 1 0 0 1
value=2k7
}
C 48300 48600 1 270 0 resistor-2.sym
{
T 48650 48200 5 10 0 0 270 0 1
device=RESISTOR
T 48600 48200 5 10 1 1 0 0 1
refdes=Ra
T 48600 48000 5 10 1 1 0 0 1
value=100k
}
C 46000 44000 1 0 0 triode.sym
{
T 48800 46800 5 10 1 1 0 0 1
refdes=U1
T 48700 46500 5 10 1 1 0 0 1
value=12ax7
T 48400 46100 5 10 0 1 0 0 1
device=TRIODE
}
C 46300 45900 1 0 0 input-1.sym
{
T 46300 46200 5 10 0 0 0 0 1
device=INPUT
T 46427 45934 5 10 1 1 0 0 1
refdes=Vin
}
N 47100 46000 47600 46000 4
C 48500 43500 1 0 0 gnd-1.sym
N 49800 47300 48400 47300 4
C 48200 48800 1 0 0 generic-power-1.sym
{
T 48400 49000 5 10 0 1 0 0 1
device=POWER
T 48732 49049 5 10 1 1 0 0 1
value=385V
T 48209 49052 5 10 1 1 0 0 1
refdes=Vpp
}
C 49800 47200 1 0 0 output-1.sym
{
T 49900 47500 5 10 0 0 0 0 1
device=OUTPUT
T 50089 47237 5 10 1 1 0 0 1
refdes=Vout
}
N 48600 43800 48600 44200 4
N 48600 45100 48600 45300 4
N 48400 48800 48400 48600 4
N 48400 46800 48400 47700 4
