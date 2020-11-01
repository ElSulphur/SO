#!/bin/bash
#cat medicos.txt | while read line;
#echo "$1, $2"
cidade=$1
saldo=$2

y=$(cat pacientes.txt | awk -F ';' '{print $3}' | grep -c "$cidade")
echo "O número de pacientes em $cidade é $y"

c=0
while read linha;
do
    t=$(echo $linha | awk -F ';' '{print $7}')
    if [ $t -gt $saldo ]
    then
        let c=c+1
    fi
done < medicos.txt
echo "O número de médicos com saldo superior a $saldo é $c"
