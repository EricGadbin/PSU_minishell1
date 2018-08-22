#!/bin/bash

echo "Downloading tests ..."
wget http://epi2022.fr/neo/PSU/PSU_minishell1_2017/PSU_minishell1_2017.sh &> /dev/null
if [ ! -f mysh ]; then
	echo "File not found!"
	rm -rf PSU_minishell1_2017.sh &> /dev/null
	exit
fi
if [ ! -f PSU_minishell1_2017.sh ]; then
	echo "[ERROR] Cannot download the tests"
	exit
fi
chmod +x mysh &> /dev/null
chmod +x PSU_minishell1_2017.sh &> /dev/null
./PSU_minishell1_2017.sh > tests.txt
rm -rf PSU_minishell1_2017.sh &> /dev/null
echo "LOG IS IN TESTS.TXT"
