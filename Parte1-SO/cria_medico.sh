#!/bin/bash
idlenght=$2
if [ ! -f medicos.txt ];
then
	if [ "${#idlenght}" -eq 5 ]
	then
		touch medicos.txt
		echo "$1;$2;$3;$4;0;0;0" >> medicos.txt
		cat medicos.txt
	else
		echo "O id do médico não tem 5 caracteres"
	fi
else
if [ "${#idlenght}" -eq 5 ]
then
	if grep -q "$2" medicos.txt;
	then
		echo "Medico ja no sistema!"
	else
		echo "$1;$2;$3;$4;0;0;0" >> medicos.txt
    	cat medicos.txt
	fi
else
	echo "O id do médico não tem 5 caracteres"
	fi
fi
