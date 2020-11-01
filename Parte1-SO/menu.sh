#!/bin/bash
echo " ------*Menu*------"
echo " 1 - Cria pacientes"
echo " 2 - Cria médico"
echo " 3 - Cria stats"
echo " 4 - Avalia médicos"
echo " 0 - Sair"
read m
case $m in
	1) ./cria_pacientes.sh 
	echo "Pacientes Criados"
	./menu;;
	2) echo "Insira a informação do médico"
	echo "Nome"
	read arg1
	echo "Id"
	read arg2
	echo "Especialidade"
	read arg3
	echo "Email"
	read arg4
	./cria_medico.sh "$arg1" "$arg2" "$arg3" "$arg4"
	./menu;;
	3) echo "Stats"
	./stats.sh
	./menu;;
	4) echo "Avalia médicos"
	./avalia_medico.sh
	./menu;;
	0) echo "Sair" | exit 0;;
	*) echo "Erro, por favor insira um número válido"
	./menu;;
esac


