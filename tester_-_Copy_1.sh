#!/bin/sh

stack(){
	ARG=`ruby -e "puts (1..$1).to_a.shuffle.join(' ')"`
}
push_swap(){
	result=`./push_swap $ARG`
}
line_count(){
	wc=`echo "$result" | wc -l`
}
checker_os(){
	if [ "$ARG" = "1 2 3" ]; then
		if [ "$result" != "" ]; then
			check="OK"
		else
			check="OK"
			wc=0
		fi
	else
		check="OK"
	fi
	if [ "$check" != "OK" ]; then
			count "\r$i/$pass \e[01;31;5;240mKO"
			warn "\nYour Push Swap don't sort number !\nCheck error.log to see ARG and your output."
			echo "ARG :\n\n"$ARG > log/error.log
			echo "\n\nYour output :" $result >> log/error.log
			exit "2"
	fi
}
output(){
    echo '\e[36m'"$1"'\e[0m';
}
warn(){
    echo '\e[31m'"$1"'\e[0m';
}
info(){
    echo '\e[33m'"$1"'\e[0m';
}
count(){
	echo -n '\e[33m'"$1"'\e[0m';
}

basic_check(){
	info "Basic test"
	stack "3"
	push_swap
	if [ $result -gt 3 ]
	then
		output "$result"
		warn "Your Push_Swap can't sort 3 number with 3 action or less !"
		exit 1
	else
		output "$result"
		info "Your Push_Swap can sort 3 number with 3 action or less !"
	fi
}

overkill_check(){
	output "____________Starting Over_kill_test____________"
	i=0
	best_case=-1
	worst_case=-1
	average=0
	info "Sorting ${nb} numbers x $pass time"
	while [ $i != $pass ]; do
		stack "${nb}"
		push_swap
		line_count
		checker_os
		i=$((i+1))
		average=$((average+wc))
		if [ $best_case -eq -1 ] || [ $best_case -gt $wc ]; then
			best_case=$wc
			best_test=$ARG
		fi
		if [ $worst_case -eq -1 ] || [ $worst_case -lt $wc ]; then
			worst_case=$wc
			worst_test=$ARG
		fi
		count "\r$i/$pass \e[01;32;5;240mOK"
	done
	if [ "$check" = "OK" ]; then
		info "\nBest_case : $best_case"
		info "Worst_case : $worst_case"
		average=$((average / i))
		info "Average : $average"
		echo $worst_test > log/worst_case_${nb}.log
		echo $best_test > log/best_case_${nb}.log
	fi
}

init_check(){
	clear
	output "###############################################"
	output "__________Starting test for Push_swap__________"
	output "###############################################"
	OS="`uname`"
	if [ "$OS" = Linux ]; then
		OS=linux
	elif
	[ "$OS" = Darwin ]; then
		OS=Mac
	else
		warn "You OS is \e[31;1m$OS\e[0m\e[31m, sorry your OS is unsupported...\nThis script support only Linux and MacOS"
		exit "1"
	fi
	rm -Rf log
	mkdir log
}

nb=${1:-500}
pass=${2:-100}
init_check
#basic_check
overkill_check
