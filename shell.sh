# !/bin/bash

data=('FIFO' 'PSJF' 'RR' 'SJF')

for ds in "${data[@]}";do
	for i in {1..5};do
		sudo dmesg -c
		sudo ./main < test_data/OS_PJ1_Test/${ds}_${i}.txt > output/${ds}_${i}_stdout.txt
		dmesg | grep Project1 > output/${ds}_${i}_dmesg.txt
	done
done

sudo dmesg -c
sudo ./main < test_data/OS_PJ1_Test/TIME_MEASUREMENT.txt > output/TIME_MEASUREMENT_stdout.txt
dmesg | grep Project1 > output/TIME_MEASUREMENT_dmesg.txt


