v 20130925 2
C 40000 40000 0 0 0 title-B.sym
C 47900 44100 1 90 0 resistor-2.sym
{
T 47550 44500 5 10 0 0 90 0 1
device=RESISTOR
T 48300 44800 5 10 1 1 180 0 1
refdes=R4
T 48000 44300 5 10 1 1 0 0 1
value=390
}
C 50000 46300 1 180 0 capacitor-1.sym
{
T 49800 45600 5 10 0 0 180 0 1
device=CAPACITOR
T 49200 46200 5 10 1 1 0 0 1
refdes=C4
T 49800 45400 5 10 0 0 180 0 1
symversion=0.1
T 50100 46400 5 10 1 1 180 0 1
value=3.3u
}
C 47700 43800 1 0 0 gnd-1.sym
C 49900 45200 1 270 1 resistor-variable-2.sym
{
T 49550 45500 5 10 1 1 180 6 1
refdes=P1
T 50800 46000 5 10 0 1 90 2 1
device=VARIABLE_RESISTOR
T 52300 45400 5 10 1 1 180 0 1
value=value=100k,var=Volume
}
C 43700 45500 1 0 0 input-1.sym
{
T 43700 45800 5 10 0 0 0 0 1
device=INPUT
T 43700 45500 5 10 1 1 0 0 1
refdes=IN1
}
C 50500 45800 1 180 1 output-1.sym
{
T 50600 45500 5 10 0 0 180 6 1
device=OUTPUT
T 50700 45800 5 10 1 1 180 6 1
refdes=OUT1
}
C 45500 46400 1 90 0 resistor-2.sym
{
T 45150 46800 5 10 0 0 90 0 1
device=RESISTOR
T 45200 47100 5 10 1 1 180 0 1
refdes=R2
T 44900 46700 5 10 1 1 0 0 1
value=430k
}
C 47900 46400 1 90 0 resistor-2.sym
{
T 47550 46800 5 10 0 0 90 0 1
device=RESISTOR
T 47600 47200 5 10 1 1 180 0 1
refdes=R3
T 47300 46700 5 10 1 1 0 0 1
value=10k
}
C 46200 45600 1 270 0 capacitor-1.sym
{
T 46900 45400 5 10 0 0 270 0 1
device=CAPACITOR
T 46300 45400 5 10 1 1 180 0 1
refdes=C2
T 47100 45400 5 10 0 0 270 0 1
symversion=0.1
T 45900 44800 5 10 1 1 0 0 1
value=0.1u
}
C 48400 47300 1 270 0 capacitor-1.sym
{
T 49100 47100 5 10 0 0 270 0 1
device=CAPACITOR
T 48500 47200 5 10 1 1 180 0 1
refdes=C3
T 49300 47100 5 10 0 0 270 0 1
symversion=0.1
T 48700 46500 5 10 1 1 0 0 1
value=0.1u
}
C 47300 45100 1 0 0 npn-2.sym
{
T 47900 45600 5 10 0 0 0 0 1
device=NPN_TRANSISTOR
T 47700 45600 5 10 1 1 0 0 1
refdes=T1
T 47300 45100 5 10 0 1 0 0 1
value=Vt=26mV,Is=20.3fA,Bf=1430,Br=4
T 47800 45400 5 10 1 1 0 0 1
model-name=2N5088
}
C 45500 44700 1 90 0 resistor-2.sym
{
T 45150 45100 5 10 0 0 90 0 1
device=RESISTOR
T 45200 45400 5 10 1 1 180 0 1
refdes=R1
T 44800 45000 5 10 1 1 0 0 1
value=43k
}
C 50100 43800 1 0 1 gnd-1.sym
C 45500 44400 1 0 1 gnd-1.sym
C 50100 44100 1 90 0 resistor-2.sym
{
T 49750 44500 5 10 0 0 90 0 1
device=RESISTOR
T 50400 44800 5 10 1 1 180 0 1
refdes=R5
T 50100 44300 5 10 1 1 0 0 1
value=1k
}
C 46500 44400 1 0 1 gnd-1.sym
C 45400 45800 1 180 0 capacitor-1.sym
{
T 45200 45100 5 10 0 0 180 0 1
device=CAPACITOR
T 44600 45700 5 10 1 1 0 0 1
refdes=C1
T 45200 44900 5 10 0 0 180 0 1
symversion=0.1
T 45400 45800 5 10 1 1 180 0 1
value=3.3u
}
C 45200 47300 1 0 0 9V-plus-1.sym
{
T 45200 47300 5 10 0 0 0 0 1
device=POWER
T 45500 47300 5 10 1 1 0 0 1
value=9V
T 45200 47700 5 10 1 1 0 0 1
refdes=Vcc
}
N 45400 45600 47300 45600 4
N 45400 45600 45400 46400 4
N 47800 46400 47800 46100 4
N 50000 45000 50000 45200 4
N 47800 45000 47800 45100 4
N 49100 46100 47800 46100 4
N 48600 46400 48600 46100 4
N 45400 47300 48600 47300 4
