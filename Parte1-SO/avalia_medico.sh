#!/bin/bash
if [ ! -f lista_negra_medicos.txt ]; 
then
	touch lista_negra_medicos.txt
	echo "Lista criada"
fi
cat medicos.txt | while read linha;
do
	y=$(echo $linha | cut -d ';' -f5)
	z=$(echo $linha | cut -d ';' -f6)
	#echo $z
	if [ $y -lt "5" ] && [ $z -gt "6" ]
	then
		if [ $(grep -c "$linha" lista_negra_medicos.txt) -eq "0" ];
		#if [ -z $(grep "$linha" lista_negra_medicos.txt) ];
		then
			echo $linha >> lista_negra_medicos.txt
		fi
	fi
done
echo "Lista negra dos médicos:"
cat lista_negra_medicos.txt
