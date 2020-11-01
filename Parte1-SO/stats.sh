#!/bin/bash
echo "$1, $2"
cidade=$1
saldo=$2
echo "$cidade, $saldo"
	#x=grep -o '\b$1\b' medicos.txt | wc -1
#echo "O número de pacientes que vive em $1 é " 
#tr '[:space:]' '[\n+]' < pacientes.txt | grep -i -c "$1"
#	tr '[:space:]' '[\n+]' < medicos.txt | grep -i -c "$2"
#sed -i -e 's/ //g' pacientes.txt
sed -i -e 's/;/ /g' pacientes.txt
sed -i -e 's/;/ /g' medicos.txt
#rm saldos.txt
#touch saldos.txt
#cat medicos.txt | awk '{print $6}' >> saldos.
c=0
cat pacientes.txt | while read linha;
do
	#Substituir o 4 e 2 em baixo por terciro e 6 e medicos por pacientes
	#y=$(echo $linha | awk '{print $4}')
	y=$(echo $linha | grep -i $cidade)
	#z=$(echo $linha | awk '{print $7}')
	#echo $y
	if [ "$y" = "$cidade" ]
	then
		((c=c+1))
		echo $c
	fi
done
d=0
i=0
cat medicos.txt | while read line;
do
	z=$(echo $line | awk '{print $5}')
	if [[ "$z" -gt "$saldo" ]]
	then
		echo "$z"
		d=$((d+1))
		i=$d
		echo $d
		#let d=d+1
	fi
	echo $d
done
echo $i
echo $c
echo "O número de pacientes que vive em $1 é $c"
sed -i -e 's/ /;/g' pacientes.txt
sed -i -e 's/ /;/g' medicos.txt
echo "O número de médicos com saldo superior a $2 é $d"

