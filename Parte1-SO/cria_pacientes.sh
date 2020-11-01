#!/bin/bash
if test -f pacientes.txt; then
	rm pacientes.txt
fi
touch pacientes.txt
cat /etc/passwd | grep "^a.*" | tail -n +3 | head | sed 's/^a*//g;' | awk -F'[,:]' '{print $1";"$5";;;a"$1"@iscte-iul.pt;100"}' >> pacientes.txt
